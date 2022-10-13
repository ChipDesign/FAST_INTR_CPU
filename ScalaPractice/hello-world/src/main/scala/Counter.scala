/** FILE: Counter.scala
  *
  * create a counter using adder, register and mux
  */
package component

import chisel3._

class Adder extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(8.W))
    val b = Input(UInt(8.W))
    val y = Output(UInt(8.W))
  })

  io.y := io.a + io.b
}

class Register extends Module{
    val io=IO(new Bundle{
        val d=Input(UInt(8.W))
        val q=Output(UInt(8.W))
    })

    val reg=RegInit(0.U) // register with init
    reg:=io.d
    io.q:=reg
}

class Counter10 extends Module{
    val io=IO(new Bundle{
        val dout=Output(UInt(8.W))
    })

    val add=Module(new Adder())
    val reg=Module(new Register)

    // register output
    val count = reg.io.q

    // connect adder
    add.io.a:=1.U
    add.io.b:=count
    val adder_result = add.io.y

    // connect register and mux
    val next = Mux(count===9.U, 0.U, adder_result)
    reg.io.d:=next

    io.dout:=count
}

object Hello extends App {
  println("Hello World Chisel")
  (new chisel3.stage.ChiselStage).emitVerilog(new Counter10())
}