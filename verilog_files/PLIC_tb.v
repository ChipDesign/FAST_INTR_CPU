`include"PLIC_top.v"
`timescale  1ps/1ps
module PLIC_tb();

reg clk,resetn;
reg [127:0] test_bundle;

reg wen,ren;
reg [23:0] PLIC_addr;
reg [31:0] wdata;

wire [31:0]rdata;
wire eip_notif;

reg [19:0] clkcnt;

initial begin
  
  clk<=1'b1;
  test_bundle<=127'b0;
  wen<=1'b0;
  ren<=1'b0;
  PLIC_addr<=24'b0;
  wdata<=32'b0;
  clkcnt<=20'b0;

  
  

  $dumpfile("PLIC.vcd");
  $dumpvars(0,PLIC_tb);
  #5 resetn<=1'b0;
  #50 resetn<=1'b1;
  #1000

  
  	
  $finish();
end
//TODO reg index*4

always begin
  #10
  clk<=~clk;
end

always@(posedge clk)
begin
    clkcnt<=clkcnt+1;
    if(clkcnt==20)//write enable
    begin
        PLIC_addr<=24'h002000;
        wdata<=32'hffffffff;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==21)//write threshold
    begin
        PLIC_addr<=24'h200000;
        wdata<=32'h0000ffff;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==22)//enabled & over thres
    begin
        PLIC_addr<=24'h00001c;
        wdata<=32'h0fff0000;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==23)//enabled & over thres
    begin
        PLIC_addr<=24'h000020;
        wdata<=32'h0ff00000;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==24)//trig
    begin
        PLIC_addr<=24'h00001c;
        wdata<=32'h0fff0000;
        wen<=1'b0;
        ren<=1'b0;
        test_bundle<=127'h180;
    end
    else if(clkcnt==30)//read claim
    begin
        PLIC_addr<=24'h200004;
        wdata<=32'h0ff00000;
        wen<=1'b0;
        ren<=1'b1;
        test_bundle<=127'b0;
    end
    else if(clkcnt==35)//write claim
    begin
        PLIC_addr<=24'h200004;
        wdata<=32'h7;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    /*
    else if(clkcnt==30)//read claim
    begin
        PLIC_addr<=24'h200004;
        wdata<=32'h0ff00000;
        wen<=1'b0;
        ren<=1'b1;
        test_bundle<=127'b0;
    end
    else if(clkcnt==31)//enabled & over thres
    begin
        PLIC_addr<=24'h00001c;
        wdata<=32'h0fff0000;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==32)//unenabled & over thres
    begin
        PLIC_addr<=24'h000040;
        wdata<=32'h0ff00001;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==33)//enabled & over thres
    begin
        PLIC_addr<=24'h000008;
        wdata<=32'h0ff00000;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
    else if(clkcnt==34)//trig
    begin
        PLIC_addr<=24'h000005;
        wdata<=32'h00001000;
        wen<=1'b0;
        ren<=1'b0;
        test_bundle<=127'h30084;
    end
    else if(clkcnt==40)//read claim again
    begin
        PLIC_addr<=24'h200004;
        wdata<=32'h0ff00000;
        wen<=1'b0;
        ren<=1'b1;
        test_bundle<=127'b0;
    end
    else if(clkcnt==43)//write clear
    begin
        PLIC_addr<=24'h200004;
        wdata<=32'h7;
        wen<=1'b1;
        ren<=1'b0;
        test_bundle<=127'b0;
    end*/
    else
    begin
        PLIC_addr<=24'h0;
        wdata<=32'h00;
        wen<=1'b0;
        ren<=1'b0;
        test_bundle<=127'b0;
    end
end



PLIC_top_unmod PLIC(
        .clk(clk),
        .rstn(resetn),
        .intr_bundle(test_bundle),
        .core_wen(wen),
        .core_addr(PLIC_addr),
        .core_wdata(wdata),
        .core_ren(ren),
    
        .core_rdata(rdata),
        .plic_notif(eip_notif)
    );

endmodule
