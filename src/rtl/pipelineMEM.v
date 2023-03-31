`include "definitions.vh"
`include "sram_1p_32x816.v"
module pipelineMEM (
  input wire clk,
  input wire resetn,
  // pipeline pass through from E stage
  input wire regWriteEnM,
  input wire [1:0] resultSrcM,
  input wire memWriteEnM,
  input wire [3:0] memOpTypeM,

  // input data to D-memory
  input wire [31:0] aluResultM,
  input wire [31:0] memWriteDataM,

  // pipeline pass through to W stage
  output reg regWriteEnW,
  output reg [1:0] resultSrcW,
  output reg [31:0] aluResultW,
  output wire[31:0] memReadDataW // delared as wire, becased the D-memory has 1 cycle delay when reading
  // TODO: other signals are ignored, add them when needed
);

  // **************************** local variables ********************
  wire [31:0] DMemAddr; // Data memory address is 4 byte aligned
  // sram signals
  wire [9:0] SramAddr; // Address to access 32x816 sram
  wire CEB, WEB;
  wire writeSRAM, readSRAM;

  
  assign writeSRAM = (memOpTypeM===`MEM_SW)|
                     (memOpTypeM===`MEM_SH)|
                     (memOpTypeM===`MEM_SB);
  assign readSRAM = (writeSRAM===0)&&(memOpTypeM !== `NO_MEM);


  
  // ******************* schematic implementation ********************
  assign DMemAddr = {aluResultM[31:2], 2'b00};
  assign SramAddr = DMemAddr[11:2];

  assign CEB = ~readSRAM; // read sram enable, negative enable
 
  always@(posedge clk) begin
    if(resetn) begin 
      regWriteEnW  <= 0;
      resultSrcW   <= 0;
      aluResultW   <= 0;
    end
  end

  // connect to sram(sram is used as D-memory)
  // store data to D-memory
  assign WEB = memWriteEnM === 1 ? (writeSRAM === 1 ? 0 : 1) : 1;
  
  sram_1p_32x816 sramInstance(
    .CLK(clk),
    .CEB(CEB),
    .WEB(WEB),
    .A(SramAddr),
    .D(memWriteDataM),
    .Q(memReadDataW)
  );
endmodule
