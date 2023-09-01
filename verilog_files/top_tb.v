`include "top.v"
`include "definitions.vh"
`define ITCM_DEPTH 1024
`define MEM_BANK0 u_top.u_pipeline_withFIFO.u_imemory.u_memory_block0.m_array
`define MEM_BANK1 u_top.u_pipeline_withFIFO.u_imemory.u_memory_block1.m_array

module top_tb ();


    reg clk,resetn;
    wire x3;
    integer index, counter;
    reg [7:0] itcm_mem [`ITCM_DEPTH*4-1:0]; // itcm in testbench
    integer i;
    reg [127:0] test;

    // get x3 value
    assign x3 = u_top.u_pipelineID.u_regfile.regfile_data[3];

    // generate clock
    initial begin
        clk<=0;
        counter <= 0;
        test<= 128'b0;
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
        if(counter==2)begin
            /* $readmemh("registerFile.txt", u_top.pipelineIDInstance.registerFile,0,15); */
        end
        // check test results
        if(counter == 20) begin
            if (x3 == 1) begin
                $display("~~~~~~~~~~~~~~~~ TEST_PASS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #####     ##     ####    #### ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #    #   #  #   #       #     ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #    #  #    #   ####    #### ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #####   ######       #       #~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #       #    #  #    #  #    #~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~ #       #    #   ####    #### ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            end
            else begin
                $display("~~~~~~~~~~~~~~~~ TEST_FAIL ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~######    ##       #    #     ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~#        #  #      #    #     ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~#####   #    #     #    #     ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~#       ######     #    #     ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~#       #    #     #    #     ~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~#       #    #     #    ######~~~~~~~~~~~~~~~~");
                $display("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
            end
        end
        //interrupt signal generate TODO: maybe put other place later
        if(counter==42)begin
            test<=128'h6;
        end
        if(counter==43)begin
            test<=128'h0;
        end
        if(counter==100)begin
            $finish();
        end

        $display("counter = %h", counter);
        $display("x3= %h", x3);
        counter+=1;
    end

    integer k,l;
    initial begin
        $dumpfile("top_tb.vcd");
        $dumpvars(0, top_tb);

        for(k=0;k<12;k++)begin
            $dumpvars(0 , itcm_mem[k]);
            $dumpvars(0 , `MEM_BANK0[k]);
            $dumpvars(0 , `MEM_BANK1[k]);
        end
        /*for(l=0;l<32;l++)
        begin
            $dumpvars(0, u_top.u_pipelineID.u_regfile.regfile_data[i]);
        end*/
    end

  // initial I_Memory
    initial begin
        $readmemh({"i-memory.txt"}, itcm_mem);
                u_top.u_pipeline_withFIFO.u_imemory.u_memory_block0.m_array[0][ 7:0]=itcm_mem[0];
                u_top.u_pipeline_withFIFO.u_imemory.u_memory_block0.m_array[0][15:8]=itcm_mem[1];
                for(i=0;i<`ITCM_DEPTH;i++)begin
                    `MEM_BANK0[i][15:8]=itcm_mem[i*4+3];
                    `MEM_BANK0[i][ 7:0]=itcm_mem[i*4+2];
                    `MEM_BANK1[i][15:8]=itcm_mem[i*4+1];
                    `MEM_BANK1[i][ 7:0]=itcm_mem[i*4+0]; 
                end
    end

    // MCU top instance
    top u_top(
        //ports
        .clk    		( clk    		),
        .resetn 		( resetn 		),
        .test_input_intr_bundle (test)
    );

endmodule
