/**
 * FILE HelloTest.scala
 * 
 * test Hello: a simple adder class
*/

package hello

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class HelloTest extends AnyFlatSpec with ChiselScalatestTester {

    "HelloTest" should "pass" in {
        test(new Hello)
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            for(a <- 0 until 4){
                for(b <- 0 until 4){
                    dut.io.a.poke(a.U)
                    dut.io.b.poke(b.U)
                    dut.io.c.expect((a+b).U)
                    dut.clock.step()
                }
            }
        }
    }

}