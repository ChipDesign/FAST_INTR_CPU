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
    input wire clk,
    input wire resetn,

    /* input data passed from MEM stage */
    input wire [31:0] aluResultM_i,   // alu calculation result
    input wire [31:0] memReadDataM_i, // delared as wire, becased the D-memory has 1 cycle delay when reading
    input wire [31:0] extendedImmM_i,  // extended imm, for 'lui' instruction
    input wire [31:0] pcPlus4M_i,      // rd=pc+4, for `jal` instruction
    input wire regWriteEnM_i,
    input wire [4:0] rdIdxM_i,  // RF write back register index, passed from MEM stage
    input wire [1:0] resultSrcM_i,    // select signal to choose one of the four inputs

    /* write back data to ID stage */
    output reg regWriteEnW_o, // write back to RF enable
    output reg [4:0] rdIdxW_o,   // RF write register index
    output reg [31:0] writeBackDataW_o // data write to RF in ID 
);


// =========================================================================
// ============================ implementation =============================
// =========================================================================
always@(posedge clk)begin 
    if(~resetn)begin
        regWriteEnW_o <= 0;
        rdIdxW_o <=0;
        writeBackDataW_o <= 0;
    end
    else begin 
        regWriteEnW_o <= regWriteEnM_i;
        rdIdxW_o <= rdIdxM_i;
        case(resultSrcM_i) 
            `WBSRC_ALU: begin
                writeBackDataW_o <= aluResultM_i; // choose alu result to write back
            end
            `WBSRC_IMM: begin
                writeBackDataW_o <= extendedImmM_i; // choose extended immdiate to write back
            end
            `WBSRC_MEM: begin
                writeBackDataW_o <= memReadDataM_i;// choose data memory output to write back
            end
            `WBSRC_PC: begin
                writeBackDataW_o <= pcPlus4M_i;// choose pc+4 to write back
            end
            default: writeBackDataW_o <= aluResultM_i;
        endcase
    end
end
endmodule
`endif
