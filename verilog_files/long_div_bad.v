`include "CSA32.v"

module long_div(dividend,divisor,clk,rstn,en,rem,quot,uns,fin);

input[31:0] dividend,divisor;
input uns,clk,en,rstn;
output[31:0] rem,quot;
output reg fin;

reg[63:0] ans_temp;
reg[3:0] state;
reg[31:0] dvs;
reg negdvd;

wire[4:0] next_state;
wire[32:0] rem1;
wire[33:0] rem2;
wire[34:0] rem3;
wire[33:0] div3;
wire[34:0] csas,csac;
wire[1:0] qi;
wire sub;
wire[32:0] dvs_comp;
wire[31:0] uquot,urem;

always@(posedge clk)
begin
	if(~rstn)
	begin
		state<=4'b0;
		fin<=1'b0;
		ans_temp<=63'b0;
		negdvd<=0;
	end
	else if((state==4'b0)&en)
	begin
		negdvd<=(~uns)&dividend[31];
		dvs<=divisor;
		ans_temp<={30'b0,{32{(~uns)&dividend[31]}}^dividend,2'b0}
					+{61'b0,(~uns)&dividend[31],2'b0};
		state<=5'b1;
		fin<=1'b0;
	end
	else if((state!=4'd0)&(state!=4'd15))
	begin
		state<=next_state;
		ans_temp<={
			({30{qi==0}}&ans_temp[61:32])|
			({30{qi==1}}&rem1[29:0])|
			({30{qi==2}}&rem2[29:0])|
			({30{qi==3}}&rem3[29:0]),
			ans_temp[31:0],qi
			};
		fin<=1'b0;
	end
	else if(state==4'd15)
	begin
		state<=next_state;
		fin<=1'b1;
		ans_temp<={
			({30{qi==0}}&ans_temp[61:32])|
			({30{qi==1}}&rem1[29:0])|
			({30{qi==2}}&rem2[29:0])|
			({30{qi==3}}&rem3[29:0]),
			ans_temp[31:0],qi
			};
	end
end


assign next_state=state+1'b1;
assign dvs_comp={33{sub}}^{(~uns)&dvs[31],dvs};
assign sub=(~(dvs[31]))|uns;

assign rem1={1'b0,ans_temp[63:32]}+dvs_comp+{32'b0,sub};
assign rem2={2'b0,ans_temp[63:32]}+{dvs_comp,sub}+{33'b0,sub};
assign rem3=csas+{csac[33:0],sub}+{34'b0,sub};
assign qi={~rem2[33],~(rem1[32]^rem2[33]^rem3[34])};
	
assign uquot={ans_temp[29:0],qi};
assign urem=	({32{qi==0}}&ans_temp[63:32])|
			({32{qi==1}}&rem1[31:0])|
			({32{qi==2}}&rem2[31:0])|
			({32{qi==3}}&rem3[31:0]);
assign quot=({32{(~uns)&(negdvd^dvs[31])}}^uquot)+{31'b0,(~uns)&(negdvd^dvs[31])};
assign rem=({32{(~uns)&negdvd}}^urem)+{31'b0,(~uns)&negdvd};

CSA35 csa(
	.ain({3'b0,ans_temp[63:32]}),
	.bin({{2{dvs_comp[32]}},dvs_comp}),
	.cin({dvs_comp[32],dvs_comp,sub}),
	.sout(csas),
	.cout(csac));





endmodule
