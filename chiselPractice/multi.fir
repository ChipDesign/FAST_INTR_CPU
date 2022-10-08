circuit multi :
  module multi :
    input clock : Clock
    input reset : UInt<1>
    output io : { flip ina : UInt<4>, flip inb : UInt<4>, out : UInt<8>}

    node _io_out_T = mul(io.ina, io.inb) @[multi.scala 16:17]
    io.out <= _io_out_T @[multi.scala 16:9]

