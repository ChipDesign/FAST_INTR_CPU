`include "dmemory.v"
module dmemory_tb(
    
);
    reg          clk, resetn; 
    reg          ceb, web;
    reg  [ 9: 0] A;
    reg  [ 3: 0] mask;
    reg  [31: 0] D;
    wire [31: 0] Q;

    integer count;

    // periodic time
    initial begin
        clk<=0;
        count<=0;
        forever begin 
          #1; clk<=~clk;
        end
    end

    always @(posedge clk ) begin 

        if(count == 0) begin
            resetn <= 1'b0;
        end
        if(count == 1) begin
            resetn <= 1'b1;
        end
        if(count == 2) begin
            ceb  <= 1'b0;
            web  <= 1'b0; // write
            A    <= 10'h0;
            mask <= 4'b1111;
            D    <= 32'h12341234;
        end
        if(count == 3) begin
            ceb  <= 1'b0;
            web  <= 1'b1; // read 
            A    <= 10'h0;
        end
        if(count == 4) begin
            ceb  <= 1'b0;
            web  <= 1'b0; // stop reading
            A    <= 10'h0;
        end
        if(count == 5) begin
            ceb  <= 1'b0;
            web  <= 1'b0; // write with mask
            A    <= 10'h1;
            mask <= 4'b0011;
            D    <= 32'h12345678;
        end
        if(count == 6) begin
            ceb  <= 1'b0;
            web  <= 1'b1; // read 
            A    <= 10'h1;
        end
        if(count == 7) begin
            ceb  <= 1'b0;
            web  <= 1'b0; // write with mask
            A    <= 10'h1;
            mask <= 4'b1110;
            D    <= 32'hffffffff;
        end
        if(count == 8) begin
            ceb  <= 1'b0;
            web  <= 1'b1; // read 
            A    <= 10'h1;
        end
        
        if(count == 20)
            $finish(0);
        count = count +1;
    end

    // =========================================================================
    // ============================ testing =============================
    // =========================================================================
    dmemory u_dmemory(
        //ports
        .clk    		( clk    		),
        .resetn 		( resetn 		),
        .ceb    		( ceb    		),
        .web    		( web    		),
        .A      		( A      		),
        .mask   		( mask   		),
        .D      		( D      		),
        .Q      		( Q      		)
    );

    // generate waveforms
    initial begin
      $dumpfile("dmemory_tb.vcd");
      $dumpvars(0, dmemory_tb);
      $dumpvars(0, u_dmemory.u_memory_block0.m_array[0]);
    end
endmodule
