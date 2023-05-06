`include "pipelineIF.v"

module pipelineIF_tb();

  reg clk,resetn;
  wire [31:0] instructionF;

  integer i, counter;

  /* initial begin */
  /*   for(i=0;i<16;i++)begin */
  /*     memory[i]=i; */
  /*   end */
/*     $writememh("i-memory.txt", memory); */
  /* end */


  // initial I_Memory
  initial begin
    // 给内部数组m_array赋值，赋值范围为m_array第0行到第15行
    $readmemh("i-memory.txt", pipelineIFInstance.sramInstance.m_array,0,15);
    /* for(i=0;i<16;i++)begin */
    /*   $display("dut line %d data is %h",i,pipelineIFInstance.sramInstance.m_array[i]); */
    /* end */
  end

  // generate clock
  initial begin
    clk<=0;
    counter <= 0;
    forever begin 
      #1; clk<=~clk;
    end
  end

  always@(posedge clk) begin 
    if(counter==0)begin
      resetn <= 0;
    end

    if(counter==1)begin
      resetn <= 1;
    end


    if(counter==10)begin
      $finish();
    end

    counter+=1;
  end
  
  

  initial begin
    $dumpfile("pipelineIF_tb.vcd");
    $dumpvars(0, pipelineIF_tb);
    for(i=0;i<16;i++)
      $dumpvars(0, pipelineIFInstance.sramInstance.m_array[i]);
  end

  pipelineIF pipelineIFInstance(
    .clk(clk),
    .resetn(resetn),
    .instructionF(instructionF)
  );

endmodule
