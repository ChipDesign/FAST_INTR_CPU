`include "top.v"
`include "definitions.vh"
module top_tb ();


  reg clk,resetn;
  integer index, counter;
  
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
      /* $readmemh("registerFile.txt", top_instance.pipelineIDInstance.registerFile,0,15); */
    end

    if(counter===20)begin
      $finish();
    end

    counter+=1;
  end

  initial begin
    $dumpfile("top_tb.vcd");
    $dumpvars(0, top_tb);
    
  for(index=0;index<32;index++)begin
    $dumpvars(0, top_instance.pipelineIDInstance.registerFile[index]);
  end
  end

  // initial I_Memory
  initial begin
    $readmemh("i-memory.txt", top_instance.pipelineIFInstance.sramInstance.m_array,0,1);
    $readmemh("registerFile.txt", top_instance.pipelineIDInstance.registerFile,0,15);
  end

  top top_instance(
    .clk(clk),
    .resetn(resetn)
  );
endmodule
