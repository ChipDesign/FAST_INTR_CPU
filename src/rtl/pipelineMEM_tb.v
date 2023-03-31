`include "definitions.vh"
`include "pipelineMEM.v"


module pipelineMEM_tb();

reg clk;
reg resetn;
reg regWriteEnM;
reg [1:0] resultSrcM;
reg memWriteEnM;
reg [3:0] memOpTypeM;
reg [31:0] aluResultM;
reg [31:0] memWriteDataM;

wire regWriteEnW;
wire [1:0] resultSrcW;
wire [31:0] aluResultW;
wire [31:0] memReadDataW; 

// ***** set clock *****
initial begin 
  clk <= 1;
  counter<=0;
  forever begin 
    #1; clk<=~clk;
  end 
end

// begin test
integer counter;

always@(posedge clk) begin 
  if(counter==0)
    resetn=0;
  if(counter==1)
    resetn=1;
  if(counter==2)begin
    memWriteEnM <= 1;
    memOpTypeM <= `MEM_SW;
    memWriteDataM <= 32'hffffffff;
    aluResultM <= 32'h80000000;
  end
  if(counter==3)begin
    memWriteEnM <= 1;
    memOpTypeM <= `MEM_SW;
    memWriteDataM <= 32'haaaaaaaa;
    aluResultM <= 32'h80000004;
  end
  if(counter==4)begin
    memWriteEnM <= 0;
    memOpTypeM <= `NO_MEM;
  end
  if(counter==5)begin
    memWriteEnM <= 0;
    memOpTypeM <= `MEM_LW;
    aluResultM <= 32'h80000000;
  end
  if(counter==6)begin
    memWriteEnM <= 0;
    memOpTypeM <= `MEM_LW;
    aluResultM <= 32'h80000004;
  end
  if(counter==10)
    $finish();

  counter+=1;
end


pipelineMEM pipelineMEM_instance(
  .clk(clk),
  .resetn(resetn),
  .regWriteEnM(regWriteEnM),
  .resultSrcM(resultSrcM),
  .memWriteEnM(memWriteEnM),
  .memOpTypeM(memOpTypeM),
  .aluResultM(aluResultM),
  .memWriteDataM(memWriteDataM),
  .regWriteEnW(regWriteEnW),
  .resultSrcW(resultSrcW),
  .aluResultW(aluResultW),
  .memReadDataW(memReadDataW)
);

integer index;
initial begin 
  $dumpfile("pipelineMEM_tb.vcd");
  $dumpvars(0, pipelineMEM_tb);
  for(index=0;index<816;index++)begin
    $dumpvars(0, pipelineMEM_tb.pipelineMEM_instance.sramInstance.m_array[index]);
  end
  /* $dumpvars; */
end


endmodule
