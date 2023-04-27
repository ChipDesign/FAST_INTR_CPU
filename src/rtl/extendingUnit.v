/*
file: extending imm segment in instruction into 32 bits 
    | immType | Amount | Instruction opcode                      |
    | ------- | ------ | --------------------------------------- |
    | IMM_U   | 2      | OPCODE_LUI, OPCODE_AUIPC                |
    | IMM_J   | 1      | OPCODE_JAL                              |
    | IMM_I   | 15     | OPCODE_OP_IMM, OPCODE_LOAD, OPCODE_JALR |
    | IMM_B   | 6      | OPCODE_BRANCH                           |
    | IMM_S   | 3      | OPCODE_STORE                            |
    | IMM_NO  | 18     | OPCODE_RTYPE                            |

    1. IMM_U: `imm_o={instr_i[31:12], 12'h000};`
    2. IMM_J: `imm_o={{11{instr_i[31]}}, instr_i[31], instr_i[19:12], instr_i[20], instr_i[30:21], 1'b0};`
    3. IMM_I: `imm_o={{20{instr_i[31]}}, instr_i[31:20]};`
    4. IMM_B: `imm_o={{19{instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30:25], instr_i[11:8], 1'b0};`
    5. IMM_S: `imm_o={{20{instr_i[31]}}, instr_i[31:25], instr_i[11:7]};`
    6. IMM_NO: no immediate ==> `imm_o = 32'h00000000;`

author: fujie 
time: 2023年 4月27日 星期四 09时20分23秒 CST

*/
`ifndef __STATICBRANCHPREDITOR__
`define __STATICBRANCHPREDITOR__
`include "definitions.vh"
module extendingUnit(
    input wire [31:0] instr_i, // 32 bits instruction
    input wire [2:0] imm_type_i, // which immediate type
    output reg [31:0] imm_o // 32 bits extended immediate
);

// =========================================================================
// ============================ implementation =============================
// =========================================================================
    always @(*) begin 
        case(imm_type_i) 
            `IMM_U: begin
                imm_o={instr_i[31:12], 12'h000};
            end
            `IMM_J: begin
                imm_o={{11{instr_i[31]}}, instr_i[31], instr_i[19:12], instr_i[20], instr_i[30:21], 1'b0};
            end
            `IMM_I: begin
                imm_o={{20{instr_i[31]}}, instr_i[31:20]};
            end
            `IMM_B: begin
                imm_o={{19{instr_i[31]}}, instr_i[31], instr_i[7], instr_i[30:25], instr_i[11:8], 1'b0};
            end
            `IMM_S: begin
                // imm_o={instr_i[31:12], 12'h000};
                imm_o={{20{instr_i[31]}}, instr_i[31:25], instr_i[11:7]};
            end
            default: imm_o = 32'h00000000;
        endcase
    end
        
endmodule
`endif
