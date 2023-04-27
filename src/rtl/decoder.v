/*
file: Decoder in ID Stage, used to decode all 32 bits instructions, 
    generate control signals for other components

    // 32 bits Instruction OP code type 
    `define OPCODE_LOAD     7'b0000011
    `define OPCODE_OP_IMM   7'b0010011
    `define OPCODE_AUIPC    7'b0010111
    `define OPCODE_STORE    7'b0100011
    `define OPCODE_RTYPE    7'b0110011
    `define OPCODE_LUI      7'b0110111
    `define OPCODE_BRANCH   7'b1100011
    `define OPCODE_JALR     7'b1100111
    `define OPCODE_JAL      7'b1101111

author: fujie 
time: 2023年 4月27日 星期四 09时09分22秒 CST
*/

`ifndef __DECODER__
`define __DECODER__
`include "definitions.vh"
module decoder(
  input wire [31:0] instructionD, // instruction from IF stage
  // ========= alu calculation signals =========
  output reg [4:0] aluOperation,
  output reg rd1Sel, // alu operand a selection
  output reg rd2Sel, // alu operand b selection

  // ========= branch signals used by extending unit and pass to ALU =========
  output reg branchBType,
  output reg branchJAL,
  output reg branchJALR,
  // ========= load store signals =========
  // ========= immediate types =========
  output reg [2:0] immType,
  // =========  =========
  output reg regWriteEnD,
  // ========= illegal instruction =========
  output reg instrIllegal
);

    wire [6:0] opcode;
    wire [2:0] funct3;
    wire funct7;

    reg [2:0] instructionType;

     
// =========================================================================
// ============================ implementation =============================
// =========================================================================
    assign opcode = instructionD[6:0];
    assign funct3 = instructionD[14:12];
    assign funct7 = instructionD[30];


    
    // ================== immType ==================
    always @(*) begin 
        instrIllegal = 1'b0; // suppose instruction is legal by default.
        immType = `IMM_NO;   // suppose instruction immType is IMM_NO by default.
        // suppose branch instruction is not asserted by default
        branchBType = 1'b0;
        branchJAL = 1'b0;
        branchJALR = 1'b0;
        case(opcode) 
            `OPCODE_LOAD  : begin
                immType = `IMM_I;
            end
            `OPCODE_OP_IMM: begin
                immType = `IMM_I;
            end
            `OPCODE_AUIPC : begin
                immType = `IMM_U;
            end
            `OPCODE_STORE : begin
                immType = `IMM_S;
            end
            `OPCODE_RTYPE : begin
                immType = `IMM_NO;
            end
            `OPCODE_LUI   : begin
                immType = `IMM_U;
            end
            `OPCODE_BRANCH: begin
                immType = `IMM_B;
                branchBType = 1'b1;
            end
            `OPCODE_JALR  : begin
                immType = `IMM_I;
                branchJALR = 1'b1;
            end
            `OPCODE_JAL   : begin
                immType = `IMM_J;
                branchJAL = 1'b1;
            end
        
            default: instrIllegal = 1'b1;
        endcase
    end
    
endmodule
`endif
