/** FILE: ChiselALU.scdala
  *
  * 实现一个支持如下指令的ALU：
  *
  *   1. 算数指令：add, sub, mul
  *
  * 2. 逻辑指令: and, or, xor
  *
  * 3. 跳转指令: beq
  *
  * 4. 移位指令: srl
  *
  * 5. 访存指令: lw, sw
  *
  * 针对上述各个指令，ALU的需要具备的计算，及各个计算的`ALUControl`如下：
  * | 计算名称 | 涉及的指令       | ALUControl |
  * |:-----|:------------|:-----------|
  * | 加法   | add, lw, sw | 000        |
  * | 减法   | sub, beq    | 001        |
  * | 乘法   | mul         | 010        |
  * | 逻辑与  | and         | 011        |
  * | 逻辑或  | or          | 100        |
  * | 逻辑异或 | xor         | 101        |
  * | 逻辑右移 | srl         | 110        |
  */
package chiselProcessor

import chisel3._
import chisel3.util._ // for switch/is

import chiselProcessor.Types._

object Types {
  val add :: sub :: mul :: and :: or :: xor :: srl :: Nil = Enum(7)
}

class ChiselALU(width: Int = 32) extends Module {
  val io = IO(new Bundle {
    val control = Input(UInt(3.W))
    val srcA = Input(UInt(width.W))
    val srcB = Input(UInt(width.W))
    val result = Output(UInt(width.W))
  })

  val control = io.control
  val a = io.srcA
  val b = io.srcB
  val res = WireDefault(io.srcA)

  switch(control) {
    is(add) {
      res := a + b
    }
    is(sub) {
      res := a - b
    }
    is(mul) {
      res := a * b
    }
    is(and) {
      res := a & b
    }
    is(or) {
      res := a | b
    }
    is(xor) {
      res := a ^ b
    }
    is(srl) {
      // if(b<32.U)
      res := a >> b
    }

  }

  io.result := res

}

object GetChiselALUVerilog extends App {
  print("Get Verilog\n")
  (new chisel3.stage.ChiselStage).emitVerilog(new ChiselALU(32))
}
