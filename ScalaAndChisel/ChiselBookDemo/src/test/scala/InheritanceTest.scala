/** FILE: InheritanceTest.scala
  *
  * test inheritance class
  */
package hardwareGenerator

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

/** Function to test different type of class dut is define by type T
  */
trait TickerTestFunc {
  def testFn[T <: Ticker](dut: T, n: Int) = {
// -1 means that no ticks have been seen yet
    var count = -1
    for (_ <- 0 to n * 3) {
// Check for correct output
      if (count > 0)
        dut.io.tick.expect(false.B)
      else if (count == 0)
        dut.io.tick.expect(true.B)
// Reset the counter on a tick
      if (dut.io.tick.peek.litToBoolean)
        count = n - 1
      else
        count -= 1
      dut.clock.step()
    }
  }
}

class InheritanceTest
    extends AnyFlatSpec
    with ChiselScalatestTester
    with TickerTestFunc {
  "Ticker Test" should "UpTicker" in {
    test(new UpTicker(3))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
        testFn(dut, 3)
      }
  }
  it should "DownTicker" in {
    test(new DownTicker(7)) { dut => testFn(dut, 7) }
  }
  it should "NerdTicker" in {
    test(new NerdTicker(11)) { dut => testFn(dut, 11) }
  }
}
