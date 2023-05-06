`ifndef __PIPELINEIF__
`define __PIPELINEIF__
`include "sram_1p_32x816.v"
module pipelineIF
(
    input wire        clk,
    input wire        resetn,
    input wire        enable,
    /* redirectionPC from static branch predictor in ID stage */
    input wire [31:0] redirectionD_i,
    input wire        takenD_i,
    // TODO: add redirectionPC from EXE stage

    /* output signals to ID stage */
    output reg [31:0] instructionF_o,
    output reg [31:0] pcPlus4F_o
);

    // =========================================================================
    // ============================== variables ================================
    // =========================================================================
    wire [9:0] SramAddr; // Address to access 32x816 sram
    wire CEB, WEB;
    wire [31:0] SramOutput;
    reg  [31:0] currentPC;


    // =========================================================================
    // ============================ implementation =============================
    // =========================================================================
    always@(posedge clk)begin
        // IF pipeline register output 
        if(~resetn)begin
            currentPC      <= 32'h0; // init pc to start at 0x00000000
            instructionF_o <= 32'h0;
            pcPlus4F_o     <= 32'h0;
        end
        else if(enable) begin 
            instructionF_o <= SramOutput; // read instruction from I-Memory
            pcPlus4F_o     <= currentPC + 32'h4;
            // calculate next pc, pc will stall if not enable
            if(takenD_i) begin
                currentPC <= redirectionD_i;    
            end
            else begin
                currentPC <= currentPC + 32'h4;    
            end
        end
    end

    // instruction memory instance
    assign WEB = 1; // only read from I-Memory
    assign CEB = 0;
    assign SramAddr = currentPC[11:2];

    sram_1p_32x816 sramInstance(
        .CLK(clk),
        .CEB(CEB),
        .WEB(WEB),
        .A(SramAddr),
        .D(32'h0), // I-Memory will not be write into, we only read from I-Memory
        .Q(SramOutput)
    );
endmodule
`endif
