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
    input wire [31:0] redirection_e_i,
    input wire        taken_e_i,

    /* output signals to ID stage */
    output reg [31:0] instruction_f_o,
    output reg [31:0] pc_plus4_f_o,
    output reg [31:0] pc_f_o
);

    // =========================================================================
    // ============================== variables ================================
    // =========================================================================
    wire [9:0] sram_addr; // Address to access 32x816 sram
    wire CEB, WEB;
    wire [31:0] sram_output;
    reg  [31:0] pc_register;
    reg  [31:0] pc_delay;
    reg  [31:0] pc_plus_delay;
    wire [31:0] pc_mux;


    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================
    // output IF stage to ID stage
    always@(posedge clk)begin
        // IF pipeline register output 
        if(~resetn)begin
            pc_register     <= 32'h0; // init pc to start at 0x00000000
            // pc_plus4_f_o    <= 32'h4;
            pc_plus_delay   <= 32'h4;
            pc_delay        <= 32'h0;
            pc_plus4_f_o    <= 32'h4;
            pc_f_o          <= 32'h0;
            instruction_f_o <= 32'h0;
        end
        else if(enable) begin 
            // instruction_f_o <= sram_output; // read instruction from I-Memory
            pc_register     <= pc_mux + 32'h4;
            pc_delay        <= pc_mux; // delay pc for 1 cycle, so pc and instruction can match
            pc_plus_delay   <= pc_mux + 32'h4;
            pc_f_o          <= pc_delay;
            pc_plus4_f_o    <= pc_plus_delay;
            instruction_f_o <= sram_output;
        end
    end
    assign pc_mux = (taken_e_i == 1'b1) ? redirection_e_i:
                    (taken_d_i == 1'b1) ? redirection_d_i : pc_register; 

    // assign instruction_f_o = sram_output; // I-Memory has 1 cycle delay already

    // instruction memory instance
    assign WEB = 1; // only read from I-Memory
    assign CEB = 0;
    assign sram_addr = pc_mux[11:2];

    sram_1p_32x816 sramInstance(
        .CLK(clk),
        .CEB(CEB),
        .WEB(WEB),
        .A(sram_addr),
        .D(32'h0), // I-Memory will not be write into, we only read from I-Memory
        .Q(sram_output),
        .resetn(resetn)
    );
endmodule
`endif
