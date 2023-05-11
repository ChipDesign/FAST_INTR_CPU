`include "alu.v"
`timescale 1ns/1ns
module alu_tb();

reg [31:0] ain;
reg [31:0] bin;
reg clk;
reg[1:0] state,type;
reg[4:0] op;
reg rstn;
wire ss,su,uu;
wire[4:0] op_next;
initial begin
  
  clk<=1'b0;

  $dumpfile("alu.vcd");
  $dumpvars(0,alu_tb);
  #5 rstn<=1'b0;
  #50 rstn<=1'b1;
  #1000
  	
  $finish();
end

always begin
  #10
  clk<=~clk;
end

always@(posedge clk)
begin 
  if(~rstn)
  begin
  	ain<=32'habcd4c63;
  	bin<=32'h0f3b6622;
  	op<=5'b0;
  end
  else
  begin
    if(~(op==5'd9))
    begin
    	op<=op_next;
    end
  end
  
end

assign op_next=op+5'b1;

alu ALU0(
	.clk(clk),
	.rstn(rstn),
	.ain(ain),
	.bin(bin),
	.ALUout(),
	.ALUop(op));


endmodule
