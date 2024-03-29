`ifndef __SRAM_32x816__
`define __SRAM_32x816__
module sram_1p_32x816 (
               CLK, CEB, WEB, A, D, Q , resetn    
                );
                               
input CLK, CEB, WEB, resetn;
input [9:0] A; // A for address 
input [31:0] D;  // D for data
output [31:0] Q; // Q for data output
//------------------------
reg [31:0] m_array[815:0]; // the memory is 816*32, each line in memory is 32 bits
reg [31:0] Q;
//-----------------------------

// write data
always @(posedge CLK) begin
    if(~WEB) 
        m_array[A] <= D;
end 

// read data
always @(posedge CLK) begin
    if(~resetn) begin
        Q <= 32'h0;    
    end
    else if(~CEB & WEB) begin
        Q <= m_array[A];
    end
end 

endmodule
`endif
