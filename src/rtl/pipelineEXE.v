`ifndef __PIPELINEEXE__
`define __PIPELINEEXE__
`include "definitions.vh"
module pipelineEXE (
  input wire clk,
  input wire resetn,
  input wire [31:0] rs1D,
  input wire [31:0] rs2D,
  input wire [4:0 ] aluOperationD,
  input wire regWriteEnD,
  input wire [4:0 ] rdD,
  
  output reg [31:0] aluResultE,
  output reg regWriteEnE,
  output reg [4:0 ] rdE,
  output wire[31:0] aluResult
);

assign aluResult = rs1D + rs2D;

always@(posedge clk) begin 
  if(~resetn) begin 
    aluResultE <= 0;
    regWriteEnE <=0;
    rdE <=0;
  end
  else begin 
    regWriteEnE <= regWriteEnD;
    rdE <= rdD;
    if(aluOperationD === `ALU_ADD) begin
      aluResultE <= aluResult;
    end
  end

end

endmodule
`endif
