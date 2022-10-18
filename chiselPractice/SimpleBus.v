module Arbiter(
  output       io_in_0_ready,
  input        io_in_0_valid,
  input  [7:0] io_in_0_bits,
  output       io_in_1_ready,
  input        io_in_1_valid,
  input  [7:0] io_in_1_bits,
  output       io_in_2_ready,
  input        io_in_2_valid,
  input  [7:0] io_in_2_bits,
  output       io_in_3_ready,
  input        io_in_3_valid,
  input  [7:0] io_in_3_bits,
  input        io_out_ready,
  output       io_out_valid,
  output [7:0] io_out_bits
);
  wire [7:0] _GEN_1 = io_in_2_valid ? io_in_2_bits : io_in_3_bits; // @[Arbiter.scala 136:15 138:26 140:19]
  wire [7:0] _GEN_3 = io_in_1_valid ? io_in_1_bits : _GEN_1; // @[Arbiter.scala 138:26 140:19]
  wire  grant_1 = ~io_in_0_valid; // @[Arbiter.scala 45:78]
  wire  grant_2 = ~(io_in_0_valid | io_in_1_valid); // @[Arbiter.scala 45:78]
  wire  grant_3 = ~(io_in_0_valid | io_in_1_valid | io_in_2_valid); // @[Arbiter.scala 45:78]
  assign io_in_0_ready = io_out_ready; // @[Arbiter.scala 146:19]
  assign io_in_1_ready = grant_1 & io_out_ready; // @[Arbiter.scala 146:19]
  assign io_in_2_ready = grant_2 & io_out_ready; // @[Arbiter.scala 146:19]
  assign io_in_3_ready = grant_3 & io_out_ready; // @[Arbiter.scala 146:19]
  assign io_out_valid = ~grant_3 | io_in_3_valid; // @[Arbiter.scala 147:31]
  assign io_out_bits = io_in_0_valid ? io_in_0_bits : _GEN_3; // @[Arbiter.scala 138:26 140:19]
endmodule
module BusMaster(
  input        clock,
  input        reset,
  input        io_data_ready,
  output       io_data_valid,
  output [7:0] io_data_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] cnt_value; // @[Counter.scala 61:40]
  wire  wrap = cnt_value == 3'h4; // @[Counter.scala 73:24]
  wire [2:0] _value_T_1 = cnt_value + 3'h1; // @[Counter.scala 77:24]
  wire  _T_1 = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  wire [7:0] _GEN_7 = 2'h1 == cnt_value[1:0] ? 8'h6 : 8'h3; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_8 = 2'h2 == cnt_value[1:0] ? 8'h9 : _GEN_7; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_9 = 2'h3 == cnt_value[1:0] ? 8'hc : _GEN_8; // @[SimpleBus.scala 43:{17,17}]
  assign io_data_valid = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  assign io_data_bits = _T_1 ? _GEN_9 : 8'h0; // @[SimpleBus.scala 41:3 43:17 47:17]
  always @(posedge clock) begin
    if (reset) begin // @[Counter.scala 61:40]
      cnt_value <= 3'h0; // @[Counter.scala 61:40]
    end else if (io_data_ready) begin // @[SimpleBus.scala 36:3]
      if (wrap) begin // @[Counter.scala 87:20]
        cnt_value <= 3'h0; // @[Counter.scala 87:28]
      end else begin
        cnt_value <= _value_T_1; // @[Counter.scala 77:15]
      end
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
  cnt_value = _RAND_0[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module BusMaster_1(
  input        clock,
  input        reset,
  input        io_data_ready,
  output       io_data_valid,
  output [7:0] io_data_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] cnt_value; // @[Counter.scala 61:40]
  wire  wrap = cnt_value == 3'h4; // @[Counter.scala 73:24]
  wire [2:0] _value_T_1 = cnt_value + 3'h1; // @[Counter.scala 77:24]
  wire  _T_1 = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  wire [7:0] _GEN_7 = 2'h1 == cnt_value[1:0] ? 8'h1 : 8'hf; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_8 = 2'h2 == cnt_value[1:0] ? 8'h4 : _GEN_7; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_9 = 2'h3 == cnt_value[1:0] ? 8'h7 : _GEN_8; // @[SimpleBus.scala 43:{17,17}]
  assign io_data_valid = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  assign io_data_bits = _T_1 ? _GEN_9 : 8'h0; // @[SimpleBus.scala 41:3 43:17 47:17]
  always @(posedge clock) begin
    if (reset) begin // @[Counter.scala 61:40]
      cnt_value <= 3'h0; // @[Counter.scala 61:40]
    end else if (io_data_ready) begin // @[SimpleBus.scala 36:3]
      if (wrap) begin // @[Counter.scala 87:20]
        cnt_value <= 3'h0; // @[Counter.scala 87:28]
      end else begin
        cnt_value <= _value_T_1; // @[Counter.scala 77:15]
      end
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
  cnt_value = _RAND_0[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module BusMaster_2(
  input        clock,
  input        reset,
  input        io_data_ready,
  output       io_data_valid,
  output [7:0] io_data_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] cnt_value; // @[Counter.scala 61:40]
  wire  wrap = cnt_value == 3'h4; // @[Counter.scala 73:24]
  wire [2:0] _value_T_1 = cnt_value + 3'h1; // @[Counter.scala 77:24]
  wire  _T_1 = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  wire [7:0] _GEN_7 = 2'h1 == cnt_value[1:0] ? 8'hd : 8'ha; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_8 = 2'h2 == cnt_value[1:0] ? 8'h10 : _GEN_7; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_9 = 2'h3 == cnt_value[1:0] ? 8'h2 : _GEN_8; // @[SimpleBus.scala 43:{17,17}]
  assign io_data_valid = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  assign io_data_bits = _T_1 ? _GEN_9 : 8'h0; // @[SimpleBus.scala 41:3 43:17 47:17]
  always @(posedge clock) begin
    if (reset) begin // @[Counter.scala 61:40]
      cnt_value <= 3'h0; // @[Counter.scala 61:40]
    end else if (io_data_ready) begin // @[SimpleBus.scala 36:3]
      if (wrap) begin // @[Counter.scala 87:20]
        cnt_value <= 3'h0; // @[Counter.scala 87:28]
      end else begin
        cnt_value <= _value_T_1; // @[Counter.scala 77:15]
      end
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
  cnt_value = _RAND_0[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module BusMaster_3(
  input        clock,
  input        reset,
  input        io_data_ready,
  output       io_data_valid,
  output [7:0] io_data_bits
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  reg [2:0] cnt_value; // @[Counter.scala 61:40]
  wire  wrap = cnt_value == 3'h4; // @[Counter.scala 73:24]
  wire [2:0] _value_T_1 = cnt_value + 3'h1; // @[Counter.scala 77:24]
  wire  _T_1 = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  wire [7:0] _GEN_7 = 2'h1 == cnt_value[1:0] ? 8'h8 : 8'h5; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_8 = 2'h2 == cnt_value[1:0] ? 8'hb : _GEN_7; // @[SimpleBus.scala 43:{17,17}]
  wire [7:0] _GEN_9 = 2'h3 == cnt_value[1:0] ? 8'he : _GEN_8; // @[SimpleBus.scala 43:{17,17}]
  assign io_data_valid = cnt_value < 3'h4; // @[SimpleBus.scala 40:17]
  assign io_data_bits = _T_1 ? _GEN_9 : 8'h0; // @[SimpleBus.scala 41:3 43:17 47:17]
  always @(posedge clock) begin
    if (reset) begin // @[Counter.scala 61:40]
      cnt_value <= 3'h0; // @[Counter.scala 61:40]
    end else if (io_data_ready) begin // @[SimpleBus.scala 36:3]
      if (wrap) begin // @[Counter.scala 87:20]
        cnt_value <= 3'h0; // @[Counter.scala 87:28]
      end else begin
        cnt_value <= _value_T_1; // @[Counter.scala 77:15]
      end
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
  cnt_value = _RAND_0[2:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Queue(
  input        clock,
  input        reset,
  output       io_enq_ready,
  input        io_enq_valid,
  input  [7:0] io_enq_bits,
  input        io_deq_ready,
  output       io_deq_valid,
  output [7:0] io_deq_bits
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  reg [7:0] ram [0:15]; // @[Decoupled.scala 275:95]
  wire  ram_io_deq_bits_MPORT_en; // @[Decoupled.scala 275:95]
  wire [3:0] ram_io_deq_bits_MPORT_addr; // @[Decoupled.scala 275:95]
  wire [7:0] ram_io_deq_bits_MPORT_data; // @[Decoupled.scala 275:95]
  wire [7:0] ram_MPORT_data; // @[Decoupled.scala 275:95]
  wire [3:0] ram_MPORT_addr; // @[Decoupled.scala 275:95]
  wire  ram_MPORT_mask; // @[Decoupled.scala 275:95]
  wire  ram_MPORT_en; // @[Decoupled.scala 275:95]
  reg [3:0] enq_ptr_value; // @[Counter.scala 61:40]
  reg [3:0] deq_ptr_value; // @[Counter.scala 61:40]
  reg  maybe_full; // @[Decoupled.scala 278:27]
  wire  ptr_match = enq_ptr_value == deq_ptr_value; // @[Decoupled.scala 279:33]
  wire  empty = ptr_match & ~maybe_full; // @[Decoupled.scala 280:25]
  wire  full = ptr_match & maybe_full; // @[Decoupled.scala 281:24]
  wire  do_enq = io_enq_ready & io_enq_valid; // @[Decoupled.scala 52:35]
  wire  do_deq = io_deq_ready & io_deq_valid; // @[Decoupled.scala 52:35]
  wire [3:0] _value_T_1 = enq_ptr_value + 4'h1; // @[Counter.scala 77:24]
  wire [3:0] _value_T_3 = deq_ptr_value + 4'h1; // @[Counter.scala 77:24]
  assign ram_io_deq_bits_MPORT_en = 1'h1;
  assign ram_io_deq_bits_MPORT_addr = deq_ptr_value;
  assign ram_io_deq_bits_MPORT_data = ram[ram_io_deq_bits_MPORT_addr]; // @[Decoupled.scala 275:95]
  assign ram_MPORT_data = io_enq_bits;
  assign ram_MPORT_addr = enq_ptr_value;
  assign ram_MPORT_mask = 1'h1;
  assign ram_MPORT_en = io_enq_ready & io_enq_valid;
  assign io_enq_ready = ~full; // @[Decoupled.scala 305:19]
  assign io_deq_valid = ~empty; // @[Decoupled.scala 304:19]
  assign io_deq_bits = ram_io_deq_bits_MPORT_data; // @[Decoupled.scala 312:17]
  always @(posedge clock) begin
    if (ram_MPORT_en & ram_MPORT_mask) begin
      ram[ram_MPORT_addr] <= ram_MPORT_data; // @[Decoupled.scala 275:95]
    end
    if (reset) begin // @[Counter.scala 61:40]
      enq_ptr_value <= 4'h0; // @[Counter.scala 61:40]
    end else if (do_enq) begin // @[Decoupled.scala 288:16]
      enq_ptr_value <= _value_T_1; // @[Counter.scala 77:15]
    end
    if (reset) begin // @[Counter.scala 61:40]
      deq_ptr_value <= 4'h0; // @[Counter.scala 61:40]
    end else if (do_deq) begin // @[Decoupled.scala 292:16]
      deq_ptr_value <= _value_T_3; // @[Counter.scala 77:15]
    end
    if (reset) begin // @[Decoupled.scala 278:27]
      maybe_full <= 1'h0; // @[Decoupled.scala 278:27]
    end else if (do_enq != do_deq) begin // @[Decoupled.scala 295:27]
      maybe_full <= do_enq; // @[Decoupled.scala 296:16]
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
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 16; initvar = initvar+1)
    ram[initvar] = _RAND_0[7:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  enq_ptr_value = _RAND_1[3:0];
  _RAND_2 = {1{`RANDOM}};
  deq_ptr_value = _RAND_2[3:0];
  _RAND_3 = {1{`RANDOM}};
  maybe_full = _RAND_3[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module BusSlave(
  input        clock,
  input        reset,
  output       io_data_in_ready,
  input        io_data_in_valid,
  input  [7:0] io_data_in_bits,
  output [7:0] io_QueueOut,
  input        io_OutReady
);
  wire  AccQueue_clock; // @[SimpleBus.scala 57:22]
  wire  AccQueue_reset; // @[SimpleBus.scala 57:22]
  wire  AccQueue_io_enq_ready; // @[SimpleBus.scala 57:22]
  wire  AccQueue_io_enq_valid; // @[SimpleBus.scala 57:22]
  wire [7:0] AccQueue_io_enq_bits; // @[SimpleBus.scala 57:22]
  wire  AccQueue_io_deq_ready; // @[SimpleBus.scala 57:22]
  wire  AccQueue_io_deq_valid; // @[SimpleBus.scala 57:22]
  wire [7:0] AccQueue_io_deq_bits; // @[SimpleBus.scala 57:22]
  Queue AccQueue ( // @[SimpleBus.scala 57:22]
    .clock(AccQueue_clock),
    .reset(AccQueue_reset),
    .io_enq_ready(AccQueue_io_enq_ready),
    .io_enq_valid(AccQueue_io_enq_valid),
    .io_enq_bits(AccQueue_io_enq_bits),
    .io_deq_ready(AccQueue_io_deq_ready),
    .io_deq_valid(AccQueue_io_deq_valid),
    .io_deq_bits(AccQueue_io_deq_bits)
  );
  assign io_data_in_ready = AccQueue_io_enq_ready; // @[SimpleBus.scala 58:18]
  assign io_QueueOut = AccQueue_io_deq_bits; // @[SimpleBus.scala 59:15]
  assign AccQueue_clock = clock;
  assign AccQueue_reset = reset;
  assign AccQueue_io_enq_valid = io_data_in_valid; // @[SimpleBus.scala 58:18]
  assign AccQueue_io_enq_bits = io_data_in_bits; // @[SimpleBus.scala 58:18]
  assign AccQueue_io_deq_ready = io_OutReady; // @[SimpleBus.scala 60:24]
endmodule
module SimpleBus(
  input        clock,
  input        reset,
  output [7:0] io_SlaveDataOut
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire  arbi_io_in_0_ready; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_0_valid; // @[SimpleBus.scala 67:18]
  wire [7:0] arbi_io_in_0_bits; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_1_ready; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_1_valid; // @[SimpleBus.scala 67:18]
  wire [7:0] arbi_io_in_1_bits; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_2_ready; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_2_valid; // @[SimpleBus.scala 67:18]
  wire [7:0] arbi_io_in_2_bits; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_3_ready; // @[SimpleBus.scala 67:18]
  wire  arbi_io_in_3_valid; // @[SimpleBus.scala 67:18]
  wire [7:0] arbi_io_in_3_bits; // @[SimpleBus.scala 67:18]
  wire  arbi_io_out_ready; // @[SimpleBus.scala 67:18]
  wire  arbi_io_out_valid; // @[SimpleBus.scala 67:18]
  wire [7:0] arbi_io_out_bits; // @[SimpleBus.scala 67:18]
  wire  M1_clock; // @[SimpleBus.scala 68:16]
  wire  M1_reset; // @[SimpleBus.scala 68:16]
  wire  M1_io_data_ready; // @[SimpleBus.scala 68:16]
  wire  M1_io_data_valid; // @[SimpleBus.scala 68:16]
  wire [7:0] M1_io_data_bits; // @[SimpleBus.scala 68:16]
  wire  M2_clock; // @[SimpleBus.scala 69:16]
  wire  M2_reset; // @[SimpleBus.scala 69:16]
  wire  M2_io_data_ready; // @[SimpleBus.scala 69:16]
  wire  M2_io_data_valid; // @[SimpleBus.scala 69:16]
  wire [7:0] M2_io_data_bits; // @[SimpleBus.scala 69:16]
  wire  M3_clock; // @[SimpleBus.scala 70:16]
  wire  M3_reset; // @[SimpleBus.scala 70:16]
  wire  M3_io_data_ready; // @[SimpleBus.scala 70:16]
  wire  M3_io_data_valid; // @[SimpleBus.scala 70:16]
  wire [7:0] M3_io_data_bits; // @[SimpleBus.scala 70:16]
  wire  M4_clock; // @[SimpleBus.scala 71:16]
  wire  M4_reset; // @[SimpleBus.scala 71:16]
  wire  M4_io_data_ready; // @[SimpleBus.scala 71:16]
  wire  M4_io_data_valid; // @[SimpleBus.scala 71:16]
  wire [7:0] M4_io_data_bits; // @[SimpleBus.scala 71:16]
  wire  S_clock; // @[SimpleBus.scala 77:15]
  wire  S_reset; // @[SimpleBus.scala 77:15]
  wire  S_io_data_in_ready; // @[SimpleBus.scala 77:15]
  wire  S_io_data_in_valid; // @[SimpleBus.scala 77:15]
  wire [7:0] S_io_data_in_bits; // @[SimpleBus.scala 77:15]
  wire [7:0] S_io_QueueOut; // @[SimpleBus.scala 77:15]
  wire  S_io_OutReady; // @[SimpleBus.scala 77:15]
  reg [4:0] cnt_value; // @[Counter.scala 61:40]
  reg  OutReady; // @[SimpleBus.scala 82:23]
  wire  wrap = cnt_value == 5'h14; // @[Counter.scala 73:24]
  wire [4:0] _value_T_1 = cnt_value + 5'h1; // @[Counter.scala 77:24]
  wire  _T = cnt_value == 5'h10; // @[SimpleBus.scala 87:17]
  wire  _GEN_2 = _T | OutReady; // @[SimpleBus.scala 88:3 89:13 82:23]
  Arbiter arbi ( // @[SimpleBus.scala 67:18]
    .io_in_0_ready(arbi_io_in_0_ready),
    .io_in_0_valid(arbi_io_in_0_valid),
    .io_in_0_bits(arbi_io_in_0_bits),
    .io_in_1_ready(arbi_io_in_1_ready),
    .io_in_1_valid(arbi_io_in_1_valid),
    .io_in_1_bits(arbi_io_in_1_bits),
    .io_in_2_ready(arbi_io_in_2_ready),
    .io_in_2_valid(arbi_io_in_2_valid),
    .io_in_2_bits(arbi_io_in_2_bits),
    .io_in_3_ready(arbi_io_in_3_ready),
    .io_in_3_valid(arbi_io_in_3_valid),
    .io_in_3_bits(arbi_io_in_3_bits),
    .io_out_ready(arbi_io_out_ready),
    .io_out_valid(arbi_io_out_valid),
    .io_out_bits(arbi_io_out_bits)
  );
  BusMaster M1 ( // @[SimpleBus.scala 68:16]
    .clock(M1_clock),
    .reset(M1_reset),
    .io_data_ready(M1_io_data_ready),
    .io_data_valid(M1_io_data_valid),
    .io_data_bits(M1_io_data_bits)
  );
  BusMaster_1 M2 ( // @[SimpleBus.scala 69:16]
    .clock(M2_clock),
    .reset(M2_reset),
    .io_data_ready(M2_io_data_ready),
    .io_data_valid(M2_io_data_valid),
    .io_data_bits(M2_io_data_bits)
  );
  BusMaster_2 M3 ( // @[SimpleBus.scala 70:16]
    .clock(M3_clock),
    .reset(M3_reset),
    .io_data_ready(M3_io_data_ready),
    .io_data_valid(M3_io_data_valid),
    .io_data_bits(M3_io_data_bits)
  );
  BusMaster_3 M4 ( // @[SimpleBus.scala 71:16]
    .clock(M4_clock),
    .reset(M4_reset),
    .io_data_ready(M4_io_data_ready),
    .io_data_valid(M4_io_data_valid),
    .io_data_bits(M4_io_data_bits)
  );
  BusSlave S ( // @[SimpleBus.scala 77:15]
    .clock(S_clock),
    .reset(S_reset),
    .io_data_in_ready(S_io_data_in_ready),
    .io_data_in_valid(S_io_data_in_valid),
    .io_data_in_bits(S_io_data_in_bits),
    .io_QueueOut(S_io_QueueOut),
    .io_OutReady(S_io_OutReady)
  );
  assign io_SlaveDataOut = S_io_QueueOut; // @[SimpleBus.scala 78:18]
  assign arbi_io_in_0_valid = M1_io_data_valid; // @[SimpleBus.scala 72:13]
  assign arbi_io_in_0_bits = M1_io_data_bits; // @[SimpleBus.scala 72:13]
  assign arbi_io_in_1_valid = M2_io_data_valid; // @[SimpleBus.scala 73:13]
  assign arbi_io_in_1_bits = M2_io_data_bits; // @[SimpleBus.scala 73:13]
  assign arbi_io_in_2_valid = M3_io_data_valid; // @[SimpleBus.scala 74:13]
  assign arbi_io_in_2_bits = M3_io_data_bits; // @[SimpleBus.scala 74:13]
  assign arbi_io_in_3_valid = M4_io_data_valid; // @[SimpleBus.scala 75:13]
  assign arbi_io_in_3_bits = M4_io_data_bits; // @[SimpleBus.scala 75:13]
  assign arbi_io_out_ready = S_io_data_in_ready; // @[SimpleBus.scala 79:15]
  assign M1_clock = clock;
  assign M1_reset = reset;
  assign M1_io_data_ready = arbi_io_in_0_ready; // @[SimpleBus.scala 72:13]
  assign M2_clock = clock;
  assign M2_reset = reset;
  assign M2_io_data_ready = arbi_io_in_1_ready; // @[SimpleBus.scala 73:13]
  assign M3_clock = clock;
  assign M3_reset = reset;
  assign M3_io_data_ready = arbi_io_in_2_ready; // @[SimpleBus.scala 74:13]
  assign M4_clock = clock;
  assign M4_reset = reset;
  assign M4_io_data_ready = arbi_io_in_3_ready; // @[SimpleBus.scala 75:13]
  assign S_clock = clock;
  assign S_reset = reset;
  assign S_io_data_in_valid = arbi_io_out_valid; // @[SimpleBus.scala 79:15]
  assign S_io_data_in_bits = arbi_io_out_bits; // @[SimpleBus.scala 79:15]
  assign S_io_OutReady = OutReady; // @[SimpleBus.scala 91:16]
  always @(posedge clock) begin
    if (reset) begin // @[Counter.scala 61:40]
      cnt_value <= 5'h0; // @[Counter.scala 61:40]
    end else if (arbi_io_out_valid) begin // @[SimpleBus.scala 84:3]
      if (wrap) begin // @[Counter.scala 87:20]
        cnt_value <= 5'h0; // @[Counter.scala 87:28]
      end else begin
        cnt_value <= _value_T_1; // @[Counter.scala 77:15]
      end
    end
    if (reset) begin // @[SimpleBus.scala 82:23]
      OutReady <= 1'h0; // @[SimpleBus.scala 82:23]
    end else begin
      OutReady <= _GEN_2;
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
  cnt_value = _RAND_0[4:0];
  _RAND_1 = {1{`RANDOM}};
  OutReady = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
