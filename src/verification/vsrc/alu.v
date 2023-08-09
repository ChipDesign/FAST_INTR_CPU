`ifndef __ALU__
`define __ALU__
`include "long_div.v"
`include "multi.v"
`include "shifter32.v"
module alu(clk,resetn,ain,bin,ALUout,ALUop,branch_taken,
mul_state,d_init,div_last,d_advance
);

input[31:0] ain,bin;
input[20:0] ALUop;
input[1:0] mul_state;
input d_init, div_last,d_advance;
input clk,resetn;

output[31:0] ALUout;
output branch_taken;



wire add_op,sub_op,sll_op,srl_op,sra_op,or_op,and_op,xor_op,slt_op,sltu_op;
wire mul_op,mulh_op,mulhu_op,mulhsu_op,div_op,divu_op,rem_op,remu_op;
wire beq,blt,branch;

wire[31:0] sft_ans,div_ans,rem_ans,log_ans,mul_low,mul_high;
wire [32:0] add_ans;





assign add_op=		ALUop[0];
assign sub_op=		ALUop[1];
assign sll_op=		ALUop[2];
assign srl_op=		ALUop[3];
assign sra_op=		ALUop[4];
assign or_op=		ALUop[5];
assign and_op=		ALUop[6];
assign xor_op=		ALUop[7];
assign slt_op=		ALUop[8];
assign sltu_op= 	ALUop[9];
assign mul_op=		ALUop[10];
assign mulh_op= 	ALUop[11];
assign mulhsu_op=	ALUop[12];
assign mulhu_op=	ALUop[13];
assign div_op=		ALUop[14];
assign divu_op=	ALUop[15];
assign rem_op=		ALUop[16];
assign remu_op=	ALUop[17];
assign beq=		ALUop[18];
assign blt=		ALUop[19];
assign branch=		ALUop[20];

assign add_ans={(~sltu_op)&ain[31],ain}+({33{sub_op|slt_op|sltu_op}}^{bin[31]&(~sltu_op),bin})+{{32{1'b0}},sub_op|slt_op|sltu_op};
assign log_ans=((ain^bin)&{32{(xor_op|or_op)}})|((ain&bin)&{32{(and_op|or_op)}});

assign ALUout=  ({32{sub_op|add_op}}&add_ans[31:0])|
		({32{rem_op|remu_op}}&rem_ans)|
		({32{div_op|divu_op}}&div_ans) |
		({32{mul_op}}&mul_low) |
		({32{mulh_op|mulhsu_op|mulhu_op}}&mul_low) |
		({32{or_op|and_op|xor_op}}&log_ans) |
		({32{sll_op|srl_op|sra_op}}&sft_ans) |
		({32{sltu_op|slt_op}}&{31'b0,add_ans[32]});
		
assign branch_taken=branch&((sub_op&(~beq^(add_ans===0)))|	((slt_op|sltu_op)&(~blt^(add_ans[32]))));


long_div  div(
          .clk(clk), 
          .dividend(ain), 
          .divisor(bin), 
          .unsign(remu_op|divu_op), 
          .d_init(d_init), 
          .e_advance(d_advance), 
          .e_last(div_last), 
          .quot(div_ans), 
          .remd(rem_ans)
          );


multi 	mul(
	.ain(ain),
	.bin(bin),
	.ss(mul_op|mulh_op),
	.su(mulhsu_op),
	.uu(mulhu_op),
	.state(mul_state),
	.prod({mul_high,mul_low}),
	.clk(clk)
	);

shifter32 #(32,5) sft(
        .d_in(ain),
        .shift(bin[4:0]),
        .arithOrLogic(srl_op), // SRA or SRL
        .leftOrRight(sra_op|srl_op), // shift left or right
        .d_out(sft_ans));


endmodule
`endif
