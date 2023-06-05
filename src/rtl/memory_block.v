`ifndef __MEMORYBLOCK__
`define __MEMORYBLOCK__
module memory_block
#(
    parameter DATA_WIDTH = 8
)
(
    input wire clk,        // clock
    input wire resetn,     // reset
    input wire ceb,        // chip enable, if not enable, can't read from this memory
    input wire web,        // write/read, 0 for write, 1 for read
    input wire write_en,     // write enable
    input wire [ 9: 0] A,  // address
    input wire [DATA_WIDTH-1: 0] D,  // data write into memory
    output reg [DATA_WIDTH-1: 0] Q   // data read from memory
);
                               
reg [ DATA_WIDTH-1:0] m_array[1023: 0]; // the memory is 816*32, each line in memory is 32 bits
//-----------------------------

// write data
always @(posedge clk) begin
    if(~web & write_en) 
        m_array[A] <= D;
end 

// read data
always @(posedge clk) begin
    if(~resetn) begin
        Q <= 8'h0;    
    end
    else if(~ceb & web) begin
        Q <= m_array[A];
    end
end 

endmodule
`endif
