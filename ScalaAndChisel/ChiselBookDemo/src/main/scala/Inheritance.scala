/** FILE: Inheritance.scala
  *
  * show how to use inheritance to generate hardware
  */
package hardwareGenerator

import chisel3._
import scala.io.Source

/** abstract class to define the ticking interface
  */
abstract class Ticker(n: Int) extends Module {
  val io = IO(new Bundle {
    val tick = Output(Bool())
  })
}

/** first implementation of that abstract class with a counter
  */
class UpTicker(n: Int) extends Ticker(n) {
  val N = (n - 1).U
  val cntReg = RegInit(0.U(8.W))
  cntReg := cntReg + 1.U
  val tick = cntReg === N
  when(tick) {
    cntReg := 0.U
  }
  io.tick := tick // use io in parent class
}

class DownTicker(n: Int) extends Ticker(n) {
  val N = (n - 1).U
  val cntReg = RegInit(N)
  cntReg := cntReg - 1.U
  when(cntReg === 0.U) {
    cntReg := N
  }
  io.tick := cntReg === N
}

class NerdTicker(n: Int) extends Ticker(n) {
  val N = n
  val MAX = (N - 2).S(8.W)
  val cntReg = RegInit(MAX)
  io.tick := false.B
  cntReg := cntReg - 1.S
  when(cntReg(7)) {
    cntReg := MAX
    io.tick := true.B
  }
}
