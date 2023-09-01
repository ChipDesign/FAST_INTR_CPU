`ifndef __LONGDIV__
`define __LONGDIV__
`include "CSA35.v"
module long_div (
          clk, 
          dividend, divisor, unsign, 
          d_init, e_advance, e_last, 
          quot, remd
          );

input clk;
input [31:0] dividend, divisor;
input unsign;
input d_init, e_advance, e_last; 
output[31:0] quot, remd;
//-------------------------
wire sign_divisor, sign_dividend;
reg [31:0] dvs;
reg sign_dvs, sign_dvd, sign_quot;
reg [31:0] dvd;
wire [31:0] quot;
wire sub;
wire [34:0] dvs_ivt, rem_sub1, rem_sub2;
wire [34:0] sub3_ps, sub3_pc, rem_sub3;
wire sign_rem1, sign_rem2, sign_rem3;
wire quot_1, quot_0;
reg [34:0] rem;  
wire [31:0] remd;
//###########################
// took 16+1 cycles to finish 32-bit division
// last cycle is to convert negative quotient from 1's complement to 2's complement
assign sign_divisor  = divisor[31] & ~unsign;
assign sign_dividend = dividend[31] & ~unsign;

always@(posedge clk) begin
  if(d_init) begin 
  	dvs       <= divisor;
		sign_dvs  <= sign_divisor;
		sign_dvd  <= sign_dividend;
		sign_quot <= sign_divisor ^ sign_dividend;
	end 
end 

always@(posedge clk) begin
  if(d_init) 
		dvd <= dividend;
	else if (e_advance)
    dvd <= {dvd[29:0], quot_1, quot_0}; // store quotient here
  // else if (e_last & sign_quot)                     
  //   dvd <= dvd + 1; // to convert negative quotent from 1's complement to 2's complement   
end 

// assign quot = dvd; 
assign quot = dvd + {31'b0, sign_quot}; 
// restoring divison
// keep remainder sign same as dividend,  
// in case remainder = 0, and dividend is negative; still keep same sub/add as previous. 
assign sub      = ~sign_quot; // not use "sign_rem" ^ sign_dvs, use "sign_dvd" ^ sign_dvs 
assign dvs_ivt  = {35{sub}} ^ {{3{sign_dvs}}, dvs};
assign rem_sub1 = {rem[32:0], dvd[31:30]} + dvs_ivt + {{34'b0},{sub}};
assign rem_sub2 = {rem[32:0], dvd[31:30]} + {dvs_ivt[33:0], sub} + {{34'b0},{sub}};

CSA35 csa_35 (
	.ain   ({rem[32:0], dvd[31:30]}),
	.bin   ({dvs_ivt[33:0], sub}),
	.cin   (dvs_ivt),
	.sout (sub3_ps),
	.cout (sub3_pc)
);

assign rem_sub3 = sub3_ps + {sub3_pc[33:0], sub} + {{34'b0},{sub}};
//remainder sign conversion for quotient evaluation
assign sign_rem1 = (rem_sub1[34] ^ sign_dvd) & ~(rem_sub1 == 35'h0);
assign sign_rem2 = (rem_sub2[34] ^ sign_dvd) & ~(rem_sub2 == 35'h0);
assign sign_rem3 = (rem_sub3[34] ^ sign_dvd) & ~(rem_sub3 == 35'h0);
// quotient evaluation
assign quot_1 = ~sign_rem2 ^ sign_quot; // 1's complement for negative quotient
assign quot_0 = ((~sign_rem1 & sign_rem2) | ~sign_rem3) ^ sign_quot; 

always@(posedge clk) begin
  if(d_init) 
		rem <= {35{sign_dividend}};
  else if (e_advance)
    rem <= ({35{sign_rem1             }} & {rem[32:0], dvd[31:30]}) |
		       ({35{~sign_rem1 & sign_rem2}} & rem_sub1) |
			     ({35{~sign_rem2 & sign_rem3}} & rem_sub2) |
			     ({35{~sign_rem3            }} & rem_sub3);
end  

assign remd = rem[31:0];

endmodule
`endif
