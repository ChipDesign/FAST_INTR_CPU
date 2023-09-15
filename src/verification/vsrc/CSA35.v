`ifndef __CSA35__
`define __CSA35__
`include "full_adder.v"

module CSA35(ain,bin,cin,sout,cout);

input[34:0] ain,bin,cin;
output[34:0] sout,cout;

full_adder fa0(
	.ain(ain[0]),
	.bin(bin[0]),
	.cin(cin[0]),
	.sout(sout[0]),
	.cout(cout[0]));
full_adder fa1(
	.ain(ain[1]),
	.bin(bin[1]),
	.cin(cin[1]),
	.sout(sout[1]),
	.cout(cout[1]));
full_adder fa2(
	.ain(ain[2]),
	.bin(bin[2]),
	.cin(cin[2]),
	.sout(sout[2]),
	.cout(cout[2]));
full_adder fa3(
	.ain(ain[3]),
	.bin(bin[3]),
	.cin(cin[3]),
	.sout(sout[3]),
	.cout(cout[3]));
full_adder fa4(
	.ain(ain[4]),
	.bin(bin[4]),
	.cin(cin[4]),
	.sout(sout[4]),
	.cout(cout[4]));
full_adder fa5(
	.ain(ain[5]),
	.bin(bin[5]),
	.cin(cin[5]),
	.sout(sout[5]),
	.cout(cout[5]));
full_adder fa6(
	.ain(ain[6]),
	.bin(bin[6]),
	.cin(cin[6]),
	.sout(sout[6]),
	.cout(cout[6]));
full_adder fa7(
	.ain(ain[7]),
	.bin(bin[7]),
	.cin(cin[7]),
	.sout(sout[7]),
	.cout(cout[7]));
full_adder fa8(
	.ain(ain[8]),
	.bin(bin[8]),
	.cin(cin[8]),
	.sout(sout[8]),
	.cout(cout[8]));
full_adder fa9(
	.ain(ain[9]),
	.bin(bin[9]),
	.cin(cin[9]),
	.sout(sout[9]),
	.cout(cout[9]));
full_adder fa10(
	.ain(ain[10]),
	.bin(bin[10]),
	.cin(cin[10]),
	.sout(sout[10]),
	.cout(cout[10]));
full_adder fa11(
	.ain(ain[11]),
	.bin(bin[11]),
	.cin(cin[11]),
	.sout(sout[11]),
	.cout(cout[11]));
full_adder fa12(
	.ain(ain[12]),
	.bin(bin[12]),
	.cin(cin[12]),
	.sout(sout[12]),
	.cout(cout[12]));
full_adder fa13(
	.ain(ain[13]),
	.bin(bin[13]),
	.cin(cin[13]),
	.sout(sout[13]),
	.cout(cout[13]));
full_adder fa14(
	.ain(ain[14]),
	.bin(bin[14]),
	.cin(cin[14]),
	.sout(sout[14]),
	.cout(cout[14]));
full_adder fa15(
	.ain(ain[15]),
	.bin(bin[15]),
	.cin(cin[15]),
	.sout(sout[15]),
	.cout(cout[15]));
full_adder fa16(
	.ain(ain[16]),
	.bin(bin[16]),
	.cin(cin[16]),
	.sout(sout[16]),
	.cout(cout[16]));
full_adder fa17(
	.ain(ain[17]),
	.bin(bin[17]),
	.cin(cin[17]),
	.sout(sout[17]),
	.cout(cout[17]));
full_adder fa18(
	.ain(ain[18]),
	.bin(bin[18]),
	.cin(cin[18]),
	.sout(sout[18]),
	.cout(cout[18]));
full_adder fa19(
	.ain(ain[19]),
	.bin(bin[19]),
	.cin(cin[19]),
	.sout(sout[19]),
	.cout(cout[19]));
full_adder fa20(
	.ain(ain[20]),
	.bin(bin[20]),
	.cin(cin[20]),
	.sout(sout[20]),
	.cout(cout[20]));
full_adder fa21(
	.ain(ain[21]),
	.bin(bin[21]),
	.cin(cin[21]),
	.sout(sout[21]),
	.cout(cout[21]));
full_adder fa22(
	.ain(ain[22]),
	.bin(bin[22]),
	.cin(cin[22]),
	.sout(sout[22]),
	.cout(cout[22]));
full_adder fa23(
	.ain(ain[23]),
	.bin(bin[23]),
	.cin(cin[23]),
	.sout(sout[23]),
	.cout(cout[23]));
full_adder fa24(
	.ain(ain[24]),
	.bin(bin[24]),
	.cin(cin[24]),
	.sout(sout[24]),
	.cout(cout[24]));
full_adder fa25(
	.ain(ain[25]),
	.bin(bin[25]),
	.cin(cin[25]),
	.sout(sout[25]),
	.cout(cout[25]));
full_adder fa26(
	.ain(ain[26]),
	.bin(bin[26]),
	.cin(cin[26]),
	.sout(sout[26]),
	.cout(cout[26]));
full_adder fa27(
	.ain(ain[27]),
	.bin(bin[27]),
	.cin(cin[27]),
	.sout(sout[27]),
	.cout(cout[27]));
full_adder fa28(
	.ain(ain[28]),
	.bin(bin[28]),
	.cin(cin[28]),
	.sout(sout[28]),
	.cout(cout[28]));
full_adder fa29(
	.ain(ain[29]),
	.bin(bin[29]),
	.cin(cin[29]),
	.sout(sout[29]),
	.cout(cout[29]));
full_adder fa30(
	.ain(ain[30]),
	.bin(bin[30]),
	.cin(cin[30]),
	.sout(sout[30]),
	.cout(cout[30]));
full_adder fa31(
	.ain(ain[31]),
	.bin(bin[31]),
	.cin(cin[31]),
	.sout(sout[31]),
	.cout(cout[31]));
full_adder fa32(
	.ain(ain[32]),
	.bin(bin[32]),
	.cin(cin[32]),
	.sout(sout[32]),
	.cout(cout[32]));
full_adder fa33(
	.ain(ain[33]),
	.bin(bin[33]),
	.cin(cin[33]),
	.sout(sout[33]),
	.cout(cout[33]));
full_adder fa34(
	.ain(ain[34]),
	.bin(bin[34]),
	.cin(cin[34]),
	.sout(sout[34]),
	.cout(cout[34]));
endmodule
`endif
