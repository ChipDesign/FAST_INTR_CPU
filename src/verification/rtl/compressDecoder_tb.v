`include "compressDecoder.v"
module compressDecoder_tb();

    reg clk;
    reg [15:0] instr_i;
    wire [31:0] instr_o;
    wire illegal_instr_o, is_compressed_o;

    integer count;

    always @(posedge clk) begin 
        $write("count = %d, ", count);
        if(count==0) begin
            instr_i <= 16'hffff; // illegal instruction
            $display("begin test");
        end
        if(count==1) begin
            instr_i <= 16'h0fc0; // C.addi4spn
        end
        if(count==2) begin
            instr_i <= 16'h4044; // C.lw
        end
        if(count==3) begin
            instr_i <= 16'hc044; // C.sw
        end
        if(count==4) begin
            instr_i <= 16'h0185; // C.addi
        end
        if(count==5) begin
            instr_i <= 16'h2001; // C.jal
        end
        if(count==6) begin
            instr_i <= 16'h418d; // C.li
        end
        if(count==7) begin
            instr_i <= 16'h61b9; // C.lui
        end
        if(count==8) begin
            instr_i <= 16'h6135; // C.addi16sp
        end
        if(count==9) begin
            instr_i <= 16'h80a1; // C.srli
        end
        if(count==10) begin
            instr_i <= 16'h8425; // C.srai
        end
        if(count==11) begin
            instr_i <= 16'h8cc5; // C.andi
        end
        if(count==12) begin
            instr_i <= 16'h8c05; // C.sub
        end
        if(count==13) begin
            instr_i <= 16'h8c45; // C.xor
        end
        if(count==14) begin
            instr_i <= 16'h8c85; // C.or
        end
        if(count==15) begin
            instr_i <= 16'h8cc5; // C.and
        end
        if(count==16) begin
            instr_i <= 16'ha001; // C.j
        end
        if(count==17) begin
            instr_i <= 16'hc089; // C.beqz
        end
        if(count==18) begin
            instr_i <= 16'he089; // C.bnez
        end
        if(count==19) begin
            instr_i <= 16'h4092; // C.slli
        end
        if(count==20) begin
            instr_i <= 16'h40a6; // C.lwsp 
        end
        if(count==21) begin
            instr_i <= 16'h808a; // C.mv
        end
        if(count==22) begin
            instr_i <= 16'h8082; // C.jr
        end
        if(count==23) begin
            instr_i <= 16'h9192; // C.add
        end
        if(count==24) begin
            instr_i <= 16'h9002; // C.ebreak
        end
        if(count==25) begin
            instr_i <= 16'h9182; // C.jalr
        end
        if(count==26) begin
            instr_i <= 16'hc886; // C.swsp
        end
        if(count==27) begin
            instr_i <= 16'hffff; // illegal instruction
        end

        if(count==27) begin
            $display("end test");
            $finish();    
        end

        count = count + 1;
    end
    


    // periodic time
    initial begin
        clk<=0;
        count <= 0;
        forever begin 
          #1; clk<=~clk;
        end
    end
    
    compressDecoder compressDecoder_i(
       .instr_i(instr_i),       
       .instr_o(instr_o),  
       .illegal_instr_o(illegal_instr_o), 
       .is_compressed_o(is_compressed_o)
    );

    // generate waveforms
    initial begin
      $dumpfile("compressDecoder_tb.vcd");
      $dumpvars(0, compressDecoder_tb);
    end
endmodule
