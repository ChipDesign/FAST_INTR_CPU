/*
this is a chisel practice
the target of the practice is to build an module with 2 input and 1 output
the 8'b output is the product of 2 4'b input
through this practice, we will learn to describe a combinational circuit module with its input and output
 */

import chisel3._

class multi  extends Module{
  val io=IO(new Bundle{
    val ina=Input(UInt(4.W))
    val inb=Input(UInt(4.W))
    val out=Output(UInt(8.W))
  })
  io.out:=io.ina*io.inb
}

object multi extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new multi())
}