module CondAcc(
  input        clock,
  input        reset,
  input  [1:0] io_ctrl,
  output [4:0] io_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [4:0] acc; // @[CondAcc.scala 19:18]
  wire  _T = io_ctrl == 2'h1; // @[CondAcc.scala 20:16]
  wire [4:0] _acc_T_1 = acc + 5'h2; // @[CondAcc.scala 22:13]
  wire  _T_1 = io_ctrl == 2'h2; // @[CondAcc.scala 23:21]
  wire [4:0] _acc_T_3 = acc + 5'h1; // @[CondAcc.scala 25:13]
  assign io_out = acc; // @[CondAcc.scala 30:9]
  always @(posedge clock) begin
    if (reset) begin // @[CondAcc.scala 19:18]
      acc <= 5'h0; // @[CondAcc.scala 19:18]
    end else if (_T) begin // @[CondAcc.scala 21:3]
      acc <= _acc_T_1; // @[CondAcc.scala 22:8]
    end else if (_T_1) begin // @[CondAcc.scala 24:3]
      acc <= _acc_T_3; // @[CondAcc.scala 25:8]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  acc = _RAND_0[4:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
