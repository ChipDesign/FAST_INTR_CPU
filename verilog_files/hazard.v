`ifndef __HAZARD__
`define __HAZARD__
module hazard(
is_b,is_j,is_load,is_m,is_d,dst_en,
fin,
pre_taken,real_taken,
r_dst,r_src1,r_src2,
src1_sel,src2_sel,
f_cmiss,m_cmiss,
f_arrival,m_arrival,
fd_st,de_st,em_st,
flush_o,
rs1_depended_h_o,ptnt_e_i,
rstn,clk);

input is_b,is_j,is_load,dst_en,is_m,is_d;
input fin;
input pre_taken,real_taken;
input [4:0] r_dst,r_src1,r_src2;
input f_cmiss,m_cmiss;
input f_arrival,m_arrival;
input rstn,clk;


output[1:0] src1_sel,src2_sel;
output fd_st,de_st,em_st;
output flush_o;
output rs1_depended_h_o;
output ptnt_e_i;


reg[4:0] dst_1,dst_2;
reg ld_dst1,ld_dst2;
wire Icmiss_st,Dcmiss_st,Linst_st,Ldhaz_st;
reg Icmiss_st_keep,Dcmiss_st_keep,Linst_st_keep;


reg jd1,jd2,jd_b1,jd_b2,jd_b3;//when jump instruction is decode, the state machine of flush control.
reg bpt,bptrt,bptnt,bptnt1;
reg bnt,bnt1,bnt2;

wire flush;
always@(posedge clk)//bypass
begin

  if(~rstn)
  begin 
    dst_1<=5'b0;
    dst_2<=5'b0;
    ld_dst1<=1'b0;
    ld_dst2<=1'b0;
  end
  else
  begin
    dst_1<=r_dst&{5{dst_en&~(flush)}};
    dst_2<=dst_1;
    ld_dst1<=is_load;
    ld_dst2<=ld_dst1;
  end  

end

assign src1_sel[0]=(~(r_src1==0))&(dst_1==r_src1);
assign src1_sel[1]=(~(r_src1==0))&(~(dst_1==dst_2))&(dst_2==r_src1);
assign src2_sel[0]=(~(r_src2==0))&(dst_1==r_src2);
assign src2_sel[1]=(~(r_src2==0))&(~(dst_1==dst_2))&(dst_2==r_src2);

//stall

assign Ldhaz_st= ld_dst1&((dst_1==r_src1)|(dst_1==r_src2));
assign Icmiss_st=~f_arrival&(f_cmiss|Icmiss_st_keep);
assign Dcmiss_st=~m_arrival&(m_cmiss|Dcmiss_st_keep);
assign Linst_st=~(fin|flush)&(is_d|is_m|Linst_st_keep);

always@(posedge clk)
begin
  if(~rstn)
  begin
    Icmiss_st_keep<=1'b0;
    Dcmiss_st_keep<=1'b0;
    Linst_st_keep<=1'b0;

  end
  else
  begin
  
  
    if(fin)
    begin
      Linst_st_keep<=1'b0;
    end
    else if((~flush)&(is_d|is_m))
    begin
      Linst_st_keep<=1'b1;
    end
    
    
    if(f_cmiss)
    begin
      Icmiss_st_keep<=1'b1;
    end
    else if(f_arrival)
    begin
      Icmiss_st_keep<=1'b0;
    end
    
    
    if(m_cmiss)
    begin
      Dcmiss_st_keep<=1'b1;
    end
    else if(m_arrival)
    begin
      Dcmiss_st_keep<=1'b0;
    end
  end 
end



assign fd_st=Linst_st|Icmiss_st|Dcmiss_st|Ldhaz_st;
assign de_st=Ldhaz_st|Dcmiss_st;
assign em_st=Dcmiss_st;



//flush
always@(posedge clk)
begin
  if(~rstn)
  begin
    jd1<=1'b0;
    jd2<=1'b0;
    jd_b1<=1'b0;
    jd_b2<=1'b0;
    jd_b3<=1'b0;
    bpt<=1'b0;
    bptrt<=1'b0;
    bptnt<=1'b0;
    bptnt1<=1'b0;
    bnt<=1'b0;
    bnt1<=1'b0;
    bnt2<=1'b0;
  end
  else
  begin
    if(is_j&(~flush))// if jump-1 is also a jump, ingore latter one
    begin
      jd1<=1'b1;
      jd_b1<=(|src1_sel[1:0])|(|src2_sel[1:0]);
    end
    else if(is_b&(~flush))
    begin
      if(pre_taken)
      begin
        bpt<=1'b1;
      end
      else
        bnt<=1'b1;
      begin
      end
    end
    else
    begin
      jd1<=1'b0;
      bpt<=1'b0;
      bnt<=1'b0;
      jd_b1<=1'b0;
    end
  
    jd2<=jd1;
    jd_b2<=jd_b1;
    jd_b3<=jd_b2;

    
    
    bptrt<=bpt&real_taken;
    bptnt<=bpt&~real_taken;
    bptnt1<=bptnt;

    

    bnt1<=bnt&real_taken;
    bnt2<=bnt1;

    
    
    
    end
  
  
end



assign flush=jd1|jd_b2|bptnt|(bpt&real_taken)|bnt1|(bnt&real_taken);
assign flush_o=flush;
assign rs1_depended_h_o=|src1_sel;
assign ptnt_e_i=bpt&~real_taken;

endmodule
`endif
