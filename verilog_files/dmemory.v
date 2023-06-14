`ifndef __DMEMORY__
`define __DMEMORY__
`include "memory_block.v"
/*
file:   Data Memory in MEM Stage 
author: fujie
time:   Fri May 26 09:22:03 CST 2023
*/
module dmemory( 
    input  wire clk, 
    input  wire resetn,
    input  wire ceb,         // chip enable, if not enable, can't read from this memory 
    input  wire web,         // write/read, 0 for write, 1 for read
    input  wire [ 9:0] A,    // A for address 
    input  wire [ 3:0] mask, // write mask
    input  wire [31:0] D,    // data write into memory 
    output wire [31:0] Q     // data read from memory  
    );


    wire [ 7: 0] read0, read1, read2, read3;
    wire [ 7: 0] write0, write1, write2, write3;
    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================
    
    assign write0 = D[ 7: 0];
    assign write1 = D[15: 8];
    assign write2 = D[23:16];
    assign write3 = D[31:24];
    assign Q = {read3, read2, read1, read0};

    memory_block u_memory_block0(
        //ports
        .clk      		( clk      		),
        .resetn   		( resetn   		),
        .ceb      		( ceb      		),
        .web      		( web      		),
        .write_en 		( mask[0] 		),
        .A        		( A        		),
        .D        		( write0   		),
        .Q        		( read0    		)
    );

    memory_block u_memory_block1(
        //ports
        .clk      		( clk      		),
        .resetn   		( resetn   		),
        .ceb      		( ceb      		),
        .web      		( web      		),
        .write_en 		( mask[1] 		),
        .A        		( A        		),
        .D        		( write1   		),
        .Q        		( read1    		)
    );

    memory_block u_memory_block2(
        //ports
        .clk      		( clk      		),
        .resetn   		( resetn   		),
        .ceb      		( ceb      		),
        .web      		( web      		),
        .write_en 		( mask[2] 		),
        .A        		( A        		),
        .D        		( write2   		),
        .Q        		( read2    		)
    );

    memory_block u_memory_block3(
        //ports
        .clk      		( clk      		),
        .resetn   		( resetn   		),
        .ceb      		( ceb      		),
        .web      		( web      		),
        .write_en 		( mask[3] 		),
        .A        		( A        		),
        .D        		( write3   		),
        .Q        		( read3    		)
    );

    
endmodule
`endif
