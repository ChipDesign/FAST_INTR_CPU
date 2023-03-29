

module alu(clk,reset_n,ain,bin,ALUout,ALUop);

input[31:0] ain,bin;
input[4:0] ALUop;
input clk,reset_n;

output[31:0] ALUout;



wire add_op,sub_op,sll_op,srl_op,sra_op,or_op,and_op,xor_op,slt_op,sltu_op;
wire mul_op,mulh_op,mulhu_op,,mulhsu_op,div_op,divu_op,rem_op,remu_op;

wire[31:0] add_ans,sft_ans,div_ans,rem_ans,log_ans,mul_low,mul_high;


assign add_op=	ALUop==5'd0;
assign sub_op=	ALUop==5'd1;
assign sll_op=	ALUop==5'd2;
assign srl_op=	ALUop==5'd3;
assign sra_op=	ALUop==5'd4;
assign or_op=	ALUop==5'd5;
assign and_op=	ALUop==5'd6;
assign xor_op=	ALUop==5'd7;
assign slt_op=	ALUop==5'd8;
assign sltu_op= ALUop==5'd9;
assign mul_op=	ALUop==5'd10;
assign mulh_op= 	ALUop==5'd11;
assign mulhsu_op=	ALUop==5'd12;
assign mulhu_op=	ALUop==5'd13;
assign div_op=	ALUop==5'd14;
assign divu_op=	ALUop==5'd15;
assign rem_op=	ALUop==5'd16;
assign remu_op=	ALUop==5'd17;

assign add_ans=ain+{32{sub_op}}^bin+{31{1'b0},sub_op};
assign log_ans=((ain^bin)&{32{(xor_op|or_op)}})|((ain&bin)&{32{(and_op|or_op)}});









endmodule
