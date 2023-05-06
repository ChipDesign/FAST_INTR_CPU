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

module top (
    input wire clk,
    input wire resetn
);

    // =========================================================================
    // =============================== variables ===============================
    // =========================================================================
    // IF stage instance signals
    wire [31:0]	instructionF_o;
    wire [31:0]	pcPlus4F_o;
    reg         enable; // TODO: `enable` should be controled by Hazard Unit
    // ID stage instance signals
    wire [31:0]	redirectionD_o;
    wire 	takenD_o;
    wire [4:0]	aluOpD_o;
    wire [31:0]	rs1D_o;
    wire [31:0]	rs2D_o;
    wire 	rs1SelD_o;
    wire 	rs2SelD_o;
    wire 	beqD_o;
    wire 	bltD_o;
    wire [2:0]	dMemTypeD_o;
    wire [31:0]	extendedImmD_o;
    wire [31:0]	pcPlus4D_o;
    wire 	regWriteEnD_o;
    wire [4:0]	rdIdxD_o;
    wire [1:0]	resultSrcD_o;
    wire 	instrIllegalD_o;
    reg     rs1DependedH_o;
    // EXE instance
    wire [31:0]	aluResultE_o;
    wire [2:0]	dMemTypeE_o;
    wire [31:0]	extendedImmE_o;
    wire [31:0]	pcPlus4E_o;
    wire 	regWriteEnE_o;
    wire [4:0]	rdIdxE_o;
    wire [1:0]	resultSrcE_o;
    wire 	instrIllegalE_o;
    // MEM stage instance signals
    wire [31:0]	memReadDataM_o;
    wire [31:0]	aluResultM_o;
    wire [31:0]	extendedImmM_o;
    wire [31:0]	pcPlus4M_o;
    wire 	regWriteEnM_o;
    wire [4:0]	rdIdxM_o;
    wire [1:0]	resultSrcM_o;
    // WB stage instance signals
    wire 	regWriteEnW_o;
    wire [4:0]	rdIdxW_o;
    wire [31:0]	writeBackDataW_o;

    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================

    //TODO: init some inner signals, should be replaced later
    initial begin
        enable = 1'b1;
        rs1DependedH_o = 1'b0; // suppose rs1 has no data dependence
    end
    // IF stage instance
    pipelineIF u_pipelineIF(
        //ports
        .clk            		( clk            		),
        .resetn         		( resetn         		),
        .enable         		( enable         		),
        .redirectionD_i 		( redirectionD_o 		),
        .takenD_i       		( takenD_o       		),
        .instructionF_o 		( instructionF_o 		),
        .pcPlus4F_o     		( pcPlus4F_o     		)
    );

    // ID stage instance
    pipelineID u_pipelineID(
        //ports
        .clk              		( clk              		),
        .resetn           		( resetn           		),
        .enable           		( enable           		),
        .instructionF_i   		( instructionF_o   		),
        .pcPlus4F_i       		( pcPlus4F_o       		),
        .regWriteEnW_i    		( regWriteEnW_o    		),
        .rdIdxW_i          		( rdIdxW_o        		),
        .writeBackDataW_i 		( writeBackDataW_o 		),
        .rs1DependedH_i   		( rs1DependedH_o   		),
        .redirectionD_o   		( redirectionD_o   		),
        .takenD_o         		( takenD_o         		),
        .aluOpD_o         		( aluOpD_o         		),
        .rs1D_o           		( rs1D_o           		),
        .rs2D_o           		( rs2D_o           		),
        .rs1SelD_o        		( rs1SelD_o        		),
        .rs2SelD_o        		( rs2SelD_o        		),
        .beqD_o           		( beqD_o           		),
        .bltD_o           		( bltD_o           		),
        .dMemTypeD_o      		( dMemTypeD_o      		),
        .extendedImmD_o   		( extendedImmD_o   		),
        .pcPlus4D_o       		( pcPlus4D_o       		),
        .regWriteEnD_o    		( regWriteEnD_o    		),
        .rdIdxD_o         		( rdIdxD_o         		),
        .resultSrcD_o     		( resultSrcD_o     		),
        .instrIllegalD_o  		( instrIllegalD_o  		)
    );

    pipelineEXE u_pipelineEXE(
        //ports
        .clk             		( clk             		),
        .resetn          		( resetn          		),
        .aluOpD_i        		( aluOpD_o        		),
        .rs1D_i          		( rs1D_o          		),
        .rs2D_i          		( rs2D_o          		),
        .extendedImmD_i  		( extendedImmD_o  		),
        .pcPlus4D_i      		( pcPlus4D_o      		),
        .dMemTypeD_i     		( dMemTypeD_o     		),
        .regWriteEnD_i   		( regWriteEnD_o   		),
        .rdIdxD_i        		( rdIdxD_o        		),
        .resultSrcD_i    		( resultSrcD_o    		),
        .instrIllegalD_i 		( instrIllegalD_o 		),
        .aluResultE_o    		( aluResultE_o    		),
        .dMemTypeE_o     		( dMemTypeE_o     		),
        .extendedImmE_o  		( extendedImmE_o  		),
        .pcPlus4E_o      		( pcPlus4E_o      		),
        .regWriteEnE_o   		( regWriteEnE_o   		),
        .rdIdxE_o        		( rdIdxE_o        		),
        .resultSrcE_o    		( resultSrcE_o    		),
        .instrIllegalE_o 		( instrIllegalE_o 		)
    );

    // MEM stage instance
    pipelineMEM u_pipelineMEM(
        //ports
        .clk             		( clk             		),
        .resetn          		( resetn          		),
        .aluResultE_i    		( aluResultE_o    		),
        .dMemTypeE_i     		( dMemTypeE_o     		),
        .extendedImmE_i  		( extendedImmE_o  		),
        .pcPlus4E_i      		( pcPlus4E_o      		),
        .regWriteEnE_i   		( regWriteEnE_o   		),
        .rdIdxE_i        		( rdIdxE_o        		),
        .resultSrcE_i    		( resultSrcE_o    		),
        .instrIllegalE_i 		( instrIllegalE_o 		),
        .memReadDataM_o  		( memReadDataM_o  		),
        .aluResultM_o    		( aluResultM_o    		),
        .extendedImmM_o  		( extendedImmM_o  		),
        .pcPlus4M_o      		( pcPlus4M_o      		),
        .regWriteEnM_o   		( regWriteEnM_o   		),
        .rdIdxM_o        		( rdIdxM_o        		),
        .resultSrcM_o    		( resultSrcM_o    		)
    );

    // WB stage instance
    pipelineWB u_pipelineWB(
        //ports
        .clk              		( clk              		),
        .resetn           		( resetn           		),
        .aluResultM_i     		( aluResultM_o     		),
        .memReadDataM_i   		( memReadDataM_o   		),
        .extendedImmM_i   		( extendedImmM_o   		),
        .pcPlus4M_i       		( pcPlus4M_o       		),
        .regWriteEnM_i    		( regWriteEnM_o    		),
        .rdIdxM_i          		( rdIdxM_o        		),
        .resultSrcM_i     		( resultSrcM_o     		),
        .regWriteEnW_o    		( regWriteEnW_o    		),
        .rdIdxW_o          		( rdIdxW_o         		),
        .writeBackDataW_o 		( writeBackDataW_o 		)
    );

endmodule
`endif
