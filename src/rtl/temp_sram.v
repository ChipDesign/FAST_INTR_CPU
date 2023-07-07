`ifndef __TEMPSRAM__
`define __TEMPSRAM__
// import "DPI-C" function void pmem_read_rtl_32(input longint raddr, output int rdata);
import "DPI-C" function void pmem_read_rtl(input longint raddr, output longint rdata);

// import "DPI-C" function longint pmem_read(input longint addr, input int len);
module temp_sram(
  input clk,
  input [31:0] addr,

  output reg [63:0] instr
);

    // reg [31:0] temp;
always @(posedge clk) begin
  // pmem_read_rtl_32({32'd0, addr}, instr);
  pmem_read_rtl({32'd0, addr}, instr);
  // instr <= pmem_read({32'h0, addr}, 4);

end

endmodule
`endif
