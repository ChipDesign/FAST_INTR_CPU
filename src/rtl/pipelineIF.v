`ifndef __PIPELINEIF__
`define __PIPELINEIF__
`include "sram_1p_32x816.v"
module pipelineIF
(
    input wire        clk,
    input wire        resetn,
    input wire        enable,
    /* redirectionPC from static branch predictor in ID stage */
    input wire [31:0] redirection_d_i,
    input wire        taken_d_i,
    // TODO: add redirectionPC from EXE stage

    /* output signals to ID stage */
    output wire [31:0] instruction_f_o,
    output reg  [31:0] pc_plus4_f_o,
    output reg  [31:0] pc_f_o
);

    // =========================================================================
    // ============================== variables ================================
    // =========================================================================
    wire [9:0] sram_addr; // Address to access 32x816 sram
    wire CEB, WEB;
    wire [31:0] sram_output;
    reg  [31:0] current_pc;


    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================
    always@(posedge clk)begin
        // IF pipeline register output 
        if(~resetn)begin
            current_pc    <= 32'h0; // init pc to start at 0x00000000
            // instruction_f_o <= 32'h0;
            pc_plus4_f_o  <= 32'h0;
        end
        else if(enable) begin 
            // instruction_f_o <= sram_output; // read instruction from I-Memory
            pc_plus4_f_o   <= current_pc + 32'h4;
            pc_f_o         <= current_pc;
            // calculate next pc, pc will stall if not enable
            if(taken_d_i) begin
                current_pc <= redirection_d_i;    
            end
            else begin
                current_pc <= current_pc + 32'h4;    
            end
        end
    end

    assign instruction_f_o = sram_output; // I-Memory has 1 cycle delay already

    // instruction memory instance
    assign WEB = 1; // only read from I-Memory
    assign CEB = 0;
    assign sram_addr = current_pc[11:2];

    sram_1p_32x816 sramInstance(
        .CLK(clk),
        .CEB(CEB),
        .WEB(WEB),
        .A(sram_addr),
        .D(32'h0), // I-Memory will not be write into, we only read from I-Memory
        .Q(sram_output)
    );
endmodule
`endif
