`ifndef __MULTI__
`define __MULTI__
`include "multi16.v"
module multi(
ain,bin,ss,su,uu,state,prod,clk);

input ss,su,uu,clk;
input[1:0] state;
input[31:0] ain,bin;
output[63:0] prod;

wire sign;
wire mul16uu,mul16us,mul16su,mul16ss;
wire[15:0] mul16ain,mul16bin;
wire [31:0] mul16ans;
wire[63:0] ans;
reg[63:0] ans_temp;
always@(posedge clk)
begin
  if(state==2'b0)
  begin
    ans_temp<={{32{sign}},mul16ans};
  end
  else if(state==2'b1)
  begin
    ans_temp<={{16{sign}},mul16ans,16'b0}+ans;
  end
  else if(state==2'b10)
  begin
    ans_temp<={{16{sign}},mul16ans,16'b0}+ans;
  end
  else if(state==2'b11)
  begin
    ans_temp<={mul16ans,32'b0}+ans;
  end

end

wire [63:0] real_calculation;
assign real_calculation = ({64{state==2'b11}} & {ans_temp+{mul16ans,32'b0}});


assign ans=ans_temp;
assign mul16ain=({16{~state[0]}}&ain[15:0]) | ({16{state[0]}}&ain[31:16]) ;
assign mul16bin=({16{~state[1]}}&bin[15:0]) | ({16{state[1]}}&bin[31:16]) ;
assign mul16uu=uu | (su&(~state[0])) | (ss&(state==2'b0));
assign mul16su=(su&state[0]) | (ss&(state==2'b1));
assign mul16us=ss&(state==2'b10);
assign mul16ss=ss&(state==2'b11);


assign prod=real_calculation;

multi16 m16(
	.ain(mul16ain),
	.bin(mul16bin),
	.ss(mul16ss),
	.us(mul16us),
	.su(mul16su),
	.uu(mul16uu),
	.prod(mul16ans),
	.sign_out(sign));



endmodule
`endif