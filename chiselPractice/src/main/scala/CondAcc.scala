/*
this is a chisel practice
the target of the practice is to build an module with 1 input and 1 output
the module is a conditional accumulator,
when input is 01, the module accumulates 1 at 1 clock
when 10, the module accumulates 1 at 1 clock
when others, the accumulator stops
through this practice, we will learn to describe a sequential circuit module and use a control flow
 */

import chisel3._


class CondAcc extends Module{
  val io=IO(new Bundle{
    val ctrl=Input(UInt(2.W))
    val out=Output(UInt(5.W))
  })
  val acc=RegInit(0.U(5.W))
  when(io.ctrl === 1.U)
  {
    acc:=acc+2.U
  }.elsewhen(io.ctrl===2.U)
  {
    acc:=acc+1.U
  }.otherwise
  {
    acc:=acc
  }
  io.out:=acc
}

object CondAcc extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new CondAcc())
}