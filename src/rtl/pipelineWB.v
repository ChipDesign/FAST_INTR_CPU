`ifndef __PIPELINEWB__
`define __PIPELINEWB__
/*
file: 5 stage pipelne write back stage
    select one of the four write back source, 
    pass the select source to RF(register file) in ID(instruction decode) stage
author: fujie 
time: 2023年 5月 5日 星期五 11时06分55秒 CST
*/
`include "definitions.vh"
module pipelineWB (
    // input wire resetn, // no reset need in WB stage
    /* input data passed from MEM stage */
    input wire        clk,
    input wire        resetn,
    input wire [31:0] alu_result_m_i,   // alu calculation result
    input wire [31:0] mem_read_data_m_i, // delared as wire, becased the D-memory has 1 cycle delay when reading
    input wire [31:0] extended_imm_m_i,  // extended imm, for 'lui' instruction
    input wire [31:0] pc_plus4_m_i,      // rd=pc+4, for `jal` instruction
    input wire reg_write_en_m_i,
    input wire [4:0] rd_idx_m_i,  // RF write back register index, passed from MEM stage
    input wire [3:0] result_src_m_i,    // select signal to choose one of the four inputs
    input wire [31:0] pc_instr_m_i,

    /* write back data to ID stage */
    output wire reg_write_en_w_o, // write back to RF enable
    output wire [4:0] rd_idx_w_o,   // RF write register index
    output wire [31:0] write_back_data_w_o, // data write to RF in ID 
    output reg [31:0] pc_instr_w_o
);


// =========================================================================
// ============================ implementation =============================
// =========================================================================
always @(posedge clk) begin 
    if(resetn) begin
        pc_instr_w_o <= 32'h80000000;
    end
    else begin
        pc_instr_w_o <= pc_instr_m_i;    
    end
end

    assign reg_write_en_w_o = reg_write_en_m_i;
    assign rd_idx_w_o       = rd_idx_m_i;
    assign write_back_data_w_o = ({32{result_src_m_i[0]}}&alu_result_m_i)|
                                 ({32{result_src_m_i[1]}}&extended_imm_m_i)|
                                 ({32{result_src_m_i[2]}}&mem_read_data_m_i)|
                                 ({32{result_src_m_i[3]}}&pc_plus4_m_i);
endmodule
`endif
