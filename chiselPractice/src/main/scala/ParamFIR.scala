/*
this is a chisel practice
through the practice, we will learn to create a parameterized module
the target of the practice is to create a FIR filter with variable data width and variable input cycle
 */
import chisel3._

import scala.collection.mutable


class ParamFIR(const:Seq[Int],width:Int) extends Module{
  val io=IO(new Bundle {
    val sig_in = Input(UInt(width.W))
    val sig_out = Output(UInt(width.W))
  })

  val regs=mutable.ArrayBuffer[UInt]()
  for(i<-0 until const.length)
    {
      if(i==0) regs+=io.sig_in
      else regs+=RegNext(regs(i-1),0.U)
    }
  val muls=mutable.ArrayBuffer[UInt]()
  for(i<-0 until const.length)
    {
      muls+=regs(i)*const(i).U
    }
  val sums=mutable.ArrayBuffer[UInt]()
  for(i<- 0 until const.length)
    {
      if(i==0) sums+=muls(i)
      else sums+= sums(i-1)+muls(i)
    }

  io.sig_out:=sums.last
}


object ParamFIR extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new ParamFIR(Seq(1,1,2,3,5),5))
}