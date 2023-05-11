`include "hazard.v"
`timescale 1ns/1ns
module hazard_tb();

reg is_b,is_j,is_load,dst_en,is_m,is_d;
reg fin;
reg pre_taken,real_taken;
reg [4:0] r_dst,r_src1,r_src2;
reg f_cmiss,m_cmiss;
reg f_arrival,m_arrival;
reg clk,rstn;
initial begin
  
  clk<=1'b0;
  is_b<=0;
  is_j<=0;
  is_load<=0;
  dst_en<=0;
  is_m<=0;
  is_d<=0;
  fin<=0;
  pre_taken<=0;
  real_taken<=0;
  r_dst<=0;
  r_src1<=0;
  r_src2<=0;
  f_cmiss<=0;
  m_cmiss<=0;
  f_arrival<=0;
  m_arrival<=0;
  

  $dumpfile("hazard.vcd");
  $dumpvars(0,hazard_tb);
  #5 rstn<=1'b0;
  #50 rstn<=1'b1;
  #1000
  
  	
  $finish();
end

always begin
  #10
  clk<=~clk;
end

always@(posedge clk)
begin
  if(r_dst==0)
  begin
    r_dst<=3;
  end
  else if(r_dst==3)
  begin
    r_dst<=5;
  end
  else if(r_dst==5)
  begin
    r_dst<=7;
  end
  else 
  begin
    r_dst<=0;
  end
end

always@(posedge clk)
begin
  if(r_dst==0)
  begin
    r_dst<=3;
  end
  else if(r_dst==3)
  begin
    r_dst<=5;
  end
  else if(r_dst==5)
  begin
    r_dst<=7;
  end
  else 
  begin
    r_dst<=0;
  end
end


hazard h1(
	.is_b(is_b),
	.is_j(is_j),
	.is_load(is_load),
	.is_m(is_m),
	.is_d(is_d),
	.dst_en(dst_en),
	.fin(fin),
	.pre_taken(pre_taken),
	.real_taken(real_taken),
	.r_dst(r_dst),
	.r_src1(r_src1),
	.r_src2(r_src2),
	.src1_sel(),
	.src2_sel(),
	.f_cmiss(f_cmiss),
	.m_cmiss(m_cmiss),
	.f_arrival(f_arrival),
	.m_arrival(m_arrival),
	.fd_st(),
	.de_st(),
	.em_st(),
	.mw_st(),
	.flush_fin(),
	.j_ignore(),
	.wb_ignore(),
	.rstn(rstn),
	.clk(clk)
	);

endmodule
