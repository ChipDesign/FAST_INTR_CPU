`include "definitions.vh"
`include "pipelineMEM.v"


module pipelineMEM_tb();

reg clk;
reg resetn;
reg regWriteEnE;
reg [1:0] resultSrcE;
reg memWriteEnE;
reg [3:0] memOpTypeE;
reg [31:0] aluResultE;
reg [31:0] memWriteDataE;

wire regWriteEnM;
wire [1:0] resultSrcM;
wire [31:0] aluResultM;
wire [31:0] memReadDataM; 

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
    memWriteEnE <= 1;
    memOpTypeE <= `MEM_SW;
    memWriteDataE <= 32'hffffffff;
    aluResultE <= 32'h80000000;
  end
  if(counter==3)begin
    memWriteEnE <= 1;
    memOpTypeE <= `MEM_SW;
    memWriteDataE <= 32'haaaaaaaa;
    aluResultE <= 32'h80000004;
  end
  if(counter==4)begin
    memWriteEnE <= 0;
    memOpTypeE <= `NO_MEM;
  end
  if(counter==5)begin
    memWriteEnE <= 0;
    memOpTypeE <= `MEM_LW;
    aluResultE <= 32'h80000000;
  end
  if(counter==6)begin
    memWriteEnE <= 0;
    memOpTypeE <= `MEM_LW;
    aluResultE <= 32'h80000004;
  end
  if(counter==10)
    $finish();

  counter+=1;
end


pipelineMEM pipelineMEM_instance(
  .clk(clk),
  .resetn(resetn),
  .regWriteEnE(regWriteEnE),
  //.resultSrcE(resultSrcE),
  .memWriteEnE(memWriteEnE),
  .memOpTypeE(memOpTypeE),
  .aluResultE(aluResultE),
  .memWriteDataE(memWriteDataE),
  .regWriteEnM(regWriteEnM),
  .resultSrcM(resultSrcM),
  .aluResultM(aluResultM),
  .memReadDataM(memReadDataM)
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
