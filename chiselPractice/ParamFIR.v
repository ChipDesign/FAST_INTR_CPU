module ParamFIR(
  input        clock,
  input        reset,
  input  [4:0] io_sig_in,
  output [4:0] io_sig_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [4:0] regs_1; // @[ParamFIR.scala 19:25]
  reg [4:0] regs_2; // @[ParamFIR.scala 19:25]
  reg [4:0] regs_3; // @[ParamFIR.scala 19:25]
  reg [4:0] regs_4; // @[ParamFIR.scala 19:25]
  wire [5:0] muls_0 = io_sig_in * 1'h1; // @[ParamFIR.scala 24:20]
  wire [5:0] muls_1 = regs_1 * 1'h1; // @[ParamFIR.scala 24:20]
  wire [6:0] muls_2 = regs_2 * 2'h2; // @[ParamFIR.scala 24:20]
  wire [6:0] muls_3 = regs_3 * 2'h3; // @[ParamFIR.scala 24:20]
  wire [7:0] muls_4 = regs_4 * 3'h5; // @[ParamFIR.scala 24:20]
  wire [5:0] sums_1 = muls_0 + muls_1; // @[ParamFIR.scala 30:28]
  wire [6:0] _GEN_0 = {{1'd0}, sums_1}; // @[ParamFIR.scala 30:28]
  wire [6:0] sums_2 = _GEN_0 + muls_2; // @[ParamFIR.scala 30:28]
  wire [6:0] sums_3 = sums_2 + muls_3; // @[ParamFIR.scala 30:28]
  wire [7:0] _GEN_1 = {{1'd0}, sums_3}; // @[ParamFIR.scala 30:28]
  wire [7:0] sums_4 = _GEN_1 + muls_4; // @[ParamFIR.scala 30:28]
  assign io_sig_out = sums_4[4:0]; // @[ParamFIR.scala 33:13]
  always @(posedge clock) begin
    if (reset) begin // @[ParamFIR.scala 19:25]
      regs_1 <= 5'h0; // @[ParamFIR.scala 19:25]
    end else begin
      regs_1 <= io_sig_in; // @[ParamFIR.scala 19:25]
    end
    if (reset) begin // @[ParamFIR.scala 19:25]
      regs_2 <= 5'h0; // @[ParamFIR.scala 19:25]
    end else begin
      regs_2 <= regs_1; // @[ParamFIR.scala 19:25]
    end
    if (reset) begin // @[ParamFIR.scala 19:25]
      regs_3 <= 5'h0; // @[ParamFIR.scala 19:25]
    end else begin
      regs_3 <= regs_2; // @[ParamFIR.scala 19:25]
    end
    if (reset) begin // @[ParamFIR.scala 19:25]
      regs_4 <= 5'h0; // @[ParamFIR.scala 19:25]
    end else begin
      regs_4 <= regs_3; // @[ParamFIR.scala 19:25]
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
  regs_1 = _RAND_0[4:0];
  _RAND_1 = {1{`RANDOM}};
  regs_2 = _RAND_1[4:0];
  _RAND_2 = {1{`RANDOM}};
  regs_3 = _RAND_2[4:0];
  _RAND_3 = {1{`RANDOM}};
  regs_4 = _RAND_3[4:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
