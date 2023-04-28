`ifndef __PIPELINEID__
`define __PIPELINEID__
/*
* file: ID stage in 5 stage pipeline 
    1. get input from IF stage 
    2. decode the instruction, generate control signals for other components
    3. pass output to EXE stage
main components: 
    1. decoder: decode the instruction 
    2. extending unit: extend imm into 32 bits
    3. static branch predictor: do the static prediction for jump and branch instructions 
    4. compressDecoder: extend the 16 bits compress instruction into 32 bits instruction
author: fujie
time: 2023年 4月28日 星期五 15时52分49秒 CST
*/
`include "definitions.vh"
`include "decoder.v"
`include "staticBranchPredictor.v"
`include "compressDecoder.v"
`include "extendingUnit.v"

module pipelineID(
    input wire clk,
    input wire resetn, // reset signal for ID stage, used for pipeline flush
    input wire enable, // enable signal for ID stage, used for pipeline stall
    input wire [31:0] instructionD, // instruction passed from IF stage
);

// =========================================================================
// ============================ implementation =============================
// =========================================================================

endmodule
`endif
