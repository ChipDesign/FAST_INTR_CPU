`include "booth16.v"
`include "comp42.v"
`include "full_adder.v"
`include "half_adder.v"
module multi16(
ain,bin,ss,us,su,uu,prod,sign_out);

input ss,su,uu,us;
input[15:0] ain,bin;
output[31:0] prod;
output sign_out;

wire [16:0] adder0,adder1,adder2,adder3,adder4,adder5,adder6,adder7,adder8;
wire [7:0] neg;
wire [7:0] sign;
wire[30:0] ans1,ans2;
wire[31:0] ans;

//-------------------------------------------------------------
wire s5_0_0, s6_0_0, s7_0_0, s8_0_0, s8_0_1, s9_0_0, s10_0_0, s10_0_1, s11_0_0, s11_0_1, s12_0_0, s12_0_1, s13_0_0, s13_0_1, s14_0_0, s14_0_1, s15_0_0, s15_0_1, s16_0_0, s16_0_1, s17_0_0, s17_0_1, s17_0_2, s18_0_0, s18_0_1, s19_0_0, s19_0_1, s20_0_0, s20_0_1, s21_0_0, s21_0_1, s22_0_0, s22_0_1, s23_0_0, s23_0_1, s24_0_0, s24_0_1, s25_0_0, s26_0_0, s27_0_0, s28_0_0, s29_0_0, s30_0_0;

wire c4_0_0, c4_0_1, c5_0_0, c6_0_0, c7_0_0, c8_0_0, c8_0_1, c9_0_0, c10_0_0, c10_0_1, c11_0_0, c11_0_1, c12_0_0, c12_0_1, c12_0_2, c13_0_0, c13_0_1, c14_0_0, c14_0_1, c15_0_0, c15_0_1, c16_0_0, c16_0_1, c17_0_0, c17_0_1, c17_0_2, c18_0_0, c18_0_1, c19_0_0, c19_0_1, c20_0_0, c20_0_1, c20_0_2, c21_0_0, c21_0_1, c22_0_0, c22_0_1, c23_0_0, c23_0_1, c24_0_0, c24_0_1, c25_0_0, c26_0_0, c27_0_0, c28_0_0, c28_0_1,c29_0_0, c30_0_0;

wire s13_1_0, s14_1_0, s15_1_0, s16_1_0, s17_1_0, s18_1_0, s18_1_1, s19_1_0, s20_1_0, s21_1_0, s22_1_0, s23_1_0, s24_1_0, s25_1_0, s26_1_0, s27_1_0, s28_1_0, s29_1_0, s30_1_0;

wire c12_1_0, c13_1_0, c14_1_0, c15_1_0, c16_1_0, c17_1_0, c18_1_0, c18_1_1, c19_1_0, c20_1_0, c21_1_0, c22_1_0, c23_1_0, c24_1_0, c25_1_0, c25_1_1, c26_1_0, c27_1_0, c28_1_0, c29_1_0, c30_1_0, c30_2_0;


//-----------------------------------------------------

booth16 b0(
	.mcand(ain),
	.mlier({bin[1:0],1'b0}),
	.umcand(us|uu),
	.sign(sign[0]),
	.adder(adder0),
	.neg(neg[0]));
	
booth16 b1(
	.mcand(ain),
	.mlier(bin[3:1]),
	.umcand(us|uu),
	.sign(sign[1]),
	.adder(adder1),
	.neg(neg[1]));
	
booth16 b2(
	.mcand(ain),
	.mlier(bin[5:3]),
	.umcand(us|uu),
	.sign(sign[2]),
	.adder(adder2),
	.neg(neg[2]));
	
booth16 b3(
	.mcand(ain),
	.mlier(bin[7:5]),
	.umcand(us|uu),
	.sign(sign[3]),
	.adder(adder3),
	.neg(neg[3]));
	
booth16 b4(
	.mcand(ain),
	.mlier(bin[9:7]),
	.umcand(us|uu),
	.sign(sign[4]),
	.adder(adder4),
	.neg(neg[4]));
	
booth16 b5(
	.mcand(ain),
	.mlier(bin[11:9]),
	.umcand(us|uu),
	.sign(sign[5]),
	.adder(adder5),
	.neg(neg[5]));
	
booth16 b6(
	.mcand(ain),
	.mlier(bin[13:11]),
	.umcand(us|uu),
	.sign(sign[6]),
	.adder(adder6),
	.neg(neg[6]));
	
booth16 b7(
	.mcand(ain),
	.mlier(bin[15:13]),
	.umcand(us|uu),
	.sign(sign[7]),
	.adder(adder7),
	.neg(neg[7]));
	
assign adder8={1'b0,{16{(bin[15])&(uu|su)}}&ain};


//input size of each column from 31 to 0 is as below
//2 3 3 4 4 5 5 6 6 7 7 8 8 9 10 9 9 10 7 8 6 7 5 6 4 5 3 4 2 3 1 2
//bit0
assign ans1[0]=neg[0];
assign ans2[0]=adder0[0];
//bit1
assign ans1[1]=1'b0;
assign ans2[1]=adder0[1];
//bit2
full_adder 	fa2_0_0(.ain(adder0[2]), .bin(adder1[0]), .cin(neg[1]), .sout(ans1[2]), .cout(ans2[3])); 
assign ans2[2]=1'b0;
//bit3
half_adder 	ha3_0_0(.ain(adder0[3]), .bin(adder1[1]), .sout(ans1[3]), .cout(ans2[4])); 

//bit4
comp42 	co4_0_0(.ain(adder0[4]), .bin(adder1[2]), .cin(adder2[0]), .din(neg[2]), .cr(1'b0), .ct(c4_0_0), .sout(ans1[4]), .cout(c4_0_1));

//bit5
full_adder 	fa5_0_0(.ain(adder0[5]), .bin(adder1[3]), .cin(adder2[1]), .sout(s5_0_0), .cout(c5_0_0)); 

full_adder 	fa5_1_0(.ain(s5_0_0), .bin(c4_0_0), .cin(c4_0_1), .sout(ans1[5]), .cout(ans2[6]));
assign ans2[5]=1'b0;

//bit6
comp42 	co6_0_0(.ain(adder0[6]), .bin(adder1[4]), .cin(adder2[2]), .din(adder3[0]), .cr(1'b0), .ct(ct6_0_0), .sout(s6_0_0), .cout(c6_0_0)); 

full_adder 	fa6_1_0(.ain(neg[3]), .bin(s6_0_0), .cin(c5_0_0), .sout(ans1[6]), .cout(ans2[7]));

//bit7
comp42 	co7_0_0(.ain(adder0[7]), .bin(adder1[5]), .cin(adder2[3]), .din(adder3[1]), .cr(ct6_0_0), .ct(ct7_0_0), .sout(s7_0_0), .cout(c7_0_0));

half_adder 	ha7_1_0(.ain(c6_0_0), .bin(s7_0_0), .sout(ans1[7]), .cout(ans2[8]));

//bit8
comp42 	co8_0_0(.ain(adder0[8]), .bin(adder1[6]), .cin(adder2[4]), .din(adder3[2]), .cr(ct7_0_0), .ct(ct8_0_0), .sout(s8_0_0), .cout(c8_0_0));
half_adder 	ha8_0_1(.ain(adder4[0]), .bin(neg[4]), .sout(s8_0_1), .cout(c8_0_1));

full_adder 	fa8_1_0(.ain(s8_0_0), .bin(c7_0_0), .cin(s8_0_1), .sout(ans1[8]), .cout(ans2[9]));

//bit9
comp42 	co9_0_0(.ain(adder0[9]), .bin(adder1[7]), .cin(adder2[5]), .din(adder3[3]), .cr(ct8_0_0), .ct(ct9_0_0), .sout(s9_0_0), .cout(c9_0_0));

comp42 	co9_1_0(.ain(adder4[1]), .bin(c8_0_0), .cin(c8_0_1), .din(s9_0_0), .cr(1'b0), .ct(ct9_1_0), .sout(ans1[9]), .cout(ans2[10]));

//bit10
comp42 	co10_0_0(.ain(adder0[10]), .bin(adder1[8]), .cin(adder2[6]), .din(adder3[4]), .cr(ct9_0_0), .ct(ct10_0_0), .sout(s10_0_0), .cout(c10_0_0));
full_adder 	fa10_0_1(.ain(adder4[2]), .bin(adder5[0]), .cin(neg[5]), .sout(s10_0_1), .cout(c10_0_1));

comp42 	co10_1_0(.ain(c9_0_0), .bin(s10_0_0), .cin(s10_0_1), .din(1'b0), .cr(ct9_1_0), .ct(ct10_1_0), .sout(ans1[10]), .cout(ans2[11]));

//bit11
comp42 	co11_0_0(.ain(adder0[11]), .bin(adder1[9]), .cin(adder2[7]), .din(adder3[5]), .cr(ct10_0_0), .ct(ct11_0_0), .sout(s11_0_0), .cout(c11_0_0));
half_adder 	ha11_0_1(.ain(adder4[3]), .bin(adder5[1]), .sout(s11_0_1), .cout(c11_0_1));

comp42 	co11_1_0(.ain(s11_0_0), .bin(s11_0_1), .cin(c10_0_0), .din(c10_0_1), .cr(ct10_1_0), .ct(ct11_1_0), .sout(ans1[11]), .cout(ans2[12]));

//bit12
comp42 	co12_0_0(.ain(adder0[12]), .bin(adder1[10]), .cin(adder2[8]), .din(adder3[6]), .cr(ct11_0_0), .ct(ct12_0_0), .sout(s12_0_0), .cout(c12_0_0));
comp42 	co12_0_1(.ain(adder4[4]), .bin(adder5[2]), .cin(adder6[0]), .din(neg[6]), .cr(1'b0), .ct(c12_0_1), .sout(s12_0_1), .cout(c12_0_2));

comp42 	co12_1_0(.ain(c11_0_0), .bin(c11_0_1), .cin(s12_0_0), .din(s12_0_1), .cr(ct11_1_0), .ct(ct12_1_0), .sout(ans1[12]), .cout(c12_1_0));

//bit13
comp42 	co13_0_0(.ain(adder0[13]), .bin(adder1[11]), .cin(adder2[9]), .din(adder3[7]), .cr(ct12_0_0), .ct(ct13_0_0), .sout(s13_0_0), .cout(c13_0_0));
full_adder 	fa13_0_1(.ain(adder4[5]), .bin(adder5[3]), .cin(adder6[1]), .sout(s13_0_1), .cout(c13_0_1));

comp42 	co13_1_0(.ain(c12_0_0), .bin(c12_0_1), .cin(c12_0_2), .din(s13_0_0), .cr(ct12_1_0), .ct(ct13_1_0), .sout(s13_1_0), .cout(c13_1_0));

full_adder 	fa13_2_0(.ain(s13_0_1), .bin(c12_1_0), .cin(s13_1_0), .sout(ans1[13]), .cout(ans2[14]));
assign ans2[13]=1'b0;

//bit14
comp42 	co14_0_0(.ain(adder0[14]), .bin(adder1[12]), .cin(adder2[10]), .din(adder3[8]), .cr(ct13_0_0), .ct(ct14_0_0), .sout(s14_0_0), .cout(c14_0_0));
comp42 	co14_0_1(.ain(adder4[6]), .bin(adder5[4]), .cin(adder6[2]), .din(adder7[0]), .cr(1'b0), .ct(ct14_0_1), .sout(s14_0_1), .cout(c14_0_1));

comp42 	co14_1_0(.ain(neg[7]), .bin(s14_0_0), .cin(s14_0_1), .din(c13_0_0), .cr(ct13_1_0), .ct(ct14_1_0), .sout(s14_1_0), .cout(c14_1_0));

full_adder 	fa14_2_0(.ain(c13_0_1), .bin(c13_1_0), .cin(s14_1_0), .sout(ans1[14]), .cout(ans2[15]));

//bit15
comp42 	co15_0_0(.ain(adder0[15]), .bin(adder1[13]), .cin(adder2[11]), .din(adder3[9]), .cr(ct14_0_0), .ct(ct15_0_0), .sout(s15_0_0), .cout(c15_0_0));
comp42 	co15_0_1(.ain(adder4[7]), .bin(adder5[5]), .cin(adder6[3]), .din(adder7[1]), .cr(ct14_0_1), .ct(ct15_0_1), .sout(s15_0_1), .cout(c15_0_1));

comp42 	co15_1_0(.ain(c14_0_0), .bin(c14_0_1), .cin(s15_0_0), .din(s15_0_1), .cr(ct14_1_0), .ct(ct15_1_0), .sout(s15_1_0), .cout(c15_1_0));


half_adder 	ha15_2_0(.ain(c14_1_0), .bin(s15_1_0), .sout(ans1[15]), .cout(ans2[16]));

//bit16
comp42 	co16_0_0(.ain(adder0[16]), .bin(adder1[14]), .cin(adder2[12]), .din(adder3[10]), .cr(ct15_0_0), .ct(ct16_0_0), .sout(s16_0_0), .cout(c16_0_0));
comp42 	co16_0_1(.ain(adder4[8]), .bin(adder5[6]), .cin(adder6[4]), .din(adder7[2]), .cr(ct15_0_1), .ct(ct16_0_1), .sout(s16_0_1), .cout(c16_0_1));

comp42 	co16_1_0(.ain(adder8[0]), .bin(c15_0_0), .cin(c15_0_1), .din(s16_0_0), .cr(ct15_1_0), .ct(ct16_1_0), .sout(s16_1_0), .cout(c16_1_0));

full_adder 	fa16_2_0(.ain(s16_0_1), .bin(c15_1_0), .cin(s16_1_0), .sout(ans1[16]), .cout(ans2[17]));

//bit17
comp42 	co17_0_0(.ain(1'b1), .bin(adder1[15]), .cin(adder2[13]), .din(adder3[11]), .cr(ct16_0_0), .ct(ct17_0_0), .sout(s17_0_0), .cout(c17_0_0));
comp42 	co17_0_1(.ain(adder4[9]), .bin(adder5[7]), .cin(adder6[5]), .din(adder7[3]), .cr(ct16_0_1), .ct(ct17_0_1), .sout(s17_0_1), .cout(c17_0_1));
half_adder 	ha17_0_2(.ain(adder8[1]), .bin(~sign[0]), .sout(s17_0_2), .cout(c17_0_2)); 

comp42 	co17_1_0(.ain(c16_0_0), .bin(c16_0_1), .cin(s17_0_0), .din(s17_0_1), .cr(ct16_1_0), .ct(ct17_1_0), .sout(s17_1_0), .cout(c17_1_0));

full_adder 	fa17_2_0(.ain(s17_0_2), .bin(c16_1_0), .cin(s17_1_0), .sout(ans1[17]), .cout(ans2[18]));

//bit18
comp42 	co18_0_0(.ain(adder1[16]), .bin(adder2[14]), .cin(adder3[12]), .din(adder4[10]), .cr(ct17_0_0), .ct(ct18_0_0), .sout(s18_0_0), .cout(c18_0_0));
comp42 	co18_0_1(.ain(adder5[8]), .bin(adder6[6]), .cin(adder7[4]), .din(adder8[2]), .cr(ct17_0_1), .ct(ct18_0_1), .sout(s18_0_1), .cout(c18_0_1));

comp42 	co18_1_0(.ain(1'b1), .bin(c17_0_0), .cin(c17_0_1), .din(c17_0_2), .cr(ct17_1_0), .ct(ct18_1_0), .sout(s18_1_0), .cout(c18_1_0));
half_adder 	ha18_1_1(.ain(s18_0_0), .bin(s18_0_1), .sout(s18_1_1), .cout(c18_1_1));

full_adder 	fa18_2_0(.ain(s18_1_0), .bin(c17_1_0), .cin(s18_1_1), .sout(ans1[18]), .cout(ans2[19]));

//bit19
comp42 	co19_0_0(.ain(adder2[15]), .bin(adder3[13]), .cin(adder4[11]), .din(adder5[9]), .cr(ct18_0_0), .ct(ct19_0_0), .sout(s19_0_0), .cout(c19_0_0));
comp42 	co19_0_1(.ain(adder6[7]), .bin(adder7[5]), .cin(adder8[3]), .din(~sign[1]), .cr(ct18_0_1), .ct(ct19_0_1), .sout(s19_0_1), .cout(c19_0_1));

comp42 	co19_1_0(.ain(c18_0_0), .bin(c18_0_1), .cin(s19_0_0), .din(s19_0_1), .cr(ct18_1_0), .ct(ct19_1_0), .sout(s19_1_0), .cout(c19_1_0));

full_adder 	fa19_2_0(.ain(s19_1_0), .bin(c18_1_0), .cin(c18_1_1), .sout(ans1[19]), .cout(ans2[20]));

//bit20
comp42 	co20_0_0(.ain(adder2[16]), .bin(adder3[14]), .cin(adder4[12]), .din(adder5[10]), .cr(ct19_0_0), .ct(ct20_0_0), .sout(s20_0_0), .cout(c20_0_0));
comp42 	co20_0_1(.ain(adder6[8]), .bin(adder7[6]), .cin(adder8[4]), .din(1'b1), .cr(ct19_0_1), .ct(c20_0_1), .sout(s20_0_1), .cout(c20_0_2));

comp42 	co20_1_0(.ain(c19_0_0), .bin(c19_0_1), .cin(s20_0_0), .din(s20_0_1), .cr(ct19_1_0), .ct(ct20_1_0), .sout(s20_1_0), .cout(c20_1_0));

half_adder 	ha20_2_0(.ain(c19_1_0), .bin(s20_1_0), .sout(ans1[20]), .cout(ans2[21]));

//bit21
comp42 	co21_0_0(.ain(adder3[15]), .bin(adder4[13]), .cin(adder5[11]), .din(adder6[9]), .cr(ct20_0_0), .ct(ct21_0_0), .sout(s21_0_0), .cout(c21_0_0));
full_adder 	fa21_0_1(.ain(adder7[7]), .bin(adder8[5]), .cin(~sign[2]), .sout(s21_0_1), .cout(c21_0_1));

comp42 	co21_1_0(.ain(c20_0_0), .bin(c20_0_1), .cin(c20_0_2), .din(s21_0_0), .cr(ct20_1_0), .ct(ct21_1_0), .sout(s21_1_0), .cout(c21_1_0));

full_adder 	fa21_2_0(.ain(s21_0_1), .bin(c20_1_0), .cin(s21_1_0), .sout(ans1[21]), .cout(ans2[22]));

//bit22
comp42 	co22_0_0(.ain(adder3[16]), .bin(adder4[14]), .cin(adder5[12]), .din(adder6[10]), .cr(ct21_0_0), .ct(ct22_0_0), .sout(s22_0_0), .cout(c22_0_0));
full_adder 	fa22_0_1(.ain(adder7[8]), .bin(adder8[6]), .cin(1'b1), .sout(s22_0_1), .cout(c22_0_1));

comp42 	co22_1_0(.ain(c21_0_0), .bin(c21_0_1), .cin(s22_0_0), .din(s22_0_1), .cr(ct21_1_0), .ct(ct22_1_0), .sout(s22_1_0), .cout(c22_1_0));

half_adder 	ha22_2_0(.ain(c21_1_0), .bin(s22_1_0), .sout(ans1[22]), .cout(ans2[23]));

//bit23
comp42 	co23_0_0(.ain(adder4[15]), .bin(adder5[13]), .cin(adder6[11]), .din(adder7[9]), .cr(ct22_0_0), .ct(ct23_0_0), .sout(s23_0_0), .cout(c23_0_0));
half_adder 	ha23_0_1(.ain(adder8[7]), .bin(~sign[3]), .sout(s23_0_1), .cout(c23_0_1));

comp42 	co23_1_0(.ain(c22_0_0), .bin(c22_0_1), .cin(s23_0_0), .din(s23_0_1), .cr(ct22_1_0), .ct(ct23_1_0), .sout(s23_1_0), .cout(c23_1_0));

half_adder 	ha23_2_0(.ain(c22_1_0), .bin(s23_1_0), .sout(ans1[23]), .cout(ans2[24]));

//bit24
comp42 	co24_0_0(.ain(adder4[16]), .bin(adder5[14]), .cin(adder6[12]), .din(adder7[10]), .cr(ct23_0_0), .ct(ct24_0_0), .sout(s24_0_0), .cout(c24_0_0));
half_adder 	ha24_0_1(.ain(adder8[8]), .bin(1'b1), .sout(s24_0_1), .cout(c24_0_1));

comp42 	co24_1_0(.ain(c23_0_0), .bin(c23_0_1), .cin(s24_0_0), .din(s24_0_1), .cr(ct23_1_0), .ct(ct24_1_0), .sout(s24_1_0), .cout(c24_1_0));

half_adder 	ha24_2_0(.ain(c23_1_0), .bin(s24_1_0), .sout(ans1[24]), .cout(ans2[25]));

//bit25
comp42 	co25_0_0(.ain(adder5[15]), .bin(adder6[13]), .cin(adder7[11]), .din(adder8[9]), .cr(ct24_0_0), .ct(ct25_0_0), .sout(s25_0_0), .cout(c25_0_0));

comp42 	co25_1_0(.ain(~sign[4]), .bin(c24_0_0), .cin(c24_0_1), .din(s25_0_0), .cr(ct24_1_0), .ct(c25_1_0), .sout(s25_1_0), .cout(c25_1_1));

half_adder 	ha25_2_0(.ain(c24_1_0), .bin(s25_1_0), .sout(ans1[25]), .cout(ans2[26]));

//bit26
comp42 	co26_0_0(.ain(adder5[16]), .bin(adder6[14]), .cin(adder7[12]), .din(adder8[10]	), .cr(ct25_0_0), .ct(ct26_0_0), .sout(s26_0_0), .cout(c26_0_0));

full_adder 	fa26_1_0(.ain(1'b1), .bin(c25_0_0), .cin(s26_0_0), .sout(s26_1_0), .cout(c26_1_0));

full_adder 	fa26_2_0(.ain(c25_1_0), .bin(c25_1_1), .cin(s26_1_0), .sout(ans1[26]), .cout(ans2[27]));

//bit27
comp42 	co27_0_0(.ain(adder6[15]), .bin(adder7[13]), .cin(adder8[11]), .din(~sign[5]), .cr(ct26_0_0), .ct(ct27_0_0), .sout(s27_0_0), .cout(c27_0_0));

half_adder 	ha27_1_0(.ain(s27_0_0), .bin(c26_0_0), .sout(s27_1_0), .cout(c27_1_0));

half_adder 	ha27_2_0(.ain(c26_1_0), .bin(s27_1_0), .sout(ans1[27]), .cout(ans2[28]));

//bit28
comp42 	co28_0_0(.ain(adder6[16]), .bin(adder7[14]), .cin(adder8[12]), .din(1'b1), .cr(ct27_0_0), .ct(c28_0_0), .sout(s28_0_0), .cout(c28_0_1));

half_adder 	ha28_1_0(.ain(s28_0_0), .bin(c27_0_0), .sout(s28_1_0), .cout(c28_1_0));

half_adder 	ha28_2_0(.ain(c27_1_0), .bin(s28_1_0), .sout(ans1[28]), .cout(ans2[29]));

//bit29
full_adder 	fa29_0_0(.ain(adder7[15]), .bin(adder8[13]), .cin(~sign[6]), .sout(s29_0_0), .cout(c29_0_0));

full_adder 	fa29_1_0(.ain(c28_0_0), .bin(c28_0_1), .cin(s29_0_0), .sout(s29_1_0), .cout(c29_1_0));

half_adder 	ha29_2_0(.ain(c28_1_0), .bin(s29_1_0), .sout(ans1[29]), .cout(ans2[30]));

//bit30
full_adder 	fa30_0_0(.ain(adder7[16]), .bin(adder8[14]), .cin(1'b1), .sout(s30_0_0), .cout(c30_0_0));

half_adder 	ha30_1_0(.ain(s30_0_0), .bin(c29_0_0), .sout(s30_1_0), .cout(c30_1_0));

half_adder 	ha30_2_0(.ain(c29_1_0), .bin(s30_1_0), .sout(ans1[30]), .cout(c30_2_0));

//bit31


assign ans={1'b0,ans1}+{1'b0,ans2};
assign prod[31]=adder8[15]^(~sign[7])^c30_0_0^c30_1_0^c30_2_0^ans[31];
assign prod[30:0]=ans[30:0];
assign sign_out=(ss&(ain[15]^bin[15])) |
		(su&ain[15]) 		|
		(us&bin[15]);


endmodule
