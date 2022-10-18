/*
this is a chisel practice
the target of the practice is to build a simple bus with 4 masters with different priorities and 1 slave
the masters produce the data at the same time and the arbiter will decide which master is able to send data
all interface connected to bus should be decoupled
through this practice, we will learn to use the chisel standard library
specifically, DecoupledIO, queue, arbiter, OneHot Encoding and counter will be used
 */

import chisel3._
import chisel3.util.{Arbiter, Counter, Decoupled, Queue, RegEnable}

import scala.collection._



class BusMaster(Source:Seq[UInt]) extends Module{

  val io=IO(new Bundle{
    val data=Decoupled(UInt(8.W))
    //val selected=Input(UInt(1.W))
  })
  val FlagReg=RegInit(UInt(1.W),0.U)
  val cnt=Counter(5)

  val reg0 =Reg(Vec(4,UInt(8.W)))
  when(reset.asBool){
    for (i <- 0 until 4) {

      reg0(i) := Source(i).asUInt
    }
  }


  when(io.data.ready)
  {
    cnt.inc()
  }

  when(cnt.value<4.U& !FlagReg.asBool)
  {
    io.data.valid:=true.B
    io.data.bits:=reg0(cnt.value)
  }.otherwise
  {
    FlagReg:=1.U
    io.data.valid:=false.B
    io.data.bits:=0.U
  }
}

class BusSlave extends Module{
  val io=IO(new Bundle{
    val data_in=Flipped(Decoupled(UInt(8.W)))
    val QueueOut=Output(UInt(8.W))
    val OutReady=Input(UInt(1.W))
  })
  val AccQueue=Module(new Queue(UInt(8.W),16))
  AccQueue.io.enq<>io.data_in
  io.QueueOut :=AccQueue.io.deq.bits
  AccQueue.io.deq.ready:=io.OutReady
}

class SimpleBus extends Module{
  val io=IO(new Bundle{
    val SlaveDataOut=Output(UInt(8.W))
  })
  val arbi=Module(new Arbiter(UInt(8.W),4))
  val M1=Module(new BusMaster(Seq[UInt](3.U,6.U,9.U,12.U)))
  val M2=Module(new BusMaster(Seq(15.U,1.U,4.U,7.U)))
  val M3=Module(new BusMaster(Seq(10.U,13.U,16.U,2.U)))
  val M4=Module(new BusMaster(Seq(5.U,8.U,11.U,14.U)))
  M1.io.data<>arbi.io.in(0)
  M2.io.data<>arbi.io.in(1)
  M3.io.data<>arbi.io.in(2)
  M4.io.data<>arbi.io.in(3)

  val S=Module(new BusSlave)
  io.SlaveDataOut:=S.io.QueueOut
  S.io.data_in<>arbi.io.out

  val cnt=Counter(21)
  val OutReady=RegInit(UInt(1.W),0.U)
  when(arbi.io.out.valid)
  {
    cnt.inc()
  }
  when(cnt.value===15.U)
  {
    OutReady:=1.U
  }
  S.io.OutReady:=OutReady

}


object SimpleBus extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new SimpleBus)
}