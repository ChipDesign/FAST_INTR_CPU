/** FILE ArbiterTest.scala
  *
  * test Arbiter and ArbiterWrapper
  */
package component

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import combinational.ArbiterWrapper

class ArbiterTest extends AnyFlatSpec with ChiselScalatestTester {
  "ArbiterWrapper" should "2 request" in {
    test(new ArbiterWrapper(2))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
        dut.io.request.poke("b01".U)
        dut.io.hotIn.expect("b01".U)
        dut.clock.step(1)

        dut.io.request.poke("b10".U)
        dut.io.hotIn.expect("b10".U)
        dut.clock.step(1)

        dut.io.request.poke("b11".U)
        dut.io.hotIn.expect("b01".U)

        print("test passed\n")
      }
  }
}
