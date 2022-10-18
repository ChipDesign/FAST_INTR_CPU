circuit ParamFIR :
  module ParamFIR :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip sig_in : UInt<5>, sig_out : UInt<5>}

    reg regs_1 : UInt, clock with :
      reset => (reset, UInt<1>("h0")) @[ParamFIR.scala 19:25]
    regs_1 <= io.sig_in @[ParamFIR.scala 19:25]
    reg regs_2 : UInt, clock with :
      reset => (reset, UInt<1>("h0")) @[ParamFIR.scala 19:25]
    regs_2 <= regs_1 @[ParamFIR.scala 19:25]
    reg regs_3 : UInt, clock with :
      reset => (reset, UInt<1>("h0")) @[ParamFIR.scala 19:25]
    regs_3 <= regs_2 @[ParamFIR.scala 19:25]
    reg regs_4 : UInt, clock with :
      reset => (reset, UInt<1>("h0")) @[ParamFIR.scala 19:25]
    regs_4 <= regs_3 @[ParamFIR.scala 19:25]
    node muls_0 = mul(io.sig_in, UInt<1>("h1")) @[ParamFIR.scala 24:20]
    node muls_1 = mul(regs_1, UInt<1>("h1")) @[ParamFIR.scala 24:20]
    node muls_2 = mul(regs_2, UInt<2>("h2")) @[ParamFIR.scala 24:20]
    node muls_3 = mul(regs_3, UInt<2>("h3")) @[ParamFIR.scala 24:20]
    node muls_4 = mul(regs_4, UInt<3>("h5")) @[ParamFIR.scala 24:20]
    node _T = add(muls_0, muls_1) @[ParamFIR.scala 30:28]
    node sums_1 = tail(_T, 1) @[ParamFIR.scala 30:28]
    node _T_1 = add(sums_1, muls_2) @[ParamFIR.scala 30:28]
    node sums_2 = tail(_T_1, 1) @[ParamFIR.scala 30:28]
    node _T_2 = add(sums_2, muls_3) @[ParamFIR.scala 30:28]
    node sums_3 = tail(_T_2, 1) @[ParamFIR.scala 30:28]
    node _T_3 = add(sums_3, muls_4) @[ParamFIR.scala 30:28]
    node sums_4 = tail(_T_3, 1) @[ParamFIR.scala 30:28]
    io.sig_out <= sums_4 @[ParamFIR.scala 33:13]

