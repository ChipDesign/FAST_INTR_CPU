`include "pipelineID.v"
module pipelineID_tb();

  reg clk,resetn;
  integer i, counter;


  reg [31:0] instructionD;
  reg regWriteEnW;
  reg [4:0] rdW;
  reg [31:0] writeBackDataW;

  wire [4:0] aluOperationD;
  wire [31:0] rs1D;
  wire [31:0] rs2D;
  wire regWriteEnD;
  wire [4:0] rdD;

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
    if(counter==0)begin
      resetn <= 0;
    end

    if(counter==1)begin
      resetn <= 1;
    end


    /* if(counter==2)begin */
    /*   instructionD <= 32'h00100293; */
    /* end */
    /* if(counter==3)begin */
    /*   instructionD <= 32'h00200313; */
    /* end */
    /* if(counter==4)begin */
    /*   instructionD <= 32'h006283b3; */
    /* end */
    /* if(counter==5)begin */
    /*   instructionD <= 32'h406283b3; */
    /* end */

    if(counter==2)begin
      instructionD <= 32'h00000000;
    end
    if(counter==3)begin
      instructionD <= 32'h00000001;
    end
    if(counter==4)begin
      instructionD <= 32'h00000002;
    end
    if(counter==5)begin
      instructionD <= 32'h00000003;
    end

    if(counter==10)begin
      $finish();
    end

    counter+=1;
  end

  initial begin
    $dumpfile("pipelineID_tb.vcd");
    $dumpvars(0, pipelineID_tb);
  end


  pipelineID pipelineID_instance(
    .clk(clk),
    .resetn(resetn),
    .instructionD(instructionD),
    .regWriteEnW(regWriteEnW),
    .rdW(rdW),
    .writeBackDataW(writeBackDataW),
    .aluOperationD(aluOperationD),
    .rs1D(rs1D),
    .rs2D(rs2D),
    .regWriteEnD(regWriteEnD),
    .rdD(rdD)
  );
endmodule
