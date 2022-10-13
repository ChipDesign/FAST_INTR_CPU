/** FILE: Decoder.scala
  *
  * show 3 codes for implementing a decoder
  */

package combinational

import chisel3._
import chisel3.util._

class DecoderSimiple extends Module {
  val io = IO(new Bundle {
    val sel = Input(UInt(2.W))
    val output = Output(UInt(4.W))
  })

  io.output := 0.U // RefNotInitializedException: Chisel need us to provide a default value

  switch(io.sel) {
    is(0.U) { io.output := 1.U }
    is(1.U) { io.output := 2.U }
    is(2.U) { io.output := 4.U }
    is(3.U) { io.output := 8.U }
  }
}

/** Use binary form of Decoder
  */
class DecoderBinary extends Module {
  val io = IO(new Bundle {
    val sel = Input(UInt(2.W))
    val output = Output(UInt(4.W))
  })

  io.output := 0.U // RefNotInitializedException: Chisel need us to provide a default value

  switch(io.sel) {
    is("b00".U) { io.output := "b0001".U }
    is("b01".U) { io.output := "b0010".U }
    is("b10".U) { io.output := "b0100".U }
    is("b11".U) { io.output := "b1000".U }
  }
}

/** Use shift to make a Decoder
  */
class DecoderShift extends Module {
  val io = IO(new Bundle {
    val sel = Input(UInt(2.W))
    val output = Output(UInt(4.W))
  })

  // io.output:= 1.U<<io.sel
  io.output := "b0001".U << io.sel
}
object GetDecoderVerilog extends App {
  println("get Decoder")

  // (new chisel3.stage.ChiselStage).emitVerilog(new DecoderSimiple())
//   (new chisel3.stage.ChiselStage).emitVerilog(new DecoderBinary())
  (new chisel3.stage.ChiselStage).emitVerilog(new DecoderShift())
}
