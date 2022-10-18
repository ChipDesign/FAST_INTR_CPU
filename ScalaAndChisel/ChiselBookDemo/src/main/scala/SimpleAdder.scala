/** FILE: Debug.scala
  *
  * Chisel debug allow:
  *   1. multi-thread test 2. use verilator or VSC as simulation backends, the
  *      chisel simulation backends is Threadle
  */
package debug

import chisel3._

class SimpleAdder extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(4.W))
    val b = Input(UInt(4.W))
    val out = Output(UInt(4.W))
  })
  io.out := io.a + io.b
}

object GetAdderVerilog extends App{
    print("get verilog of SimpleAdder\n")
    (new chisel3.stage.ChiselStage).emitVerilog(new SimpleAdder())
}