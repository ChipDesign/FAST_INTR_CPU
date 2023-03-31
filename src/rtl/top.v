`ifndef __TOP__
`define __TOP__
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

  // signals in IF stage
  wire [31:0] instructionF;
  // signals in ID stage
  wire regWriteEnW;
  wire [4:0] rdW;
  wire [31:0] writeBackDataW;
  wire [4:0] aluOperationD;
  wire [31:0] rs1D, rs2D;
  wire regWriteEnD;
  wire [4:0] rdD;
  // signals in EXE stage
  wire [31:0] aluResultE, aluResult;
  wire [4:0] rdE;
  wire regWriteEnE;
  // signals in MEM stage 
  wire memWriteEnE;
  wire [3:0] memOpTypeE;
  wire [31:0] memWriteDataE;
  wire regWriteEnM;
  wire [1:0] resultSrcM;
  wire [31:0] aluResultM;
  wire [31:0] memReadDataM;
  wire [4:0] rdM;

  // signals in WB  stage 

  


  
  //**********************************************************
  //         Implementations  
  //**********************************************************
  // ===== IF stage =====
  pipelineIF pipelineIFInstance(
    .clk(clk),
    .resetn(resetn),
    .instructionF(instructionF)
  );

  // ===== ID stage =====
  pipelineID pipelineIDInstance(
    .clk(clk),
    .resetn(resetn),
    .instructionD(instructionF),
    .regWriteEnW(regWriteEnW),
    .rdW(rdW),
    .writeBackDataW(writeBackDataW),
    .aluOperationD(aluOperationD),
    .rs1D(rs1D),
    .rs2D(rs2D),
    .regWriteEnD(regWriteEnD),
    .rdD(rdD)
  );

  // ===== EXE stage =====
  pipelineEXE pipelineEXEInstance(
  .clk(clk),
  .resetn(resetn),
  .rs1D(rs1D),
  .rs2D(rs2D),
  .aluOperationD(aluOperationD),
  .regWriteEnD(regWriteEnD),
  .rdD(rdD),
  .aluResultE(aluResultE),
  .regWriteEnE(regWriteEnE),
  .rdE(rdE),
  .aluResult(aluResult)
); 
  // ===== MEM stage =====
  pipelineMEM pipelineMEMInstance(
  .clk(clk),
  .resetn(resetn),
  .aluResultE(aluResultE),
  .aluResult(aluResult),
  .regWriteEnE(regWriteEnE),
  .rdE(rdE),
  .memWriteEnE(memWriteEnE),
  .memOpTypeE(memOpTypeE),
  .memWriteDataE(memWriteDataE),
  .regWriteEnM(regWriteEnM),
  .resultSrcM(resultSrcM),
  .aluResultM(aluResultM),
  .memReadDataM(memReadDataM),
  .rdM(rdM)
  );
  assign memWriteEnE = 0;
  assign memOpTypeE  = `MEM_SW; 
  assign memWriteDataE = 32'b0;
  //TODO: pass these signals from ID->EXE->MEM

  // ===== WB stage =====
  pipelineWB pipelineWBInstance(
    .clk(clk),
    .resetn(resetn),
    .regWriteEnM(regWriteEnM),
    .resultSrcM(resultSrcM),
    .aluResultM(aluResultM),
    .memReadDataM(memReadDataM),
    .rdM(rdM),
    .regWriteEnW(regWriteEnW),
    .rdW(rdW),
    .writeBackDataW(writeBackDataW)
  );
  
endmodule
`endif
