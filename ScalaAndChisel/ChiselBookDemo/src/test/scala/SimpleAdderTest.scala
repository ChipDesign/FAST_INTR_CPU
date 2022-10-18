/**
 * FILE: SimpleAdderTest.scala
 * 
 * use SimpleAdder to test "using verilator as backend simulation tool"
*/

package debug

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chiseltest.simulator.VerilatorFlags

class SimpleAdderTest extends AnyFlatSpec with ChiselScalatestTester{
    "Simulation Backend" should "Threadle" in{
        test(new SimpleAdder())
        .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
            print("begin Threadle\n")
            var o=1.U
            for(i <- 0 to 2){
                for( j <- 3 to 5)
                {
                    dut.io.a.poke(i.U)
                    dut.io.b.poke(j.U)
                    dut.io.out.expect((i+j).U)
                    dut.clock.step()

                    o=dut.io.out.peek()
                    print("out: "+o+"\n")
                }
            }
            print("end Threadle\n")
        }
    }

    it should "Verilator" in{
        test(new SimpleAdder())
        .withAnnotations(Seq(VerilatorBackendAnnotation, WriteVcdAnnotation)) { dut =>
            print("begin Verilator\n")
            var o=1.U
            for(i <- 0 to 2){
                for( j <- 3 to 5)
                {
                    dut.io.a.poke(i.U)
                    dut.io.b.poke(j.U)
                    dut.io.out.expect((i+j).U)
                    dut.clock.step()

                    o=dut.io.out.peek()
                    print("out: "+o+"\n")
                }
            }
            print("end Verilator\n")
        }
    }
}