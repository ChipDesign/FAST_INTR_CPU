module pgm_fetch(
                 clk, rstn,
                 p_rd, 
                 pe_addr, po_addr,
                 pe_rdata, po_rdata,
                 drain_1, drain_2, 
                 trans_d, trans_addr,
                 null_ir, ir, word2_d, parallel,
                 acc_depend_chk, rlm_depend_chk
                 );

input clk, rstn;
input [15:0] pe_rdata, po_rdata;
input drain_1, drain_2;
input trans_d;
input [17:0] trans_addr;
input null_ir;
output p_rd; 
output [16:0] pe_addr, po_addr;
output [31:0] ir;
output word2_d, parallel;
output [7:0] acc_depend_chk;
output [18:0] rlm_depend_chk;
//-------------------------------
reg [17:0] linear_paddr;
wire [17:0] paddr, next_paddr;
wire [16:0] po_addr, pe_addr;
reg paddr_d;
wire p_rd;
reg fill;
wire [15:0] lead_word, next_word;
reg [2:0] pf_fifo_cnt;
wire [2:0] next_fifo_cnt;
wire next_pt1, next_pt2, next_pt3, next_pt4, next_pt5;
wire pt2, pt3, pt4, pt5;
wire drain;
reg [15:0] pir2, pir1, pir0, ir1, ir0;
wire [31:0] ir;
wire word2_d;
wire ir_0000, jmp_la, jmp_acc, call_la, call_acc;
wire loop_con, loop_var, rep_var, mvli, ldst_la;
wire ld1_acc, ld2_acc, st1_acc, st2_acc;
wire ld1_reg, ld2_reg, ldsa1, ldsa2, push, st1_reg, st2_reg, stsa1, stsa2, pop, mr;
wire ldd1, ldd2, std1, std2, ld1ld2, ld1st2, st1ld2, ldd1ldd2, ldd1std2, std1ldd2;
wire cmpli, adli, anli, orli, xoli;
wire parallel, ir_0010_0001;
wire trans_acc, cnt_acc, ldst_acc, sel_a, sel_b, sel_c, sel_d;
wire [1:0] acc_sel;
wire depend_a_chk_a, depend_b_chk_a, depend_c_chk_a, depend_d_chk_a;
wire depend_a_chk_e, depend_b_chk_e, depend_c_chk_e, depend_d_chk_e;
wire x_reg;
wire [1:0] x_rsel;
wire x_msel;
wire y_reg;
wire [1:0] y_rsel;
wire y_msel;
wire sel_r0, sel_r1, sel_r2, sel_r3, sel_r4, sel_r5, sel_r6, sel_r7;
wire depend_rl0_chk_a, depend_rl1_chk_a, depend_rl2_chk_a, depend_rl3_chk_a;
wire depend_m0_chk_a, depend_m1_chk_a, depend_m2_chk_a, depend_m3_chk_a;
wire depend_xdpp_chk_a, depend_swsp_chk_a;
wire depend_rl4_chk_a, depend_rl5_chk_a, depend_rl6_chk_a, depend_rl7_chk_a;
wire depend_m4_chk_a, depend_m5_chk_a, depend_m6_chk_a, depend_m7_chk_a;
wire depend_ydpp_chk_a;
wire [7:0] acc_depend_chk;
wire [18:0] rlm_depend_chk;
wire x_mr, y_mr;
//-------------------------------------------------
always @ (posedge clk) begin
 if (p_rd)  // p_rd is for `program read`，表示fifo需要从i-memory里读取指令
   linear_paddr <= paddr + 18'h2; 
end	

assign paddr      = (~rstn | trans_d) ? trans_addr : linear_paddr; // linear_paddr是顺序取指的地址，trans_addr是发生pc重定向时输入的地址
assign next_paddr = paddr + 18'h1; // memory有2个bank，高bank的地址是低back地址+1·    
//------------------------------------------------
// program memory address interface
assign po_addr  = paddr[0] ? paddr[17:1] : next_paddr[17:1];
assign pe_addr  = ~paddr[0] ? paddr[17:1] : next_paddr[17:1];

always @(posedge clk) begin	
   paddr_d <= paddr[0];
end
// program read request
// TODO: next_fifo_cnt change to pf_fifo_cnt
assign p_rd  = (trans_d | ~(next_fifo_cnt >= 3'h4)) & rstn; // fifo count less than or equal to 3

always @(posedge clk) begin
   fill <= p_rd; 
end	

// program memory data interface
assign	lead_word = paddr_d ?  po_rdata : pe_rdata;
assign	next_word = ~paddr_d ?  po_rdata : pe_rdata;
//#######################################
// instruction FIFO
//######################################
// calculate fifo depth

always @ (posedge clk) begin
    if (~rstn | trans_d)         
      pf_fifo_cnt <= 3'h0; 
    else if (fill | drain) // fill: FIFO push, drain: fifo pop
      pf_fifo_cnt  <= next_fifo_cnt;
end

assign next_fifo_cnt = pf_fifo_cnt + ({3{fill}} & 3'h2) 
                                   - (({3{drain_2}} & 3'h2) | ({3{drain_1}} & 3'h1)); // fifo pop 1 or 2
                                   
assign next_pt1 = (next_fifo_cnt == 3'h1);
assign next_pt2 = (next_fifo_cnt == 3'h2);
assign next_pt3 = (next_fifo_cnt == 3'h3);
assign next_pt4 = (next_fifo_cnt == 3'h4);
assign next_pt5 = (next_fifo_cnt == 3'h5); 

assign pt2 = (pf_fifo_cnt == 3'h2);
assign pt3 = (pf_fifo_cnt == 3'h3);
assign pt4 = (pf_fifo_cnt == 3'h4);
assign pt5 = (pf_fifo_cnt == 3'h5); 

//-------------------------------      
// FIFO body
assign drain = drain_1 | drain_2;

always @(posedge clk) begin
 if (next_pt5 & fill)   
     pir2 <= next_word;     
end

always @(posedge clk) begin
 if ((next_pt5 | next_pt4) & fill)   
     pir1 <= ({16{next_pt5}} & lead_word) |
             ({16{next_pt4}} & next_word);
 else if (pt5 & drain_1)
     pir1 <= pir2;
end

always @(posedge clk) begin
 if ((next_pt4 | next_pt3) & fill)   
     pir0 <= ({16{next_pt4}} & lead_word) |
             ({16{next_pt3}} & next_word);  
 else if ((pt5 & drain) | (pt4 & drain_1))
     pir0 <= ({16{drain_1}} & pir1) |
             ({16{drain_2}} & pir2);  
end

always @(posedge clk) begin
 if ((next_pt3 | next_pt2) & fill)   // fifo 空或者有1*16bits数据
     ir1 <= ({16{next_pt3}} & lead_word) |
            ({16{next_pt2}} & next_word);
 else if (((pt5 | pt4) & drain) | (pt3 & drain_1)) // fifo至少有2*16bits数据
     ir1 <= ({16{drain_1}} & pir0) |
            ({16{drain_2}} & pir1);
end

always @(posedge clk) begin
 if (~rstn) // TODO: 为什么只有ir0才会reset?
     ir0 <= 16'h0;
 else if (next_pt2 & fill) // fifo empty  
     ir0 <= ({16{next_pt2}} & lead_word);    
 else if (((pt5 | pt4 | pt3) & drain) | (pt2 & drain_1)) // fifo not empty
     ir0 <= ({16{drain_1}} & ir1) |
            ({16{drain_2}} & pir0);
end 
//############################################################
// pre_decode 2-word instructions
assign ir_0000  = (ir0[15:12] == 4'b0000);
assign jmp_la   = ir_0000 & (ir0[11:6]  == 6'b0011_00); 
assign jmp_acc  = ir_0000 & (ir0[11:6]  == 6'b0001_00); 
assign call_la  = ir_0000 & (ir0[11:6]  == 6'b0011_10); 
assign call_acc = ir_0000 & (ir0[11:6]  == 6'b0001_01); 
assign rep_var  = ir_0000 & (ir0[11:2] == 10'b0100_0000_00); 
assign loop_var = ir_0000 & (ir0[11:4]  == 8'b0100_0010); 
assign loop_con = (ir0[15:10] == 6'b0001_00); 
assign mvli     = (ir0[15:6]  == 10'b0010_0001_00); 
assign ldst_la  = (ir0[15:8]  == 8'b0010_0000); 

assign ld1_acc = (ir0[15:6]  == 10'b1111_1001_00);  
assign ld2_acc = (ir0[15:6]  == 10'b1111_1011_00); 
assign st1_acc = (ir0[15:6]  == 10'b1111_1101_00); 
assign st2_acc = (ir0[15:6]  == 10'b1111_1111_00); 
//----------------------------------------------------
assign ld1_reg = (ir0[15:8]  ==  8'b1111_1000); 
assign ld2_reg = (ir0[15:8]  ==  8'b1111_1010);   
assign ldsa1   = (ir0[15:11]  == 5'b0110_0); 
assign ldsa2   = (ir0[15:11]  == 5'b0110_1); 
assign push    = (ir0[15:6]  == 10'b1111_1101_01); 
assign st1_reg = (ir0[15:8]  ==  8'b1111_1100); 
assign st2_reg = (ir0[15:8]  ==  8'b1111_1110);  
assign stsa1   = (ir0[15:11]  == 5'b0111_0); 
assign stsa2   = (ir0[15:11]  == 5'b0111_1); 
assign pop     = (ir0[15:6]  == 10'b1111_1001_01);
assign mr      = (ir0[15:10]  == 6'b1111_01);

assign ldd1 = (ir0[15:7] == 9'b1111_1001_1);
assign ldd2 = (ir0[15:7] == 9'b1111_1011_1);
assign std1 = (ir0[15:6] == 10'b1111_1101_10);
assign std2 = (ir0[15:6] == 10'b1111_1111_10);

assign ld1ld2 = (ir0[15:12] == 4'b1100);
assign ld1st2 = (ir0[15:12] == 4'b1101);
assign st1ld2 = (ir0[15:12] == 4'b1110);

assign ldd1ldd2 = (ir0[15:12] == 4'b1000);
assign ldd1std2 = (ir0[15:12] == 4'b1001);
assign std1ldd2 = (ir0[15:12] == 4'b1010);
//-------------------------------------------------
assign ir_0010_0001 = (ir0[15:8] == 8'b0010_0001);
assign cmpli = ir_0010_0001 & (ir0[7:2] == 6'b0101_01);
assign adli  = ir_0010_0001 & (ir0[7:2] == 6'b0101_00);
assign anli  = ir_0010_0001 & (ir0[7:2] == 6'b0100_00);
assign orli  = ir_0010_0001 & (ir0[7:2] == 6'b0100_01);
assign xoli  = ir_0010_0001 & (ir0[7:2] == 6'b0100_00);

assign parallel = ir0[10] & ((ir0[15:11] == 5'b00111) |
                             (ir0[15:11] == 5'b01000) |
                             (ir0[15:11] == 5'b01001) |
                             (ir0[15:11] == 5'b01010) |
                             (ir0[15:11] == 5'b01011));
//-----------------------------------------------------------
assign word2_d = jmp_la | call_la | loop_con | loop_var | mvli | ldst_la |
                 cmpli | adli | anli | orli | xoli | parallel;
//-----------------------------------------------------------
// jump acc, call acc dependecy check
assign trans_acc = jmp_acc | call_acc;
assign cnt_acc = loop_var | rep_var;
assign ldst_acc  = ld1_acc | ld2_acc | st1_acc |st2_acc;
assign acc_sel = ({2{trans_acc | ldst_acc}} & ir0[5:4]) | 
                 ({2{cnt_acc}} & ir0[1:0]);
assign sel_a = (acc_sel == 2'b00);
assign sel_b = (acc_sel == 2'b01);
assign sel_c = (acc_sel == 2'b10);
assign sel_d = (acc_sel == 2'b11);
assign depend_a_chk_a = (trans_acc | cnt_acc | ldst_acc) & sel_a;
assign depend_b_chk_a = (trans_acc | cnt_acc | ldst_acc) & sel_b;
assign depend_c_chk_a = (trans_acc | cnt_acc | ldst_acc) & sel_c;
assign depend_d_chk_a = (trans_acc | cnt_acc | ldst_acc) & sel_d;
assign depend_a_chk_e = (trans_acc | cnt_acc) & sel_a;
assign depend_b_chk_e = (trans_acc | cnt_acc) & sel_b;
assign depend_c_chk_e = (trans_acc | cnt_acc) & sel_c;
assign depend_d_chk_e = (trans_acc | cnt_acc) & sel_d;
assign acc_depend_chk = {depend_d_chk_e, depend_c_chk_e, depend_b_chk_e, depend_a_chk_e, 
                         depend_d_chk_a, depend_c_chk_a, depend_b_chk_a, depend_a_chk_a};
//----------------------------------------------------------
// r, l, m, xdpp, ydpp, swsp dependency check
assign x_mr = mr & ~ir0[9];

assign y_mr = mr & ir0[9];

assign x_reg  = ld1_reg | st1_reg | ldd1 | std1 | ld1ld2 | ld1st2 | st1ld2 |
                 ldd1ldd2 | ldd1std2 | std1ldd2 | x_mr;
assign x_rsel = ({2{x_mr}} & ir0[8:7]) | 
                  ({2{ld1_reg | st1_reg}} & ir0[5:4]) |
                  ({2{ldd1}} & ir0[4:3]) |
                  ({2{std1 | ld1ld2 | ld1st2 | st1ld2 | ldd1ldd2 | ldd1std2 | std1ldd2}} & ir0[3:2]);             
assign x_msel = ((({2{ld1_reg | st1_reg}} & ir0[7:6]) |
                  ({2{ldd1}} & ir0[6:5]) |
                  ({2{std1 | ld1ld2 | ld1st2 | st1ld2 | ldd1ldd2 | ldd1std2 | std1ldd2}} & ir0[5:4]))
                  == 2'b11);
assign y_reg = ld2_reg | st2_reg | ldd2 | std2 | ld1ld2 | ld1st2 | st1ld2 |
                 ldd1ldd2 | ldd1std2 | std1ldd2 | y_mr;
assign y_rsel = ({2{y_mr}} & ir0 [8:7]) |
                  ({2{ld2_reg | st2_reg}} & ir0[5:4]) |
                  ({2{ldd2}} & ir0[4:3]) |
                  ({2{std2}} & ir0[3:2]) |
                  ({2{ld1ld2 | ld1st2 | st1ld2 | ldd1ldd2 | ldd1std2 | std1ldd2}} & ir0[9:8]);         
assign y_msel  = ((({2{ld2_reg | st2_reg}} & ir0[7:6]) |
                  ({2{ldd2}} & ir0[6:5]) |
                  ({2{std2}} & ir0[5:4]) |
                  ({2{ld1ld2 | ld1st2 | st1ld2 | ldd1ldd2 | ldd1std2 | std1ldd2}} & ir0[11:10])) 
                  == 2'b11);  
assign sel_r0 = (x_rsel == 2'b00);
assign sel_r1 = (x_rsel == 2'b01);
assign sel_r2 = (x_rsel == 2'b10);
assign sel_r3 = (x_rsel == 2'b11);
assign sel_r4 = (y_rsel == 2'b00);
assign sel_r5 = (y_rsel == 2'b01);
assign sel_r6 = (y_rsel == 2'b10);
assign sel_r7 = (y_rsel == 2'b11);

assign depend_rl0_chk_a = x_reg & sel_r0;
assign depend_rl1_chk_a = x_reg & sel_r1;
assign depend_rl2_chk_a = x_reg & sel_r2;
assign depend_rl3_chk_a = x_reg & sel_r3;
assign depend_m0_chk_a  = x_reg & x_msel & sel_r0;
assign depend_m1_chk_a  = x_reg & x_msel & sel_r1;
assign depend_m2_chk_a  = x_reg & x_msel & sel_r2;
assign depend_m3_chk_a  = x_reg & x_msel & sel_r3;
assign depend_xdpp_chk_a = ldsa1 | stsa1;
assign depend_swsp_chk_a = push | pop;
assign depend_rl4_chk_a = y_reg & sel_r4;
assign depend_rl5_chk_a = y_reg & sel_r5;
assign depend_rl6_chk_a = y_reg & sel_r6;
assign depend_rl7_chk_a = y_reg & sel_r7;
assign depend_m4_chk_a  = y_reg & y_msel & sel_r4;
assign depend_m5_chk_a  = y_reg & y_msel & sel_r5;
assign depend_m6_chk_a  = y_reg & y_msel & sel_r6;
assign depend_m7_chk_a  = y_reg & y_msel & sel_r7;
assign depend_ydpp_chk_a = ldsa2 | stsa2;
assign rlm_depend_chk = {depend_ydpp_chk_a, depend_xdpp_chk_a, depend_swsp_chk_a, 
                         depend_m7_chk_a, depend_m6_chk_a, depend_m5_chk_a, depend_m4_chk_a,
                         depend_m3_chk_a, depend_m2_chk_a, depend_m1_chk_a, depend_m0_chk_a,
                         depend_rl7_chk_a, depend_rl6_chk_a, depend_rl5_chk_a, depend_rl4_chk_a,
                         depend_rl3_chk_a, depend_rl2_chk_a, depend_rl1_chk_a, depend_rl0_chk_a};
                         
                         
//#######################################################
assign ir = {32{~null_ir}} & {ir1, ir0};

endmodule           
