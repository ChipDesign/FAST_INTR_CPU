`ifndef __PIPELINEMEM__
`define __PIPELINEMEM__
`include "definitions.vh"
`include "sram_1p_32x816.v"
module pipelineMEM (
  input wire clk,
  input wire resetn,
  // pipeline pass through from E stage
  input wire [31:0] aluResultE,
  input wire [31:0] aluResult,
  input wire regWriteEnE,
  input wire [4:0 ] rdE,
  /* input wire [1:0] resultSrcE, */
  input wire memWriteEnE,
  input wire [3:0] memOpTypeE,
  // input data to D-memory
  input wire [31:0] memWriteDataE,
  // pipeline pass through to W stage
  output reg regWriteEnM,
  output reg [1:0] resultSrcM,
  output reg [31:0] aluResultM,
  output wire[31:0] memReadDataM, // delared as wire, becased the D-memory has 1 cycle delay when reading
  output reg [4:0] rdM
  // TODO: other signals are ignored, add them when needed
);

  // **************************** local variables ********************
  // sram signals
  wire [9:0] SramAddr; // Address to access 32x816 sram
  wire CEB, WEB;
  wire writeSRAM, readSRAM;

  
  assign writeSRAM = (memOpTypeE===`MEM_SW)|
                     (memOpTypeE===`MEM_SH)|
                     (memOpTypeE===`MEM_SB);
  assign readSRAM = (writeSRAM===0)&&(memOpTypeE !== `NO_MEM);


  
  // ******************* schematic implementation ********************
  assign SramAddr = aluResult[11:2];

  assign CEB = ~readSRAM; // read sram enable, negative enable
 
  always@(posedge clk) begin
    if(~resetn) begin 
      regWriteEnM  <= 0;
      resultSrcM   <= 0;
      aluResultM   <= 0;
    end
    else begin 
      aluResultM <= aluResultE;
      regWriteEnM <= regWriteEnE;
      rdM <= rdE;

    end
  end

  // connect to sram(sram is used as D-memory)
  // store data to D-memory
  assign WEB = memWriteEnE === 1 ? (writeSRAM === 1 ? 0 : 1) : 1;
  
  sram_1p_32x816 sramInstance(
    .CLK(clk),
    .CEB(CEB),
    .WEB(WEB),
    .A(SramAddr),
    .D(memWriteDataE),
    .Q(memReadDataM)
  );
endmodule
`endif
