/** FILE: Counter10Test.scala
  *
  * test counter10 class, use command `sbt "testOnly Counter10Test" to run this
  * test
  */
package component

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

// import component.Counter10 //如果使用了packet指明了包信息，就不用import DUT了

class Counter10Test extends AnyFlatSpec with ChiselScalatestTester {
  "Counter10Test" should "pass" in {
    test(new Counter10)
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
        for (a <- 0 to 10) {
          var countValue = dut.io.dout.peek()
          print("countValue:"+countValue+"\n")
          dut.clock.step()
        }
      }
  }
}
