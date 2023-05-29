module hazard(
is_b,is_j,is_load,is_m,is_d,dst_en,
fin,
pre_taken,real_taken,
r_dst,r_src1,r_src2,
src1_sel,src2_sel,
f_cmiss,m_cmiss,
f_arrival,m_arrival,
fd_st,de_st,em_st,mw_st,
flush_fin,j_ignore,wb_ignore,
rstn,clk);

input is_b,is_j,is_load,dst_en,is_m,is_d;
input fin;
input pre_taken,real_taken;
input [4:0] r_dst,r_src1,r_src2;
input f_cmiss,m_cmiss;
input f_arrival,m_arrival;
input rstn,clk;


output[1:0] src1_sel,src2_sel;
output fd_st,de_st,em_st,mw_st;
output flush_fin,j_ignore,wb_ignore;


reg[4:0] dst_1,dst_2;
reg ld_dst1,ld_dst2;
wire Icmiss_st,Dcmiss_st,Linst_st,Ldhaz_st;
reg Icmiss_st_keep,Dcmiss_st_keep,Linst_st_keep;


reg jd1,jd2,jd3;//when jump instruction is decode, the state machine of flush control.
reg bpt,bptrt,bptnt,bptrt1,bptnt1,bptrt2,bptnt2,bptnt3;
reg bnt,bnt1,bnt2,bnt3,bnt4;

wire jump_ignore;
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
    dst_1<=r_dst&{5{dst_en}};
    dst_2<=dst_1;
    ld_dst1<=is_load;
    ld_dst2<=ld_dst1;
  end  

end

assign src1_sel[0]=(~(r_src1==0))&(dst_1==r_src1)&(~jd1)&(~bptrt)&(~bptnt1)&(~bnt1)&(~bnt2);
assign src1_sel[1]=(~(r_src2==0))&(~(dst_1==dst_2))&(dst_2==r_src1)&(~jd2)&(~bptrt1)&(~bptnt2)&(~bnt2)&(~bnt3);
assign src2_sel[0]=(~(r_src1==0))&(dst_1==r_src2)&(~jd1)&(~bptrt)&(~bptnt1)&(~bnt1)&(~bnt2);
assign src2_sel[1]=(~(r_src2==0))&(~(dst_1==dst_2))&(dst_2==r_src2)&(~jd2)&(~bptrt1)&(~bptnt2)&(~bnt2)&(~bnt3);

//stall

assign Ldhaz_st= ld_dst1&((dst_1==r_src1)|(dst_1==r_src2));
assign Icmiss_st=~f_arrival&(f_cmiss|Icmiss_st_keep);
assign Dcmiss_st=~m_arrival&(m_cmiss|Dcmiss_st_keep);
assign Linst_st=~(flush_fin|fin)&(is_d|is_m|Linst_st_keep);

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
  
  
    if(is_d|is_m)
    begin
      Linst_st_keep<=1'b1;
    end
    else if(flush_fin|fin)
    begin
      Linst_st_keep<=1'b0;
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
    jd3<=1'b0;
    bpt<=1'b0;
    bptrt<=1'b0;
    bptnt<=1'b0;
    bptrt1<=1'b0;
    bptnt1<=1'b0;
    bptrt2<=1'b0;
    bptnt2<=1'b0;
    bptnt3<=1'b0;
    bnt<=1'b0;
    bnt1<=1'b0;
    bnt2<=1'b0;
    bnt3<=1'b0;
    bnt4<=1'b0;
  end
  else
  begin
    if(is_j&(~jump_ignore))// if jump-1 is also a jump, ingore latter one
    begin
      jd1<=1'b1;
    end
    else if(is_b&(~jump_ignore))
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
    end
  
    jd2<=jd1;
    jd3<=jd2;

    
    
    bptrt<=bpt&real_taken;
    bptnt<=bpt&~real_taken;
    bptrt1<=bptrt;
    bptnt1<=bptnt;
    bptrt2<=bptrt1;
    bptnt2<=bptnt1;
    bptnt3<=bptnt2;
    

    bnt1<=bnt&real_taken;
    bnt2<=bnt1;
    bnt3<=bnt2;
    bnt4<=bnt3;

    
    
    
    end
  
  
end


assign flush_fin=jd1|bptrt|bptnt1|bnt1|bnt2;
assign wb_ignore=jd3|bptrt2|bptnt3|bnt3|bnt4;
assign jump_ignore=jd1|bptnt|(bpt&real_taken)|bnt1|(bnt&real_taken);


endmodule
