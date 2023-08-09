`ifndef __BOOTH16__
`define __BOOTH16__
module booth16(
mcand,mlier,umcand,sign,adder,neg);

input[15:0] mcand;//multiplicand
input[2:0] mlier;//multiplier
input umcand;//unsigned multiplicand
output[16:0] adder;//output
output sign;//for signed extention
output neg;//for 1's to 2's complement

wire[15:0] mcand_comp;
wire zero,one,two;
wire s,n;
assign mcand_comp={16{mlier[2]}}^mcand;
assign n=mlier[2];
assign zero=(~mlier[1]^mlier[0])&(~mlier[2]^mlier[0]);
assign one=mlier[1]^mlier[0];
assign two=(~mlier[1]^mlier[0])&(mlier[2]^mlier[0]);
assign s=~zero&(n^(~umcand&mcand[15]));


assign adder=({17{one}}&{s,mcand_comp})|
		({17{two}}&{mcand_comp,mlier[2]});
assign sign=s;
assign neg=n&(~zero);

endmodule
`endif
