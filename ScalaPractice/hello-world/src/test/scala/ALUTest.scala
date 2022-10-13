/**
 * FILE ALUTest.scala
 * 
 * test a simple ALU for +, -, |, &
*/
package component

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class ALUTest extends AnyFlatSpec with ChiselScalatestTester {
     
    "ALUTest" should  "add" in {
        test(new ALU)
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            dut.io.a.poke(0xfff0.U)
            dut.io.b.poke(0x000f.U)
            dut.io.fn.poke(0.U)
            var out=dut.io.y.peek()
            println("Out is "+out)
        }
    }
    // it means "ALUTest"
    it should "substract" in{
        test(new ALU)
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            dut.io.a.poke(10.U)
            dut.io.b.poke(2.U)
            dut.io.fn.poke(1.U)
            var out=dut.io.y.peek()
            println("Out is "+out)
        }
    }
    it should "or" in{
        test(new ALU)
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            dut.io.a.poke(1.U)
            dut.io.b.poke(2.U)
            dut.io.fn.poke(2.U)
            var out=dut.io.y.peek()
            println("Out is "+out)
        }
    }
    it should "and" in{
        test(new ALU)
        .withAnnotations(Seq(WriteVcdAnnotation)){dut=>
            dut.io.a.poke(3.U)
            dut.io.b.poke(2.U)
            dut.io.fn.poke(3.U)
            var out=dut.io.y.peek()
            println("Out is "+out)
        }
    }

}