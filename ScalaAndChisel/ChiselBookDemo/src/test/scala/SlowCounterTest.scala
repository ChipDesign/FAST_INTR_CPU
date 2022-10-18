/** FILE: SlowCounterTest.scala
  *
  * test SlowCounter
  */

package sequential

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class SlowCounterTest extends AnyFlatSpec with ChiselScalatestTester {
  "SlowCounterTest" should "Pass" in {
    test(new SlowCounter)
    .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
        dut.clock.step(30)    
    }
  }
}
