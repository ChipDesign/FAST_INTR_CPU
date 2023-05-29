`include "sram_1p_32x816.v"
module sram_1p_32x816_tb();

reg CLK, CEB, WEB;
reg [9:0] A;
reg [31:0] D;
wire[31:0] Q;


initial begin
  CLK=0;
// generate clock 
  forever begin
    #1 CLK <= ~CLK;
  end
end

initial begin
  CEB<=0; WEB<=0;
  A <= 10'b0;
  D <= 32'b0;
  /* Q <= 32'b0; */
  #1;

  A <= 1;
  D <= 100;
  #2;

  A <= 2;
  #2;

  A <= 1;
  WEB <= 1;
  #10; $finish;

end

sram_1p_32x816 sram_1p_32x816_instance(
  .CLK(CLK),
  .CEB(CEB),
  .WEB(WEB),
  .A(A),
  .D(D),
  .Q(Q)
);

  initial begin
    $dumpfile("sram_1p_32x816_tb.vcd");
    $dumpvars(0, sram_1p_32x816_tb);
  end

endmodule
