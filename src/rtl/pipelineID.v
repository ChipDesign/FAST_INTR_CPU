`ifndef __PIPELINEID__
`define __PIPELINEID__
/*
* file: ID stage in 5 stage pipeline 
    1. get input from IF stage 
    2. decode the instruction, generate control signals for other components
    3. pass output to EXE stage
main components: 
    1. decoder: decode the instruction 
    2. extending unit: extend imm into 32 bits
    3. static branch predictor: do the static prediction for jump and branch instructions 
    4. compressDecoder: extend the 16 bits compress instruction into 32 bits instruction
author: fujie
time: 2023年 4月28日 星期五 15时52分49秒 CST
*/
`include "definitions.vh"
`include "decoder.v"
`include "staticBranchPredictor.v"
`include "compressDecoder.v"
`include "extendingUnit.v"

module pipelineID(
    input wire clk,
    input wire resetn, // reset signal for ID stage, used for pipeline flush
    input wire enable, // enable signal for ID stage, used for pipeline stall
    // 1. signals passed from IF stage
    input wire [31:0] instructionF_i, // instruction passed from IF stage
    input wire [31:0] pcPlus4F_i,      
    // 2. signals passed from WB stage
    input wire        regWriteEnW_i, // write back to RF enable
    input wire [ 4:0] rdIdxW_i,   // RF write register index
    input wire [31:0] writeBackDataW_i, // data write to RF in ID 
    // 3. signals passed from Hazard Unit
    input wire        rs1DependedH_i, // used by `jalr`
    
    /* redirection info passed back to IF stage */
    output reg [31:0] redirectionD_o,
    output reg        takenD_o,
    /* signals passed to EXE stage */
    // EXE stage signals
    output reg [ 4:0] aluOpD_o,         // ALU Operation
    output reg [31:0] rs1D_o,           // ALU operand 1
    output reg [31:0] rs2D_o,           // ALU operand 2
    output reg        rs1SelD_o,        // ALU operand select
    output reg        rs2SelD_o,        // ALU operand select
    output reg        beqD_o,           // additional control for ALU
    output reg        bltD_o,           // additional control for ALU
    // MEM stage signals
    output reg [ 2:0] dMemTypeD_o,      // load/store types
    // WB stage signals
    output reg [31:0] extendedImmD_o,  
    output reg [31:0] pcPlus4D_o,      
    output reg        regWriteEnD_o,         
    output reg [ 4:0] rdIdxD_o,          
    output reg [ 1:0] resultSrcD_o,   
    output reg        instrIllegalD_o   // instruction illegal

);
// =========================================================================
// =============================   variables   =============================
// =========================================================================
    wire [4:0] rs1Index, rs2Index, rdIndex;
    wire       instrIllegal;
    // decoder instance signals
    wire [4:0]	aluOperation_o;
    wire 	    rs1Sel_o;
    wire 	    rs2Sel_o;
    wire [2:0]	immType_o;
    wire 	    beq_o;
    wire 	    blt_o;
    wire 	    branchBType_o;
    wire 	    branchJAL_o;
    wire 	    branchJALR_o;
    wire [2:0]	dMemType_o;
    wire [1:0]	wbSrc_o;
    wire 	    wbEn_o;
    wire 	    decoderInstrIllegal;
    // compress decoder instance signals 
    wire [31:0]	instr_o;
    wire 	    is_compressed_o;
    wire 	    compressInstrIllegal;
    wire [31:0] instruction32Bits;
    // extending unit instance signals
    wire [31:0]	imm_o;
    // register file  instance signals
    wire [31:0]	rs1_data_o;
    wire [31:0]	rs2_data_o;
    // static branch predictor instance signals
    wire [31:0]	redirectionPC;
    wire 	taken;

// =========================================================================
// ============================ implementation =============================
// =========================================================================

    // index for rd, rs1, rs2
    assign rdIndex  = instruction32Bits[11: 7];
    assign rs1Index = instruction32Bits[19:15];
    assign rs2Index = instruction32Bits[24:20];
    assign instrIllegal = decoderInstrIllegal | compressInstrIllegal;
    assign instruction32Bits = (is_compressed_o==1'b1) ? instr_o : instructionF_i;

    // ID stage pipeline register output
    always @(posedge clk ) begin 
        if(~resetn) begin
            regWriteEnD_o   <= 1'b0; 
            resultSrcD_o    <= 2'b0;  
            pcPlus4D_o      <= 32'h0;    
            extendedImmD_o  <= 32'h0;
            rdIdxD_o        <= 5'b0;         
            aluOpD_o        <= `ALUOP_ADD;      
            rs1D_o          <= 32'h0;        
            rs2D_o          <= 32'h0;        
            redirectionD_o  <= 32'h0;
            takenD_o        <= 1'b0;
            rs1SelD_o       <= 1'b0;
            rs2SelD_o       <= 1'b0;
            beqD_o          <= 1'b0;        
            bltD_o          <= 1'b0;        
            dMemTypeD_o     <= 3'b0;   
            instrIllegalD_o <= 1'b0;
        end
        else if(enable) begin
            regWriteEnD_o   <= wbEn_o; 
            resultSrcD_o    <= wbSrc_o;  
            pcPlus4D_o      <= pcPlus4F_i;    
            extendedImmD_o  <= imm_o;
            rdIdxD_o        <= rdIndex; 
            aluOpD_o        <= aluOperation_o;      
            rs1D_o          <= rs1_data_o;        
            rs2D_o          <= rs2_data_o;        
            redirectionD_o  <= redirectionPC;
            takenD_o        <= taken;
            rs1SelD_o       <= rs1Sel_o;
            rs2SelD_o       <= rs2Sel_o;
            beqD_o          <= beq_o;        
            bltD_o          <= blt_o;        
            dMemTypeD_o     <= dMemType_o;   
            instrIllegalD_o <= instrIllegal;
        end
    end


    // decode instance
    decoder u_decoder(
        //ports
        .instruction_i  		( instruction32Bits  	),
        .aluOperation_o 		( aluOperation_o 		),
        .rs1Sel_o       		( rs1Sel_o       		),
        .rs2Sel_o       		( rs2Sel_o       		),
        .immType_o      		( immType_o      		),
        .beq_o            		( beq_o            		),
        .blt_o          		( blt_o          		),
        .branchBType_o  		( branchBType_o  		),
        .branchJAL_o    		( branchJAL_o    		),
        .branchJALR_o   		( branchJALR_o   		),
        .dMemType_o     		( dMemType_o     		),
        .wbSrc_o        		( wbSrc_o        		),
        .wbEn_o         		( wbEn_o         		),
        .instrIllegal_o 		( decoderInstrIllegal 	)
    );

    // compress decode instance
    compressDecoder u_compressDecoder(
        //ports
        .instr_i         		( instructionF_i[15:0]	),
        .instr_o         		( instr_o         		),
        .is_compressed_o 		( is_compressed_o 		),
        .illegal_instr_o 		( compressInstrIllegal	)
    );


    // extending unit instance
    extendingUnit u_extendingUnit(
        //ports
        .instr_i    		( instruction32Bits ),
        .immType_i  		( immType_o 		),
        .imm_o      		( imm_o      		)
    );

    // register file instance
    regfile #(
        .REG_DATA_WIDTH     		( 32 		),
        .REGFILE_ADDR_WIDTH 		( 5  		),
        .REGFILE_DEPTH      		( 32 		))
    u_regfile(
        //ports
        .clk_i        		( clk        		),
        .resetn_i     		( resetn     		),
        .rs1_data_o   		( rs1_data_o   		),
        .rs2_data_o   		( rs2_data_o   		),
        .rs1_addr_i   		( rs1Index          ),
        .rs2_addr_i   		( rs2Index          ),
        .rd_addr_i    		( rdIdxW_i  	    ),
        .rd_wr_data_i 		( writeBackDataW_i 	),
        .rd_wr_en_i   		( regWriteEnW_i   	)
    );

    // static branch predictor instance
    staticBranchPredictor u_staticBranchPredictor(
        //ports
        .branchBType   		( branchBType_o   		),
        .branchJAL     		( branchJAL_o     		),
        .branchJALR    		( branchJALR_o    		),
        .rs1           		( rs1_data_o      		),
        .offset        		( imm_o         		),
        .pc            		( pcPlus4F_i      		),
        .rs1Depended   		( rs1DependedH_i   		),
        .redirectionPC 		( redirectionPC 		),
        .taken         		( taken         		)
    );

endmodule
`endif
