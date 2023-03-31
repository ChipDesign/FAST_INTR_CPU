`ifndef __PIPELINEIF__
`define __PIPELINEIF__
`include "sram_1p_32x816.v"
module pipelineIF
(
  input wire clk,
  input wire resetn,
  /* input wire [32-1:0] redirectionPC, */ // pc redirection
  output reg [32-1:0] instructionF
);

  // sram signals
  wire [9:0] SramAddr; // Address to access 32x816 sram
  wire CEB, WEB;
  wire [31:0] SramOutput;
  reg [31:0] pc_register;


  //**********************************************************
  //         Implementations  
  //**********************************************************
  always@(posedge clk)begin
    if(~resetn)begin
      instructionF <= 0;
      pc_register  <= 0;
    end
    else begin 
      instructionF <= SramOutput;
      pc_register  <= pc_register+4; // instruction pc +=4, to get next instruction
    end
  end

  assign WEB = 1; // only read from I-Memory
  assign CEB = 0;
  assign SramAddr = pc_register[11:2];

  sram_1p_32x816 sramInstance(
    .CLK(clk),
    .CEB(CEB),
    .WEB(WEB),
    .A(SramAddr),
    .D(32'h00000000), // I-Memory will not be write into, we only read from I-Memory
    .Q(SramOutput)
  );
endmodule
`endif
