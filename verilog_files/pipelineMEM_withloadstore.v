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
    input wire [31:0] CSR_data_e_i,
    input wire        mret_e_i,
    // TODO: add D-memory write data, rs1[31:0]
    // WB stage signals
    input wire [31:0] extended_imm_e_i,  
    input wire [31:0] pc_plus_e_i,      
    input wire        reg_write_en_e_i,         
    input wire [ 4:0] rd_idx_e_i,          
    input wire [ 4:0] result_src_e_i,   
    input wire        trap_flush_t_i,
    input wire [31:0] epc_source_e_i,
    input wire [31:0] epc_source_d_i_w,
    input wire        bnt1_h_i,

    /* signals to passed to WB stage */
    output reg [31:0] mem_read_data_m_o,  // data read from D-memory 
    output reg [31:0] alu_result_m_o,    // alu calculation result
    output reg [31:0] extended_imm_m_o,  // extended imm, for 'lui' instruction
    output reg [31:0] pc_plus_m_o,      // rd=pc+4, for `jal` instruction
    output reg        reg_write_en_m_o,   // RF write enable
    output reg [ 4:0] rd_idx_m_o,            // RF write back register index, passed from MEM stage
    output reg [ 4:0] result_src_m_o,    // select signal to choose one of the four inputs
    output wire [31:0] bypass_m_o,
    output reg [31:0] CSR_data_m_o,
    output reg        mret_m_o,
    // PC passed to top
    // TODO: signals to communicate with Data Memory
    // TODO: add CSR Unit signals

    //addr and data wires to PLIC unit
    output wire [23:0] PLIC_addr_m_o,
    output wire [31:0] PLIC_wdata_m_o,
    output wire PLIC_wen_m_o,
    output wire PLIC_ren_m_o,
    input wire [31:0] PLIC_rdata_p_i,
    output reg [31:0] epc_source_m_o
);

// =========================================================================
// ====================+++======== variables ===============================
// =========================================================================
    // D-memory Store
    reg [ 3:0] byte_en;
    reg [31:0] dmem_write_data;
    wire [31:0] dmem_write_data_f;

    // D-memory Load
    reg  [ 3:0] mem_op;
    reg  [ 1:0] byte_addr;
    wire [31:0] read_data_32;
    reg  [31:0] read_data;
    wire [31:0] dmem_read_data; // dmem output
    reg         dmem_load;

    // D-memory instance
    wire [ 9:0] dmem_addr;
    wire        ceb;
    wire        web;

    //PLIC load
    reg plic_load;
    reg eb_r;
    


// =========================================================================
// ============================ implementation =============================
// =========================================================================
//addr space separation: 0-ffc:dmem
//                       100000-3FFFFF:PLIC

//TODO: forbid dmem write when PLIC write

    always@(posedge clk)
    begin
        plic_load<=(alu_calculation_e_i[31:22]==0)&(alu_calculation_e_i[21:20]!=0)&(web)&(~ceb);
        dmem_load<=(alu_calculation_e_i[31:12]==0)&(web);
    end

    assign dmem_write_data_f={32{~trap_flush_t_i}}&dmem_write_data;
    

    assign PLIC_addr_m_o={24{(alu_calculation_e_i[31:22]==0)&(alu_calculation_e_i[21:20]!=0)}}&(alu_calculation_e_i[23:0]-24'h100000);
    assign PLIC_ren_m_o=(alu_calculation_e_i[31:22]==0)&(alu_calculation_e_i[21:20]!=0)&(web)&(~ceb);
    assign PLIC_wen_m_o=(alu_calculation_e_i[31:22]==0)&(alu_calculation_e_i[21:20]!=0)&(~web)&(~ceb);
    assign PLIC_wdata_m_o=dmem_write_data_f;

    assign dmem_addr = {10{alu_calculation_e_i[31:12]==0}}&alu_calculation_e_i[11:2];
    assign ceb = (trap_flush_t_i)|(dmem_type_e_i == `DMEM_NO);
    assign web = (dmem_type_e_i == `DMEM_LB) |
                 (dmem_type_e_i == `DMEM_LH) |
                 (dmem_type_e_i == `DMEM_LBU)|
                 (dmem_type_e_i == `DMEM_LHU)|
                 (dmem_type_e_i == `DMEM_LW);

    /*always@(posedge clk)
    begin
        if(~resetn)
        begin
            eb_r<=1'b0;
        end
        else
        begin
            eb_r<=(~web)&(~ceb);
        end
    end*/


    //*********************************    
    //          PIPELINE OUT
    //*********************************
    always @(posedge clk ) begin 
        if(~resetn||trap_flush_t_i) begin
            result_src_m_o    <= 5'b00000;
            alu_result_m_o    <= 32'h0;
            pc_plus_m_o       <= 32'h0;
            extended_imm_m_o  <= 32'h0;
            reg_write_en_m_o  <= 1'b0;
            rd_idx_m_o        <= 5'h0;
            CSR_data_m_o      <= 32'b0;
            mret_m_o          <= 1'b0;
            epc_source_m_o    <= 32'h80000000;
        end
        else begin
            // pass signals to MEM stage
            result_src_m_o    <= result_src_e_i;
            alu_result_m_o    <= alu_result_e_i;
            pc_plus_m_o       <= pc_plus_e_i;
            extended_imm_m_o  <= extended_imm_e_i;
            reg_write_en_m_o  <= reg_write_en_e_i;
            rd_idx_m_o        <= rd_idx_e_i;
            CSR_data_m_o      <= CSR_data_e_i;
            mret_m_o          <= mret_e_i;
            epc_source_m_o    <= bnt1_h_i?epc_source_d_i_w:epc_source_e_i;
        end
    end

    
    assign bypass_m_o = ({32{result_src_e_i[0]}}&alu_result_e_i)|
                                 ({32{result_src_e_i[1]}}&extended_imm_e_i)|
                                 ({32{result_src_e_i[2]}}&read_data)|
                                 ({32{result_src_e_i[3]}}&pc_plus_e_i)|
                                 ({32{result_src_e_i[4]}}&CSR_data_e_i);

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
        if(trap_flush_t_i)
        begin
            mem_op    <= `DMEM_NO; 
            byte_addr <= 2'b0;
            mem_read_data_m_o <= 32'b0;
        end
        else
        begin
            mem_op    <= dmem_type_e_i; 
            byte_addr <= alu_result_e_i[1:0];
            mem_read_data_m_o <= read_data;
        end
    end
    assign read_data_32={32{dmem_load}}&dmem_read_data
                        |{32{plic_load}}&PLIC_rdata_p_i;


    always @(*) begin 
        case(mem_op) 
            `DMEM_LB: begin
                case(byte_addr)
                    2'b00: read_data = { {24{read_data_32[7]}},   read_data_32[7:0] }; 
                    2'b01: read_data = { {24{read_data_32[15]}},  read_data_32[15:8] }; 
                    2'b10: read_data = { {24{read_data_32[23]}},  read_data_32[23:16] }; 
                    2'b11: read_data = { {24{read_data_32[31]}},  read_data_32[31:24] }; 
                endcase
            end

            `DMEM_LH: begin
                case(byte_addr[1])
                    0: read_data = { {16{read_data_32[15]}}, read_data_32[15:0] };
                    1: read_data = { {16{read_data_32[31]}}, read_data_32[31:16] };
                endcase
            end

            `DMEM_LBU: begin
                case(byte_addr)
                    2'b00: read_data = { {24{1'b0}}, read_data_32[7:0] }; 
                    2'b01: read_data = { {24{1'b0}}, read_data_32[15:8] }; 
                    2'b10: read_data = { {24{1'b0}}, read_data_32[23:16] }; 
                    2'b11: read_data = { {24{1'b0}}, read_data_32[31:24] }; 
                endcase

            end
            `DMEM_LHU: begin
                case(byte_addr[1])
                    0: read_data = { {16{1'b0}}, read_data_32[15:0] };
                    1: read_data = { {16{1'b0}}, read_data_32[31:16] };
                endcase
            end

            `DMEM_LW: begin
                read_data = read_data_32;
            end

            default: read_data = read_data_32;
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
        .D      		( dmem_write_data_f ),
        .Q      		( dmem_read_data	)
    );
 
endmodule
`endif
