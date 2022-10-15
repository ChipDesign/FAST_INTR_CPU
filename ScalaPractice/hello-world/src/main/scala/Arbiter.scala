/** FILE: Arbiter.scala
  *
  * create a priority arbiter, the lsb has the highest priority
  */

import chisel3._

class Arbiter(n: Int) extends Module { // n is same to `constructor param` in C++
  val io = IO(new Bundle {
    val request = Input(Vec(n, Bool())) // create an array Input
    val output = Output(Vec(n, Bool()))
  })

  val grant = VecInit.fill(n)(false.B)
  val notGranted = VecInit.fill(n)(false.B)
  grant(0) := io.request(0)
  notGranted(0) := !grant(0)
  for (i <- 1 until n) {
    grant(i) := io.request(i) && notGranted(i - 1)
    notGranted(i) := !grant(i) && notGranted(i - 1)
  }

  io.output := grant
}

object PassVerilog extends App {
  println("get Pass Veriog")

  // println(getVerilogString(new Arbiter(2)))                // 只是在终端中打印verilog代码
//   (new chisel3.stage.ChiselStage).emitVerilog(new Arbiter(2)) // 创建.v文件
  (new chisel3.stage.ChiselStage).emitVerilog(new Arbiter(3)) // 创建.v文件
}
