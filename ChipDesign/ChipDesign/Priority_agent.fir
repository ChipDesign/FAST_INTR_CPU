circuit Priority_agent :
  module Pri_elem :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h0")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_1 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h1")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_2 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h2")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_3 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h3")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_4 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h4")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_5 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h5")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_6 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h6")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_7 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h1")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h7")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_8 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h8")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_9 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("h9")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_10 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("ha")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_11 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("hb")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_12 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("hc")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_13 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("hd")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_14 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("he")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module Pri_elem_15 :
    input clock : Clock
    input reset : Reset
    output io : { id : UInt<4>, pri : UInt<5>, flip pri_update : UInt<5>, flip pri_update_sig : UInt<1>, flip elem_act : UInt<1>, flip elem_deact : UInt<1>, actevated : UInt<1>}

    reg Pri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 21:18]
    reg ID : UInt<4>, clock with :
      reset => (reset, UInt<4>("hf")) @[Priority_agent.scala 22:17]
    reg act : UInt<1>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 23:18]
    node _T = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 26:26]
    when _T : @[Priority_agent.scala 27:3]
      Pri <= io.pri_update @[Priority_agent.scala 28:8]
    io.id <= ID @[Priority_agent.scala 30:8]
    io.pri <= Pri @[Priority_agent.scala 31:9]
    io.actevated <= act @[Priority_agent.scala 32:15]
    node _T_1 = bits(io.elem_act, 0, 0) @[Priority_agent.scala 35:20]
    when _T_1 : @[Priority_agent.scala 36:3]
      act <= UInt<1>("h1") @[Priority_agent.scala 36:7]
    node _T_2 = bits(io.elem_deact, 0, 0) @[Priority_agent.scala 37:22]
    when _T_2 : @[Priority_agent.scala 38:3]
      act <= UInt<1>("h0") @[Priority_agent.scala 38:7]
    node _T_3 = bits(io.pri_update_sig, 0, 0) @[Priority_agent.scala 39:26]
    when _T_3 : @[Priority_agent.scala 40:3]
      Pri <= io.pri_update @[Priority_agent.scala 40:7]

  module By_ID_sel :
    input clock : Clock
    input reset : Reset
    output io : { sel_sig : UInt<1>[8], flip ID_in : UInt<4>}

    reg IDs : UInt<4>[8], clock with :
      reset => (UInt<1>("h0"), IDs) @[By_ID_sel.scala 7:14]
    IDs[0] <= UInt<4>("h8") @[By_ID_sel.scala 12:15]
    IDs[1] <= UInt<4>("h9") @[By_ID_sel.scala 12:15]
    IDs[2] <= UInt<4>("ha") @[By_ID_sel.scala 12:15]
    IDs[3] <= UInt<4>("hb") @[By_ID_sel.scala 12:15]
    IDs[4] <= UInt<4>("hc") @[By_ID_sel.scala 12:15]
    IDs[5] <= UInt<4>("hd") @[By_ID_sel.scala 12:15]
    IDs[6] <= UInt<4>("he") @[By_ID_sel.scala 12:15]
    IDs[7] <= UInt<4>("hf") @[By_ID_sel.scala 12:15]
    node _io_sel_sig_0_T = eq(io.ID_in, IDs[0]) @[By_ID_sel.scala 21:31]
    io.sel_sig[0] <= _io_sel_sig_0_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_1_T = eq(io.ID_in, IDs[1]) @[By_ID_sel.scala 21:31]
    io.sel_sig[1] <= _io_sel_sig_1_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_2_T = eq(io.ID_in, IDs[2]) @[By_ID_sel.scala 21:31]
    io.sel_sig[2] <= _io_sel_sig_2_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_3_T = eq(io.ID_in, IDs[3]) @[By_ID_sel.scala 21:31]
    io.sel_sig[3] <= _io_sel_sig_3_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_4_T = eq(io.ID_in, IDs[4]) @[By_ID_sel.scala 21:31]
    io.sel_sig[4] <= _io_sel_sig_4_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_5_T = eq(io.ID_in, IDs[5]) @[By_ID_sel.scala 21:31]
    io.sel_sig[5] <= _io_sel_sig_5_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_6_T = eq(io.ID_in, IDs[6]) @[By_ID_sel.scala 21:31]
    io.sel_sig[6] <= _io_sel_sig_6_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_7_T = eq(io.ID_in, IDs[7]) @[By_ID_sel.scala 21:31]
    io.sel_sig[7] <= _io_sel_sig_7_T @[By_ID_sel.scala 21:20]

  module By_ID_sel_1 :
    input clock : Clock
    input reset : Reset
    output io : { sel_sig : UInt<1>[8], flip ID_in : UInt<4>}

    reg IDs : UInt<4>[8], clock with :
      reset => (UInt<1>("h0"), IDs) @[By_ID_sel.scala 7:14]
    IDs[0] <= UInt<4>("h8") @[By_ID_sel.scala 12:15]
    IDs[1] <= UInt<4>("h9") @[By_ID_sel.scala 12:15]
    IDs[2] <= UInt<4>("ha") @[By_ID_sel.scala 12:15]
    IDs[3] <= UInt<4>("hb") @[By_ID_sel.scala 12:15]
    IDs[4] <= UInt<4>("hc") @[By_ID_sel.scala 12:15]
    IDs[5] <= UInt<4>("hd") @[By_ID_sel.scala 12:15]
    IDs[6] <= UInt<4>("he") @[By_ID_sel.scala 12:15]
    IDs[7] <= UInt<4>("hf") @[By_ID_sel.scala 12:15]
    node _io_sel_sig_0_T = eq(io.ID_in, IDs[0]) @[By_ID_sel.scala 21:31]
    io.sel_sig[0] <= _io_sel_sig_0_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_1_T = eq(io.ID_in, IDs[1]) @[By_ID_sel.scala 21:31]
    io.sel_sig[1] <= _io_sel_sig_1_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_2_T = eq(io.ID_in, IDs[2]) @[By_ID_sel.scala 21:31]
    io.sel_sig[2] <= _io_sel_sig_2_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_3_T = eq(io.ID_in, IDs[3]) @[By_ID_sel.scala 21:31]
    io.sel_sig[3] <= _io_sel_sig_3_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_4_T = eq(io.ID_in, IDs[4]) @[By_ID_sel.scala 21:31]
    io.sel_sig[4] <= _io_sel_sig_4_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_5_T = eq(io.ID_in, IDs[5]) @[By_ID_sel.scala 21:31]
    io.sel_sig[5] <= _io_sel_sig_5_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_6_T = eq(io.ID_in, IDs[6]) @[By_ID_sel.scala 21:31]
    io.sel_sig[6] <= _io_sel_sig_6_T @[By_ID_sel.scala 21:20]
    node _io_sel_sig_7_T = eq(io.ID_in, IDs[7]) @[By_ID_sel.scala 21:31]
    io.sel_sig[7] <= _io_sel_sig_7_T @[By_ID_sel.scala 21:20]

  module Priority_agent :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip dyn_int_claim_sig : UInt<1>, int_pri : UInt<5>[16], flip dyn_int_occ_sig : UInt<1>, flip dyn_int_occ_ID : UInt<4>, flip dyn_int_claim_ID : UInt<4>}

    inst Pri_elem of Pri_elem @[Priority_agent.scala 50:25]
    Pri_elem.clock <= clock
    Pri_elem.reset <= reset
    inst Pri_elem_1 of Pri_elem_1 @[Priority_agent.scala 50:25]
    Pri_elem_1.clock <= clock
    Pri_elem_1.reset <= reset
    inst Pri_elem_2 of Pri_elem_2 @[Priority_agent.scala 50:25]
    Pri_elem_2.clock <= clock
    Pri_elem_2.reset <= reset
    inst Pri_elem_3 of Pri_elem_3 @[Priority_agent.scala 50:25]
    Pri_elem_3.clock <= clock
    Pri_elem_3.reset <= reset
    inst Pri_elem_4 of Pri_elem_4 @[Priority_agent.scala 50:25]
    Pri_elem_4.clock <= clock
    Pri_elem_4.reset <= reset
    inst Pri_elem_5 of Pri_elem_5 @[Priority_agent.scala 50:25]
    Pri_elem_5.clock <= clock
    Pri_elem_5.reset <= reset
    inst Pri_elem_6 of Pri_elem_6 @[Priority_agent.scala 50:25]
    Pri_elem_6.clock <= clock
    Pri_elem_6.reset <= reset
    inst Pri_elem_7 of Pri_elem_7 @[Priority_agent.scala 50:25]
    Pri_elem_7.clock <= clock
    Pri_elem_7.reset <= reset
    inst Pri_elem_8 of Pri_elem_8 @[Priority_agent.scala 54:24]
    Pri_elem_8.clock <= clock
    Pri_elem_8.reset <= reset
    inst Pri_elem_9 of Pri_elem_9 @[Priority_agent.scala 54:24]
    Pri_elem_9.clock <= clock
    Pri_elem_9.reset <= reset
    inst Pri_elem_10 of Pri_elem_10 @[Priority_agent.scala 54:24]
    Pri_elem_10.clock <= clock
    Pri_elem_10.reset <= reset
    inst Pri_elem_11 of Pri_elem_11 @[Priority_agent.scala 54:24]
    Pri_elem_11.clock <= clock
    Pri_elem_11.reset <= reset
    inst Pri_elem_12 of Pri_elem_12 @[Priority_agent.scala 54:24]
    Pri_elem_12.clock <= clock
    Pri_elem_12.reset <= reset
    inst Pri_elem_13 of Pri_elem_13 @[Priority_agent.scala 54:24]
    Pri_elem_13.clock <= clock
    Pri_elem_13.reset <= reset
    inst Pri_elem_14 of Pri_elem_14 @[Priority_agent.scala 54:24]
    Pri_elem_14.clock <= clock
    Pri_elem_14.reset <= reset
    inst Pri_elem_15 of Pri_elem_15 @[Priority_agent.scala 54:24]
    Pri_elem_15.clock <= clock
    Pri_elem_15.reset <= reset
    reg InitPri : UInt<5>, clock with :
      reset => (reset, UInt<5>("h2")) @[Priority_agent.scala 56:22]
    reg Tcnt : UInt<3>, clock with :
      reset => (reset, UInt<1>("h0")) @[Priority_agent.scala 57:19]
    inst IntClaimSel of By_ID_sel @[Priority_agent.scala 59:25]
    IntClaimSel.clock <= clock
    IntClaimSel.reset <= reset
    inst IntOccSel of By_ID_sel_1 @[Priority_agent.scala 60:23]
    IntOccSel.clock <= clock
    IntOccSel.reset <= reset
    wire DynamPriUpdate : UInt<5>[8] @[Priority_agent.scala 61:26]
    wire PriUpdateSig : UInt<1> @[Priority_agent.scala 62:24]
    io.int_pri[0] <= Pri_elem.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[1] <= Pri_elem_1.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[2] <= Pri_elem_2.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[3] <= Pri_elem_3.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[4] <= Pri_elem_4.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[5] <= Pri_elem_5.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[6] <= Pri_elem_6.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[7] <= Pri_elem_7.io.pri @[Priority_agent.scala 75:18]
    io.int_pri[8] <= Pri_elem_8.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[9] <= Pri_elem_9.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[10] <= Pri_elem_10.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[11] <= Pri_elem_11.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[12] <= Pri_elem_12.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[13] <= Pri_elem_13.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[14] <= Pri_elem_14.io.pri @[Priority_agent.scala 78:31]
    io.int_pri[15] <= Pri_elem_15.io.pri @[Priority_agent.scala 78:31]
    IntOccSel.io.ID_in <= io.dyn_int_occ_ID @[Priority_agent.scala 80:21]
    IntClaimSel.io.ID_in <= io.dyn_int_claim_ID @[Priority_agent.scala 81:23]
    Pri_elem.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_1.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_1.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_1.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_1.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_2.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_2.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_2.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_2.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_3.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_3.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_3.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_3.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_4.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_4.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_4.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_4.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_5.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_5.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_5.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_5.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_6.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_6.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_6.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_6.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_7.io.elem_deact <= UInt<1>("h1") @[Priority_agent.scala 84:30]
    Pri_elem_7.io.elem_act <= UInt<1>("h0") @[Priority_agent.scala 85:28]
    Pri_elem_7.io.pri_update_sig <= UInt<1>("h0") @[Priority_agent.scala 86:34]
    Pri_elem_7.io.pri_update <= UInt<5>("h0") @[Priority_agent.scala 87:30]
    Pri_elem_8.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T = bits(IntOccSel.io.sel_sig[0], 0, 0) @[Bitwise.scala 77:15]
    node _T_1 = mux(_T, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_2 = and(_T_1, InitPri) @[Priority_agent.scala 94:73]
    node _T_3 = eq(IntOccSel.io.sel_sig[0], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_4 = and(_T_3, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_5 = bits(_T_4, 0, 0) @[Bitwise.scala 77:15]
    node _T_6 = mux(_T_5, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_7 = and(_T_6, DynamPriUpdate[0]) @[Priority_agent.scala 95:64]
    node _T_8 = or(_T_2, _T_7) @[Priority_agent.scala 94:84]
    Pri_elem_8.io.pri_update <= _T_8 @[Priority_agent.scala 94:32]
    node _T_9 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[0]) @[Priority_agent.scala 96:50]
    Pri_elem_8.io.elem_act <= _T_9 @[Priority_agent.scala 96:30]
    node _T_10 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[0]) @[Priority_agent.scala 97:54]
    Pri_elem_8.io.elem_deact <= _T_10 @[Priority_agent.scala 97:32]
    Pri_elem_9.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_11 = bits(IntOccSel.io.sel_sig[1], 0, 0) @[Bitwise.scala 77:15]
    node _T_12 = mux(_T_11, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_13 = and(_T_12, InitPri) @[Priority_agent.scala 94:73]
    node _T_14 = eq(IntOccSel.io.sel_sig[1], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_15 = and(_T_14, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_16 = bits(_T_15, 0, 0) @[Bitwise.scala 77:15]
    node _T_17 = mux(_T_16, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_18 = and(_T_17, DynamPriUpdate[1]) @[Priority_agent.scala 95:64]
    node _T_19 = or(_T_13, _T_18) @[Priority_agent.scala 94:84]
    Pri_elem_9.io.pri_update <= _T_19 @[Priority_agent.scala 94:32]
    node _T_20 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[1]) @[Priority_agent.scala 96:50]
    Pri_elem_9.io.elem_act <= _T_20 @[Priority_agent.scala 96:30]
    node _T_21 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[1]) @[Priority_agent.scala 97:54]
    Pri_elem_9.io.elem_deact <= _T_21 @[Priority_agent.scala 97:32]
    Pri_elem_10.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_22 = bits(IntOccSel.io.sel_sig[2], 0, 0) @[Bitwise.scala 77:15]
    node _T_23 = mux(_T_22, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_24 = and(_T_23, InitPri) @[Priority_agent.scala 94:73]
    node _T_25 = eq(IntOccSel.io.sel_sig[2], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_26 = and(_T_25, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_27 = bits(_T_26, 0, 0) @[Bitwise.scala 77:15]
    node _T_28 = mux(_T_27, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_29 = and(_T_28, DynamPriUpdate[2]) @[Priority_agent.scala 95:64]
    node _T_30 = or(_T_24, _T_29) @[Priority_agent.scala 94:84]
    Pri_elem_10.io.pri_update <= _T_30 @[Priority_agent.scala 94:32]
    node _T_31 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[2]) @[Priority_agent.scala 96:50]
    Pri_elem_10.io.elem_act <= _T_31 @[Priority_agent.scala 96:30]
    node _T_32 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[2]) @[Priority_agent.scala 97:54]
    Pri_elem_10.io.elem_deact <= _T_32 @[Priority_agent.scala 97:32]
    Pri_elem_11.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_33 = bits(IntOccSel.io.sel_sig[3], 0, 0) @[Bitwise.scala 77:15]
    node _T_34 = mux(_T_33, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_35 = and(_T_34, InitPri) @[Priority_agent.scala 94:73]
    node _T_36 = eq(IntOccSel.io.sel_sig[3], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_37 = and(_T_36, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_38 = bits(_T_37, 0, 0) @[Bitwise.scala 77:15]
    node _T_39 = mux(_T_38, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_40 = and(_T_39, DynamPriUpdate[3]) @[Priority_agent.scala 95:64]
    node _T_41 = or(_T_35, _T_40) @[Priority_agent.scala 94:84]
    Pri_elem_11.io.pri_update <= _T_41 @[Priority_agent.scala 94:32]
    node _T_42 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[3]) @[Priority_agent.scala 96:50]
    Pri_elem_11.io.elem_act <= _T_42 @[Priority_agent.scala 96:30]
    node _T_43 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[3]) @[Priority_agent.scala 97:54]
    Pri_elem_11.io.elem_deact <= _T_43 @[Priority_agent.scala 97:32]
    Pri_elem_12.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_44 = bits(IntOccSel.io.sel_sig[4], 0, 0) @[Bitwise.scala 77:15]
    node _T_45 = mux(_T_44, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_46 = and(_T_45, InitPri) @[Priority_agent.scala 94:73]
    node _T_47 = eq(IntOccSel.io.sel_sig[4], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_48 = and(_T_47, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_49 = bits(_T_48, 0, 0) @[Bitwise.scala 77:15]
    node _T_50 = mux(_T_49, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_51 = and(_T_50, DynamPriUpdate[4]) @[Priority_agent.scala 95:64]
    node _T_52 = or(_T_46, _T_51) @[Priority_agent.scala 94:84]
    Pri_elem_12.io.pri_update <= _T_52 @[Priority_agent.scala 94:32]
    node _T_53 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[4]) @[Priority_agent.scala 96:50]
    Pri_elem_12.io.elem_act <= _T_53 @[Priority_agent.scala 96:30]
    node _T_54 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[4]) @[Priority_agent.scala 97:54]
    Pri_elem_12.io.elem_deact <= _T_54 @[Priority_agent.scala 97:32]
    Pri_elem_13.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_55 = bits(IntOccSel.io.sel_sig[5], 0, 0) @[Bitwise.scala 77:15]
    node _T_56 = mux(_T_55, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_57 = and(_T_56, InitPri) @[Priority_agent.scala 94:73]
    node _T_58 = eq(IntOccSel.io.sel_sig[5], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_59 = and(_T_58, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_60 = bits(_T_59, 0, 0) @[Bitwise.scala 77:15]
    node _T_61 = mux(_T_60, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_62 = and(_T_61, DynamPriUpdate[5]) @[Priority_agent.scala 95:64]
    node _T_63 = or(_T_57, _T_62) @[Priority_agent.scala 94:84]
    Pri_elem_13.io.pri_update <= _T_63 @[Priority_agent.scala 94:32]
    node _T_64 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[5]) @[Priority_agent.scala 96:50]
    Pri_elem_13.io.elem_act <= _T_64 @[Priority_agent.scala 96:30]
    node _T_65 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[5]) @[Priority_agent.scala 97:54]
    Pri_elem_13.io.elem_deact <= _T_65 @[Priority_agent.scala 97:32]
    Pri_elem_14.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_66 = bits(IntOccSel.io.sel_sig[6], 0, 0) @[Bitwise.scala 77:15]
    node _T_67 = mux(_T_66, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_68 = and(_T_67, InitPri) @[Priority_agent.scala 94:73]
    node _T_69 = eq(IntOccSel.io.sel_sig[6], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_70 = and(_T_69, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_71 = bits(_T_70, 0, 0) @[Bitwise.scala 77:15]
    node _T_72 = mux(_T_71, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_73 = and(_T_72, DynamPriUpdate[6]) @[Priority_agent.scala 95:64]
    node _T_74 = or(_T_68, _T_73) @[Priority_agent.scala 94:84]
    Pri_elem_14.io.pri_update <= _T_74 @[Priority_agent.scala 94:32]
    node _T_75 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[6]) @[Priority_agent.scala 96:50]
    Pri_elem_14.io.elem_act <= _T_75 @[Priority_agent.scala 96:30]
    node _T_76 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[6]) @[Priority_agent.scala 97:54]
    Pri_elem_14.io.elem_deact <= _T_76 @[Priority_agent.scala 97:32]
    Pri_elem_15.io.pri_update_sig <= PriUpdateSig @[Priority_agent.scala 93:36]
    node _T_77 = bits(IntOccSel.io.sel_sig[7], 0, 0) @[Bitwise.scala 77:15]
    node _T_78 = mux(_T_77, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_79 = and(_T_78, InitPri) @[Priority_agent.scala 94:73]
    node _T_80 = eq(IntOccSel.io.sel_sig[7], UInt<1>("h0")) @[Priority_agent.scala 95:25]
    node _T_81 = and(_T_80, PriUpdateSig) @[Priority_agent.scala 95:50]
    node _T_82 = bits(_T_81, 0, 0) @[Bitwise.scala 77:15]
    node _T_83 = mux(_T_82, UInt<5>("h1f"), UInt<5>("h0")) @[Bitwise.scala 77:12]
    node _T_84 = and(_T_83, DynamPriUpdate[7]) @[Priority_agent.scala 95:64]
    node _T_85 = or(_T_79, _T_84) @[Priority_agent.scala 94:84]
    Pri_elem_15.io.pri_update <= _T_85 @[Priority_agent.scala 94:32]
    node _T_86 = and(io.dyn_int_occ_sig, IntOccSel.io.sel_sig[7]) @[Priority_agent.scala 96:50]
    Pri_elem_15.io.elem_act <= _T_86 @[Priority_agent.scala 96:30]
    node _T_87 = and(io.dyn_int_claim_sig, IntClaimSel.io.sel_sig[7]) @[Priority_agent.scala 97:54]
    Pri_elem_15.io.elem_deact <= _T_87 @[Priority_agent.scala 97:32]
    node _PriUpdateSig_T = andr(Tcnt) @[Priority_agent.scala 100:42]
    node _PriUpdateSig_T_1 = or(io.dyn_int_occ_sig, _PriUpdateSig_T) @[Priority_agent.scala 100:35]
    PriUpdateSig <= _PriUpdateSig_T_1 @[Priority_agent.scala 100:15]
    node _DynamPriUpdate_0_T = add(Pri_elem_8.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_0_T_1 = tail(_DynamPriUpdate_0_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[0] <= _DynamPriUpdate_0_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_1_T = add(Pri_elem_9.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_1_T_1 = tail(_DynamPriUpdate_1_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[1] <= _DynamPriUpdate_1_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_2_T = add(Pri_elem_10.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_2_T_1 = tail(_DynamPriUpdate_2_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[2] <= _DynamPriUpdate_2_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_3_T = add(Pri_elem_11.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_3_T_1 = tail(_DynamPriUpdate_3_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[3] <= _DynamPriUpdate_3_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_4_T = add(Pri_elem_12.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_4_T_1 = tail(_DynamPriUpdate_4_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[4] <= _DynamPriUpdate_4_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_5_T = add(Pri_elem_13.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_5_T_1 = tail(_DynamPriUpdate_5_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[5] <= _DynamPriUpdate_5_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_6_T = add(Pri_elem_14.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_6_T_1 = tail(_DynamPriUpdate_6_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[6] <= _DynamPriUpdate_6_T_1 @[Priority_agent.scala 103:24]
    node _DynamPriUpdate_7_T = add(Pri_elem_15.io.pri, UInt<5>("h1")) @[Priority_agent.scala 103:44]
    node _DynamPriUpdate_7_T_1 = tail(_DynamPriUpdate_7_T, 1) @[Priority_agent.scala 103:44]
    DynamPriUpdate[7] <= _DynamPriUpdate_7_T_1 @[Priority_agent.scala 103:24]

