`include "comp42.v"
`timescale 1ns/1ns
module long_div_tb(
);

reg a,b,c,d,cr;
reg clk;


initial begin
  a<=1'b0;
  b<=1'b0;
  c<=1'b0;
  d<=1'b0;
  cr<=1'b0;
  clk<=1'b0;
  
  $dumpfile("comp42.vcd");
  $dumpvars(0,long_div_tb);
  
  #400;
  	
  $finish();
end

always
begin 
	#5
		clk<=~clk;
end

always@(posedge clk)
begin
	a<=~a;
	if(a) begin
	b<=~b;
	end
	if(a&b) begin
	c<=~c;
	end
	if(a&b&c) begin
	d<=~d;
	end
	if(a&b&c&d) begin
	cr<=~cr;
	end
end




comp42 comp(
	.ain(a),
	.bin(b),
	.cin(c),
	.din(d),
	.ct(),
	.cr(cr),
	.sout(),
	.cout());

endmodule
