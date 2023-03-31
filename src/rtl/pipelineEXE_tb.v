`include "pipelineEXE.v"
`include "definitions.vh"
module pipelineEXE_tb();

  reg clk,resetn;
  integer i, counter;
  reg [31:0] rs1D;
  reg [31:0] rs2D;
  reg [4:0 ] aluOperationD;
  reg regWriteEnD;
  reg [4:0 ] rdD;
  
  wire [31:0] aluResultE;
  wire regWriteEnE;
  wire [4:0 ] rdE;


  // generate clock
  initial begin
    clk<=0;
    counter <= 0;
    forever begin 
      #1; clk<=~clk;
    end
  end
  
  // begin test
  always@(posedge clk) begin 
    if(counter===0)begin
      resetn <= 0;
    end

    if(counter===1)begin
      resetn <= 1;
    end

    if(counter===2)begin
      aluOperationD <= `ALU_ADD;
      rs1D <= 1;
      rs2D <= 2;
      rdD <= 7;
      regWriteEnD<=1;
    end
    if(counter===3)begin
      aluOperationD <= `ALU_ADD;
      rs1D <= 100;
      rs2D <= 200;
      rdD <= 8;
      regWriteEnD<=0;
    end
    if(counter===4)begin
      aluOperationD <= `ALU_ADD;
      rs1D <= 10;
      rs2D <= 20;
      rdD <= 9;
      regWriteEnD<=1;
    end
    if(counter===5)begin
      aluOperationD <= `ALU_ADD;
      rs1D <= 0;
      rs2D <= 0;
      rdD <= 4;
      regWriteEnD<=0;
    end
    if(counter===10)begin
      $finish();
    end

    counter+=1;
  end

  initial begin
    $dumpfile("pipelineEXE_tb.vcd");
    $dumpvars(0, pipelineEXE_tb);
  end


  pipelineEXE pipelineEXE_instance(
    .clk(clk),
    .resetn(resetn),
    .rs1D(rs1D),
    .rs2D(rs2D),
    .aluOperationD(aluOperationD),
    .regWriteEnD(regWriteEnD),
    .rdD(rdD),
    .aluResultE(aluResultE),
    .regWriteEnE(regWriteEnE),
    .rdE(rdE)
  );
endmodule
