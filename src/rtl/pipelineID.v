`ifndef __PIPELINEID__
`define __PIPELINEID__
`include "definitions.vh"
`include "decoder.v"
module pipelineID(
  input wire clk,
  input wire resetn,
  input wire [31:0] instructionD,
  input wire regWriteEnW,
  input wire [4:0] rdW,
  input wire [31:0] writeBackDataW,

  output reg [4:0] aluOperationD,
  output reg [31:0] rs1D,
  output reg [31:0] rs2D,
  output reg regWriteEnD,
  output reg [4:0] rdD
);

  reg [31:0] registerFile[31:0];
  wire [4:0] rs1_idx, rs2_idx;
  wire [4:0] aluOperation;
  wire regWriteEn;
  integer i;

  //**********************************************************
  //         Implementations  
  //**********************************************************

  assign rs1_idx = instructionD[19:15];
  assign rs2_idx = instructionD[24:20];
  /* assign registerFile[0] = 32'h00000000;  // x0 is hardwired to 0 */
  /* initial begin */
  /*   for(i=0;i<32;i++)begin */
  /*     registerFile[i]=0; // init RF when start */
  /*   end */
  /* end */


  always@(posedge clk) begin 
    if(~resetn)begin
      rs1D<=0;
      rs2D<=0;
      rdD <=0;
      /* for(i=0;i<32;i++)begin */
      /*   registerFile[i]<=0; // init RF when start */
      /* end */
    end
    else begin 
      // read from RF
      rs1D <= registerFile[rs1_idx];
      rs2D <= registerFile[rs2_idx];
      /* rdD  <= instructionD[11:7]; */
      rdD  <= instructionD[11:7];
      /* rdD  <= 5'b11111; */
      // write to RF
      if(regWriteEnW)begin
        registerFile[rdW]<=writeBackDataW;
      end
      aluOperationD <= aluOperation;
      regWriteEnD   <= regWriteEn;
    end
  end

  // initialize decoder
  decoder decoderInstance(
    .instructionD(instructionD),
    .aluOperation(aluOperation),
    .regWriteEnD(regWriteEn)
  );


  //TODO: make RF a dut
endmodule
`endif
