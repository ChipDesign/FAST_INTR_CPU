/** FILE: ALU.scala
  *
  * implement a simple ALU with: add, substraction, and, or function
  */
package component

import chisel3._
import chisel3.util._ // for switch/is

class ALU extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(16.W))
    val b = Input(UInt(16.W))
    val fn = Input(UInt(2.W)) // select function
    val y = Output(UInt(16.W))
  })

  io.y := 0.U // default value for y

  switch(io.fn) {
    is(0.U) { io.y := io.a + io.b }
    is(1.U) { io.y := io.a - io.b }
    is(2.U) { io.y := io.a | io.b }
    is(3.U) { io.y := io.a & io.b }
  }
}

object ALUVerilog extends App {
  println("get ALU Veriog")

  (new chisel3.stage.ChiselStage).emitVerilog(new ALU()) // 创建.v文件
    // println(getVerilogString(new ALU))                // 只是在终端中打印verilog代码
}
