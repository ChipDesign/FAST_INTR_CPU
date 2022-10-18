import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class CondAccTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "CondAcc"
  it should "pass" in{
    test(new CondAcc) { c =>
      for(i<- 0 until 3)
        {
          c.io.ctrl.poke(1)
          c.io.out.expect(2*i)
          c.clock.step(1)
        }
      for (i <- 0 until 3)
      {
        c.io.ctrl.poke(2)
        c.io.out.expect(6+i)
        c.clock.step(1)
      }
      for (i <- 0 until 3) {
        c.io.ctrl.poke(0)
        c.io.out.expect(9)
        c.clock.step(1)
      }
    }
  }
}
