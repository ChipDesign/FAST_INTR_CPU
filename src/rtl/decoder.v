`ifndef __DECODER__
`define __DECODER__
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

`include "definitions.vh"
module decoder(
    input wire [31:0] instruction_i, // instruction from IF stage
    // ========= alu related signals =========
    output reg [4:0] aluOperation_o,
    output reg rs1Sel_o, // alu operand a selection, 0 for rd1, 1 for pc
    output reg rs2Sel_o, // alu operand b selection, 0 for rd2, 1 for imm
    // ========= immediate types =========
    output reg [2:0] immType_o,

    // addtional signals for branch control 
    output reg beq_o,  // used by `beq`
    output reg blt_o,  // used by `blt`, `bge`
    // ========= branch signals used by extending unit and pass to ALU =========
    output reg branchBType_o, // to show the instruction is BType instruction
    output reg branchJAL_o,
    output reg branchJALR_o,
    // ========= load store signals =========
    output reg [2:0] dMemType_o, // data memory type
    // =========  =========
    // output reg regWriteEnD,
    output reg [1:0] wbSrc_o, // write back select
    output reg wbEn_o,  // write back enable
    // ========= illegal instruction =========
    output reg instrIllegal_o
);

// =========================================================================
// ============================ signals defination =============================
// =========================================================================
    wire [6:0] opcode;
    wire [2:0] funct3;
    wire funct7;
     
// =========================================================================
// ============================ implementation =============================
// =========================================================================
    assign opcode = instruction_i[6:0];
    assign funct3 = instruction_i[14:12];
    assign funct7 = instruction_i[30];

    always @(*) begin 
        // suppose branch instruction is not asserted by default
        aluOperation_o = `ALUOP_ERROR; // suppose alu opcode = error by default
        rs1Sel_o = `RD1SEL_RF;
        rs2Sel_o = `RD2SEL_IMM;
        immType_o = `IMM_NO;   // suppose instruction immType_o is IMM_NO by default.
        beq_o = 1'b0; // suppose branch instruction is not asserted by default
        blt_o = 1'b0;
        branchBType_o = 1'b0;  
        branchJAL_o = 1'b0;
        branchJALR_o = 1'b0;
        instrIllegal_o = 1'b0; // suppose instruction is legal by default.
        wbSrc_o = `WBSRC_ALU;  // suppose write back source is from ALU 
        wbEn_o = 1'b1; // suppose write back is enabled
        case(opcode) 
            `OPCODE_LOAD  : begin
                immType_o = `IMM_I;
                aluOperation_o = `ALUOP_ADD;
                wbSrc_o = `WBSRC_MEM;
                wbEn_o = 1'b1;
                case(funct3) 
                    3'b000: begin
                        dMemType_o = `DMEM_LB;
                    end
                    3'b001: begin
                        dMemType_o = `DMEM_LH;
                    end
                    3'b010: begin
                        dMemType_o = `DMEM_LW;
                    end
                    3'b100: begin
                        dMemType_o = `DMEM_LBU;
                    end
                    3'b101: begin
                        dMemType_o = `DMEM_LHU;
                    end
                    default: instrIllegal_o = 1'b1;
                endcase
            end
            `OPCODE_OP_IMM: begin
                immType_o = `IMM_I;
                wbSrc_o = `WBSRC_ALU;
                wbEn_o = 1'b1;
                case(funct3) 
                    3'b000: begin
                        aluOperation_o = `ALUOP_ADD; // addi
                    end
                    3'b001: begin
                        aluOperation_o = `ALUOP_SLL; // slli
                    end
                    3'b010: begin
                        aluOperation_o = `ALUOP_SLT; // slti
                    end
                    3'b011: begin
                        aluOperation_o = `ALUOP_SLTU; // sluti
                    end
                    3'b100: begin
                        aluOperation_o = `ALUOP_XOR; // xori
                    end
                    3'b101: begin
                        case(funct7) 
                            0: aluOperation_o = `ALUOP_SRL; // srli
                            default: aluOperation_o = `ALUOP_SRA; // srai
                        endcase
                    end
                    3'b110: begin
                        aluOperation_o = `ALUOP_OR; // ori
                    end
                    3'b111: begin
                        aluOperation_o = `ALUOP_AND; // andi
                    end
                    default: instrIllegal_o = 1'b1;
                endcase
            end
            `OPCODE_AUIPC : begin
                immType_o = `IMM_U;
                aluOperation_o = `ALUOP_ADD;
                rs1Sel_o = `RD1SEL_PC;
                wbSrc_o = `WBSRC_ALU;
                wbEn_o = 1'b1;
            end
            `OPCODE_STORE : begin
                immType_o = `IMM_S;
                aluOperation_o = `ALUOP_ADD;
                wbEn_o = 1'b0;
                case(funct3) 
                    3'b000: begin
                        dMemType_o = `DMEM_SB;
                    end
                    3'b001: begin
                        dMemType_o = `DMEM_SH;
                    end
                    3'b010: begin
                        dMemType_o = `DMEM_SW;
                    end
                    default: instrIllegal_o = 1'b1;
                endcase

            end
            `OPCODE_RTYPE : begin
                immType_o = `IMM_NO; // rType instructions don't have imm
                rs2Sel_o = `RD2SEL_RF;
                wbSrc_o = `WBSRC_ALU;
                wbEn_o = 1'b1;
                if(instruction_i[25]) begin // R type instruction
                    case(funct3) 
                        3'b000: begin
                            case(funct7) 
                                0: aluOperation_o = `ALUOP_ADD; // add
                                default: aluOperation_o = `ALUOP_SUB; // sub
                            endcase
                        end
                        3'b001: begin
                            aluOperation_o = `ALUOP_SLL; // sll
                        end
                        3'b010: begin
                            aluOperation_o = `ALUOP_SLT; // slt
                        end
                        3'b011: begin
                            aluOperation_o = `ALUOP_SLTU; // sltu
                        end
                        3'b100: begin
                            aluOperation_o = `ALUOP_XOR; // xor
                        end
                        3'b101: begin
                            case(funct7) 
                                0: aluOperation_o = `ALUOP_SRL; // srl
                                default: aluOperation_o = `ALUOP_SRA; // sra
                            endcase
                        end
                        3'b110: begin
                            aluOperation_o = `ALUOP_OR; // or
                        end
                        3'b111: begin
                            aluOperation_o = `ALUOP_AND; // and
                        end
                        default: instrIllegal_o = 1'b1;
                    endcase    
                end
                else begin // RISC-V 32M instruction
                    case(funct3) 
                        3'b000: begin
                            aluOperation_o = `ALUOP_MUL; // mul
                        end
                        3'b001: begin
                            aluOperation_o = `ALUOP_MULH; // mulh
                        end
                        3'b010: begin
                            aluOperation_o = `ALUOP_MULHSU; // mulhsu
                        end
                        3'b011: begin
                            aluOperation_o = `ALUOP_MULHU; // mulhu
                        end
                        3'b100: begin
                            aluOperation_o = `ALUOP_DIV; // div
                        end
                        3'b101: begin
                            aluOperation_o = `ALUOP_DIVU; // divu
                        end
                        3'b110: begin
                            aluOperation_o = `ALUOP_REM; // rem
                        end
                        3'b111: begin
                            aluOperation_o = `ALUOP_REMU; // remu
                        end
                        default:  instrIllegal_o = 1'b1;
                    endcase
                end
            end
            `OPCODE_LUI   : begin
                immType_o = `IMM_U;
                aluOperation_o = `ALUOP_ADD;
                wbSrc_o = `WBSRC_IMM;
                wbEn_o = 1'b1;
            end
            `OPCODE_BRANCH: begin
                immType_o = `IMM_B;
                branchBType_o = 1'b1;
                rs1Sel_o = `RD1SEL_PC;
                wbEn_o = 1'b0;
                case(funct3) 
                    3'b000: begin
                        aluOperation_o = `ALUOP_SUB; // beq
                        beq_o = 1'b1;
                    end
                    3'b001: begin
                        aluOperation_o = `ALUOP_SUB; // bne
                    end
                    3'b100: begin
                        aluOperation_o = `ALUOP_SLT; // blt_o
                        blt_o = 1'b1;
                    end
                    3'b101: begin
                        aluOperation_o = `ALUOP_SLT; // bge
                    end
                    3'b110: begin
                        aluOperation_o = `ALUOP_SLTU; // blt_ou
                        blt_o = 1'b1;
                    end
                    3'b111: begin
                        aluOperation_o = `ALUOP_SLTU; // bgeu
                    end
                    default: instrIllegal_o = 1'b1;
                endcase
            end
            `OPCODE_JALR  : begin
                immType_o = `IMM_I;
                branchJALR_o = 1'b1;
                aluOperation_o = `ALUOP_ADD;
                wbSrc_o = `WBSRC_IMM;
                wbEn_o = 1'b1;
            end
            `OPCODE_JAL   : begin
                immType_o = `IMM_J;
                branchJAL_o = 1'b1;
                aluOperation_o = `ALUOP_ADD;
                rs1Sel_o = `RD1SEL_PC;
                wbSrc_o = `WBSRC_IMM;
                wbEn_o = 1'b1;
            end
            default: instrIllegal_o = 1'b1;
        endcase
    end
    
endmodule
`endif
