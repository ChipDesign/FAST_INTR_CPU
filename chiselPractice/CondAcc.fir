circuit CondAcc :
  module CondAcc :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip ctrl : UInt<2>, out : UInt<5>}

    reg acc : UInt<5>, clock with :
      reset => (reset, UInt<5>("h0")) @[CondAcc.scala 19:18]
    node _T = eq(io.ctrl, UInt<1>("h1")) @[CondAcc.scala 20:16]
    when _T : @[CondAcc.scala 21:3]
      node _acc_T = add(acc, UInt<2>("h2")) @[CondAcc.scala 22:13]
      node _acc_T_1 = tail(_acc_T, 1) @[CondAcc.scala 22:13]
      acc <= _acc_T_1 @[CondAcc.scala 22:8]
    else :
      node _T_1 = eq(io.ctrl, UInt<2>("h2")) @[CondAcc.scala 23:21]
      when _T_1 : @[CondAcc.scala 24:3]
        node _acc_T_2 = add(acc, UInt<1>("h1")) @[CondAcc.scala 25:13]
        node _acc_T_3 = tail(_acc_T_2, 1) @[CondAcc.scala 25:13]
        acc <= _acc_T_3 @[CondAcc.scala 25:8]
      else :
        acc <= acc @[CondAcc.scala 28:8]
    io.out <= acc @[CondAcc.scala 30:9]

