`include "adder_32.v"
`timescale 1ns/1ns
module adder_32_tb(
);

reg[31:0] ain,bin;
reg cin;
reg suboradd;
wire[31:0] sout,andout,orout,xorout;

wire [31:0] nexta,nextb;
wire correct;

initial begin
  ain=32'h4cdf;
  bin=32'h136f;
  cin=1'b0;
  
  $dumpfile("adder_32.vcd");
  $dumpvars(0,adder_32_tb);
  #1000;
  $finish();
end

always
begin 
	#5
		cin=~cin;
end

assign nexta=ain+32'd3;
assign nextb=bin+32'd1;

always@(negedge cin)
begin
	ain<=nexta;
	bin<=nextb;
end

assign correct=cin?(ain-bin==sout):(ain+bin==sout);

adder_32 a32(
	.ain(ain),
	.bin(bin),
	.suboradd(cin),
	.sout(sout),
	.cout(cout),
	.andout(andout),
	.orout(orout),
	.xorout(xorout)
	);

endmodule
