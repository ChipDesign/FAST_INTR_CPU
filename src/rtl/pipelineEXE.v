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
    input wire resetn, // no reset need in EXE stage

    /* signals passed from ID stage*/
    // EXE stage signals
    input wire [17:0] alu_op_d_i,          // ALU Operation
    input wire [31:0] rs1_d_i,            // ALU operand 1
    input wire [31:0] rs2_d_i,            // ALU operand 2
    input wire [31:0] extended_imm_d_i,  
    input wire [31:0] pc_plus4_d_i,
    // TODO: signals below are uesd 
    // 1. for choosing ALU operand
    // 2. calculate jump instructions
    // input wire        rs1Sel_d_i,        // ALU operand select
    // input wire        rs2Sel_d_i,        // ALU operand select
    // input wire [31:0] pc__d_i,
    // input wire        beq_d_i,           // additional control for ALU
    // input wire        blt_d_i,           // additional control for ALU
    // TODO add input from Hazard Unit
    // MEM stage signals
    input wire [ 2:0] dmem_type_d_i,      // load/store types
    // WB stage signals 
    input wire        reg_write_en_d_i,         
    input wire [ 4:0] rd_idx_d_i,          
    input wire [ 3:0] result_src_d_i,   
    input wire        instr_illegal_d_i,  // instruction illegal

    /* signals passed to MEM stage */
    output reg [31:0] alu_result_e_o,   // alu calculation result                                               
    output reg [ 2:0] dmem_type_e_o,      // load/store types
    // WB stage signals 
    output reg [31:0] extended_imm_e_o, // extended imm, for 'lui' instruction                                 ,
    output reg [31:0] pc_plus4_e_o,     // rd=pc+4, for `jal` instruction                                       
    output reg        reg_write_en_e_o,  // RF write enable                                                      
    output reg [ 4:0] rd_idx_e_o,          
    output reg [ 3:0] result_src_e_o,   // select signal to choose one of the four inputs
    output reg        instr_illegal_e_o // instruction illegal
);


// =========================================================================
// ============================ internal variables =========================
// =========================================================================
    reg [31:0] alu_calculation;
// =========================================================================
// ============================ implementation =============================
// =========================================================================

    // calculate ALU result, this is combinational logic
    always @(*) begin 
        case(alu_op_d_i) 
            `ALUOP_ADD: begin
                alu_calculation = rs1_d_i + rs2_d_i;
            end
            default: alu_calculation = rs1_d_i - rs2_d_i;
        endcase
    end
    // TODO: `jalr` newPC = (pc+offset)&~1
    
    // pass through data to next stage
    always @(posedge clk ) begin 
        if(~resetn) begin
            reg_write_en_e_o  <= 1'b0;
            result_src_e_o    <= 4'b0000;
            alu_result_e_o    <= 32'h0;
            pc_plus4_e_o      <= 32'h0;
            extended_imm_e_o  <= 32'h0;
            rd_idx_e_o        <= 5'h0;
            dmem_type_e_o     <= 3'h0;
            instr_illegal_e_o <= 1'h0;
        end
        else begin
            reg_write_en_e_o  <= reg_write_en_d_i;
            result_src_e_o    <= result_src_d_i;
            alu_result_e_o    <= alu_calculation;
            pc_plus4_e_o      <= pc_plus4_d_i;
            extended_imm_e_o  <= extended_imm_d_i;
            rd_idx_e_o        <= rd_idx_d_i;      
            dmem_type_e_o     <= dmem_type_d_i;   
            instr_illegal_e_o <= instr_illegal_d_i;
        end
    end
    
endmodule
`endif
