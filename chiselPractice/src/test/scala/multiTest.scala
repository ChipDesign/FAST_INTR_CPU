import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class multiTest extends AnyFlatSpec with ChiselScalatestTester {

  behavior of "multi"
  it should "pass" in{
    test(new multi) { c =>
      c.io.ina.poke(5)
      c.io.inb.poke(5)
      c.io.out.expect(25)
    }
  }
}
