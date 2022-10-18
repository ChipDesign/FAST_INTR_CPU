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
class EncoderGenerator(n: Int) extends Module {
  val io = IO(new Bundle {
    val hotIn = Input(UInt(n.W))
    val code = Output(UInt(log2Up(n).W))
  })

  val v = Wire(Vec(n, UInt(2.W)))

  v(0) := 0.U
  for (i <- 1 until n) {
    v(i) := Mux(io.hotIn(i), i.U, 0.U) | v(i - 1)
  }
  io.code := v(n - 1)
}

/** 之前的encoder只允许hotIn中最多有一位是1 PriorityEncoder允许hotIn中有多位是1，
  * 通过一个Arbiter选择优先级最高的1
  */
class PriorityEncoder(n: Int) extends Module {
  val io = IO(new Bundle {
    val hotIn = Input(UInt(4.W))
    val code = Output(UInt(2.W))
  })

  val aw = Module(new ArbiterWrapper(4))
  var eg = Module(new EncoderGenerator(4))

  // connect all ports, using BULK Connection
  aw.io.request := io.hotIn
  eg.io.hotIn := aw.io.hotIn
  io.code := eg.io.code
}

object GetEncoderVerilog extends App {
  println("get Encoder")

//   (new chisel3.stage.ChiselStage).emitVerilog(new EncoderSimple())
  // (new chisel3.stage.ChiselStage).emitVerilog(new EncoderGenerator(3))
  (new chisel3.stage.ChiselStage).emitVerilog(new PriorityEncoder(4))
}
