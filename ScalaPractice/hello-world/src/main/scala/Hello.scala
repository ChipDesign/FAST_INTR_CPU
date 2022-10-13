/**
 * file: Hello.scala
 * Chisele Hello World项目
 * 
*/
// package myPacket

package hello

import chisel3._
// import chisel3.util._
// import chisel3.tester._
// import chisel3.tester.RawTester.test
// import dotvisualizer._


class Hello extends Module{
  val io=IO(new Bundle{
    val a=Input(UInt(4.W))
    val b=Input(UInt(4.W))
    val c=Output(UInt(4.W))
  })

  io.c:=io.a+io.b
}


object Hello extends App {
  println("Hello World Chisel")
  (new chisel3.stage.ChiselStage).emitVerilog(new Hello())
}
