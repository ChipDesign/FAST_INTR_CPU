/*
file: Static Branch Predictor in ID Stage
author: fujie 
time: 2023年 4月26日 星期三 19时04分59秒 CST
*/
`ifndef __STATICBRANCHPREDITOR__
`define __STATICBRANCHPREDITOR__

// `include "definitions.vh"
module staticBranchPredictor(
    input wire bType,  // 6 bType instruction is: beq, bne, bge, geu, glt, gltu => BTFN(bacwarding taken, forwarding not taken)
    input wire isJAL,  // jal instruction  => 100% taken, pc = pc+offset
    input wire isJALR, // jalr instruction => if rs1 is x0, x1, then suppose jalr is taken; or suppose jalr is not taken
    input wire [31:0] rd1, // register data, used by jalr instruction
    input wire [31:0] offset, // branch offset, passed from Extending Unit
    input wire [31:0] pc,     // pc value, passed from IF stage 
    input wire rs1Depended, // used by jalr instruction, to detect rs1 dependency, passed from Hazard Unit
    output reg [31:0] redirectionPC,  // new pc to IF stage
    output reg taken                  // branch taken
);

// =========================================================================
// ============================ implementation =============================
// =========================================================================
    always @(*) begin 
        taken = 1'b0;                 // suppose not taken by default
        redirectionPC = 32'h00000000; // suppose redirectionPC = 0x00000000 by default
        if(isJAL) begin
            taken = 1'b1;    
            redirectionPC = pc+offset;
        end
        if(isJALR) begin
            if(rs1Depended) begin
                taken = 1'b0; // if rs1 has data dependency, we suppose jalr is not taken in branch predictor    
            end
            else begin
                taken = 1'b1; // if rs1 doesn't have data dependency, we suppose jalr is taken in branch predictor    
                redirectionPC = rd1+offset; // only jalr instruction need access register file, so it has to deal with data dependency problem
            end
        end
        if(bType) begin
            if(offset[31]) begin
                taken = 1'b1; // offset[31]=1 => offset less than 0 => backwarding taken
                redirectionPC = pc+offset;
            end
            else begin
                taken = 1'b0; // offset[31]=0 => offset greater than 0 => forwarding not taken
            end
        end
    end
        
endmodule
`endif
