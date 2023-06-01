`ifndef __FIFO5X16__
`define __FIFO5X16__ 
/*
file: fifo between instructions I-Memory and ID stage
  1. store instructions readed from I-Memory
  2. pass instructions to ID stage
  3. calculate instruction address, pass to instruction I-Memory
*/
module fifo5x16 (
    input              clk,
    input              resetn,
    // instructions passed from I-Memory
    input wire  [31:0] mem_data, // instructions read from I-Memory 
    // address passed from later pipeline
    input wire  [31:0] re_addr, // rediction address 
    input wire         taken,   // rediction taken
    input wire  [ 1:0] drain_cnt,   // ID take instruction
    // address pass to I-Memory
    output wire [31:0] mem_addr,  // address passed to I-Memory
    output wire        mem_rq,    // I-Memory read request
    // instructions passed to ID
    output wire [31:0] ir      // 32 bits data passed to ID
);


// =========================================================================
// ============================ variables =============================
// =========================================================================
reg  [15:0] pir2, pir1, pir0, ir1, ir0; // 5*16 fifo
wire [31:0] cur_addr; // current address
reg  [31:0] linear_addr; // linear address, +4 every time
wire [15:0] lead_data, next_data;
reg  [ 2:0] pf_fifo_cnt; // current fifo count
wire [ 2:0] next_fifo_cnt; // next cycle fifo count
reg         fill;          // push into fifo
wire        drain, drain_1, drain_2; // ID takes 16 bits or 32 bits
wire        next_pt2, next_pt3, next_pt4, next_pt5;
wire        pt2, pt3, pt4, pt5;


// =========================================================================
// ============================ implementation =============================
// =========================================================================

// FIFO output to ID
assign ir = {ir1, ir0};

// address calculation
assign cur_addr = (~resetn | taken) ? re_addr : linear_addr;
always @(posedge clk ) begin 
    if(mem_rq) begin
        linear_addr <= cur_addr + 32'h4;
    end
end
assign mem_addr = cur_addr; // I-Memory access address



// I-Memory read request
assign mem_rq = (taken | (next_fifo_cnt <= 3'h3)) & resetn; // request I-Memory read, if next_fifo_cnt <=3 and no reset assert
always @(posedge clk ) begin 
    fill <= mem_rq; // data read out from I-Memory takes 1 cycle 
end

// data concatenation is done by I-Memory
assign lead_data = mem_data[31:16];
assign next_data    = mem_data[15: 0];


// fifo count
assign drain_1 = drain_cnt == 2'h1; // ID takens 16 bits
assign drain_2 = drain_cnt == 2'h2; // ID takens 32 bits
assign drain   = drain_1 | drain_2;

assign next_fifo_cnt = pf_fifo_cnt + ({3{fill}} & 3'h2) 
       - (({3{drain_2}} & 3'h2) | ({3{drain_1}} & 3'h1));
always @(posedge clk) begin 
    if(~resetn | taken) begin
        // set fifo count to 0
        pf_fifo_cnt <= 3'h0;    
    end
    else if(fill | (drain_cnt!=2'h0)) begin
        // update fifo count
        pf_fifo_cnt <= next_fifo_cnt;    
    end
end


assign next_pt2 = (next_fifo_cnt == 3'h2);
assign next_pt3 = (next_fifo_cnt == 3'h3);
assign next_pt4 = (next_fifo_cnt == 3'h4);
assign next_pt5 = (next_fifo_cnt == 3'h5); 

assign pt2 = (pf_fifo_cnt == 3'h2);
assign pt3 = (pf_fifo_cnt == 3'h3);
assign pt4 = (pf_fifo_cnt == 3'h4);
assign pt5 = (pf_fifo_cnt == 3'h5); 

// fifo body
always @(posedge clk) begin 
    // read data from I-Memory
    if(next_pt5 & fill) begin
        pir2 <= next_data;    
    end
end

always @(posedge clk) begin 
    // read data from I-Memory
    if((next_pt5 | next_pt4) & fill) begin
        pir1 <= ({16{next_pt4}} & next_data)|
                ({16{next_pt5}} & lead_data);
    end
    // no read data from I-Memory
    else if(pt5 & drain_1) begin
        pir1 <= pir2;
    end
end


always @(posedge clk) begin 
    // read data from I-Memory
    if((next_pt4 | next_pt3) & fill) begin
        pir0 <= ({16{next_pt3}} & next_data)|
                ({16{next_pt4}} & lead_data);
    end
    // no read data from I-Memory
    else if((pt5 & drain) | (pt4 & drain_1)) begin
        pir0 <= ({16{drain_1}} & pir1)|
                ({16{drain_2}} & pir2);
    end
end

always @(posedge clk) begin 
    // read data from I-Memory
    if((next_pt3 | next_pt2) & fill) begin
        ir1 <= ({16{next_pt2}} & next_data)|
               ({16{next_pt3}} & lead_data);
    end
    // no read data from I-Memory
    else if(((pt5 | pt4) & drain) | (pt3 & drain_1)) begin
        ir1 <= ({16{drain_1}} & pir0)|
               ({16{drain_2}} & pir1);
    end
end

always @(posedge clk ) begin 
    if(~resetn) begin
        ir0 <= 16'h0;    
    end
    // read data from I-Memory
    else if(next_pt2 & fill) begin
        ir0 <= lead_data;    
    end
    // no read data from I-Memory
    else if(((pt5 | pt4 | pt3) & drain) | (pt2 & drain_1)) begin
        ir0 <= ({16{drain_1}} & ir1)|
               ({16{drain_2}} & pir0);
    end
end

endmodule

`endif
