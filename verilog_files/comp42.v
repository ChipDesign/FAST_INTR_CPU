`include "cgen.v"
module comp42(
ain,bin,cin,din,ct,cr,sout,cout);

input ain,bin,cin,din,cr;
output sout,cout,ct;

wire w1,w2,w3;

assign w1=ain^bin;
assign w2=cin^w1;
assign w3=cr^din;
assign sout=w2^w3;

cgen cgen0(
	.ain(ain),
	.bin(bin),
	.cin(cin),
	.cout(ct)	);
	
cgen cgen1(
	.ain(w2),
	.bin(din),
	.cin(cr),
	.cout(cout)	);


endmodule
