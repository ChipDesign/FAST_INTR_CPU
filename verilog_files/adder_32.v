`include "four_bits_CLA.v"

module adder_32(ain,bin,sout,cout,xorout,orout,andout,suboradd);

input[31:0] ain,bin;
input suboradd;
output[31:0] sout,xorout,orout,andout;
output cout;


wire[31:0] binc;
wire[7:0] cins;
wire[7:0] couts;
wire[7:0] p;

assign binc={32{suboradd}}^bin;
assign cins[0]=suboradd;
assign cout=couts[7];
assign cins[1]=p[0]?cins[0]:couts[0];
assign cins[2]=p[1]?cins[1]:couts[1];
assign cins[3]=p[2]?cins[2]:couts[2];
assign cins[4]=p[3]?cins[3]:couts[3];
assign cins[5]=p[4]?cins[4]:couts[4];
assign cins[6]=p[5]?cins[5]:couts[5];
assign cins[7]=p[6]?cins[6]:couts[6];
assign cout=p[7]?cins[7]:couts[7];

four_bits_CLA cla0(
	.ain(ain[3:0]),
	.bin(binc[3:0]),
	.cin(cins[0]),
	.sout(sout[3:0]),
	.cout(couts[0]),
	.xorout(xorout[3:0]),
	.orout(orout[3:0]),
	.andout(andout[3:0]),
	.p(p[0])
	);

four_bits_CLA cla1(
	.ain(ain[7:4]),
	.bin(binc[7:4]),
	.cin(cins[1]),
	.sout(sout[7:4]),
	.cout(couts[1]),
	.xorout(xorout[7:4]),
	.orout(orout[7:4]),
	.andout(andout[7:4]),
	.p(p[1])
	);

four_bits_CLA cla2(
	.ain(ain[11:8]),
	.bin(binc[11:8]),
	.cin(cins[2]),
	.sout(sout[11:8]),
	.cout(couts[2]),
	.xorout(xorout[11:8]),
	.orout(orout[11:8]),
	.andout(andout[11:8]),
	.p(p[2])
	);

four_bits_CLA cla3(
	.ain(ain[15:12]),
	.bin(binc[15:12]),
	.cin(cins[3]),
	.sout(sout[15:12]),
	.cout(couts[3]),
	.xorout(xorout[15:12]),
	.orout(orout[15:12]),
	.andout(andout[15:12]),
	.p(p[3])
	);

four_bits_CLA cla4(
	.ain(ain[19:16]),
	.bin(binc[19:16]),
	.cin(cins[4]),
	.sout(sout[19:16]),
	.cout(couts[4]),
	.xorout(xorout[19:16]),
	.orout(orout[19:16]),
	.andout(andout[19:16]),
	.p(p[4])
	);

four_bits_CLA cla5(
	.ain(ain[23:20]),
	.bin(binc[23:20]),
	.cin(cins[5]),
	.sout(sout[23:20]),
	.cout(couts[5]),
	.xorout(xorout[23:20]),
	.orout(orout[23:20]),
	.andout(andout[23:20]),
	.p(p[5])
	);

four_bits_CLA cla6(
	.ain(ain[27:24]),
	.bin(binc[27:24]),
	.cin(cins[6]),
	.sout(sout[27:24]),
	.cout(couts[6]),
	.xorout(xorout[27:24]),
	.orout(orout[27:24]),
	.andout(andout[27:24]),
	.p(p[6])
	);

four_bits_CLA cla7(
	.ain(ain[31:28]),
	.bin(binc[31:28]),
	.cin(cins[7]),
	.sout(sout[31:28]),
	.cout(couts[7]),
	.xorout(xorout[31:28]),
	.orout(orout[31:28]),
	.andout(andout[31:28]),
	.p(p[7])
	);






endmodule
