`ifndef __PIPELINEEXE__
`define __PIPELINEEXE__
/*
file: 5 stage pipeline EXE stage, do calculation according to different ALU_OP type
author: fujie
time: 2023年 5月 5日 星期五 14时48分40秒 CST
*/
`include "definitions.vh"
`include "alu.v"
module pipelineEXE (
    input wire clk,
    input wire resetn, // no reset need in EXE stage

    /* signals passed from ID stage*/
    // EXE stage signals
    input wire [20:0] alu_op_d_i,          // ALU Operation
    input wire [31:0] rs1_d_i,            // ALU operand 1
    input wire [31:0] rs2_d_i,            // ALU operand 2
    input wire [31:0] extended_imm_d_i,  
    input wire [31:0] pc_plus4_d_i,
    input wire        taken_d_i, // sbp(static branch predictor) taken decision
    input wire [31:0] prediction_pc_d_i, // sbp prediction pc 
    input wire        jalr_d_i,       // instruction is jalr

    // TODO: Hazard must add some flush logic when EXE find ID is wrong
    // MEM stage signals
    input wire [ 2:0] dmem_type_d_i,      // load/store types
    // WB stage signals 
    input wire        reg_write_en_d_i,         
    input wire [ 4:0] rd_idx_d_i,          
    input wire [ 3:0] result_src_d_i,   
    input wire        instr_illegal_d_i,  // instruction illegal

    /* signals passed to IF stage */
    output reg        redirection_e_o,        // sbp wrong, alu revise pc to correct pc 
    output reg [31:0] redirection_pc_e_o, // new pc for IF
    /* signals passed to MEM stage */
    // MEM stage signals
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
    wire [31:0] alu_calculation;     // alu calculation result
    wire 	    alu_taken;        // alu branch decision for b-type instruction
    wire        is_branch;
// =========================================================================
// ============================ implementation =============================
// =========================================================================

    assign is_branch = alu_op_d_i[20];
    // pass through data to next stage
    always @(posedge clk ) begin 
        if(~resetn) begin
            alu_result_e_o    <= 32'h0;
            dmem_type_e_o     <= 3'b0;
            extended_imm_e_o  <= 32'h0;
            pc_plus4_e_o      <= 32'h0;
            reg_write_en_e_o  <= 1'b0;
            rd_idx_e_o        <= 5'h0;
            result_src_e_o    <= 4'b0000;
            instr_illegal_e_o <= 1'h0;
        end
        else begin
            alu_result_e_o    <= alu_calculation;
            dmem_type_e_o     <= dmem_type_d_i;   
            extended_imm_e_o  <= extended_imm_d_i;
            pc_plus4_e_o      <= pc_plus4_d_i;
            reg_write_en_e_o  <= reg_write_en_d_i;
            rd_idx_e_o        <= rd_idx_d_i;      
            result_src_e_o    <= result_src_d_i;
            instr_illegal_e_o <= instr_illegal_d_i;
        end
    end

    // deal with b-type instruction, check if sbp is correct
    // deal with jalr instruction, calculate correct pc  
    always @(posedge clk ) begin 
        if(~resetn) begin
            redirection_e_o   <= 1'b0;
            redirection_pc_e_o<= 32'h0;
        end
        else begin
            // b-type instruction prediction wrong in ID
            if(taken_d_i != alu_taken && is_branch) begin
                if(alu_taken==1'b1) begin // sbp no taken, alu taken, choose rediction pc
                    redirection_e_o    <= 1'b1;    
                    redirection_pc_e_o <= prediction_pc_d_i;
            end
                else begin // sbp taken, alu not taken, choose pc+4 for next pc
                    redirection_e_o    <= 1'b1;    
                    redirection_pc_e_o <= pc_plus4_d_i;
                end
            end
            else if(jalr_d_i && ~taken_d_i) begin
            // jalr instruction
            // if it's jarl instruction, and ID says it's not taken 
            // it means sbp can not calculate it's target pc, 
            // so alu have to calculate target pc
                redirection_e_o    <= 1'b1;    
                redirection_pc_e_o <= alu_calculation & ~1; // new pc for jalr instruction
            end
            else begin
                redirection_e_o    <= 1'b0;    
                redirection_pc_e_o <= 32'h0;
            end
        end
    end
    
    // alu instance
    alu u_alu(
        //ports
        .ain          		( rs1_d_i          	),
        .bin          		( rs2_d_i          	),
        .ALUop        		( alu_op_d_i        ),
        .clk          		( clk          		),
        .resetn       		( resetn       		),
        .ALUout       		( alu_calculation   ),
        .branch_taken 		( alu_taken 		)
    );
    // TODO: `jalr` newPC = (pc+offset)&~1

endmodule
`endif
