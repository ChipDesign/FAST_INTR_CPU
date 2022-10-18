//import chisel3.tester.testableClock
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class BusTest extends AnyFlatSpec with ChiselScalatestTester{
  behavior of "SimpleBus"
  it should "pass" in {
    test(new SimpleBus) { c =>
      c.clock.step(16)
      for(i <- 0 until 16)
        {
          c.io.SlaveDataOut.expect(3*(i+1)%17)
          c.clock.step(1)
        }
    }
  }
}
