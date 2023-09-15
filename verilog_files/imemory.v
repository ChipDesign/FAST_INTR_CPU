`ifndef __IMEMORY__
`define __IMEMORY__
`include "memory_block.v"
/*
file:   Data Memory in MEM Stage 
author: fujie
time:   Fri May 26 09:22:03 CST 2023
*/
module imemory( 
    input  wire clk, 
    input  wire resetn,
    input  wire ceb,         // chip enable, if not enable, can't read from this memory 
    input  wire web,         // write/read, 0 for write, 1 for read
    input  wire [ 9:0] A,    // A for address 
    output wire [31:0] Q     // data read from memory  
    );


    wire [15: 0] write0, write1;
    wire [15: 0] read0, read1;
    wire [ 9: 0] left_addr, right_addr;
    wire         aligned; // address 4 byte aligned
    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================
    
    assign aligned    = A[0];
    assign left_addr  = A>>1;
    assign right_addr = left_addr + ({10{aligned}} & 10'h1);

    assign Q = ({32{aligned}}  & {read0, read1})|
               ({32{~aligned}} & {read1, read0});
    
    // I-Memory doesn't need write into
    assign write0 = 16'h0;
    assign write1 = 16'h0;

    memory_block #(.DATA_WIDTH(16)) u_memory_block0(
        //ports
        .clk      		( clk      		),
        .ceb      		( ceb      		),
        .web      		( web      		),
        .write_en 		( 1'b0   		),
        .A        		( left_addr   	),
        .D        		( write0   		),
        .Q        		( read0    		)
    );

    memory_block #(.DATA_WIDTH(16)) u_memory_block1(
        //ports
        .clk      		( clk      		),
        .ceb      		( ceb      		),
        .web      		( web      		),
        .write_en 		( 1'b0   		),
        .A        		( right_addr   	),
        .D        		( write1   		),
        .Q        		( read1    		)
    );

endmodule
`endif
