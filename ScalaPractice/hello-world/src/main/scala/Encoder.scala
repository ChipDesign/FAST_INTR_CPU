/** FILE: Encoder.scala
  *
  * show 2 way to get an encoder. the input has only 1 hot bit(at most 1 bit is
  * 1, others are 0)
  */

package combinational

import chisel3._
import chisel3.util._

/** simple Encoder: reverse of simple decoder
  */
class EncoderSimple extends Module {
  val io = IO(new Bundle {
    val hotIn = Input(UInt(4.W))
    val code = Output(UInt(2.W))
  })

  io.code := 0.U
  switch(io.hotIn) {
    is("b0001".U) { io.code := "b00".U }
    is("b0010".U) { io.code := "b01".U }
    is("b0100".U) { io.code := "b10".U }
    is("b1000".U) { io.code := "b11".U }
  }
}

/** Encoder generator
  */
class EncoderGenerator extends Module {
  val io = IO(new Bundle {
    val hotIn = Input(UInt(4.W))
    val code = Output(UInt(2.W))
  })

  val v = Wire(Vec(4, UInt(2.W)))

  v(0) := 0.U
  for (i <- 1 until 4) {
    v(i) := Mux(io.hotIn(i), i.U, 0.U) | v(i - 1)
  }
  io.code := v(3)
}

object GetEncoderVerilog extends App {
  println("get Encoder")

//   (new chisel3.stage.ChiselStage).emitVerilog(new EncoderSimple())
  (new chisel3.stage.ChiselStage).emitVerilog(new EncoderGenerator())
}
