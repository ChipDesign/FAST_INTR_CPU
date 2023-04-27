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
    input wire [31:0] instructionD, // instruction from IF stage
    // ========= alu related signals =========
    output reg [4:0] aluOperation,
    output reg rd1Sel, // alu operand a selection, 0 for rd1, 1 for pc
    output reg rd2Sel, // alu operand b selection, 0 for rd2, 1 for imm
    // ========= immediate types =========
    output reg [2:0] immType,

    // addtional signals for branch control 
    output reg beq,  // used by `beq`
    output reg blt,  // used by `blt`, `bge`
    // ========= branch signals used by extending unit and pass to ALU =========
    output reg branchBType, // to show the instruction is BType instruction
    output reg branchJAL,
    output reg branchJALR,
    // ========= load store signals =========
    output reg [2:0] dMemType, // data memory type
    // =========  =========
    // output reg regWriteEnD,
    output reg [1:0] wbSrc, // write back select
    output reg wbEn,  // write back enable
    // ========= illegal instruction =========
    output reg instrIllegal
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
    assign opcode = instructionD[6:0];
    assign funct3 = instructionD[14:12];
    assign funct7 = instructionD[30];


    
    // ================== immType ==================
    always @(*) begin 
        // suppose branch instruction is not asserted by default
        aluOperation = `ALUOP_ERROR; // suppose alu opcode = error by default
        rd1Sel = `RD1SEL_RF;
        rd2Sel = `RD2SEL_IMM;
        immType = `IMM_NO;   // suppose instruction immType is IMM_NO by default.
        beq = 1'b0; // suppose branch instruction is not asserted by default
        blt = 1'b0;
        branchBType = 1'b0;  
        branchJAL = 1'b0;
        branchJALR = 1'b0;
        instrIllegal = 1'b0; // suppose instruction is legal by default.
        wbSrc = `WBSRC_ALU;  // suppose write back source is from ALU 
        wbEn = 1'b1; // suppose write back is enabled
        case(opcode) 
            `OPCODE_LOAD  : begin
                immType = `IMM_I;
                aluOperation = `ALUOP_ADD;
                wbSrc = `WBSRC_MEM;
                wbEn = 1'b1;
                case(funct3) 
                    000: begin
                        dMemType = `DMEM_LB;
                    end
                    001: begin
                        dMemType = `DMEM_LH;
                    end
                    010: begin
                        dMemType = `DMEM_LW;
                    end
                    100: begin
                        dMemType = `DMEM_LBU;
                    end
                    101: begin
                        dMemType = `DMEM_LHU;
                    end
                    default: instrIllegal = 1'b1;
                endcase
            end
            `OPCODE_OP_IMM: begin
                immType = `IMM_I;
                wbSrc = `WBSRC_ALU;
                wbEn = 1'b1;
                case(funct3) 
                    000: begin
                        aluOperation = `ALUOP_ADD; // addi
                    end
                    001: begin
                        aluOperation = `ALUOP_SLL; // slli
                    end
                    010: begin
                        aluOperation = `ALUOP_SLT; // slti
                    end
                    011: begin
                        aluOperation = `ALUOP_SLTU; // sluti
                    end
                    100: begin
                        aluOperation = `ALUOP_XOR; // xori
                    end
                    101: begin
                        case(funct7) 
                            0: aluOperation = `ALUOP_SRL; // srli
                            default: aluOperation = `ALUOP_SRA; // srai
                        endcase
                    end
                    110: begin
                        aluOperation = `ALUOP_OR; // ori
                    end
                    111: begin
                        aluOperation = `ALUOP_AND; // andi
                    end
                    default: instrIllegal = 1'b1;
                endcase
            end
            `OPCODE_AUIPC : begin
                immType = `IMM_U;
                aluOperation = `ALUOP_ADD;
                rd1Sel = `RD1SEL_PC;
                wbSrc = `WBSRC_ALU;
                wbEn = 1'b1;
            end
            `OPCODE_STORE : begin
                immType = `IMM_S;
                aluOperation = `ALUOP_ADD;
                wbEn = 1'b0;
                case(funct3) 
                    000: begin
                        dMemType = `DMEM_SB;
                    end
                    001: begin
                        dMemType = `DMEM_SH;
                    end
                    010: begin
                        dMemType = `DMEM_SW;
                    end
                    default: instrIllegal = 1'b1;
                endcase

            end
            `OPCODE_RTYPE : begin
                immType = `IMM_NO; // rType instructions don't have imm
                rd2Sel = `RD2SEL_RF;
                wbSrc = `WBSRC_ALU;
                wbEn = 1'b1;
                if(instructionD[25]) begin // R type instruction
                    case(funct3) 
                        000: begin
                            case(funct7) 
                                0: aluOperation = `ALUOP_ADD; // add
                                default: aluOperation = `ALUOP_SUB; // sub
                            endcase
                        end
                        001: begin
                            aluOperation = `ALUOP_SLL; // sll
                        end
                        010: begin
                            aluOperation = `ALUOP_SLT; // slt
                        end
                        011: begin
                            aluOperation = `ALUOP_SLTU; // sltu
                        end
                        100: begin
                            aluOperation = `ALUOP_XOR; // xor
                        end
                        101: begin
                            case(funct7) 
                                0: aluOperation = `ALUOP_SRL; // srl
                                default: aluOperation = `ALUOP_SRA; // sra
                            endcase
                        end
                        110: begin
                            aluOperation = `ALUOP_OR; // or
                        end
                        111: begin
                            aluOperation = `ALUOP_AND; // and
                        end
                        default: instrIllegal = 1'b1;
                    endcase    
                end
                else begin // RISC-V 32M instruction
                    case(funct3) 
                        000: begin
                            aluOperation = `ALUOP_MUL; // mul
                        end
                        001: begin
                            aluOperation = `ALUOP_MULH; // mulh
                        end
                        010: begin
                            aluOperation = `ALUOP_MULHSU; // mulhsu
                        end
                        011: begin
                            aluOperation = `ALUOP_MULHU; // mulhu
                        end
                        100: begin
                            aluOperation = `ALUOP_DIV; // div
                        end
                        101: begin
                            aluOperation = `ALUOP_DIVU; // divu
                        end
                        110: begin
                            aluOperation = `ALUOP_REM; // rem
                        end
                        111: begin
                            aluOperation = `ALUOP_REMU; // remu
                        end
                        default:  instrIllegal = 1'b1;
                    endcase
                end
            end
            `OPCODE_LUI   : begin
                immType = `IMM_U;
                aluOperation = `ALUOP_ADD;
                wbSrc = `WBSRC_IMM;
                wbEn = 1'b1;
            end
            `OPCODE_BRANCH: begin
                immType = `IMM_B;
                branchBType = 1'b1;
                rd1Sel = `RD1SEL_PC;
                wbEn = 1'b0;
                case(funct3) 
                    000: begin
                        aluOperation = `ALUOP_SUB;
                        beq = 1'b1;
                    end
                    001: begin
                        aluOperation = `ALUOP_SUB;
                    end
                    100: begin
                        aluOperation = `ALUOP_SLT;
                        blt = 1'b1;
                    end
                    101: begin
                        aluOperation = `ALUOP_SLT;
                    end
                    110: begin
                        aluOperation = `ALUOP_SLTU;
                        blt = 1'b1;
                    end
                    111: begin
                        aluOperation = `ALUOP_SLTU;
                    end
                    default: instrIllegal = 1'b1;
                endcase
            end
            `OPCODE_JALR  : begin
                immType = `IMM_I;
                branchJALR = 1'b1;
                aluOperation = `ALUOP_ADD;
                wbSrc = `WBSRC_IMM;
                wbEn = 1'b1;
            end
            `OPCODE_JAL   : begin
                immType = `IMM_J;
                branchJAL = 1'b1;
                aluOperation = `ALUOP_ADD;
                rd1Sel = `RD1SEL_PC;
                wbSrc = `WBSRC_IMM;
                wbEn = 1'b1;
            end
            default: instrIllegal = 1'b1;
        endcase
    end
    
endmodule
