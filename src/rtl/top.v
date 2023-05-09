`ifndef __TOP__
`define __TOP__
/*
file: MCU Core top, five stage pipeline MCU core
author: fujie
time: 2023年 5月 6日 星期六 16时03分58秒 CST
*/
`include "definitions.vh"
`include "pipelineIF.v"
`include "pipelineID.v"
`include "pipelineEXE.v"
`include "pipelineMEM.v"
`include "pipelineWB.v"
`include "regfile.v"

module top (
    input wire clk,
    input wire resetn
);

    // =========================================================================
    // =============================== variables ===============================
    // =========================================================================
    // IF stage instance signals
    wire [31:0]	instruction_f_o;
    wire [31:0]	pc_plus4_f_o;
    wire [31:0] pc_f_o;
    reg         enable; // TODO: `enable` should be controled by Hazard Unit
    // ID stage instance signals
    wire [31:0]	redirection_d_o;
    wire 	taken_d_o;
    wire [17:0]	alu_op_d_o;
    wire [31:0]	rs1_d_o;
    wire [31:0]	rs2_d_o;
    wire 	rs1_sel_d_o;
    wire 	rs2_sel_d_o;
    wire 	beq_d_o;
    wire 	blt_d_o;
    wire [ 2:0]	dmem_type_d_o;
    wire [31:0]	extended_imm_d_o;
    wire [31:0]	pc_plus4_d_o;
    wire 	reg_write_en_d_o;
    wire [ 4:0]	rd_idx_d_o;
    wire [ 3:0]	resultSrc_d_o;
    wire 	instrIllegal_d_o;
    reg     rs1_depended_h_o;
    // EXE instance
    wire [31:0]	aluResult_e_o;
    wire [ 2:0]	dMemType_e_o;
    wire [31:0]	extendedImm_e_o;
    wire [31:0]	pcPlus4_e_o;
    wire 	regWriteEn_e_o;
    wire [ 4:0]	rdIdx_e_o;
    wire [ 3:0]	resultSrc_e_o;
    wire 	instrIllegal_e_o;
    // MEM stage instance signals
    wire [31:0]	mem_read_data_m_o;
    wire [31:0]	alu_result_m_o;
    wire [31:0]	extended_imm_m_o;
    wire [31:0]	pc_plus4_m_o;
    wire 	reg_write_en_m_o;
    wire [ 4:0]	rd_idx_m_o;
    wire [ 3:0]	result_src_m_o;
    // WB stage instance signals
    wire 	reg_write_en_w_o;
    wire [ 4:0]	rd_idx_w_o;
    wire [31:0]	write_back_data_w_o;

    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================

    //TODO: init some inner signals, should be replaced later
    initial begin
        enable = 1'b1;
        rs1_depended_h_o = 1'b0; // suppose rs1 has no data dependence
    end
    // IF stage instance
    pipelineIF u_pipelineIF(
        //ports
        .clk            		( clk            		),
        .resetn         		( resetn         		),
        .enable         		( enable         		),
        .redirection_d_i 		( redirection_d_o 		),
        .taken_d_i       		( taken_d_o       		),
        .instruction_f_o 		( instruction_f_o 		),
        .pc_plus4_f_o     		( pc_plus4_f_o     		),
        .pc_f_o                 ( pc_f_o)
    );

    // ID stage instance
    pipelineID u_pipelineID(
        //ports
        .clk              		( clk              		),
        .resetn           		( resetn           		),
        .enable           		( enable           		),
        .instruction_f_i   		( instruction_f_o  		),
        .pc_plus4_f_i      		( pc_plus4_f_o     		),
        .pc_f_i                 ( pc_f_o                ),
        .reg_write_en_w_i  		( reg_write_en_w_o    	),
        .rd_idx_w_i        		( rd_idx_w_o        		),
        .write_back_data_w_i 	( write_back_data_w_o 	),
        .rs1_depended_h_i   	( rs1_depended_h_o   	),
        .redirection_d_o   		( redirection_d_o   	),
        .taken_d_o         		( taken_d_o         	),
        .alu_op_d_o         	( alu_op_d_o         	),
        .rs1_d_o           		( rs1_d_o           	),
        .rs2_d_o           		( rs2_d_o           	),
        // .rs1_sel_d_o        	( rs1_sel_d_o        	),
        // .rs2_sel_d_o        	( rs2_sel_d_o        	),
        .beq_d_o           		( beq_d_o           	),
        .blt_d_o           		( blt_d_o           	),
        .dmem_type_d_o      	( dmem_type_d_o      	),
        .extended_imm_d_o   	( extended_imm_d_o   	),
        .pc_plus4_d_o       	( pc_plus4_d_o       	),
        .reg_write_en_d_o    	( reg_write_en_d_o    	),
        .rd_idx_d_o         	( rd_idx_d_o         	),
        .result_src_d_o     	( resultSrc_d_o     	),
        .instr_illegal_d_o  	( instrIllegal_d_o  	)
    );

    pipelineEXE u_pipelineEXE(
        //ports
        .clk             		( clk             		),
        .resetn           		( resetn           		),
        .alu_op_d_i        		( alu_op_d_o        	),
        .rs1_d_i          		( rs1_d_o          		),
        .rs2_d_i          		( rs2_d_o          		),
        .extended_imm_d_i  		( extended_imm_d_o  	),
        .pc_plus4_d_i      		( pc_plus4_d_o      	),
        .dmem_type_d_i     		( dmem_type_d_o     	),
        .reg_write_en_d_i   	( reg_write_en_d_o   	),
        .rd_idx_d_i        		( rd_idx_d_o        	),
        .result_src_d_i    		( resultSrc_d_o    		),
        .instr_illegal_d_i 		( instrIllegal_d_o 		),
        .alu_result_e_o    		( aluResult_e_o    		),
        .dmem_type_e_o     		( dMemType_e_o     		),
        .extended_imm_e_o  		( extendedImm_e_o  		),
        .pc_plus4_e_o      		( pcPlus4_e_o      		),
        .reg_write_en_e_o   	( regWriteEn_e_o   		),
        .rd_idx_e_o        		( rdIdx_e_o        		),
        .result_src_e_o    		( resultSrc_e_o    		),
        .instr_illegal_e_o 		( instrIllegal_e_o 		)
    );

    // MEM stage instance
    pipelineMEM u_pipelineMEM(
        //ports
        .clk             		( clk             		),
        .resetn           		( resetn           		),
        .alu_result_e_i    		( aluResult_e_o    		),
        .dmem_type_e_i     		( dMemType_e_o     		),
        .extended_imm_e_i  		( extendedImm_e_o  		),
        .pc_plus4_e_i      		( pcPlus4_e_o      		),
        .reg_write_en_e_i   	( regWriteEn_e_o   		),
        .rd_idx_e_i        		( rdIdx_e_o        		),
        .result_src_e_i    		( resultSrc_e_o    		),
        .instr_illegal_e_i 		( instrIllegal_e_o 		),
        .mem_read_data_m_o  	( mem_read_data_m_o  	),
        .alu_result_m_o    		( alu_result_m_o    	),
        .extended_imm_m_o  		( extended_imm_m_o  	),
        .pc_plus4_m_o      		( pc_plus4_m_o      	),
        .reg_write_en_m_o   	( reg_write_en_m_o   	),
        .rd_idx_m_o        		( rd_idx_m_o        	),
        .result_src_m_o    		( result_src_m_o    	)
    );

    // WB stage instance
    pipelineWB u_pipelineWB(
        //ports
        .alu_result_m_i     	( alu_result_m_o     	),
        .mem_read_data_m_i  	( mem_read_data_m_o   	),
        .extended_imm_m_i   	( extended_imm_m_o   	),
        .pc_plus4_m_i       	( pc_plus4_m_o       	),
        .reg_write_en_m_i   	( reg_write_en_m_o    	),
        .rd_idx_m_i          	( rd_idx_m_o        	),
        .result_src_m_i     	( result_src_m_o     	),
        .reg_write_en_w_o    	( reg_write_en_w_o    	),
        .rd_idx_w_o          	( rd_idx_w_o         	),
        .write_back_data_w_o 	( write_back_data_w_o 	)
    );

endmodule
`endif
