module barrel_sft(
                 sft_in,
                 sft_amount, sft_right, logic_sft,
                 sft_out
                 );

input [31:0] sft_in;
input [4:0] sft_amount;
input sft_right, logic_sft;
output [31:0] sft_out;
//-------------------------
wire [31:0] sft_out, swap_out;
wire [31:0] sft_out1, sft_out2, sft_out3;
wire [4:0] sfl_cnt;
wire sign_x, sft_right;
//#################################
assign sfl_cnt = sft_amount;
// sign extension for arithmetic shift right
assign sign_x = ~logic_sft & sft_right & sft_in[31];
//--------------------------------
// data input swap        
assign swap_out = sft_right ? {sft_in[0], sft_in[1], sft_in[2], sft_in[3], sft_in[4], sft_in[5], sft_in[6], sft_in[7],
                               sft_in[8], sft_in[9],sft_in[10],sft_in[11],sft_in[12],sft_in[13],sft_in[14],sft_in[15],
                               sft_in[16],sft_in[17],sft_in[18],sft_in[19],sft_in[20],sft_in[21],sft_in[22],sft_in[23],
                               sft_in[24],sft_in[25],sft_in[26],sft_in[27],sft_in[28],sft_in[29],sft_in[30],sft_in[31]} 
                               : sft_in;
//------------------------------------------
// shift "left" body
// shift 1 by 1 with Shift count b0,b1
assign sft_out1 = ({32{~sfl_cnt[1] & ~sfl_cnt[0]}} & swap_out) | // shift 0
                  ({32{~sfl_cnt[1] &  sfl_cnt[0]}} & {swap_out[30:0], sign_x}) | // shift by 1
                  ({32{ sfl_cnt[1] & ~sfl_cnt[0]}} & {swap_out[29:0], {2{sign_x}}}) | // shift by 2
                  ({32{ sfl_cnt[1] &  sfl_cnt[0]}} & {swap_out[28:0], {3{sign_x}}});  // shift by 3
//----------------------------------------------------------------------
// Shift 4 by 4 with shif count b2,b3
assign sft_out2 = ({32{~sfl_cnt[3] & ~sfl_cnt[2]}} &  sft_out1) | // shift by 0
                  ({32{~sfl_cnt[3] &  sfl_cnt[2]}} & {sft_out1[27:0], {4{sign_x}}}) | // shift by 4
                  ({32{ sfl_cnt[3] & ~sfl_cnt[2]}} & {sft_out1[23:0], {8{sign_x}}}) | // shift by 8
                  ({32{ sfl_cnt[3] &  sfl_cnt[2]}} & {sft_out1[19:0], {12{sign_x}}}); // shift by 12 
//----------------------------------------------------------
// Shift 16 with shift count b4
assign sft_out3 = ({32{~sfl_cnt[4]}} &  sft_out2) |  // shift by 0
                  ({32{ sfl_cnt[4]}} & {sft_out2[15:0], {16{sign_x}}}); // shif by 16
//-----------------------------------------------
// data output swap                                         
assign sft_out = sft_right ? {sft_out3[0], sft_out3[1], sft_out3[2], sft_out3[3], sft_out3[4], sft_out3[5], sft_out3[6], sft_out3[7],
                              sft_out3[8], sft_out3[9],sft_out3[10],sft_out3[11],sft_out3[12],sft_out3[13],sft_out3[14],sft_out3[15],
                              sft_out3[16],sft_out3[17],sft_out3[18],sft_out3[19],sft_out3[20],sft_out3[21],sft_out3[22],sft_out3[23],
                              sft_out3[24],sft_out3[25],sft_out3[26],sft_out3[27],sft_out3[28],sft_out3[29],sft_out3[30],sft_out3[31]} 
                              : sft_out3[31:0];

endmodule


