circuit multi :
  module multi :
    input clock : Clock
    input reset : UInt<1>
    input io_ina : UInt<4>
    input io_inb : UInt<4>
    output io_out : UInt<8>

    node _io_out_T = mul(io_ina, io_inb) @[multi.scala 16:17]
    io_out <= _io_out_T @[multi.scala 16:9]
