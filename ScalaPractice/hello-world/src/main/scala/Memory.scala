/** FILE: Memory.scala
  *
  * Implement the Memory and ForwardingMemory class
  */
package sequential

import chisel3._

class Memory extends Module {
  val io = IO(new Bundle {
    val rdAddr = Input(UInt(10.W))
    val rdData = Output(UInt(8.W))
    val wrAddr = Input(UInt(10.W))
    val wrData = Input(UInt(8.W))
    val wrEna = Input(Bool())
  })

  val mem = SyncReadMem(1024, UInt(8.W))

  io.rdData := mem.read(io.rdAddr)

  when(io.wrEna) {
    mem.write(io.wrAddr, io.wrData)
  }
}

/**
 * when write and read to the same address: we can forwarding the 
 * write_data to read_data, instead of using the data read from memory
*/
class ForwardingMemory extends Module {
  val io = IO(new Bundle {
    val rdAddr = Input(UInt(10.W))
    val rdData = Output(UInt(8.W))
    val wrAddr = Input(UInt(10.W))
    val wrData = Input(UInt(8.W))
    val wrEna = Input(Bool())
  })

  val mem = SyncReadMem(1024, UInt(8.W))
  val wrDataReg = RegNext(io.wrData)
  val doForwardReg = RegNext(
    io.wrAddr === io.rdAddr &&
      io.wrEna
  )
  val memData = mem.read(io.rdAddr)
  when(io.wrEna) {
    mem.write(io.wrAddr, io.wrData)
  }
  io.rdData := Mux(doForwardReg, wrDataReg, memData)
}
object GetMemoryVerilog extends App {
  print("get verilog")
//   (new chisel3.stage.ChiselStage).emitVerilog(new Memory())
  (new chisel3.stage.ChiselStage).emitVerilog(new ForwardingMemory())
}
