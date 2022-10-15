/** FILE: ShiftRegister.scala
  *
  * ShiftRegister for delay, parallel output
  */

package sequential
import chisel3._

/** output is 4 cycle delay of input
  */
class DelayRegister extends Module {
  val io = IO(new Bundle {
    val din = Input(UInt(1.W))
    val dout = Output(UInt(1.W))
  })

  val shiftReg = Reg(UInt(4.W))
  shiftReg := shiftReg(2, 0) ## io.din

  io.dout := shiftReg(3)
}

/** change serial input to parallel output
  */
class ParallelRegister extends Module {
  val io = IO(new Bundle {
    val din = Input(UInt(1.W))
    val dout = Output(UInt(4.W))
  })

  val parallelReg = RegInit(0.U(4.W))
  parallelReg := io.din ## parallelReg(3, 1)
  io.dout := parallelReg
}

object GetShiftRegisterVerilog extends App {
//   (new chisel3.stage.ChiselStage).emitVerilog(new DelayRegister())
  (new chisel3.stage.ChiselStage).emitVerilog(new ParallelRegister())
}
