`include "top.v"
`include "definitions.vh"
module top_tb ();


    reg clk,resetn;
    wire x3;
    integer index, counter;

    // get x3 value
    assign x3 = u_top.u_pipelineID.u_regfile.regfile_data[3];

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
        if(counter==40)begin
            $finish();
        end

        $display("counter = %h", counter);
        $display("x3= %h", x3);
        counter+=1;
    end

    initial begin
        $dumpfile("top_tb.vcd");
        $dumpvars(0, top_tb);
        for(index=0;index<32;index++)begin
            $dumpvars(0, u_top.u_pipelineID.u_regfile.regfile_data[index]);
        end
    end

  // initial I_Memory
    initial begin
        $readmemh("../asm/generated/i-memory.txt", u_top.u_pipelineIF.sramInstance.m_array);
        // $readmemh("i-memory.txt", u_top.u_pipelineIF.sramInstance.m_array);
        // $readmemh("registerFile.txt", u_top.u_pipelineID.u_regfile.regfile_data,0,15);
    end

    // MCU top instance
    top u_top(
        //ports
        .clk    		( clk    		),
        .resetn 		( resetn 		)
    );

endmodule
