`include "cgen.v"
`timescale 1ns/1ns
module cgen_tb();

reg ain,bin,cin;
wire cout;

initial begin
  ain<=1'b1;
  bin<=1'b0;
  cin<=1'b0;

  $dumpfile("cgen.vcd");
  $dumpvars(0,cgen_tb);
  #10
  ain<=1'b0;	
  $finish();
end

cgen cg(
	.ain(ain),
	.bin(bin),
	.cin(cin),
	.cout(cout));


endmodule
