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
    input wire resetn,

    /* signals passed from EXE stage */
    // MEM stage signals
    input wire [31:0] aluResultE_i,   
    input wire [ 2:0] dMemTypeE_i,      // load/store types
    // WB stage signals
    input wire [31:0] extendedImmE_i,  
    input wire [31:0] pcPlus4E_i,      
    input wire        regWriteEnE_i,         
    input wire [ 4:0] rdIdxE_i,          
    input wire [ 1:0] resultSrcE_i,   
    input wire        instrIllegalE_i, // instruction illegal, used by CSR unit

    /* signals to passed to WB stage */
    output reg [31:0] memReadDataM_o,  // data read from D-memory 
    output reg [31:0] aluResultM_o,    // alu calculation result
    output reg [31:0] extendedImmM_o,  // extended imm, for 'lui' instruction
    output reg [31:0] pcPlus4M_o,      // rd=pc+4, for `jal` instruction
    output reg        regWriteEnM_o,   // RF write enable
    output reg [ 4:0] rdIdxM_o,            // RF write back register index, passed from MEM stage
    output reg [ 1:0] resultSrcM_o    // select signal to choose one of the four inputs
    // TODO: signals to communicate with Data Memory
    // TODO: add CSR Unit signals
);

// =========================================================================
// ============================ implementation =============================
// =========================================================================

    always @(posedge clk ) begin 
        if(~resetn) begin
            regWriteEnM_o  <= 1'b0;    
            resultSrcM_o   <= 2'b0;  
            aluResultM_o   <= 32'h0;  
            memReadDataM_o <= 32'h0;
            pcPlus4M_o     <= 32'h0;     
            extendedImmM_o <= 32'h0; 
            rdIdxM_o       <= 5'h0;
        end
        else begin
            // pass signals to MEM stage
            regWriteEnM_o  <= regWriteEnE_i;
            resultSrcM_o   <= resultSrcE_i;
            aluResultM_o   <= aluResultE_i;
            memReadDataM_o <= 32'h0; // TODO: memory read data must from D-memory
            pcPlus4M_o     <= pcPlus4E_i;
            extendedImmM_o <= extendedImmE_i;
            rdIdxM_o       <= rdIdxE_i;
        end
    end


    // TODO: add D-memory logic signals
endmodule
`endif
