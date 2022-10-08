module multi(
  input        clock,
  input        reset,
  input  [3:0] io_ina,
  input  [3:0] io_inb,
  output [7:0] io_out
);
  assign io_out = io_ina * io_inb; // @[multi.scala 16:17]
endmodule
