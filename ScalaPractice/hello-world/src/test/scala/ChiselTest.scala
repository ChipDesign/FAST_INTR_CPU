/**
 * file: ChiselTest.scala
 * 
 * ChiselTest is the standard testing tool for Chisel modules based on the ScalaTest
 * tool for Scala and Java, which we can use to run Chisel tests
 * -----------------------------------------------------
 * Use Command `sbt "testOnly ChiselTest" to do this test
*/

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

/**
 * Device Under Test(DUT)
 * AND Gate && Comparator
*/
class DeviceUnderTest extends Module {
    val io = IO(new Bundle {
    val a = Input(UInt(2.W))
    val b = Input(UInt(2.W))
    val out = Output(UInt(2.W))
    val equ = Output(Bool()) // Chisel Bool
})
    io.out := io.a & io.b
    io.equ := io.a === io.b
}

/**
 * Testbench to test DUT
*/
class ChiselTest extends AnyFlatSpec with
    ChiselScalatestTester {
    "DUT" should "pass" in {
        // DUT as parameter
    test(new DeviceUnderTest) { dut =>
        // test logic
        dut.io.a.poke(0.U)
        dut.io.b.poke(1.U)
        dut.clock.step()
        println("Result is: " + dut.io.out.peek().toString)
        dut.io.a.poke(3.U)
        dut.io.b.poke(2.U)
        dut.clock.step()
        println("Result is: " + dut.io.out.peek().toString)
        }
    }
}