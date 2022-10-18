/** FILE: Arbiter.scala
  *
  * create a priority arbiter, the lsb has the highest priority
  */
package combinational

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

/**
 * 封装Arbiter的接口，将Vec接口换成数组：Vec(n, Bool()) -> n.W
*/
class ArbiterWrapper(n: Int) extends Module {
  val io = IO(new Bundle {
    val request = Input(UInt(n.W))
    val hotIn = Output(UInt(n.W))
  })

  val ar = Module(new Arbiter(n))
  ar.io.request := VecInit(io.request.asBools)
  io.hotIn := ar.io.output.asUInt
}

object PassVerilog extends App {
  println("get Pass Veriog")

  // println(getVerilogString(new Arbiter(2)))                // 只是在终端中打印verilog代码

//   (new chisel3.stage.ChiselStage).emitVerilog(new Arbiter(3)) // 创建.v文件
  (new chisel3.stage.ChiselStage).emitVerilog(new ArbiterWrapper(4)) // 创建.v文件
}
