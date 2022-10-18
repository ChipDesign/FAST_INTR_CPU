/**
 * ChiselTest is an extension of ScalaTest.
 * Therefore, we first explore a simple ScalaTest example
*/


import org.scalatest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

class HelloTest extends AnyFlatSpec with Matchers {
  "Integers" should "add" in {
    val i = 2
    val j = 3
    i + j should be (5)
}
"Integers" should "multiply" in {
    val a = 3
    val b = 4
    a * b should be (12)
  }
}