`include "decoder.v"
module decoder_tb(); 
    reg clk;

    reg  [31:0] instructionD;
    wire [4:0] aluOperation;
    wire rd1Sel, rd2Sel;
    wire [2:0] immType;
    wire beq, blt, branchBType, branchJAL, branchJALR;
    wire [2:0] dMemType;
    wire [1:0] wbSrc;
    wire wbEn;
    wire instrIllegal;
    
    integer count;

    // periodic time
    initial begin
        clk<=0;
        count<=0;
        forever begin 
          #1; clk<=~clk;
        end
    end

    always @(posedge clk ) begin 

        if(count == 0) begin
            instructionD <= 32'h00400093; // addi x1, x0, 4    
        end
        if(count == 1) begin
            instructionD <= 32'hfe628ee3; // beq x5, x6, _start    
        end
        if(count == 2) begin
            instructionD <= 32'hfe629ee3; // beq x5, x6, _start    
        end
        if(count == 3) begin
            instructionD <= 32'hfe62cee3; // blt x5, x6, _start    
        end
        if(count == 4) begin
            instructionD <= 32'hfe62eee3; // bltu x5, x6, _start    
        end
        if(count == 5) begin
            instructionD <= 32'hfe62dee3; // bge x5, x6, _start    
        end
        if(count == 6) begin
            instructionD <= 32'hfe62fee3; // bgeu x5, x6, _start    
        end
        
        
        
        if(count == 20)
            $finish(0);
        count = count +1;
    end
    


    // =========================================================================
    // ============================ testing =============================
    // =========================================================================
    decoder decoderIn(
        .instructionD(instructionD), 
        .aluOperation(aluOperation),
        .rd1Sel(rd1Sel), 
        .rd2Sel(rd2Sel), 
        .immType(immType),
        .beq(beq),  
        .blt(blt),  
        .branchBType(branchBType), 
        .branchJAL(branchJAL),
        .branchJALR(branchJALR),
        .dMemType(dMemType), 
        .wbSrc(wbSrc), 
        .wbEn(wbEn),  
        .instrIllegal(instrIllegal)
    );

    // generate waveforms
    initial begin
      $dumpfile("decoder_tb.vcd");
      $dumpvars(0, decoder_tb);
    end

endmodule
