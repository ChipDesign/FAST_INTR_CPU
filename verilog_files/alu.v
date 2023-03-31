`include "long_div.v"
`include "multi.v"
`include "shifter32.v"
module alu(clk,rstn,ain,bin,ALUout,ALUop);

input[31:0] ain,bin;
input[4:0] ALUop;
input clk,rstn;

output[31:0] ALUout;




wire add_op,sub_op,sll_op,srl_op,sra_op,or_op,and_op,xor_op,slt_op,sltu_op;
wire mul_op,mulh_op,mulhu_op,mulhsu_op,div_op,divu_op,rem_op,remu_op;

wire[31:0] sft_ans,div_ans,rem_ans,log_ans,mul_low,mul_high;
wire [32:0] add_ans;
wire[1:0] mul_next_state;
reg[1:0] mul_state;
wire[3:0] div_next_state;
reg[3:0] div_state;
reg div_last;
reg fin;
wire d_init,d_advance;

always@(posedge clk)
begin
  if(~rstn)
  begin
    mul_state<=2'b0;
    div_state<=4'b0;
    div_last<=0;
  end
  
  
  else if(mul_op|mulh_op|mulhu_op|mulhsu_op)
  begin
    mul_state<=mul_next_state;
    if(mul_state==2'b11)
    begin
      fin<=1'b1;
    end
    else begin 
      fin<=1'b0;
    end
  end
  
  else if(div_op|divu_op|rem_op|remu_op)
  begin
    if(div_state==4'b1111)
    begin
      div_last<=1'b1;
    end
    
    
    if(div_last)
    begin
    	div_last<=1'b0;
    	fin<=1'b1;
    end
    else 
    begin
    	div_state<=div_next_state; 
      	fin<=1'b0;
    end
  end
  
  else begin
  fin<=1'b0;
  end
  
end


assign div_next_state= div_state+4'b1;
assign mul_next_state= mul_state+2'b1;

assign d_init=(div_op|divu_op|rem_op|remu_op)&(div_state==4'b0)&(~div_last);
assign d_advance=(div_op|divu_op|rem_op|remu_op)&(~(div_state==4'b0));

assign add_op=		ALUop==5'd0;
assign sub_op=		ALUop==5'd1;
assign sll_op=		ALUop==5'd2;
assign srl_op=		ALUop==5'd3;
assign sra_op=		ALUop==5'd4;
assign or_op=		ALUop==5'd5;
assign and_op=		ALUop==5'd6;
assign xor_op=		ALUop==5'd7;
assign slt_op=		ALUop==5'd8;
assign sltu_op= 	ALUop==5'd9;
assign mul_op=		ALUop==5'd10;
assign mulh_op= 	ALUop==5'd11;
assign mulhsu_op=	ALUop==5'd12;
assign mulhu_op=	ALUop==5'd13;
assign div_op=		ALUop==5'd14;
assign divu_op=	ALUop==5'd15;
assign rem_op=		ALUop==5'd16;
assign remu_op=	ALUop==5'd17;

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
