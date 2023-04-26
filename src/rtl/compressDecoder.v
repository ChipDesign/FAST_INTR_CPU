/*
file: Convert RISC-V compress instruction into RISC-V 32I instruction
author: fujie 
date: 2023-04-23 11:02
*/
`ifndef __COMPRESSDECODER__
`define __COMPRESSDECODER__

`include "definitions.vh"
module compressDecoder (
    input [15:0] instr_i,       // 16 bits compressed instruction
    output reg [31:0] instr_o,  // 32 bits RV-32I instruction
    output reg is_compressed_o, // if the instruction is compressed instruction
    output reg illegal_instr_o // if instruction is compressed, define the compress instruction is illegal or not. Don't judge if the 32 bits instruction is legal.
    // TODO: add logic control to avoid unnecessary gate change to save power
);


// =========================================================================
// ============================ implementation =============================
// =========================================================================
    // assign is_compressed_o = instr_i[1:0] != 2'b11; // 32 bits instruction lsb is always `11`

    always @(*) begin 
        illegal_instr_o = 1'b0; // suppose compress instruction is legal
        instr_o= 32'h00000013; // suppose compress instruction is `nop -> addi x0, 0(x0)`
        is_compressed_o = 1'b1;
        case(instr_i[1:0]) 
            2'b00: begin // lsb=2'b00
                case(instr_i[15:13]) 
                    3'b000:begin
                        // c.addi4spn -> addi rd', x2, imm
                        // $display("C.addi4spn find");
                        instr_o = {2'b0, instr_i[10:7], instr_i[12:11], instr_i[5], 
                        instr_i[6], 2'b00, 5'h02, 3'b000, 2'b01, instr_i[4:2], {`OPCODE_OP_IMM}};
                        if (instr_i[12:5] == 8'b0)  illegal_instr_o = 1'b1;
                    end
                    3'b010:begin
                        // c.lw -> lw rd', imm(rs1')
                        // $display("C.lw find");
                        instr_o = {5'b0, instr_i[5], instr_i[12:10], instr_i[6],
                        2'b00, 2'b01, instr_i[9:7], 3'b010, 2'b01, instr_i[4:2], {`OPCODE_LOAD}};  
                    end
                    3'b110:begin
                        // c.sw -> sw rs2', imm(rs1')
                        // $display("C.sw find");
                        instr_o = {5'b0, instr_i[5], instr_i[12], 2'b01, instr_i[4:2],
                        2'b01, instr_i[9:7], 3'b010, instr_i[11:10], instr_i[6],
                        2'b00, {`OPCODE_STORE}};
                    end
                    default:
                        illegal_instr_o = 1'b1;
                endcase

            end
            2'b01: begin // lsb=2'b01 
                case(instr_i[15:13]) 
                    3'b000: begin
                        // c.addi -> addi rd, rd, nzimm
                        // c.nop
                        // $display("C.addi find");
                        instr_o = {{6 {instr_i[12]}}, instr_i[12], instr_i[6:2],
                        instr_i[11:7], 3'b0, instr_i[11:7], {`OPCODE_OP_IMM}};
                    end
                    3'b001, 3'b101: begin
                        // 001: c.jal -> jal x1, imm
                        // 101: c.j   -> jal x0, imm
                        // $display("C.jal, j find");
                        instr_o = {instr_i[12], instr_i[8], instr_i[10:9], instr_i[6],
                        instr_i[7], instr_i[2], instr_i[11], instr_i[5:3],
                        {9 {instr_i[12]}}, 4'b0, ~instr_i[15], {`OPCODE_JAL}};
                    end
                    3'b010: begin
                        // c.li -> addi rd, x0, nzimm
                        // (c.li hints are translated into an addi hint)
                        // $display("C.li find");
                        instr_o = {{6 {instr_i[12]}}, instr_i[12], instr_i[6:2], 5'b0,
                        3'b0, instr_i[11:7], {`OPCODE_OP_IMM}};
                    end
                    3'b011: begin
                        // c.lui -> lui rd, imm
                        // (c.lui hints are translated into a lui hint)
                        if (instr_i[11:7] == 5'h02) begin
                            // c.addi16sp -> addi x2, x2, nzimm
                            // $display("C.addi16sp find");
                            instr_o = {{3 {instr_i[12]}}, instr_i[4:3], instr_i[5], instr_i[2],
                            instr_i[6], 4'b0, 5'h02, 3'b000, 5'h02, {`OPCODE_OP_IMM}};
                        end
                        else begin
                            // $display("C.lui find");
                            instr_o = {{15 {instr_i[12]}}, instr_i[6:2], instr_i[11:7], {`OPCODE_LUI}};
                        end
                        
                        if ({instr_i[12], instr_i[6:2]} == 6'b0) begin
                            illegal_instr_o = 1'b1; // imm can not be zero
                        end
                    end
                    3'b100: begin
                        case(instr_i[11:10]) 
                            2'b00, 2'b01: begin
                                // 00: c.srli -> srli rd, rd, shamt
                                // 01: c.srai -> srai rd, rd, shamt
                                // (c.srli/c.srai hints are translated into a srli/srai hint)
                                // $display("C.srli, srai find");
                                instr_o = {1'b0, instr_i[10], 5'b0, instr_i[6:2], 2'b01, instr_i[9:7],
                                3'b101, 2'b01, instr_i[9:7], {`OPCODE_OP_IMM}};
                                if (instr_i[12] == 1'b1)  illegal_instr_o = 1'b1;
                            end
                            2'b10: begin
                                // c.andi -> andi rd, rd, imm
                                // $display("C.andi find");
                                instr_o = {{6 {instr_i[12]}}, instr_i[12], instr_i[6:2], 2'b01, instr_i[9:7],
                                3'b111, 2'b01, instr_i[9:7], {`OPCODE_OP_IMM}};
                            end
                            2'b11: begin
                                case({instr_i[12], instr_i[6:5]}) 
                                    3'b000: begin
                                    // c.sub -> sub rd', rd', rs2'
                                    // $display("C.sub find");
                                    instr_o = {2'b01, 5'b0, 2'b01, instr_i[4:2], 2'b01, instr_i[9:7],
                                    3'b000, 2'b01, instr_i[9:7], {`OPCODE_OP}};
                                    end
                                    3'b001: begin
                                    // c.xor -> xor rd', rd', rs2'
                                    // $display("C.xor find");
                                    instr_o = {7'b0, 2'b01, instr_i[4:2], 2'b01, instr_i[9:7], 3'b100,
                                    2'b01, instr_i[9:7], {`OPCODE_OP}};
                                    end
                                    3'b010: begin
                                    // c.or  -> or  rd', rd', rs2'
                                    // $display("C.or find");
                                    instr_o = {7'b0, 2'b01, instr_i[4:2], 2'b01, instr_i[9:7], 3'b110,
                                    2'b01, instr_i[9:7], {`OPCODE_OP}};
                                    end
                                    3'b011: begin
                                    // c.and -> and rd', rd', rs2'
                                    // $display("C.and find");
                                    instr_o = {7'b0, 2'b01, instr_i[4:2], 2'b01, instr_i[9:7], 3'b111,
                                    2'b01, instr_i[9:7], {`OPCODE_OP}};
                                    end
                                    default: illegal_instr_o = 1'b1;
                                endcase
                            end
                            default: illegal_instr_o = 1'b1;
                        endcase
                    end
                    3'b110, 3'b111: begin
                        // 0: c.beqz -> beq rs1', x0, imm
                        // 1: c.bnez -> bne rs1', x0, imm
                        // $display("C.beqz, bnez find");
                        instr_o = {{4 {instr_i[12]}}, instr_i[6:5], instr_i[2], 5'b0, 2'b01,
                        instr_i[9:7], 2'b00, instr_i[13], instr_i[11:10], instr_i[4:3],
                        instr_i[12], {`OPCODE_BRANCH}};
                    end
                    default: illegal_instr_o = 1'b1;
                endcase        
            end
            2'b10: begin // lsb=2'b11
                case(instr_i[15:13]) 
                    3'b000: begin
                        // c.slli -> slli rd, rd, shamt
                        // (c.ssli hints are translated into a slli hint)
                        // $display("C.slli find");
                        instr_o = {7'b0, instr_i[6:2], instr_i[11:7], 3'b001, instr_i[11:7], {`OPCODE_OP_IMM}};
                        if (instr_i[12] == 1'b1)  illegal_instr_o = 1'b1; // reserved for custom extensions
                    end

                    3'b010: begin
                        // c.lwsp -> lw rd, imm(x2)
                        // $display("C.lwsp find");
                        instr_o = {4'b0, instr_i[3:2], instr_i[12], instr_i[6:4], 2'b00, 5'h02,
                        3'b010, instr_i[11:7], `OPCODE_LOAD};
                        if (instr_i[11:7] == 5'b0)  illegal_instr_o = 1'b1;
                    end
                    3'b100: begin
                        if (instr_i[12] == 1'b0) begin
                            if (instr_i[6:2] != 5'b0) begin
                                // c.mv -> add rd/rs1, x0, rs2
                                // $display("C.mv find");
                                // (c.mv hints are translated into an add hint)
                                instr_o = {7'b0, instr_i[6:2], 5'b0, 3'b0, instr_i[11:7], {`OPCODE_OP}};
                            end 
                            else begin
                                // c.jr -> jalr x0, rd/rs1, 0
                                // $display("C.jalr find");
                                instr_o = {12'b0, instr_i[11:7], 3'b0, 5'b0, {`OPCODE_JALR}};
                                if (instr_i[11:7] == 5'b0) illegal_instr_o = 1'b1;
                            end
                        end 
                        else begin
                            if (instr_i[6:2] != 5'b0) begin
                                // c.add -> add rd, rd, rs2
                                // (c.add hints are translated into an add hint)
                                // $display("C.add find");
                                instr_o = {7'b0, instr_i[6:2], instr_i[11:7], 3'b0, instr_i[11:7], {`OPCODE_OP}};
                            end 
                            else begin
                                if (instr_i[11:7] == 5'b0) begin
                                    // c.ebreak -> ebreak
                                    // $display("C.ebreak find");
                                    instr_o = {32'h00_10_00_73};
                                end 
                                else begin
                                    // c.jalr -> jalr x1, rs1, 0
                                    // $display("C.jalr find");
                                    instr_o = {12'b0, instr_i[11:7], 3'b000, 5'b00001, {`OPCODE_JALR}};
                                end
                            end
                        end
                    end
                    3'b110: begin
                        // c.swsp -> sw rs2, imm(x2)
                        // $display("C.swsp find");
                        instr_o = {4'b0, instr_i[8:7], instr_i[12], instr_i[6:2], 5'h02, 3'b010,
                        instr_i[11:9], 2'b00, {`OPCODE_STORE}};
                    end
                    default: illegal_instr_o = 1'b1;
                endcase 
            end
            default:
                is_compressed_o = 1'b0;
        endcase
    end

endmodule
`endif
