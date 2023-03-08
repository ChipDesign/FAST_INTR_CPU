module Int_status(
  input        clock,
  input        reset,
  input  [4:0] io_pri_in,
  output [4:0] io_pri_out,
  input  [3:0] io_ID_in,
  output [3:0] io_ID_out,
  input        io_act,
  input        io_deact,
  input        io_nest,
  input        io_denest,
  output       io_status
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg [4:0] Priority; // @[Int_nesting.scala 6:23]
  reg [3:0] Int_ID; // @[Int_nesting.scala 7:21]
  reg [1:0] Status; // @[Int_nesting.scala 8:21]
  wire  _T = Status == 2'h0; // @[Int_nesting.scala 26:14]
  wire [4:0] _GEN_0 = io_act ? io_pri_in : Priority; // @[Int_nesting.scala 29:5 30:15 6:23]
  wire [3:0] _GEN_1 = io_act ? io_ID_in : Int_ID; // @[Int_nesting.scala 29:5 31:13 7:21]
  wire  _T_2 = Status == 2'h1; // @[Int_nesting.scala 34:20]
  wire [1:0] _GEN_5 = io_nest ? 2'h3 : Status; // @[Int_nesting.scala 42:5 43:13 8:21]
  wire [4:0] _GEN_6 = io_nest ? Priority : _GEN_0; // @[Int_nesting.scala 42:5 6:23]
  wire [3:0] _GEN_7 = io_nest ? Int_ID : _GEN_1; // @[Int_nesting.scala 42:5 7:21]
  assign io_pri_out = Priority; // @[Int_nesting.scala 22:13]
  assign io_ID_out = Int_ID; // @[Int_nesting.scala 23:12]
  assign io_status = Status[0]; // @[Int_nesting.scala 24:12]
  always @(posedge clock) begin
    if (reset) begin // @[Int_nesting.scala 6:23]
      Priority <= 5'h0; // @[Int_nesting.scala 6:23]
    end else if (_T) begin // @[Int_nesting.scala 27:3]
      if (io_act) begin // @[Int_nesting.scala 29:5]
        Priority <= io_pri_in; // @[Int_nesting.scala 30:15]
      end
    end else if (_T_2) begin // @[Int_nesting.scala 35:3]
      if (io_deact) begin // @[Int_nesting.scala 37:5]
        Priority <= 5'h0; // @[Int_nesting.scala 38:15]
      end else begin
        Priority <= _GEN_6;
      end
    end
    if (reset) begin // @[Int_nesting.scala 7:21]
      Int_ID <= 4'h0; // @[Int_nesting.scala 7:21]
    end else if (_T) begin // @[Int_nesting.scala 27:3]
      if (io_act) begin // @[Int_nesting.scala 29:5]
        Int_ID <= io_ID_in; // @[Int_nesting.scala 31:13]
      end
    end else if (_T_2) begin // @[Int_nesting.scala 35:3]
      if (io_deact) begin // @[Int_nesting.scala 37:5]
        Int_ID <= 4'h0; // @[Int_nesting.scala 39:13]
      end else begin
        Int_ID <= _GEN_7;
      end
    end
    if (reset) begin // @[Int_nesting.scala 8:21]
      Status <= 2'h0; // @[Int_nesting.scala 8:21]
    end else if (_T) begin // @[Int_nesting.scala 27:3]
      if (io_act) begin // @[Int_nesting.scala 29:5]
        Status <= 2'h1; // @[Int_nesting.scala 32:13]
      end
    end else if (_T_2) begin // @[Int_nesting.scala 35:3]
      if (io_deact) begin // @[Int_nesting.scala 37:5]
        Status <= 2'h0; // @[Int_nesting.scala 40:13]
      end else begin
        Status <= _GEN_5;
      end
    end else if (io_denest) begin // @[Int_nesting.scala 51:5]
      Status <= 2'h1; // @[Int_nesting.scala 52:13]
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
  Priority = _RAND_0[4:0];
  _RAND_1 = {1{`RANDOM}};
  Int_ID = _RAND_1[3:0];
  _RAND_2 = {1{`RANDOM}};
  Status = _RAND_2[1:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Int_nesting(
  input        clock,
  input        reset,
  output       io_empty,
  output [4:0] io_current_pri,
  input        io_nest_disable,
  output [4:0] io_nested_pri,
  input  [4:0] io_coming_pri,
  output       io_is_nesting,
  output [3:0] io_current_ID,
  input  [3:0] io_coming_ID,
  output [3:0] io_nested_ID,
  output       io_en_nest,
  output       io_de_nest,
  input        io_is_pending,
  input        io_int_fin
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_REG_INIT
  wire  Int_status_clock; // @[Int_nesting.scala 63:23]
  wire  Int_status_reset; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_io_pri_in; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_io_pri_out; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_io_ID_in; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_io_ID_out; // @[Int_nesting.scala 63:23]
  wire  Int_status_io_act; // @[Int_nesting.scala 63:23]
  wire  Int_status_io_deact; // @[Int_nesting.scala 63:23]
  wire  Int_status_io_nest; // @[Int_nesting.scala 63:23]
  wire  Int_status_io_denest; // @[Int_nesting.scala 63:23]
  wire  Int_status_io_status; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_clock; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_reset; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_1_io_pri_in; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_1_io_pri_out; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_1_io_ID_in; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_1_io_ID_out; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_io_act; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_io_deact; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_io_nest; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_io_denest; // @[Int_nesting.scala 63:23]
  wire  Int_status_1_io_status; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_clock; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_reset; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_2_io_pri_in; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_2_io_pri_out; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_2_io_ID_in; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_2_io_ID_out; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_io_act; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_io_deact; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_io_nest; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_io_denest; // @[Int_nesting.scala 63:23]
  wire  Int_status_2_io_status; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_clock; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_reset; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_3_io_pri_in; // @[Int_nesting.scala 63:23]
  wire [4:0] Int_status_3_io_pri_out; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_3_io_ID_in; // @[Int_nesting.scala 63:23]
  wire [3:0] Int_status_3_io_ID_out; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_io_act; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_io_deact; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_io_nest; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_io_denest; // @[Int_nesting.scala 63:23]
  wire  Int_status_3_io_status; // @[Int_nesting.scala 63:23]
  reg [1:0] StatusPtr; // @[Int_nesting.scala 65:24]
  wire  _io_empty_T = StatusPtr == 2'h0; // @[Int_nesting.scala 103:23]
  wire  _io_empty_T_2 = StatusPtr == 2'h0 & ~Int_status_io_status; // @[Int_nesting.scala 103:30]
  wire  _T = ~io_nest_disable; // @[Int_nesting.scala 112:23]
  wire  _T_7 = _io_empty_T & Int_status_io_status; // @[Int_nesting.scala 121:35]
  wire [4:0] _CurrentPri_T_2 = _io_empty_T ? 5'h1f : 5'h0; // @[Bitwise.scala 77:12]
  wire [4:0] _CurrentPri_T_3 = _CurrentPri_T_2 & Int_status_io_pri_out; // @[Int_nesting.scala 238:52]
  wire  _CurrentPri_T_4 = StatusPtr == 2'h1; // @[Int_nesting.scala 239:31]
  wire [4:0] _CurrentPri_T_6 = _CurrentPri_T_4 ? 5'h1f : 5'h0; // @[Bitwise.scala 77:12]
  wire [4:0] _CurrentPri_T_7 = _CurrentPri_T_6 & Int_status_1_io_pri_out; // @[Int_nesting.scala 239:40]
  wire [4:0] _CurrentPri_T_8 = _CurrentPri_T_3 | _CurrentPri_T_7; // @[Int_nesting.scala 238:78]
  wire  _CurrentPri_T_9 = StatusPtr == 2'h2; // @[Int_nesting.scala 240:31]
  wire [4:0] _CurrentPri_T_11 = _CurrentPri_T_9 ? 5'h1f : 5'h0; // @[Bitwise.scala 77:12]
  wire [4:0] _CurrentPri_T_12 = _CurrentPri_T_11 & Int_status_2_io_pri_out; // @[Int_nesting.scala 240:40]
  wire [4:0] _CurrentPri_T_13 = _CurrentPri_T_8 | _CurrentPri_T_12; // @[Int_nesting.scala 239:66]
  wire  _CurrentPri_T_14 = StatusPtr == 2'h3; // @[Int_nesting.scala 241:31]
  wire [4:0] _CurrentPri_T_16 = _CurrentPri_T_14 ? 5'h1f : 5'h0; // @[Bitwise.scala 77:12]
  wire [4:0] _CurrentPri_T_17 = _CurrentPri_T_16 & Int_status_3_io_pri_out; // @[Int_nesting.scala 241:40]
  wire [4:0] CurrentPri = _CurrentPri_T_13 | _CurrentPri_T_17; // @[Int_nesting.scala 240:66]
  wire  _T_11 = io_coming_pri[4:3] > CurrentPri[4:3]; // @[Int_nesting.scala 128:57]
  wire [1:0] _GEN_0 = _T_11 ? 2'h1 : StatusPtr; // @[Int_nesting.scala 129:9 130:20 65:24]
  wire [1:0] _GEN_1 = _T_11 ? 2'h2 : 2'h0; // @[Int_nesting.scala 129:9 131:20]
  wire [3:0] _GEN_3 = _T_11 ? io_coming_ID : 4'h0; // @[Int_nesting.scala 129:9 133:24]
  wire [4:0] _GEN_4 = _T_11 ? io_coming_pri : 5'h0; // @[Int_nesting.scala 129:9 134:26]
  wire [1:0] _GEN_5 = io_int_fin ? 2'h1 : _GEN_1; // @[Int_nesting.scala 124:9 125:20]
  wire [3:0] _GEN_6 = io_int_fin ? io_coming_ID : 4'h0; // @[Int_nesting.scala 124:9 126:25]
  wire [4:0] _GEN_7 = io_int_fin ? io_coming_pri : 5'h0; // @[Int_nesting.scala 124:9 127:26]
  wire [1:0] _GEN_8 = io_int_fin ? StatusPtr : _GEN_0; // @[Int_nesting.scala 124:9 65:24]
  wire  _GEN_9 = io_int_fin ? 1'h0 : _T_11; // @[Int_nesting.scala 124:9]
  wire [3:0] _GEN_10 = io_int_fin ? 4'h0 : _GEN_3; // @[Int_nesting.scala 124:9]
  wire [4:0] _GEN_11 = io_int_fin ? 5'h0 : _GEN_4; // @[Int_nesting.scala 124:9]
  wire [4:0] _NestedPri_T_3 = _CurrentPri_T_6 & Int_status_io_pri_out; // @[Int_nesting.scala 247:40]
  wire [4:0] _NestedPri_T_8 = _CurrentPri_T_11 & Int_status_1_io_pri_out; // @[Int_nesting.scala 248:40]
  wire [4:0] _NestedPri_T_9 = _NestedPri_T_3 | _NestedPri_T_8; // @[Int_nesting.scala 247:66]
  wire [4:0] _NestedPri_T_13 = _CurrentPri_T_16 & Int_status_2_io_pri_out; // @[Int_nesting.scala 249:40]
  wire [4:0] NestedPri = _NestedPri_T_9 | _NestedPri_T_13; // @[Int_nesting.scala 248:66]
  wire  _T_16 = io_coming_pri[4:3] > NestedPri[4:3]; // @[Int_nesting.scala 141:53]
  wire [3:0] _GEN_12 = _T_16 ? 4'h8 : 4'h0; // @[Int_nesting.scala 142:11 143:22]
  wire [3:0] _GEN_13 = _T_16 ? io_coming_ID : 4'h0; // @[Int_nesting.scala 142:11 144:26]
  wire [4:0] _GEN_14 = _T_16 ? io_coming_pri : 5'h0; // @[Int_nesting.scala 142:11 145:27]
  wire [3:0] _GEN_15 = _T_16 ? 4'h0 : 4'h8; // @[Int_nesting.scala 142:11 148:24]
  wire [2:0] _GEN_16 = _T_16 ? 3'h0 : 3'h4; // @[Int_nesting.scala 142:11 149:25]
  wire [1:0] _GEN_17 = _T_16 ? StatusPtr : 2'h2; // @[Int_nesting.scala 142:11 150:22 65:24]
  wire  _GEN_18 = _T_16 ? 1'h0 : 1'h1; // @[Int_nesting.scala 142:11 151:19]
  wire [3:0] _GEN_19 = io_int_fin ? _GEN_12 : 4'h0; // @[Int_nesting.scala 140:9]
  wire [3:0] _GEN_20 = io_int_fin ? _GEN_13 : 4'h0; // @[Int_nesting.scala 140:9]
  wire [4:0] _GEN_21 = io_int_fin ? _GEN_14 : 5'h0; // @[Int_nesting.scala 140:9]
  wire [3:0] _GEN_22 = io_int_fin ? _GEN_15 : 4'h0; // @[Int_nesting.scala 140:9]
  wire [2:0] _GEN_23 = io_int_fin ? _GEN_16 : 3'h0; // @[Int_nesting.scala 140:9]
  wire [1:0] _GEN_24 = io_int_fin ? _GEN_17 : StatusPtr; // @[Int_nesting.scala 140:9 65:24]
  wire  _GEN_25 = io_int_fin & _GEN_18; // @[Int_nesting.scala 140:9]
  wire [1:0] _GEN_26 = _T_16 ? 2'h2 : 2'h0; // @[Int_nesting.scala 159:11 160:22]
  wire [1:0] _GEN_29 = _T_16 ? 2'h0 : 2'h2; // @[Int_nesting.scala 159:11 165:24]
  wire [1:0] _GEN_31 = _T_16 ? StatusPtr : 2'h0; // @[Int_nesting.scala 159:11 167:23 65:24]
  wire [2:0] _GEN_34 = _T_11 ? 3'h4 : 3'h0; // @[Int_nesting.scala 173:11 176:22]
  wire [1:0] _GEN_37 = _T_11 ? 2'h2 : StatusPtr; // @[Int_nesting.scala 173:11 179:22 65:24]
  wire [2:0] _GEN_38 = io_int_fin ? {{1'd0}, _GEN_26} : _GEN_34; // @[Int_nesting.scala 157:9]
  wire [1:0] _GEN_41 = io_int_fin ? _GEN_29 : 2'h0; // @[Int_nesting.scala 157:9]
  wire [1:0] _GEN_43 = io_int_fin ? _GEN_31 : _GEN_37; // @[Int_nesting.scala 157:9]
  wire [1:0] _GEN_46 = io_int_fin ? 2'h0 : _GEN_1; // @[Int_nesting.scala 157:9]
  wire [2:0] _GEN_48 = _T_16 ? 3'h4 : 3'h0; // @[Int_nesting.scala 187:11 188:22]
  wire [3:0] _GEN_57 = _T_11 ? 4'h8 : 4'h0; // @[Int_nesting.scala 200:11 204:22]
  wire [1:0] _GEN_58 = _T_11 ? 2'h3 : StatusPtr; // @[Int_nesting.scala 200:11 205:22 65:24]
  wire [3:0] _GEN_60 = io_int_fin ? {{1'd0}, _GEN_48} : _GEN_57; // @[Int_nesting.scala 185:9]
  wire [1:0] _GEN_64 = io_int_fin ? _GEN_17 : _GEN_58; // @[Int_nesting.scala 185:9]
  wire [2:0] _GEN_68 = io_int_fin ? 3'h0 : _GEN_34; // @[Int_nesting.scala 185:9]
  wire [3:0] _GEN_70 = _CurrentPri_T_4 ? {{1'd0}, _GEN_38} : _GEN_60; // @[Int_nesting.scala 155:7]
  wire [3:0] _GEN_71 = _CurrentPri_T_4 ? _GEN_20 : 4'h0; // @[Int_nesting.scala 155:7]
  wire [4:0] _GEN_72 = _CurrentPri_T_4 ? _GEN_21 : 5'h0; // @[Int_nesting.scala 155:7]
  wire [2:0] _GEN_73 = _CurrentPri_T_4 ? {{1'd0}, _GEN_41} : _GEN_23; // @[Int_nesting.scala 155:7]
  wire  _GEN_74 = _CurrentPri_T_4 & _GEN_25; // @[Int_nesting.scala 155:7]
  wire [1:0] _GEN_75 = _CurrentPri_T_4 ? _GEN_43 : _GEN_64; // @[Int_nesting.scala 155:7]
  wire  _GEN_76 = _CurrentPri_T_4 ? _GEN_25 : _GEN_25; // @[Int_nesting.scala 155:7]
  wire [3:0] _GEN_77 = _CurrentPri_T_4 ? _GEN_10 : _GEN_20; // @[Int_nesting.scala 155:7]
  wire [4:0] _GEN_78 = _CurrentPri_T_4 ? _GEN_11 : _GEN_21; // @[Int_nesting.scala 155:7]
  wire [2:0] _GEN_79 = _CurrentPri_T_4 ? {{1'd0}, _GEN_46} : _GEN_68; // @[Int_nesting.scala 155:7]
  wire  _GEN_80 = _CurrentPri_T_4 ? _GEN_9 : _GEN_9; // @[Int_nesting.scala 155:7]
  wire [3:0] _GEN_81 = _CurrentPri_T_4 ? 4'h0 : _GEN_10; // @[Int_nesting.scala 155:7]
  wire [4:0] _GEN_82 = _CurrentPri_T_4 ? 5'h0 : _GEN_11; // @[Int_nesting.scala 155:7]
  wire [3:0] _GEN_83 = _CurrentPri_T_14 ? _GEN_19 : _GEN_70; // @[Int_nesting.scala 138:7]
  wire [3:0] _GEN_84 = _CurrentPri_T_14 ? _GEN_20 : _GEN_81; // @[Int_nesting.scala 138:7]
  wire [4:0] _GEN_85 = _CurrentPri_T_14 ? _GEN_21 : _GEN_82; // @[Int_nesting.scala 138:7]
  wire [3:0] _GEN_86 = _CurrentPri_T_14 ? _GEN_22 : {{1'd0}, _GEN_73}; // @[Int_nesting.scala 138:7]
  wire [2:0] _GEN_87 = _CurrentPri_T_14 ? _GEN_23 : {{2'd0}, _GEN_74}; // @[Int_nesting.scala 138:7]
  wire [1:0] _GEN_88 = _CurrentPri_T_14 ? _GEN_24 : _GEN_75; // @[Int_nesting.scala 138:7]
  wire  _GEN_89 = _CurrentPri_T_14 ? _GEN_25 : _GEN_76; // @[Int_nesting.scala 138:7]
  wire [3:0] _GEN_90 = _CurrentPri_T_14 ? 4'h0 : _GEN_71; // @[Int_nesting.scala 138:7]
  wire [4:0] _GEN_91 = _CurrentPri_T_14 ? 5'h0 : _GEN_72; // @[Int_nesting.scala 138:7]
  wire [3:0] _GEN_92 = _CurrentPri_T_14 ? 4'h0 : _GEN_77; // @[Int_nesting.scala 138:7]
  wire [4:0] _GEN_93 = _CurrentPri_T_14 ? 5'h0 : _GEN_78; // @[Int_nesting.scala 138:7]
  wire [2:0] _GEN_94 = _CurrentPri_T_14 ? 3'h0 : _GEN_79; // @[Int_nesting.scala 138:7]
  wire  _GEN_95 = _CurrentPri_T_14 ? 1'h0 : _GEN_80; // @[Int_nesting.scala 138:7]
  wire [3:0] _GEN_96 = _T_7 ? {{2'd0}, _GEN_5} : _GEN_83; // @[Int_nesting.scala 122:7]
  wire [3:0] _GEN_97 = _T_7 ? _GEN_6 : 4'h0; // @[Int_nesting.scala 122:7]
  wire [4:0] _GEN_98 = _T_7 ? _GEN_7 : 5'h0; // @[Int_nesting.scala 122:7]
  wire [1:0] _GEN_99 = _T_7 ? _GEN_8 : _GEN_88; // @[Int_nesting.scala 122:7]
  wire [2:0] _GEN_100 = _T_7 ? {{2'd0}, _GEN_9} : _GEN_94; // @[Int_nesting.scala 122:7]
  wire [3:0] _GEN_101 = _T_7 ? _GEN_10 : _GEN_90; // @[Int_nesting.scala 122:7]
  wire [4:0] _GEN_102 = _T_7 ? _GEN_11 : _GEN_91; // @[Int_nesting.scala 122:7]
  wire  _GEN_103 = _T_7 ? _GEN_9 : _GEN_95; // @[Int_nesting.scala 122:7]
  wire [3:0] _GEN_104 = _T_7 ? 4'h0 : _GEN_84; // @[Int_nesting.scala 122:7]
  wire [4:0] _GEN_105 = _T_7 ? 5'h0 : _GEN_85; // @[Int_nesting.scala 122:7]
  wire [3:0] _GEN_106 = _T_7 ? 4'h0 : _GEN_86; // @[Int_nesting.scala 122:7]
  wire [2:0] _GEN_107 = _T_7 ? 3'h0 : _GEN_87; // @[Int_nesting.scala 122:7]
  wire  _GEN_108 = _T_7 ? 1'h0 : _GEN_89; // @[Int_nesting.scala 122:7]
  wire [3:0] _GEN_109 = _T_7 ? 4'h0 : _GEN_92; // @[Int_nesting.scala 122:7]
  wire [4:0] _GEN_110 = _T_7 ? 5'h0 : _GEN_93; // @[Int_nesting.scala 122:7]
  wire [3:0] _GEN_111 = _io_empty_T_2 ? 4'h1 : _GEN_96; // @[Int_nesting.scala 117:7 118:18]
  wire [3:0] _GEN_112 = _io_empty_T_2 ? io_coming_ID : _GEN_97; // @[Int_nesting.scala 117:7 119:22]
  wire [4:0] _GEN_113 = _io_empty_T_2 ? io_coming_pri : _GEN_98; // @[Int_nesting.scala 117:7 120:23]
  wire [2:0] _GEN_115 = _io_empty_T_2 ? 3'h0 : _GEN_100; // @[Int_nesting.scala 117:7]
  wire [3:0] _GEN_116 = _io_empty_T_2 ? 4'h0 : _GEN_101; // @[Int_nesting.scala 117:7]
  wire [4:0] _GEN_117 = _io_empty_T_2 ? 5'h0 : _GEN_102; // @[Int_nesting.scala 117:7]
  wire  _GEN_118 = _io_empty_T_2 ? 1'h0 : _GEN_103; // @[Int_nesting.scala 117:7]
  wire [3:0] _GEN_119 = _io_empty_T_2 ? 4'h0 : _GEN_104; // @[Int_nesting.scala 117:7]
  wire [4:0] _GEN_120 = _io_empty_T_2 ? 5'h0 : _GEN_105; // @[Int_nesting.scala 117:7]
  wire [3:0] _GEN_121 = _io_empty_T_2 ? 4'h0 : _GEN_106; // @[Int_nesting.scala 117:7]
  wire [2:0] _GEN_122 = _io_empty_T_2 ? 3'h0 : _GEN_107; // @[Int_nesting.scala 117:7]
  wire  _GEN_123 = _io_empty_T_2 ? 1'h0 : _GEN_108; // @[Int_nesting.scala 117:7]
  wire [3:0] _GEN_124 = _io_empty_T_2 ? 4'h0 : _GEN_109; // @[Int_nesting.scala 117:7]
  wire [4:0] _GEN_125 = _io_empty_T_2 ? 5'h0 : _GEN_110; // @[Int_nesting.scala 117:7]
  wire [3:0] _StatusDeact_T_5 = {_CurrentPri_T_14,_CurrentPri_T_9,_CurrentPri_T_4,1'h0}; // @[Cat.scala 33:92]
  wire [3:0] _StatusDenest_T_5 = {1'h0,_CurrentPri_T_14,_CurrentPri_T_9,_CurrentPri_T_4}; // @[Cat.scala 33:92]
  wire [1:0] _StatusPtr_T_1 = StatusPtr - 2'h1; // @[Int_nesting.scala 219:29]
  wire [3:0] _GEN_126 = _io_empty_T ? 4'h1 : _StatusDeact_T_5; // @[Int_nesting.scala 213:7 214:20 217:21]
  wire [3:0] _GEN_127 = _io_empty_T ? 4'h0 : _StatusDenest_T_5; // @[Int_nesting.scala 213:7 218:22]
  wire [1:0] _GEN_128 = _io_empty_T ? StatusPtr : _StatusPtr_T_1; // @[Int_nesting.scala 213:7 219:18 65:24]
  wire [3:0] _GEN_129 = io_int_fin ? _GEN_126 : 4'h0; // @[Int_nesting.scala 211:5]
  wire [3:0] _GEN_130 = io_int_fin ? _GEN_127 : 4'h0; // @[Int_nesting.scala 211:5]
  wire [3:0] _GEN_132 = io_is_pending ? _GEN_111 : 4'h0; // @[Int_nesting.scala 115:5]
  wire [3:0] _GEN_133 = io_is_pending ? _GEN_112 : 4'h0; // @[Int_nesting.scala 115:5]
  wire [4:0] _GEN_134 = io_is_pending ? _GEN_113 : 5'h0; // @[Int_nesting.scala 115:5]
  wire [2:0] _GEN_136 = io_is_pending ? _GEN_115 : 3'h0; // @[Int_nesting.scala 115:5]
  wire [3:0] _GEN_137 = io_is_pending ? _GEN_116 : 4'h0; // @[Int_nesting.scala 115:5]
  wire [4:0] _GEN_138 = io_is_pending ? _GEN_117 : 5'h0; // @[Int_nesting.scala 115:5]
  wire  _GEN_139 = io_is_pending & _GEN_118; // @[Int_nesting.scala 115:5]
  wire [3:0] _GEN_140 = io_is_pending ? _GEN_119 : 4'h0; // @[Int_nesting.scala 115:5]
  wire [4:0] _GEN_141 = io_is_pending ? _GEN_120 : 5'h0; // @[Int_nesting.scala 115:5]
  wire [3:0] _GEN_142 = io_is_pending ? _GEN_121 : _GEN_129; // @[Int_nesting.scala 115:5]
  wire [3:0] _GEN_143 = io_is_pending ? {{1'd0}, _GEN_122} : _GEN_130; // @[Int_nesting.scala 115:5]
  wire  _GEN_144 = io_is_pending & _GEN_123; // @[Int_nesting.scala 115:5]
  wire [3:0] _GEN_145 = io_is_pending ? _GEN_124 : 4'h0; // @[Int_nesting.scala 115:5]
  wire [4:0] _GEN_146 = io_is_pending ? _GEN_125 : 5'h0; // @[Int_nesting.scala 115:5]
  wire [3:0] StatusAct = _T ? _GEN_132 : 4'h0; // @[Int_nesting.scala 113:3]
  wire [2:0] _GEN_151 = _T ? _GEN_136 : 3'h0; // @[Int_nesting.scala 113:3]
  wire [3:0] StatusDeact = _T ? _GEN_142 : 4'h0; // @[Int_nesting.scala 113:3]
  wire [3:0] StatusDenest = _T ? _GEN_143 : 4'h0; // @[Int_nesting.scala 113:3]
  wire [3:0] StatusNest = {{1'd0}, _GEN_151};
  wire [3:0] _CurrentID_T_2 = _io_empty_T ? 4'hf : 4'h0; // @[Bitwise.scala 77:12]
  wire [3:0] _CurrentID_T_3 = _CurrentID_T_2 & Int_status_io_ID_out; // @[Int_nesting.scala 234:48]
  wire [3:0] _CurrentID_T_6 = _CurrentPri_T_4 ? 4'hf : 4'h0; // @[Bitwise.scala 77:12]
  wire [3:0] _CurrentID_T_7 = _CurrentID_T_6 & Int_status_1_io_ID_out; // @[Int_nesting.scala 235:37]
  wire [3:0] _CurrentID_T_8 = _CurrentID_T_3 | _CurrentID_T_7; // @[Int_nesting.scala 234:73]
  wire [3:0] _CurrentID_T_11 = _CurrentPri_T_9 ? 4'hf : 4'h0; // @[Bitwise.scala 77:12]
  wire [3:0] _CurrentID_T_12 = _CurrentID_T_11 & Int_status_2_io_ID_out; // @[Int_nesting.scala 236:37]
  wire [3:0] _CurrentID_T_13 = _CurrentID_T_8 | _CurrentID_T_12; // @[Int_nesting.scala 235:62]
  wire [3:0] _CurrentID_T_16 = _CurrentPri_T_14 ? 4'hf : 4'h0; // @[Bitwise.scala 77:12]
  wire [3:0] _CurrentID_T_17 = _CurrentID_T_16 & Int_status_3_io_ID_out; // @[Int_nesting.scala 237:37]
  wire [3:0] _NestedID_T_3 = _CurrentID_T_6 & Int_status_io_ID_out; // @[Int_nesting.scala 243:37]
  wire [3:0] _NestedID_T_8 = _CurrentID_T_11 & Int_status_1_io_ID_out; // @[Int_nesting.scala 244:37]
  wire [3:0] _NestedID_T_9 = _NestedID_T_3 | _NestedID_T_8; // @[Int_nesting.scala 243:62]
  wire [3:0] _NestedID_T_13 = _CurrentID_T_16 & Int_status_2_io_ID_out; // @[Int_nesting.scala 245:37]
  Int_status Int_status ( // @[Int_nesting.scala 63:23]
    .clock(Int_status_clock),
    .reset(Int_status_reset),
    .io_pri_in(Int_status_io_pri_in),
    .io_pri_out(Int_status_io_pri_out),
    .io_ID_in(Int_status_io_ID_in),
    .io_ID_out(Int_status_io_ID_out),
    .io_act(Int_status_io_act),
    .io_deact(Int_status_io_deact),
    .io_nest(Int_status_io_nest),
    .io_denest(Int_status_io_denest),
    .io_status(Int_status_io_status)
  );
  Int_status Int_status_1 ( // @[Int_nesting.scala 63:23]
    .clock(Int_status_1_clock),
    .reset(Int_status_1_reset),
    .io_pri_in(Int_status_1_io_pri_in),
    .io_pri_out(Int_status_1_io_pri_out),
    .io_ID_in(Int_status_1_io_ID_in),
    .io_ID_out(Int_status_1_io_ID_out),
    .io_act(Int_status_1_io_act),
    .io_deact(Int_status_1_io_deact),
    .io_nest(Int_status_1_io_nest),
    .io_denest(Int_status_1_io_denest),
    .io_status(Int_status_1_io_status)
  );
  Int_status Int_status_2 ( // @[Int_nesting.scala 63:23]
    .clock(Int_status_2_clock),
    .reset(Int_status_2_reset),
    .io_pri_in(Int_status_2_io_pri_in),
    .io_pri_out(Int_status_2_io_pri_out),
    .io_ID_in(Int_status_2_io_ID_in),
    .io_ID_out(Int_status_2_io_ID_out),
    .io_act(Int_status_2_io_act),
    .io_deact(Int_status_2_io_deact),
    .io_nest(Int_status_2_io_nest),
    .io_denest(Int_status_2_io_denest),
    .io_status(Int_status_2_io_status)
  );
  Int_status Int_status_3 ( // @[Int_nesting.scala 63:23]
    .clock(Int_status_3_clock),
    .reset(Int_status_3_reset),
    .io_pri_in(Int_status_3_io_pri_in),
    .io_pri_out(Int_status_3_io_pri_out),
    .io_ID_in(Int_status_3_io_ID_in),
    .io_ID_out(Int_status_3_io_ID_out),
    .io_act(Int_status_3_io_act),
    .io_deact(Int_status_3_io_deact),
    .io_nest(Int_status_3_io_nest),
    .io_denest(Int_status_3_io_denest),
    .io_status(Int_status_3_io_status)
  );
  assign io_empty = StatusPtr == 2'h0 & ~Int_status_io_status; // @[Int_nesting.scala 103:30]
  assign io_current_pri = _CurrentPri_T_13 | _CurrentPri_T_17; // @[Int_nesting.scala 240:66]
  assign io_nested_pri = _NestedPri_T_9 | _NestedPri_T_13; // @[Int_nesting.scala 248:66]
  assign io_is_nesting = StatusPtr != 2'h0; // @[Int_nesting.scala 106:28]
  assign io_current_ID = _CurrentID_T_13 | _CurrentID_T_17; // @[Int_nesting.scala 236:62]
  assign io_nested_ID = _NestedID_T_9 | _NestedID_T_13; // @[Int_nesting.scala 244:62]
  assign io_en_nest = _T & _GEN_139; // @[Int_nesting.scala 113:3]
  assign io_de_nest = _T & _GEN_144; // @[Int_nesting.scala 113:3]
  assign Int_status_clock = clock;
  assign Int_status_reset = reset;
  assign Int_status_io_pri_in = _T ? _GEN_134 : 5'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_io_ID_in = _T ? _GEN_133 : 4'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_io_act = StatusAct[0]; // @[Int_nesting.scala 225:34]
  assign Int_status_io_deact = StatusDeact[0]; // @[Int_nesting.scala 226:38]
  assign Int_status_io_nest = StatusNest[0]; // @[Int_nesting.scala 227:36]
  assign Int_status_io_denest = StatusDenest[0]; // @[Int_nesting.scala 228:40]
  assign Int_status_1_clock = clock;
  assign Int_status_1_reset = reset;
  assign Int_status_1_io_pri_in = _T ? _GEN_138 : 5'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_1_io_ID_in = _T ? _GEN_137 : 4'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_1_io_act = StatusAct[1]; // @[Int_nesting.scala 225:34]
  assign Int_status_1_io_deact = StatusDeact[1]; // @[Int_nesting.scala 226:38]
  assign Int_status_1_io_nest = StatusNest[1]; // @[Int_nesting.scala 227:36]
  assign Int_status_1_io_denest = StatusDenest[1]; // @[Int_nesting.scala 228:40]
  assign Int_status_2_clock = clock;
  assign Int_status_2_reset = reset;
  assign Int_status_2_io_pri_in = _T ? _GEN_146 : 5'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_2_io_ID_in = _T ? _GEN_145 : 4'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_2_io_act = StatusAct[2]; // @[Int_nesting.scala 225:34]
  assign Int_status_2_io_deact = StatusDeact[2]; // @[Int_nesting.scala 226:38]
  assign Int_status_2_io_nest = StatusNest[2]; // @[Int_nesting.scala 227:36]
  assign Int_status_2_io_denest = StatusDenest[2]; // @[Int_nesting.scala 228:40]
  assign Int_status_3_clock = clock;
  assign Int_status_3_reset = reset;
  assign Int_status_3_io_pri_in = _T ? _GEN_141 : 5'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_3_io_ID_in = _T ? _GEN_140 : 4'h0; // @[Int_nesting.scala 113:3]
  assign Int_status_3_io_act = StatusAct[3]; // @[Int_nesting.scala 225:34]
  assign Int_status_3_io_deact = StatusDeact[3]; // @[Int_nesting.scala 226:38]
  assign Int_status_3_io_nest = StatusNest[3]; // @[Int_nesting.scala 227:36]
  assign Int_status_3_io_denest = StatusDenest[3]; // @[Int_nesting.scala 228:40]
  always @(posedge clock) begin
    if (reset) begin // @[Int_nesting.scala 65:24]
      StatusPtr <= 2'h0; // @[Int_nesting.scala 65:24]
    end else if (_T) begin // @[Int_nesting.scala 113:3]
      if (io_is_pending) begin // @[Int_nesting.scala 115:5]
        if (!(_io_empty_T_2)) begin // @[Int_nesting.scala 117:7]
          StatusPtr <= _GEN_99;
        end
      end else if (io_int_fin) begin // @[Int_nesting.scala 211:5]
        StatusPtr <= _GEN_128;
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
  StatusPtr = _RAND_0[1:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
