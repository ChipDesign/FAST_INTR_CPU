/** FILE: NocRouter.scala
  *
  * test type parameter, and different number of ports using Vec
  */
package hardwareGenerator

import chisel3._

class NocRouter[T <: Data](dt: T, n: Int) extends Module {
  val io = IO(new Bundle {
    val inPort = Input(Vec(n, dt))
    val address = Input(Vec(n, UInt(8.W)))
    val outPort = Output(Vec(n, dt))
  })
  io.outPort := io.inPort
}

// data type
class Payload extends Bundle {
  val data = UInt(16.W)
  val flag = Bool()
}

object GeNocRoutertVerilog extends App{
    print("get verilog code\n")
    (new chisel3.stage.ChiselStage).emitVerilog(new NocRouter(new Payload,2))
}