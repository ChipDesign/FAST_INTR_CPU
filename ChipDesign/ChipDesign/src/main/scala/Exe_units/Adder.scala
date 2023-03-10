package Exe_units
import chisel3._
import chisel3.util.{HasBlackBoxInline, HasBlackBoxResource}

class Full_adder_v extends BlackBox with HasBlackBoxInline{
  val io=IO(new Bundle{
    val ain=Input(UInt(1.W))
    val bin=Input(UInt(1.W))
    val cin=Input(UInt(1.W))
    val sout=Output(UInt(1.W))
    val cout=Output(UInt(1.W))
    val orout=Output(UInt(1.W))
    val xorout=Output(UInt(1.W))
    val andout=Output(UInt(1.W))
  })

  setInline("full_adder.v",
    s"""
       |module full_adder(
       |ain,bin,cin,sout,cout,xorout,orout,andout);
       |
       |input ain,bin,cin;
       |output sout,cout,xorout,orout,andout;
       |
       |wire axorb,aorb,aandb
       |
       |assign axorb= ain ^ bin
       |assign aorb=  ain | bin
       |assign aandb= ain & bin
       |
       |
       |assign xorout= axorb
       |assign orout=aorb
       |assign andour=aandb
       |assign sout=axorb ^ cin
       |assign cout=(c & aorb) | aandb
       |
       |endmodule
       |
      """.stripMargin)

}

class Full_adder extends Module{
  val io = IO(new Bundle {
    val ain = Input(UInt(1.W))
    val bin = Input(UInt(1.W))
    val cin = Input(UInt(1.W))
    val sout = Output(UInt(1.W))
    val cout = Output(UInt(1.W))
    val orout = Output(UInt(1.W))
    val xorout = Output(UInt(1.W))
    val andout = Output(UInt(1.W))
  })
  val bb=Module(new Full_adder_v)

  io<>bb.io

}
