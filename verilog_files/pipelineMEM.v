`ifndef __PIPELINEMEM__
`define __PIPELINEMEM__
/*
file: five stage pipeline MEM stage
    1. if need to read from data memory, use the address calculated by alu to access data memory 
    2. if need to write to data memory, use the address calculated by alu to access data memory
    3. use MASK to choose which Byte to access
author: fujie
time: 2023年 5月 5日 星期五 11时27分51秒 CST
*/
`include "definitions.vh"
// `include "sram_1p_32x816.v"
module pipelineMEM (
    input wire clk,
    input wire resetn, // no reset need in MEM stage

    /* signals passed from EXE stage */
    // MEM stage signals
    input wire [31:0] alu_result_e_i,   
    input wire [ 2:0] dmem_type_e_i,      // load/store types
    // WB stage signals
    input wire [31:0] extended_imm_e_i,  
    input wire [31:0] pc_plus4_e_i,      
    input wire        reg_write_en_e_i,         
    input wire [ 4:0] rd_idx_e_i,          
    input wire [ 3:0] result_src_e_i,   
    input wire        instr_illegal_e_i, // instruction illegal, used by CSR unit

    /* signals to passed to WB stage */
    output reg [31:0] mem_read_data_m_o,  // data read from D-memory 
    output reg [31:0] alu_result_m_o,    // alu calculation result
    output reg [31:0] extended_imm_m_o,  // extended imm, for 'lui' instruction
    output reg [31:0] pc_plus4_m_o,      // rd=pc+4, for `jal` instruction
    output reg        reg_write_en_m_o,   // RF write enable
    output reg [ 4:0] rd_idx_m_o,            // RF write back register index, passed from MEM stage
    output reg [ 3:0] result_src_m_o,    // select signal to choose one of the four inputs
    output wire [31:0] bypass_m_o
    // TODO: signals to communicate with Data Memory
    // TODO: add CSR Unit signals
);

// =========================================================================
// ============================ implementation =============================
// =========================================================================


    always @(posedge clk ) begin 
        if(~resetn) begin
            reg_write_en_m_o  <= 1'b0;
            result_src_m_o    <= 4'b0000;
            alu_result_m_o    <= 32'h0;
            mem_read_data_m_o <= 32'h0;
            pc_plus4_m_o      <= 32'h0;
            extended_imm_m_o  <= 32'h0;
            rd_idx_m_o        <= 5'h0;
        end
        else begin
            // pass signals to MEM stage
            reg_write_en_m_o  <= reg_write_en_e_i;
            result_src_m_o    <= result_src_e_i;
            alu_result_m_o    <= alu_result_e_i;
            mem_read_data_m_o <= 32'h0; // TODO: memory read data must from D-memory
            pc_plus4_m_o      <= pc_plus4_e_i;
            extended_imm_m_o  <= extended_imm_e_i;
            rd_idx_m_o        <= rd_idx_e_i;
        end
    end

    assign bypass_m_o = 32'b0 ;
    // TODO: add D-memory logic signals
endmodule
`endif
