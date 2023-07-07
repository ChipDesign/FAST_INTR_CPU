`ifndef __PIPELINEIFWITHFIFO__
`define __PIPELINEIFWITHFIFO__
// `include "imemory.v"
// `include "fifo5x16.v"
`include "temp_sram.v"
module pipelineIF_withFIFO
(
    input wire        clk,
    input wire        resetn,
    input wire        enable, // if not enable, stall pipeline
    /* redirectionPC from static branch predictor in ID stage */
    input wire [31:0] redirection_d_i,
    input wire        taken_d_i,
    input wire        is_compress_d_i, // 16 bits or 32 bits
    input             flush_i,

    /* output signals to ID stage */
    output wire [31:0] instruction_f_o,
    output wire [63:0] top_ins
);
    // 1 bank implementation
    wire [63:0] ins;
    reg  [31:0] addr;

    always @(posedge clk) begin
        if(~resetn)begin
            addr <= 32'h80000000;
            // addr <= 32'h80000004;
        end 
        else if(taken_d_i) begin
            addr <= redirection_d_i;
            // addr <= addr+32'h4;
            // addr <= 32'h8000000c;
        end 
        else begin
            addr <= addr+32'h4;
            // addr <= 32'h8000000c;
        end
    end 

    assign instruction_f_o = ins[31:0];
    // assign top_ins         = {32'h0, ins};
    assign top_ins         = ins;
    temp_sram u_temp_sram(
        .clk(clk),
        .addr(addr),
        .instr(ins)
    );

//   input clk,
    // // =========================================================================
    // // ============================== variables ================================
    // // =========================================================================
    // // I-Memory variables
    // wire [9:0] sram_addr; // Address to access 32x816 sram
    // wire ceb, web;
    // wire [31:0] sram_output;
    // // FIFO variables
    // wire [31:0] mem_addr;
    // wire [31:0] re_addr;
    // wire [31:0] ir;
    // wire        taken;
    // reg         resetn_delay1, resetn_delay2;
    // reg         taken_d_delay1;
    // wire [ 1:0] drain_cnt;
    // wire        instru_valid;

    // // =========================================================================
    // // ============================ implementation =============================
    // // =========================================================================

    // always @(posedge clk ) begin 
    //     resetn_delay1  <= resetn;
    //     resetn_delay2  <= resetn_delay1;
    //     taken_d_delay1 <= taken_d_i;
    // end


    // // if flush, output instruction is NOP(0x00000013)
    // // assign instru_valid = ~resetn | ~resetn_delay1 | ~resetn_delay2 | flush_i;
    // assign instru_valid = resetn & resetn_delay1 & resetn_delay2 & ~flush_i;
    // assign instruction_f_o = ({32{~instru_valid}} & 32'h13)|
    //                          ({32{instru_valid}} & ir);

    // // instruction memory instance
    // assign web = 1; // only read from I-Memory
    // assign sram_addr = mem_addr[10:1];

    // assign taken = taken_d_i;

    // assign re_addr = redirection_d_i;

    // // if not enable, to redirection pc, don't read from FIFO
    // assign drain_cnt = ({2{enable & resetn & resetn_delay1 & resetn_delay2 & ~taken_d_delay1}}) & 
    //                    (({2{is_compress_d_i}} & 2'b01)|({2{~is_compress_d_i}}&2'b10));

    // // I-Memory instance
    // imemory u_imemory(
    //     //ports
    //     .clk    		( clk    		),
    //     .resetn 		( resetn 		),
    //     .ceb    		( ~ceb    		),
    //     .web    		( web    		),
    //     .A      		( sram_addr  	),
    //     .Q      		( sram_output  	)
    // );

    // // 5x16 FIFO instance
    // // TODO: add flush in FIFO
    // fifo5x16 u_fifo5x16(
    //     //ports
    //     .clk       		( clk       		),
    //     .resetn    		( resetn    		),
    //     .mem_data  		( sram_output  		),
    //     .re_addr   		( re_addr   		),
    //     .taken     		( taken     		),
    //     .drain_cnt 		( drain_cnt 		),
    //     .mem_addr  		( mem_addr  		),
    //     .mem_rq    		( ceb        		),
    //     .ir        		( ir            	)
    // );
endmodule
`endif
