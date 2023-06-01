`include "fifo5x16.v"
module fifo5x16_tb();
reg          clk, resetn; 
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
        resetn    <= 1'b0;
        taken     <= 1'h0;
        drain_cnt <= 2'h0;
    end
    if(count == 1) begin
        resetn   <= 1'b1;
        taken    <= 1'b1; // get first address
        re_addr  <= 32'h0;
    end
    if(count == 2) begin
        taken    <= 1'b0; 
        mem_data <= 32'h11111111;
    end
    if(count == 3) begin
        drain_cnt <= 2'h2;
        mem_data <= 32'h22222222;
    end
    if(count == 4) begin
        drain_cnt <= 2'h1;
        mem_data <= 32'h33333333;
    end
    if(count == 5) begin
        drain_cnt <= 2'h0;
        mem_data <= 32'h44444444;
    end
    
    if(count == 20)
        $finish(0);
    count = count +1;
end

// =========================================================================
// ============================ testing =============================
// =========================================================================
wire [31:0]	mem_addr;
wire 	    mem_rq;
wire [31:0]	ir;
reg  [31:0] mem_data;
reg  [31:0] re_addr;
reg         taken;
reg  [ 1:0] drain_cnt;

fifo5x16 u_fifo5x16(
    //ports
    .clk       		( clk       		),
    .resetn    		( resetn    		),
    .mem_data  		( mem_data  		),
    .re_addr   		( re_addr   		),
    .taken     		( taken     		),
    .drain_cnt 		( drain_cnt 		),
    .mem_addr  		( mem_addr  		),
    .mem_rq    		( mem_rq    		),
    .ir        		( ir        		)
);

// generate waveforms
initial begin
  $dumpfile("myFIFO_tb.vcd");
  $dumpvars(0, myFIFO_tb);
end
endmodule
