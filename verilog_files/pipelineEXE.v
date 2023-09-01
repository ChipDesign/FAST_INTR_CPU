`ifndef __PIPELINEEXE__
`define __PIPELINEEXE__
/*
file: 5 stage pipeline EXE stage, do calculation according to different ALU_OP type
author: fujie
time: 2023年 5月 5日 星期五 14时48分40秒 CST
*/
`include "definitions.vh"
`include "alu.v"//TODO pc_e_o<=flush?redirection_d_o?pc_plus4_d_i
module pipelineEXE (
    input wire clk,
    input wire resetn, // no reset need in EXE stage

    /* signals passed from ID stage*/
    // EXE stage signals
    input wire [20:0] alu_op_d_i,          // ALU Operation
    input wire [31:0] rs1_d_i,            // ALU operand 1
    input wire [31:0] rs2_d_i,            // ALU operand 2
    input wire [31:0] rs2_reg_d_i,
    input wire [31:0] extended_imm_d_i,  
    input wire [31:0] pc_plus4_d_i,
    input wire        taken_d_i, // sbp(static branch predictor) taken decision
    input wire [31:0] prediction_pc_d_i, // sbp prediction pc 
    input wire        jalr_d_i,       // instruction is jalr
    input wire        btype_d_i,
    input wire        mret_d_i,
    input wire [31:0] epc_source_d_i,
    input wire [31:0] epc_source_d_i_w,
    // TODO: Hazard must add some flush logic when EXE find ID is wrong
    input             flush_e_i,
    input wire        trap_flush_t_i,
    // MEM stage signals
    input wire [ 3:0] dmem_type_d_i,      // load/store types
    // WB stage signals 
    input wire        reg_write_en_d_i,         
    input wire [ 4:0] rd_idx_d_i,          
    input wire [ 4:0] result_src_d_i,   
    input wire        instr_illegal_d_i,  // instruction illegal
    input wire        d_init_d_o,
    input wire        d_advance_d_o,
    input wire [ 1:0] mul_state_d_o,
    //csr signals
    input wire [31:0] CSR_data_d_i,
    //input wire        CSR_wen_d_i,
    

    input wire        st_e_i,

    /* signals passed to IF stage */
    output wire        redirection_e_o,        // sbp wrong, alu revise pc to correct pc 
    output wire [31:0] redirection_pc_e_o, // new pc for IF
    /* signals passed to MEM stage */
    // MEM stage signals
    output reg [31:0] alu_result_e_o,   // alu calculation result
    output wire [31:0] alu_calculation_e_o,                                               
    output wire [ 3:0] dmem_type_e_o,      // load/store types
    output reg         mret_e_o,
    // WB stage signals 
    output reg [31:0] extended_imm_e_o, // extended imm, for 'lui' instruction                                 ,
    output reg [31:0] pc_plus4_e_o,     // rd=pc+4, for `jal` instruction                                       
    output reg        reg_write_en_e_o,  // RF write enable                                                      
    output reg [ 4:0] rd_idx_e_o,          
    output reg [ 4:0] result_src_e_o,   // select signal to choose one of the four inputs
    output wire [31:0] rs2_e_o,
    output reg        instr_illegal_e_o, // instruction illegal
    output wire       real_taken_e_o,  
    output wire [31:0]      bypass_e_o,
    //csr signals
    output reg [31:0]  CSR_data_e_o,
   // output wire        CSR_wen_e_o
    output reg [31:0]   epc_source_e_o
);


// =========================================================================
// ============================ internal variables =========================
// =========================================================================
    wire [31:0] alu_calculation;     // alu calculation result
    wire 	    alu_taken;        // alu branch decision for b-type instruction
    //wire        is_branch;
    reg redirection_r;
    reg [31:0] redirection_pc_r;
    reg epc_source_sel;
// =========================================================================
// ============================ implementation =============================
// =========================================================================

    assign alu_calculation_e_o = alu_calculation;    
    assign bypass_e_o = {32{result_src_d_i[0]}} & alu_calculation |
                        {32{result_src_d_i[1]}} & extended_imm_d_i|
                        {32{result_src_d_i[3]}} & pc_plus4_d_i;
    assign real_taken_e_o=alu_taken;
    assign rs2_e_o=rs2_reg_d_i;
    assign dmem_type_e_o=dmem_type_d_i;
    // pass through data to next stage
    always @(posedge clk ) begin 
        if(~resetn || flush_e_i||trap_flush_t_i) begin
            alu_result_e_o    <= 32'h0;
            extended_imm_e_o  <= 32'h0;
            pc_plus4_e_o      <= 32'h0;
            reg_write_en_e_o  <= 1'b0;
            rd_idx_e_o        <= 5'h0;
            result_src_e_o    <= 5'b00000;
            instr_illegal_e_o <= 1'h0;
            CSR_data_e_o      <= 32'b0;
            mret_e_o          <= 1'b0;
            epc_source_e_o    <= 32'h80000000;
        end
        else if(st_e_i)
        begin
            alu_result_e_o    <= alu_result_e_o ;   
            extended_imm_e_o  <= extended_imm_e_o ;
            pc_plus4_e_o      <= pc_plus4_e_o;
            reg_write_en_e_o  <= reg_write_en_e_o;
            rd_idx_e_o        <= rd_idx_e_o;      
            result_src_e_o    <= result_src_e_o;
            instr_illegal_e_o <= instr_illegal_e_o;
            CSR_data_e_o      <= CSR_data_e_o ;
            mret_e_o          <= mret_e_o;
            epc_source_e_o    <= epc_source_e_o;
        end
        else begin
            alu_result_e_o    <= alu_calculation;  
            extended_imm_e_o  <= extended_imm_d_i;
            pc_plus4_e_o      <= pc_plus4_d_i;
            reg_write_en_e_o  <= reg_write_en_d_i;
            rd_idx_e_o        <= rd_idx_d_i;      
            result_src_e_o    <= result_src_d_i;
            instr_illegal_e_o <= instr_illegal_d_i;
            CSR_data_e_o      <= CSR_data_d_i; 
            mret_e_o          <= mret_d_i;
            epc_source_e_o    <= epc_source_sel? epc_source_d_i:epc_source_d_i_w;
        end
    end

    always@(posedge clk)
    begin
        epc_source_sel <= (~btype_d_i) & (~real_taken_e_o^taken_d_i);
    end

    always@(posedge clk)
    begin
        redirection_r <= redirection_e_o;
        redirection_pc_r <= redirection_pc_e_o;
    end

    assign redirection_e_o = st_e_i? redirection_r :
                                    (btype_d_i & taken_d_i^alu_taken)|(jalr_d_i&~taken_d_i);
    assign redirection_pc_e_o =st_e_i? redirection_pc_r :  
                                ({32{~taken_d_i&alu_taken}}&prediction_pc_d_i)|
                                ({32{~taken_d_i&jalr_d_i}})&(alu_calculation&~1);
    
    
    
    // alu instance
    alu u_alu(
        //ports
        .ain          		( rs1_d_i          	),
        .bin          		( rs2_d_i         	),
        .ALUop        		( alu_op_d_i        ),
        .clk          		( clk          		),
        .mul_state          ( mul_state_d_o     ),
        .d_advance          ( d_advance_d_o     ),
        .d_init             ( d_init_d_o        ),
        .ALUout       		( alu_calculation   ),
        .branch_taken 		( alu_taken 		)
    );
    // TODO: `jalr` newPC = (pc+offset)&~1

endmodule
`endif
