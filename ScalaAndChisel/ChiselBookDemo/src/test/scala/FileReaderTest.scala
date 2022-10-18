/**
 * FILE: FileReaderTest
 * 
 * test file reader
*/
package hardwareGenerator

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

class FileReaderTest extends AnyFlatSpec with ChiselScalatestTester {
    "FileReaderTest" should "Pass" in{
        test(new FileReader())
        .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>
            print("begin test\n")
            dut.io.address.poke(1.U) // set address to read the second line
            var ioData=dut.io.data.peek()
            print("data is "+ioData+"\n")
            print("end test\n")
        }
    }
}