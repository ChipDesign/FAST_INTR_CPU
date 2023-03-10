`include "lookahead.v"
`include "full_adder.v"

module four_bits_CLA(ain,bin,cin,sout,cout,xorout,orout,andout,p);

input[3:0] ain,bin;
input cin;
output[3:0] sout,xorout,orout,andout;
output cout;
output p;

wire[3:0] axorb,aorb,aandb;
wire c1,c2,c3;

assign p=(ain[0]^bin[0])&(ain[1]^bin[1])&(ain[2]^bin[2])&(ain[3]^bin[3]);


lookahead la(
	.ain(ain),
	.bin(bin),
	.cin(cin),
	.cout({cout,c3,c2,c1})
	);

full_adder fa0(
	.ain(ain[0]),
	.bin(bin[0]),
	.cin(cin),
	.sout(sout[0]),
	.cout(),
	.andout(andout[0]),
	.orout(orout[0]),
	.xorout(xorout[0])
	);
	
full_adder fa1(
	.ain(ain[1]),
	.bin(bin[1]),
	.cin(c1),
	.sout(sout[1]),
	.cout(),
	.andout(andout[1]),
	.orout(orout[1]),
	.xorout(xorout[1])
	);
	
full_adder fa2(
	.ain(ain[2]),
	.bin(bin[2]),
	.cin(c2),
	.sout(sout[2]),
	.cout(),
	.andout(andout[2]),
	.orout(orout[2]),
	.xorout(xorout[2])
	);

full_adder fa3(
	.ain(ain[3]),
	.bin(bin[3]),
	.cin(c3),
	.sout(sout[3]),
	.cout(),
	.andout(andout[3]),
	.orout(orout[3]),
	.xorout(xorout[3])
	);





endmodule
