/**
 * FILE EncoderScala.scala
 * 
 * test encoder
*/
package combinational

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class EncoderTest extends AnyFlatSpec with ChiselScalatestTester {
    "EncoderGenerator" should "pass" in{
        test(new EncoderGenerator(4))
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            dut.io.hotIn.poke("b0001".U)
            dut.io.code.expect("b00".U)
            dut.clock.step(1)    

            dut.io.hotIn.poke("b0010".U)
            dut.io.code.expect("b01".U)
            dut.clock.step(1)

            dut.io.hotIn.poke("b0100".U)
            dut.io.code.expect("b10".U)
            dut.clock.step(1)

            dut.io.hotIn.poke("b1000".U)
            dut.io.code.expect("b11".U)
            dut.clock.step(1)        
        }
    }

    "PriorityEncoder" should "pass" in{
        test(new PriorityEncoder(4))
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            dut.io.hotIn.poke("b0000".U)
            dut.io.code.expect("b00".U)
            dut.clock.step(1)    

            dut.io.hotIn.poke("b1111".U)
            dut.io.code.expect("b00".U)
            dut.clock.step(1)

            dut.io.hotIn.poke("b0100".U)
            dut.io.code.expect("b10".U)
            dut.clock.step(1)
        }
    }
}