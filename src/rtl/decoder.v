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
    output wire [20:0] alu_op_o,
    output reg rs1_sel_o, // alu operand a selection, 0 for rd1, 1 for pc
    output reg rs2_sel_o, // alu operand b selection, 0 for rd2, 1 for imm
    // ========= immediate types =========
    output reg [2:0] imm_type_o,

    // ========= branch signals used by extending unit and pass to ALU =========
    output reg branchBType_o, // to show the instruction is BType instruction
    output reg branchJAL_o,
    output reg branchJALR_o,
    // ========= load store signals =========
    output reg [3:0] dmem_type_o, // data memory type
    // =========  =========
    // output reg regWriteEnD,
    output reg [3:0] wb_src_o, // write back select
    output reg wb_en_o,  // write back enable
    // ========= illegal instruction =========
    output reg instr_illegal_o
);

// =========================================================================
// ============================ signals defination =============================
// =========================================================================
    wire [6:0] opcode;
    wire [2:0] funct3;
    wire funct7;
    wire beq_wire, blt_wire, branch_type_wire;
    reg [17:0] alu_calculation;
    // addtional signals for branch control 
    reg beq;  // used by `beq`
    reg blt;  // used by `blt`, `bge`
     
// =========================================================================
// ============================ implementation =============================
// =========================================================================
    assign opcode   = instruction_i[6:0];
    assign funct3   = instruction_i[14:12];
    assign funct7   = instruction_i[30];
    assign beq_wire = beq;
    assign blt_wire = blt;
    assign branch_type_wire = branchBType_o;
    assign alu_op_o = {branch_type_wire, blt_wire, beq_wire, alu_calculation};

    always @(*) begin 
        // suppose branch instruction is not asserted by default
        alu_calculation = `ALUOP_ADD; // suppose alu opcode = error by default
        rs1_sel_o = `RS1SEL_RF;
        rs2_sel_o = `RS2SEL_IMM;
        imm_type_o = `IMM_NO;   // suppose instruction imm_type_o is IMM_NO by default.
        beq = 1'b0; // suppose branch instruction is not asserted by default
        blt = 1'b0;
        branchBType_o = 1'b0;  
        branchJAL_o = 1'b0;
        branchJALR_o = 1'b0;
        instr_illegal_o = 1'b0; // suppose instruction is legal by default.
        wb_src_o = `WBSRC_ALU;  // suppose write back source is from ALU 
        wb_en_o = 1'b0; // suppose write back is not enable 
        case(opcode) 
            `OPCODE_LOAD  : begin
                imm_type_o = `IMM_I;
                alu_calculation = `ALUOP_ADD;
                wb_src_o = `WBSRC_MEM;
                wb_en_o = 1'b1;
                case(funct3) 
                    3'b000: begin
                        dmem_type_o = `DMEM_LB;
                    end
                    3'b001: begin
                        dmem_type_o = `DMEM_LH;
                    end
                    3'b010: begin
                        dmem_type_o = `DMEM_LW;
                    end
                    3'b100: begin
                        dmem_type_o = `DMEM_LBU;
                    end
                    3'b101: begin
                        dmem_type_o = `DMEM_LHU;
                    end
                    default: instr_illegal_o = 1'b1;
                endcase
            end
            `OPCODE_OP_IMM: begin
                imm_type_o = `IMM_I;
                wb_src_o = `WBSRC_ALU;
                wb_en_o = instruction_i != 32'h00000013;
                case(funct3) 
                    3'b000: begin
                        alu_calculation = `ALUOP_ADD; // addi
                    end
                    3'b001: begin
                        alu_calculation = `ALUOP_SLL; // slli
                    end
                    3'b010: begin
                        alu_calculation = `ALUOP_SLT; // slti
                    end
                    3'b011: begin
                        alu_calculation = `ALUOP_SLTU; // sluti
                    end
                    3'b100: begin
                        alu_calculation = `ALUOP_XOR; // xori
                    end
                    3'b101: begin
                        case(funct7) 
                            0: alu_calculation = `ALUOP_SRL; // srli
                            default: alu_calculation = `ALUOP_SRA; // srai
                        endcase
                    end
                    3'b110: begin
                        alu_calculation = `ALUOP_OR; // ori
                    end
                    3'b111: begin
                        alu_calculation = `ALUOP_AND; // andi
                    end
                    default: instr_illegal_o = 1'b1;
                endcase
            end
            `OPCODE_AUIPC : begin
                imm_type_o = `IMM_U;
                alu_calculation = `ALUOP_ADD;
                rs1_sel_o = `RS1SEL_PC;
                wb_src_o = `WBSRC_ALU;
                wb_en_o = 1'b1;
            end
            `OPCODE_STORE : begin
                imm_type_o = `IMM_S;
                alu_calculation = `ALUOP_ADD;
                wb_en_o = 1'b0;
                case(funct3) 
                    3'b000: begin
                        dmem_type_o = `DMEM_SB;
                    end
                    3'b001: begin
                        dmem_type_o = `DMEM_SH;
                    end
                    3'b010: begin
                        dmem_type_o = `DMEM_SW;
                    end
                    default: instr_illegal_o = 1'b1;
                endcase

            end
            `OPCODE_RTYPE : begin
                imm_type_o = `IMM_NO; // rType instructions don't have imm
                rs2_sel_o = `RS2SEL_RF;
                wb_src_o = `WBSRC_ALU;
                wb_en_o = 1'b1;
                if(~instruction_i[25]) begin // R type instruction
                    case(funct3) 
                        3'b000: begin
                            case(funct7) 
                                0: alu_calculation = `ALUOP_ADD; // add
                                default: alu_calculation = `ALUOP_SUB; // sub
                            endcase
                        end
                        3'b001: begin
                            alu_calculation = `ALUOP_SLL; // sll
                        end
                        3'b010: begin
                            alu_calculation = `ALUOP_SLT; // slt
                        end
                        3'b011: begin
                            alu_calculation = `ALUOP_SLTU; // sltu
                        end
                        3'b100: begin
                            alu_calculation = `ALUOP_XOR; // xor
                        end
                        3'b101: begin
                            case(funct7) 
                                0: alu_calculation = `ALUOP_SRL; // srl
                                default: alu_calculation = `ALUOP_SRA; // sra
                            endcase
                        end
                        3'b110: begin
                            alu_calculation = `ALUOP_OR; // or
                        end
                        3'b111: begin
                            alu_calculation = `ALUOP_AND; // and
                        end
                        default: instr_illegal_o = 1'b1;
                    endcase    
                end
                else begin // RISC-V 32M instruction
                    case(funct3) 
                        3'b000: begin
                            alu_calculation = `ALUOP_MUL; // mul
                        end
                        3'b001: begin
                            alu_calculation = `ALUOP_MULH; // mulh
                        end
                        3'b010: begin
                            alu_calculation = `ALUOP_MULHSU; // mulhsu
                        end
                        3'b011: begin
                            alu_calculation = `ALUOP_MULHU; // mulhu
                        end
                        3'b100: begin
                            alu_calculation = `ALUOP_DIV; // div
                        end
                        3'b101: begin
                            alu_calculation = `ALUOP_DIVU; // divu
                        end
                        3'b110: begin
                            alu_calculation = `ALUOP_REM; // rem
                        end
                        3'b111: begin
                            alu_calculation = `ALUOP_REMU; // remu
                        end
                        default:  instr_illegal_o = 1'b1;
                    endcase
                end
            end
            `OPCODE_LUI   : begin
                imm_type_o = `IMM_U;
                alu_calculation = `ALUOP_ADD;
                wb_src_o = `WBSRC_IMM;
                wb_en_o = 1'b1;
            end
            `OPCODE_BRANCH: begin
                imm_type_o = `IMM_B;
                branchBType_o = 1'b1;
                rs2_sel_o = `RS2SEL_RF;
                wb_en_o = 1'b0;
                case(funct3) 
                    3'b000: begin
                        alu_calculation = `ALUOP_SUB; // beq
                        beq = 1'b1;
                    end
                    3'b001: begin
                        alu_calculation = `ALUOP_SUB; // bne
                    end
                    3'b100: begin
                        alu_calculation = `ALUOP_SLT; // blt
                        blt = 1'b1;
                    end
                    3'b101: begin
                        alu_calculation = `ALUOP_SLT; // bge
                    end
                    3'b110: begin
                        alu_calculation = `ALUOP_SLTU; // bltu
                        blt = 1'b1;
                    end
                    3'b111: begin
                        alu_calculation = `ALUOP_SLTU; // bgeu
                    end
                    default: instr_illegal_o = 1'b1;
                endcase
            end
            `OPCODE_JALR  : begin
                imm_type_o = `IMM_I;
                branchJALR_o = 1'b1;
                alu_calculation = `ALUOP_ADD;
                wb_src_o = `WBSRC_PC;
                wb_en_o = 1'b1;
            end
            `OPCODE_JAL   : begin
                imm_type_o = `IMM_J;
                branchJAL_o = 1'b1;
                alu_calculation = `ALUOP_ADD;
                wb_src_o = `WBSRC_PC;
                wb_en_o = 1'b1;
            end
            default: instr_illegal_o = 1'b1;
        endcase
    end
    
endmodule
`endif
