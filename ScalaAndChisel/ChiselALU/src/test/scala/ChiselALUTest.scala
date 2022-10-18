/** FILE: ChiselALUTest.scala
  *
  * test Chisel ALU
  */

package chiselProcessor

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chiselProcessor.Types._

class ChiselALUTest extends AnyFlatSpec with ChiselScalatestTester {
  val width: Int = 32
  
  /**
   * alu函数返回ALU计算的期待值，用于跟硬件电路的结果进行比较
  */
  def alu(a: Int, b: Int, op: Int): Int = {
    val maxValue = scala.math.pow(2, width).toInt
    op match {
      case 0 => a + b
      case 1 => a - b
      case 2 => a * b
      case 3 => a & b
      case 4 => a | b
      case 5 => a ^ b
      case 6 => if (b >= width) 0 else a >>> b // avoid: x>>>32 = x
    }
  }

  /**
   * x should in y格式，用于测试：如果y中的内容满足，则x测试通过
  */
  "ChiselALUTest" should "Pass" in {
    test(new ChiselALU(width))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
        dut.clock.step()
        for (i <- 0 to 6) {
          print("i= " + i + "\n")
          for (j <- 0 to 10) {
            var a = scala.util.Random.nextInt(1000)
            var b = scala.util.Random.nextInt(1000)
            print("a,b = " + a + ", " + b + "\n")
            dut.io.srcA.poke(a.U)
            dut.io.srcB.poke(b.U)
            dut.io.control.poke(i.U)
            dut.io.result.expect(
              (alu(a, b, i).toLong & 0x00ffffffffL).U
            ) // avoid negative value
            dut.clock.step()
          }
        }
        print("add, div, mul, and, or, xor, srl all PASS\n")
      }
  }
}
