`ifndef __PIPELINEMEMWITHLOADSTORE__
`define __PIPELINEMEMWITHLOADSTORE__
/*
file: five stage pipeline MEM stage
    1. if need to read from data memory, use the address calculated by alu to access data memory 
    2. if need to write to data memory, use the address calculated by alu to access data memory
    3. use MASK to choose which Byte to access
author: fujie
time: 2023年 5月 5日 星期五 11时27分51秒 CST
*/
`include "definitions.vh"
`include "dmemory.v"
module pipelineMEM_withloadstore (
    input wire clk,
    input wire resetn, // no reset need in MEM stage

    /* signals passed from EXE stage */
    // MEM stage signals
    input wire [31:0] alu_result_e_i,   
    input wire [31:0] alu_calculation_e_i,   
    input wire [ 3:0] dmem_type_e_i, // load/store types
    input wire [31:0] rs2_e_i,       // memory write data
    // TODO: add D-memory write data, rs1[31:0]
    // WB stage signals
    input wire [31:0] extended_imm_e_i,  
    input wire [31:0] pc_plus_e_i,      
    input wire        reg_write_en_e_i,         
    input wire [ 4:0] rd_idx_e_i,          
    input wire [ 3:0] result_src_e_i,   

    /* signals to passed to WB stage */
    output reg [31:0] mem_read_data_m_o,  // data read from D-memory 
    output reg [31:0] alu_result_m_o,    // alu calculation result
    output reg [31:0] extended_imm_m_o,  // extended imm, for 'lui' instruction
    output reg [31:0] pc_plus_m_o,      // rd=pc+4, for `jal` instruction
    output reg        reg_write_en_m_o,   // RF write enable
    output reg [ 4:0] rd_idx_m_o,            // RF write back register index, passed from MEM stage
    output reg [ 3:0] result_src_m_o,    // select signal to choose one of the four inputs
    output wire [31:0] bypass_m_o
    // PC passed to top
    // TODO: signals to communicate with Data Memory
    // TODO: add CSR Unit signals
);

// =========================================================================
// ====================+++======== variables ===============================
// =========================================================================
    // D-memory Store
    reg [ 3:0] byte_en;
    reg [31:0] dmem_write_data;

    // D-memory Load
    reg  [ 3:0] mem_op;
    reg  [ 1:0] byte_addr;
    reg  [31:0] read_data;
    wire [31:0] dmem_read_data; // dmem output

    // D-memory instance
    wire [ 9:0] dmem_addr;
    wire        ceb;
    wire        web;
    


// =========================================================================
// ============================ implementation =============================
// =========================================================================
    assign dmem_addr = alu_calculation_e_i[11:2];
    assign ceb =  dmem_type_e_i == `DMEM_NO;
    assign web = (dmem_type_e_i == `DMEM_LB) |
                 (dmem_type_e_i == `DMEM_LH) |
                 (dmem_type_e_i == `DMEM_LBU)|
                 (dmem_type_e_i == `DMEM_LHU)|
                 (dmem_type_e_i == `DMEM_LW);



    //*********************************    
    //          PIPELINE OUT
    //*********************************
    always @(posedge clk ) begin 
        if(~resetn) begin
            result_src_m_o    <= 4'b0000;
            alu_result_m_o    <= 32'h0;
            pc_plus_m_o       <= 32'h0;
            extended_imm_m_o  <= 32'h0;
            reg_write_en_m_o  <= 1'b0;
            rd_idx_m_o        <= 5'h0;
        end
        else begin
            // pass signals to MEM stage
            result_src_m_o    <= result_src_e_i;
            alu_result_m_o    <= alu_result_e_i;
            pc_plus_m_o       <= pc_plus_e_i;
            extended_imm_m_o  <= extended_imm_e_i;
            reg_write_en_m_o  <= reg_write_en_e_i;
            rd_idx_m_o        <= rd_idx_e_i;
        end
    end

    
    assign bypass_m_o = ({32{result_src_e_i[0]}}&alu_result_e_i)|
                                 ({32{result_src_e_i[1]}}&extended_imm_e_i)|
                                 ({32{result_src_e_i[2]}}&read_data)|
                                 ({32{result_src_e_i[3]}}&pc_plus_e_i);

    //*********************************    
    //        DATA MEM STORES
    //*********************************
    always@(*) begin
        // DEFAULTS
        dmem_write_data   = 32'b0; 
        byte_en          = 4'b0;

        case(dmem_type_e_i)

            `DMEM_SW: begin
                dmem_write_data = rs2_e_i;
                byte_en     = 4'b1111;
            end

            `DMEM_SB: begin
                // determine which byte to write to based on last two bits of address
                case(alu_calculation_e_i[1:0]) 
                    2'b00: begin
                        dmem_write_data = { {24{1'b0}}, rs2_e_i[7:0] }; 
                        byte_en = 4'b0001;
                    end
                    2'b01: begin
                        dmem_write_data = { {16{1'b0}}, rs2_e_i[7:0],  { 8{1'b0}} };
                        byte_en = 4'b0010;
                    end
                    2'b10: begin
                        dmem_write_data = { {8{1'b0}},  rs2_e_i[7:0], {16{1'b0}} };
                        byte_en = 4'b0100;
                    end
                    2'b11: begin
                       dmem_write_data = { rs2_e_i[7:0], {24{1'b0}} };
                       byte_en = 4'b1000;
                    end
                endcase
            end 

            `DMEM_SH: begin
                case(alu_calculation_e_i[1:0])
                    2'b00: begin
                       dmem_write_data = { {16{1'b0}}, rs2_e_i[15:0] };
                       byte_en = 4'b0011;
                    end
                    default: begin
                       dmem_write_data = { rs2_e_i[15:0], {16{1'b0}} };
                       byte_en = 4'b1100;
                    end
                endcase 
            end   
            default: begin
                dmem_write_data = 32'h0;
                byte_en = 4'h0;
            end
        endcase
    end


    //*********************************    
    //        DATA MEM LOADS
    //*********************************
    // D-memory read data is 1 cycle behind
    // flop mem_op and byte_addr 
    always@(posedge clk) begin
        mem_op    <= dmem_type_e_i; 
        byte_addr <= alu_result_e_i[1:0];
        mem_read_data_m_o <= read_data;
    end

    always @(*) begin 
        case(mem_op) 
            `DMEM_LB: begin
                case(byte_addr)
                    2'b00: read_data = { {24{dmem_read_data[7]}},   dmem_read_data[7:0] }; 
                    2'b01: read_data = { {24{dmem_read_data[15]}},  dmem_read_data[15:8] }; 
                    2'b10: read_data = { {24{dmem_read_data[23]}},  dmem_read_data[23:16] }; 
                    2'b11: read_data = { {24{dmem_read_data[31]}},  dmem_read_data[31:24] }; 
                endcase
            end

            `DMEM_LH: begin
                case(byte_addr[1])
                    0: read_data = { {16{dmem_read_data[15]}}, dmem_read_data[15:0] };
                    1: read_data = { {16{dmem_read_data[31]}}, dmem_read_data[31:16] };
                endcase
            end

            `DMEM_LBU: begin
                case(byte_addr)
                    2'b00: read_data = { {24{1'b0}}, dmem_read_data[7:0] }; 
                    2'b01: read_data = { {24{1'b0}}, dmem_read_data[15:8] }; 
                    2'b10: read_data = { {24{1'b0}}, dmem_read_data[23:16] }; 
                    2'b11: read_data = { {24{1'b0}}, dmem_read_data[31:24] }; 
                endcase

            end
            `DMEM_LHU: begin
                case(byte_addr[1])
                    0: read_data = { {16{1'b0}}, dmem_read_data[15:0] };
                    1: read_data = { {16{1'b0}}, dmem_read_data[31:16] };
                endcase
            end

            `DMEM_LW: begin
                read_data = dmem_read_data;
            end

            default: read_data = dmem_read_data;
        endcase
    end

    //*********************************    
    //       D-memory instance 
    //*********************************

    dmemory u_dmemory(
        //ports
        .clk    		( clk    		    ),
        .ceb    		( ceb    		    ),
        .web    		( web    		    ),
        .A      		( dmem_addr   	    ),
        .mask   		( byte_en   	    ),
        .D      		( dmem_write_data   ),
        .Q      		( dmem_read_data	)
    );
 
endmodule
`endif
