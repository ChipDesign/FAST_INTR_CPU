/*
file: Static Branch Predictor in ID Stage
author: fujie 
time: 2023年 4月26日 星期三 19时04分59秒 CST
*/
`ifndef __STATICBRANCHPREDITOR__
`define __STATICBRANCHPREDITOR__

// `include "definitions.vh"
module staticBranchPredictor(
    input wire branchBType,  // 6 branchBType instruction is: beq, bne, bge, geu, glt, gltu => BTFN(bacwarding taken, forwarding not taken)
    input wire branchJAL,  // jal instruction  => 100% taken, pc = pc+offset
    input wire branchJALR, // jalr instruction => if rs1 is x0, x1, then suppose jalr is taken; or suppose jalr is not taken
    input wire [31:0] rs1, // register data, used by jalr instruction
    input wire [31:0] offset, // branch offset, passed from Extending Unit
    input wire [31:0] pc,     // pc value, passed from IF stage 
    input wire rs1_depended, // used by jalr instruction, to detect rs1 dependency, passed from Hazard Unit
    output reg [31:0] redirection_pc,  // new pc to IF stage
    output reg taken                  // branch taken
);

// =========================================================================
// ============================ implementation =============================
// =========================================================================
    always @(*) begin 
        taken = 1'b0;                 // suppose not taken by default
        redirection_pc = 32'h00000000; // suppose redirection_pc = 0x00000000 by default
        if(branchJAL) begin 
            taken = 1'b1;    
            redirection_pc = pc+offset; // pc += sext(offset)
        end
        if(branchJALR) begin
            if(rs1_depended) begin
                taken = 1'b0; // if rs1 has data dependency, we suppose jalr is not taken in branch predictor    
            end
            
            else begin // only jalr instruction need access register file, so it has to deal with data dependency problem
                taken = 1'b1; // if rs1 doesn't have data dependency, we suppose jalr is taken in branch predictor    
                redirection_pc = (rs1+offset)&32'hfffffffe; // pc=(x[rs1]+sext(offset))&∼1
            end
        end
        if(branchBType) begin
            if(offset[31]) begin
                taken = 1'b1; // offset[31]=1 => offset less than 0 => backwarding taken
                redirection_pc = pc+offset; // pc += sext(offset)
            end
            else begin
                taken = 1'b0; // offset[31]=0 => offset greater than 0 => forwarding not taken
                redirection_pc = pc+offset; // pc += sext(offset)
            end
        end
    end
        
endmodule
`endif
