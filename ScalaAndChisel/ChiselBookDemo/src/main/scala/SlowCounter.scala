/** FILE: SlowCounter.scala
  *
  * make a counter which increase every k cycle
  */
package sequential

import chisel3._
import org.scalatest.tagobjects.Slow

class SlowCounter extends Module {
  val io = IO(new Bundle {
    val out = Output(UInt(2.W))
  })

  val tickCounter = RegInit(0.U(2.W))
  val tick = tickCounter === 3.U
  tickCounter := tickCounter + 1.U
  when(tick) {
    tickCounter := 0.U
  }

  val slowCount = RegInit(0.U(2.W))
  when(tick) {
    slowCount := slowCount + 1.U
  }

  io.out := slowCount

}

object GetSlowCounter extends App {
  print("get waveform\n")
  (new chisel3.stage.ChiselStage).emitVerilog(new SlowCounter())

}
