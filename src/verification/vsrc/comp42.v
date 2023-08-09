`ifndef __COMP42__
`define __COMP42__
`include "cgen.v"
module comp42(
ain,bin,cin,din,ct,cr,sout,cout);

input ain,bin,cin,din,cr;
output sout,cout,ct;

wire w1,w2,w3;

assign w1=ain^bin;
assign w2=cin^din;
assign w3=w2^w1;
assign sout=w3^cr;

cgen cgen0(
	.ain(w1),
	.bin(ain),
	.cin(cin),
	.cout(ct)	);
	
cgen cgen1(
	.ain(w3),
	.bin(din),
	.cin(cr),
	.cout(cout)	);


endmodule
`endif
