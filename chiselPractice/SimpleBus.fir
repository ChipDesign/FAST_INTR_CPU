circuit SimpleBus :
  module Arbiter :
    input clock : Clock
    input reset : Reset
    output io : { flip in : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}[4], out : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}, chosen : UInt<2>}

    io.chosen <= UInt<2>("h3") @[Arbiter.scala 135:13]
    io.out.bits <= io.in[3].bits @[Arbiter.scala 136:15]
    when io.in[2].valid : @[Arbiter.scala 138:26]
      io.chosen <= UInt<2>("h2") @[Arbiter.scala 139:17]
      io.out.bits <= io.in[2].bits @[Arbiter.scala 140:19]
    when io.in[1].valid : @[Arbiter.scala 138:26]
      io.chosen <= UInt<1>("h1") @[Arbiter.scala 139:17]
      io.out.bits <= io.in[1].bits @[Arbiter.scala 140:19]
    when io.in[0].valid : @[Arbiter.scala 138:26]
      io.chosen <= UInt<1>("h0") @[Arbiter.scala 139:17]
      io.out.bits <= io.in[0].bits @[Arbiter.scala 140:19]
    node _grant_T = or(io.in[0].valid, io.in[1].valid) @[Arbiter.scala 45:68]
    node _grant_T_1 = or(_grant_T, io.in[2].valid) @[Arbiter.scala 45:68]
    node grant_1 = eq(io.in[0].valid, UInt<1>("h0")) @[Arbiter.scala 45:78]
    node grant_2 = eq(_grant_T, UInt<1>("h0")) @[Arbiter.scala 45:78]
    node grant_3 = eq(_grant_T_1, UInt<1>("h0")) @[Arbiter.scala 45:78]
    node _io_in_0_ready_T = and(UInt<1>("h1"), io.out.ready) @[Arbiter.scala 146:19]
    io.in[0].ready <= _io_in_0_ready_T @[Arbiter.scala 146:14]
    node _io_in_1_ready_T = and(grant_1, io.out.ready) @[Arbiter.scala 146:19]
    io.in[1].ready <= _io_in_1_ready_T @[Arbiter.scala 146:14]
    node _io_in_2_ready_T = and(grant_2, io.out.ready) @[Arbiter.scala 146:19]
    io.in[2].ready <= _io_in_2_ready_T @[Arbiter.scala 146:14]
    node _io_in_3_ready_T = and(grant_3, io.out.ready) @[Arbiter.scala 146:19]
    io.in[3].ready <= _io_in_3_ready_T @[Arbiter.scala 146:14]
    node _io_out_valid_T = eq(grant_3, UInt<1>("h0")) @[Arbiter.scala 147:19]
    node _io_out_valid_T_1 = or(_io_out_valid_T, io.in[3].valid) @[Arbiter.scala 147:31]
    io.out.valid <= _io_out_valid_T_1 @[Arbiter.scala 147:16]

  module BusMaster :
    input clock : Clock
    input reset : Reset
    output io : { data : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}}

    reg cnt_value : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Counter.scala 61:40]
    reg reg0 : UInt<8>[4], clock with :
      reset => (UInt<1>("h0"), reg0) @[SimpleBus.scala 26:16]
    node _T = asUInt(reset) @[SimpleBus.scala 27:14]
    when _T : @[SimpleBus.scala 27:21]
      reg0[0] <= UInt<2>("h3") @[SimpleBus.scala 30:15]
      reg0[1] <= UInt<3>("h6") @[SimpleBus.scala 30:15]
      reg0[2] <= UInt<4>("h9") @[SimpleBus.scala 30:15]
      reg0[3] <= UInt<4>("hc") @[SimpleBus.scala 30:15]
    when io.data.ready : @[SimpleBus.scala 36:3]
      node wrap = eq(cnt_value, UInt<3>("h4")) @[Counter.scala 73:24]
      node _value_T = add(cnt_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_1 = tail(_value_T, 1) @[Counter.scala 77:24]
      cnt_value <= _value_T_1 @[Counter.scala 77:15]
      when wrap : @[Counter.scala 87:20]
        cnt_value <= UInt<1>("h0") @[Counter.scala 87:28]
    node _T_1 = lt(cnt_value, UInt<3>("h4")) @[SimpleBus.scala 40:17]
    when _T_1 : @[SimpleBus.scala 41:3]
      io.data.valid <= UInt<1>("h1") @[SimpleBus.scala 42:18]
      node _io_data_bits_T = bits(cnt_value, 1, 0)
      io.data.bits <= reg0[_io_data_bits_T] @[SimpleBus.scala 43:17]
    else :
      io.data.valid <= UInt<1>("h0") @[SimpleBus.scala 46:18]
      io.data.bits <= UInt<1>("h0") @[SimpleBus.scala 47:17]

  module BusMaster_1 :
    input clock : Clock
    input reset : Reset
    output io : { data : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}}

    reg cnt_value : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Counter.scala 61:40]
    reg reg0 : UInt<8>[4], clock with :
      reset => (UInt<1>("h0"), reg0) @[SimpleBus.scala 26:16]
    node _T = asUInt(reset) @[SimpleBus.scala 27:14]
    when _T : @[SimpleBus.scala 27:21]
      reg0[0] <= UInt<4>("hf") @[SimpleBus.scala 30:15]
      reg0[1] <= UInt<1>("h1") @[SimpleBus.scala 30:15]
      reg0[2] <= UInt<3>("h4") @[SimpleBus.scala 30:15]
      reg0[3] <= UInt<3>("h7") @[SimpleBus.scala 30:15]
    when io.data.ready : @[SimpleBus.scala 36:3]
      node wrap = eq(cnt_value, UInt<3>("h4")) @[Counter.scala 73:24]
      node _value_T = add(cnt_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_1 = tail(_value_T, 1) @[Counter.scala 77:24]
      cnt_value <= _value_T_1 @[Counter.scala 77:15]
      when wrap : @[Counter.scala 87:20]
        cnt_value <= UInt<1>("h0") @[Counter.scala 87:28]
    node _T_1 = lt(cnt_value, UInt<3>("h4")) @[SimpleBus.scala 40:17]
    when _T_1 : @[SimpleBus.scala 41:3]
      io.data.valid <= UInt<1>("h1") @[SimpleBus.scala 42:18]
      node _io_data_bits_T = bits(cnt_value, 1, 0)
      io.data.bits <= reg0[_io_data_bits_T] @[SimpleBus.scala 43:17]
    else :
      io.data.valid <= UInt<1>("h0") @[SimpleBus.scala 46:18]
      io.data.bits <= UInt<1>("h0") @[SimpleBus.scala 47:17]

  module BusMaster_2 :
    input clock : Clock
    input reset : Reset
    output io : { data : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}}

    reg cnt_value : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Counter.scala 61:40]
    reg reg0 : UInt<8>[4], clock with :
      reset => (UInt<1>("h0"), reg0) @[SimpleBus.scala 26:16]
    node _T = asUInt(reset) @[SimpleBus.scala 27:14]
    when _T : @[SimpleBus.scala 27:21]
      reg0[0] <= UInt<4>("ha") @[SimpleBus.scala 30:15]
      reg0[1] <= UInt<4>("hd") @[SimpleBus.scala 30:15]
      reg0[2] <= UInt<5>("h10") @[SimpleBus.scala 30:15]
      reg0[3] <= UInt<2>("h2") @[SimpleBus.scala 30:15]
    when io.data.ready : @[SimpleBus.scala 36:3]
      node wrap = eq(cnt_value, UInt<3>("h4")) @[Counter.scala 73:24]
      node _value_T = add(cnt_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_1 = tail(_value_T, 1) @[Counter.scala 77:24]
      cnt_value <= _value_T_1 @[Counter.scala 77:15]
      when wrap : @[Counter.scala 87:20]
        cnt_value <= UInt<1>("h0") @[Counter.scala 87:28]
    node _T_1 = lt(cnt_value, UInt<3>("h4")) @[SimpleBus.scala 40:17]
    when _T_1 : @[SimpleBus.scala 41:3]
      io.data.valid <= UInt<1>("h1") @[SimpleBus.scala 42:18]
      node _io_data_bits_T = bits(cnt_value, 1, 0)
      io.data.bits <= reg0[_io_data_bits_T] @[SimpleBus.scala 43:17]
    else :
      io.data.valid <= UInt<1>("h0") @[SimpleBus.scala 46:18]
      io.data.bits <= UInt<1>("h0") @[SimpleBus.scala 47:17]

  module BusMaster_3 :
    input clock : Clock
    input reset : Reset
    output io : { data : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}}

    reg cnt_value : UInt<3>, clock with :
      reset => (reset, UInt<3>("h0")) @[Counter.scala 61:40]
    reg reg0 : UInt<8>[4], clock with :
      reset => (UInt<1>("h0"), reg0) @[SimpleBus.scala 26:16]
    node _T = asUInt(reset) @[SimpleBus.scala 27:14]
    when _T : @[SimpleBus.scala 27:21]
      reg0[0] <= UInt<3>("h5") @[SimpleBus.scala 30:15]
      reg0[1] <= UInt<4>("h8") @[SimpleBus.scala 30:15]
      reg0[2] <= UInt<4>("hb") @[SimpleBus.scala 30:15]
      reg0[3] <= UInt<4>("he") @[SimpleBus.scala 30:15]
    when io.data.ready : @[SimpleBus.scala 36:3]
      node wrap = eq(cnt_value, UInt<3>("h4")) @[Counter.scala 73:24]
      node _value_T = add(cnt_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_1 = tail(_value_T, 1) @[Counter.scala 77:24]
      cnt_value <= _value_T_1 @[Counter.scala 77:15]
      when wrap : @[Counter.scala 87:20]
        cnt_value <= UInt<1>("h0") @[Counter.scala 87:28]
    node _T_1 = lt(cnt_value, UInt<3>("h4")) @[SimpleBus.scala 40:17]
    when _T_1 : @[SimpleBus.scala 41:3]
      io.data.valid <= UInt<1>("h1") @[SimpleBus.scala 42:18]
      node _io_data_bits_T = bits(cnt_value, 1, 0)
      io.data.bits <= reg0[_io_data_bits_T] @[SimpleBus.scala 43:17]
    else :
      io.data.valid <= UInt<1>("h0") @[SimpleBus.scala 46:18]
      io.data.bits <= UInt<1>("h0") @[SimpleBus.scala 47:17]

  module Queue :
    input clock : Clock
    input reset : Reset
    output io : { flip enq : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}, deq : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}, count : UInt<5>}

    cmem ram : UInt<8> [16] @[Decoupled.scala 275:95]
    reg enq_ptr_value : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Counter.scala 61:40]
    reg deq_ptr_value : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Counter.scala 61:40]
    reg maybe_full : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Decoupled.scala 278:27]
    node ptr_match = eq(enq_ptr_value, deq_ptr_value) @[Decoupled.scala 279:33]
    node _empty_T = eq(maybe_full, UInt<1>("h0")) @[Decoupled.scala 280:28]
    node empty = and(ptr_match, _empty_T) @[Decoupled.scala 280:25]
    node full = and(ptr_match, maybe_full) @[Decoupled.scala 281:24]
    node _do_enq_T = and(io.enq.ready, io.enq.valid) @[Decoupled.scala 52:35]
    wire do_enq : UInt<1>
    do_enq <= _do_enq_T
    node _do_deq_T = and(io.deq.ready, io.deq.valid) @[Decoupled.scala 52:35]
    wire do_deq : UInt<1>
    do_deq <= _do_deq_T
    when do_enq : @[Decoupled.scala 288:16]
      infer mport MPORT = ram[enq_ptr_value], clock @[Decoupled.scala 289:8]
      MPORT <= io.enq.bits @[Decoupled.scala 289:24]
      node wrap = eq(enq_ptr_value, UInt<4>("hf")) @[Counter.scala 73:24]
      node _value_T = add(enq_ptr_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_1 = tail(_value_T, 1) @[Counter.scala 77:24]
      enq_ptr_value <= _value_T_1 @[Counter.scala 77:15]
    when do_deq : @[Decoupled.scala 292:16]
      node wrap_1 = eq(deq_ptr_value, UInt<4>("hf")) @[Counter.scala 73:24]
      node _value_T_2 = add(deq_ptr_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_3 = tail(_value_T_2, 1) @[Counter.scala 77:24]
      deq_ptr_value <= _value_T_3 @[Counter.scala 77:15]
    node _T = neq(do_enq, do_deq) @[Decoupled.scala 295:15]
    when _T : @[Decoupled.scala 295:27]
      maybe_full <= do_enq @[Decoupled.scala 296:16]
    when UInt<1>("h0") : @[Decoupled.scala 298:15]
      enq_ptr_value <= UInt<1>("h0") @[Counter.scala 98:11]
      deq_ptr_value <= UInt<1>("h0") @[Counter.scala 98:11]
      maybe_full <= UInt<1>("h0") @[Decoupled.scala 301:16]
    node _io_deq_valid_T = eq(empty, UInt<1>("h0")) @[Decoupled.scala 304:19]
    io.deq.valid <= _io_deq_valid_T @[Decoupled.scala 304:16]
    node _io_enq_ready_T = eq(full, UInt<1>("h0")) @[Decoupled.scala 305:19]
    io.enq.ready <= _io_enq_ready_T @[Decoupled.scala 305:16]
    infer mport io_deq_bits_MPORT = ram[deq_ptr_value], clock @[Decoupled.scala 312:23]
    io.deq.bits <= io_deq_bits_MPORT @[Decoupled.scala 312:17]
    node _ptr_diff_T = sub(enq_ptr_value, deq_ptr_value) @[Decoupled.scala 328:32]
    node ptr_diff = tail(_ptr_diff_T, 1) @[Decoupled.scala 328:32]
    node _io_count_T = and(maybe_full, ptr_match) @[Decoupled.scala 331:32]
    node _io_count_T_1 = mux(_io_count_T, UInt<5>("h10"), UInt<1>("h0")) @[Decoupled.scala 331:20]
    node _io_count_T_2 = or(_io_count_T_1, ptr_diff) @[Decoupled.scala 331:62]
    io.count <= _io_count_T_2 @[Decoupled.scala 331:14]

  module BusSlave :
    input clock : Clock
    input reset : Reset
    output io : { flip data_in : { flip ready : UInt<1>, valid : UInt<1>, bits : UInt<8>}, QueueOut : UInt<8>, flip OutReady : UInt<1>}

    inst AccQueue of Queue @[SimpleBus.scala 57:22]
    AccQueue.clock <= clock
    AccQueue.reset <= reset
    AccQueue.io.enq <= io.data_in @[SimpleBus.scala 58:18]
    io.QueueOut <= AccQueue.io.deq.bits @[SimpleBus.scala 59:15]
    AccQueue.io.deq.ready <= io.OutReady @[SimpleBus.scala 60:24]

  module SimpleBus :
    input clock : Clock
    input reset : UInt<1>
    output io : { SlaveDataOut : UInt<8>}

    inst arbi of Arbiter @[SimpleBus.scala 67:18]
    arbi.clock <= clock
    arbi.reset <= reset
    inst M1 of BusMaster @[SimpleBus.scala 68:16]
    M1.clock <= clock
    M1.reset <= reset
    inst M2 of BusMaster_1 @[SimpleBus.scala 69:16]
    M2.clock <= clock
    M2.reset <= reset
    inst M3 of BusMaster_2 @[SimpleBus.scala 70:16]
    M3.clock <= clock
    M3.reset <= reset
    inst M4 of BusMaster_3 @[SimpleBus.scala 71:16]
    M4.clock <= clock
    M4.reset <= reset
    arbi.io.in[0] <= M1.io.data @[SimpleBus.scala 72:13]
    arbi.io.in[1] <= M2.io.data @[SimpleBus.scala 73:13]
    arbi.io.in[2] <= M3.io.data @[SimpleBus.scala 74:13]
    arbi.io.in[3] <= M4.io.data @[SimpleBus.scala 75:13]
    inst S of BusSlave @[SimpleBus.scala 77:15]
    S.clock <= clock
    S.reset <= reset
    io.SlaveDataOut <= S.io.QueueOut @[SimpleBus.scala 78:18]
    S.io.data_in <= arbi.io.out @[SimpleBus.scala 79:15]
    reg cnt_value : UInt<5>, clock with :
      reset => (reset, UInt<5>("h0")) @[Counter.scala 61:40]
    reg OutReady : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[SimpleBus.scala 82:23]
    when arbi.io.out.valid : @[SimpleBus.scala 84:3]
      node wrap = eq(cnt_value, UInt<5>("h14")) @[Counter.scala 73:24]
      node _value_T = add(cnt_value, UInt<1>("h1")) @[Counter.scala 77:24]
      node _value_T_1 = tail(_value_T, 1) @[Counter.scala 77:24]
      cnt_value <= _value_T_1 @[Counter.scala 77:15]
      when wrap : @[Counter.scala 87:20]
        cnt_value <= UInt<1>("h0") @[Counter.scala 87:28]
    node _T = eq(cnt_value, UInt<5>("h10")) @[SimpleBus.scala 87:17]
    when _T : @[SimpleBus.scala 88:3]
      OutReady <= UInt<1>("h1") @[SimpleBus.scala 89:13]
    S.io.OutReady <= OutReady @[SimpleBus.scala 91:16]

