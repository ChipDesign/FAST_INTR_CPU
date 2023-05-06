`ifndef __PIPELINEEXE__
`define __PIPELINEEXE__
/*
file: 5 stage pipeline EXE stage, do calculation according to different ALU_OP type
author: fujie
time: 2023年 5月 5日 星期五 14时48分40秒 CST
*/
`include "definitions.vh"
module pipelineEXE (
    input wire clk,
    input wire resetn,

    /* signals passed from ID stage*/
    // EXE stage signals
    input wire [ 4:0] aluOpD_i,          // ALU Operation
    input wire [31:0] rs1D_i,            // ALU operand 1
    input wire [31:0] rs2D_i,            // ALU operand 2
    input wire [31:0] extendedImmD_i,  
    input wire [31:0] pcPlus4D_i,      
    // TODO: signals below are uesd 
    // 1. for choosing ALU operand
    // 2. calculate jump instructions
    // input wire        rs1SelD_i,        // ALU operand select
    // input wire        rs2SelD_i,        // ALU operand select
    // input wire        beqD_i,           // additional control for ALU
    // input wire        bltD_i,           // additional control for ALU
    // TODO add input from Hazard Unit
    // MEM stage signals
    input wire [ 2:0] dMemTypeD_i,      // load/store types
    // WB stage signals 
    input wire        regWriteEnD_i,         
    input wire [ 4:0] rdIdxD_i,          
    input wire [ 1:0] resultSrcD_i,   
    input wire        instrIllegalD_i,  // instruction illegal

    /* signals passed to MEM stage */
    output reg [31:0] aluResultE_o,   // alu calculation result                                               
    output reg [ 2:0] dMemTypeE_o,      // load/store types
    // WB stage signals 
    output reg [31:0] extendedImmE_o, // extended imm, for 'lui' instruction                                 ,
    output reg [31:0] pcPlus4E_o,     // rd=pc+4, for `jal` instruction                                       
    output reg        regWriteEnE_o,  // RF write enable                                                      
    output reg [ 4:0] rdIdxE_o,          
    output reg [ 1:0] resultSrcE_o,   // select signal to choose one of the four inputs
    output reg        instrIllegalE_o // instruction illegal
);


// =========================================================================
// ============================ internal variables =========================
// =========================================================================
    reg [31:0] aluResult;
// =========================================================================
// ============================ implementation =============================
// =========================================================================

    // calculate ALU result, this is combinational logic
    always @(*) begin 
        case(aluOpD_i) 
            `ALUOP_ADD: begin
                aluResult = rs1D_i + rs2D_i;
            end
            default: aluResult = rs1D_i + rs2D_i;
        endcase
    end
    
    // pass through data to next stage
    always @(posedge clk ) begin 
        if(~resetn) begin
            regWriteEnE_o   <= 1'b0;
            resultSrcE_o    <= 2'b00;
            aluResultE_o    <= 32'h0;
            pcPlus4E_o      <= 32'h0;
            extendedImmE_o  <= 32'h0;
            rdIdxE_o        <= 5'b0;      
            dMemTypeE_o     <= 3'b0;   
            instrIllegalE_o <= 1'b0;

        end 
        else begin
            regWriteEnE_o   <= regWriteEnD_i;
            resultSrcE_o    <= resultSrcD_i;
            aluResultE_o    <= aluResult;
            pcPlus4E_o      <= pcPlus4D_i;
            extendedImmE_o  <= extendedImmD_i;
            rdIdxE_o        <= rdIdxD_i;      
            dMemTypeE_o     <= dMemTypeD_i;   
            instrIllegalE_o <= instrIllegalD_i;
        end
        
    end
    
endmodule
`endif
