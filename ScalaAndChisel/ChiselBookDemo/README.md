# Chisel Hello World

# 第一个简单的demo
```
├── Makefile
├── README.md
├── build.sbt
└── src
    ├── main
    │   └── scala
    │       └── Hello.scala
    └── test
        └── scala
            └── HelloTest.scala
```
初始时，项目的结构如上述树状图所示。其中最重要的是`src`和`build.sbt`，各个文件介绍如下：
1. src：存放项目的源代码和测试代码，分别是Hello.scala和HelloTest.scala
2. build.sbt：Scala采用SBT来构建项目，build.sbt文件指明了Scala文件需要的Scala版本和Chisel库，SBT根据该文件会去自动下载相应的依赖
3. Makefile/README.md：非必须的文件，前者负责make，后者负责提供说明文档

## 运行项目
1. 在Hello.scala中输入以下内容
    ```Scala
    /**
     * file: Hello.scala
     * Chisele Hello World项目
     * 
    */
    
    package myPacket
    
    object Hello extends App {
    println("Hello World Chisel")
    }
    ```
2. 使用sbt构建项目，在build.sbt同级目录下，输入如下命令
    `sbt run`或者`sbt "runMain myPacket.Hello"`
    > This command will compile all your Chisel code from the source tree and searches for classes that contain an object that includes a main method, or simpler that extends App

    可以看到终端输出了`Hello World Chisel`

3. 测试项目
`sbt test`或者`sbt "test:runMain myPacket.HelloTest"

## 生成Verilog代码
1. `emitVerilog(object, path)`
    ```Scala
    object HelloOption extends App {
        emitVerilog(new Hello(), Array("--target -dir",
        "generated"))
    }
    ```
2. `getVerilogString(object)`
    ```Scala
    object HelloString extends App {
        val s = getVerilogString(new Hello())
        println(s)
    }
    ```

## Test
### Scala Test
>  ChiselTest is an extension of ScalaTest. 所以我们先介绍Scala Test

[介绍ScalaTest的文章](https://blog.csdn.net/debang2014010/article/details/102327031?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&utm_relevant_index=9)


```Scala
import org.scalatest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

class HelloTest extends AnyFlatSpec with Matchers {
  "Integers" should "add" in {
    val i = 2
    val j = 3
    i + j should be (5)
}
"Integers" should "multiply" in {
    val a = 3
    val b = 4
    a * b should be (12)
  }
}
```
使用命令~~sbt test~~或者**sbt "testOnly HelloTest"**开始测试。前者测试所有test，后者只测试一个指定的test

### ChiselTest
> ChiselTest is the standard testing tool for Chisel modules based on the ScalaTest tool for Scala and Java, which we can use to run Chisel tests
1. DUT(device under test), testbench：用于测试DUT
2. ChiselTest需要继承`ChiselScalatestTester`
```Scala
/**
 * file: ChiselTest.scala
 * 
 * ChiselTest is the standard testing tool for Chisel modules based on the ScalaTest
 * tool for Scala and Java, which we can use to run Chisel tests
 * -----------------------------------------------------
 * Use Command `sbt "testOnly ChiselTest" to do this test
*/

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec

/**
 * Device Under Test(DUT)
 * AND Gate && Comparator
*/
class DeviceUnderTest extends Module {
    val io = IO(new Bundle {
    val a = Input(UInt(2.W))
    val b = Input(UInt(2.W))
    val out = Output(UInt(2.W))
    val equ = Output(Bool()) // Chisel Bool
})
    io.out := io.a & io.b
    io.equ := io.a === io.b
}

/**
 * Testbench to test DUT
*/
class ChiselTest extends AnyFlatSpec with
    ChiselScalatestTester {
    "DUT" should "pass" in {
        // DUT as parameter
    test(new DeviceUnderTest) { dut =>
        // test logic
        dut.io.a.poke(0.U)
        dut.io.b.poke(1.U)
        dut.clock.step()
        println("Result is: " + dut.io.out.peek().toString)
        dut.io.a.poke(3.U)
        dut.io.b.poke(2.U)
        dut.clock.step()
        println("Result is: " + dut.io.out.peek().toString)
        }
    }
}
```

## Waveform
1. `sbt "testOnly SimpleTest -- -DwriteVcd=1"`其中DwriteVcd表示输出波形，得到的vcd文件可以在波形软件中查看。
2. 在test中指定生成波形：
    ```Scala
    test(new DeviceUnderTest).withAnnotations(Seq(WriteVcdAnnotation))
    ```

# Combination Logic
## Decoder
1. simple decoder: `switch/is`
    ```Scala
    class DecoderSimiple extends Module{
        val io=IO(new Bundle{
            val sel=Input(UInt(2.W))
            val output=Output(UInt(4.W))
        })
    
        io.output:=0.U // RefNotInitializedException: Chisel need us to provide a default value
    
        switch(io.sel){
            is (0.U) {io.output:=1.U}
            is (1.U) {io.output:=2.U}
            is (2.U) {io.output:=4.U}
            is (3.U) {io.output:=8.U}
        }
    }
    ```
2. binary decoder
    ```Scala
    class DecoderBinary extends Module{
        val io=IO(new Bundle{
            val sel=Input(UInt(2.W))
            val output=Output(UInt(4.W))
        })
    
        io.output:=0.U // RefNotInitializedException: Chisel need us to provide a default value
    
        switch(io.sel){
            is ("b00".U) {io.output:="b0001".U}
            is ("b01".U) {io.output:="b0010".U}
            is ("b10".U) {io.output:="b0100".U}
            is ("b11".U) {io.output:="b1000".U}
        }
    }
    ```
3. shift decoder
    ```Scala
    class DecoderShift extends Module{
        val io=IO(new Bundle{
            val sel=Input(UInt(2.W))
            val output=Output(UInt(4.W))
        })
    
        // io.output:= 1.U<<io.sel
        io.output:= "b0001".U<<io.sel
    }
    ```

## Encoder
1. inverse of simple decoder: `switch/is`
    ```Scala
    class EncoderSimple extends Module {
        val io = IO(new Bundle {
            val hotIn = Input(UInt(4.W))
            val code = Output(UInt(2.W))
        })
    
        io.code := 0.U
        switch(io.hotIn) {
            is("b0001".U) { io.code := "b00".U }
            is("b0010".U) { io.code := "b01".U }
            is("b0100".U) { io.code := "b10".U }
            is("b1000".U) { io.code := "b11".U }
        }
    }
    ```
2. encoder generator: `Vec`, `log2Up`, `unsignedBitLength(n)`
    ```Scala
    class EncoderGenerator(n: Int) extends Module {
        val io = IO(new Bundle {
            val hotIn = Input(UInt(n.W))
            val code = Output(UInt(log2Up(n).W)) // can use `unsignedBitLength(n)` instead
        })
    
        val v = Wire(Vec(n, UInt(2.W)))
    
        v(0) := 0.U
        for (i <- 1 until n) {
            v(i) := Mux(io.hotIn(i), i.U, 0.U) | v(i - 1)
        }
        io.code := v(n - 1)
    }
    ```

3. Priority Encoder
    ```Scala
        /** 之前的encoder只允许hotIn中最多有一位是1 PriorityEncoder允许hotIn中有多位是1，
     * 通过一个Arbiter选择优先级最高的1
     */
    class PriorityEncoder(n: Int) extends Module {
        val io = IO(new Bundle {
            val hotIn = Input(UInt(4.W))
            val code = Output(UInt(2.W))
        })
    
        val aw = Module(new ArbiterWrapper(4))
        var eg = Module(new EncoderGenerator(4))
    
        // connect all ports, using BULK Connection
        aw.io.request := io.hotIn
        eg.io.hotIn := aw.io.hotIn
        io.code := eg.io.code
    }
    ```

## Arbiter
```Scala
    class Arbiter(n: Int) extends Module { // n is same to `constructor param` in C++
        val io = IO(new Bundle {
            val request = Input(Vec(n, Bool())) // create an array Input
            val output = Output(Vec(n, Bool()))
        })

        val grant = VecInit.fill(n)(false.B)
        val notGranted = VecInit.fill(n)(false.B)
        grant(0) := io.request(0)
        notGranted(0) := !grant(0)
        for (i <- 1 until n) {
            grant(i) := io.request(i) && notGranted(i - 1)
            notGranted(i) := !grant(i) && notGranted(i - 1)
        }

        io.output := grant
    }
```

# Sequential Logic
## Slow Counter: use `tick` signal to slow a counter
```Scala
    class SlowCounter extends Module {
    val io = IO(new Bundle {
        val out = Output(UInt(2.W))
    })

        val tickCounter = RegInit(0.U(2.W))
        val tick = tickCounter === 3.U
        tickCounter := tickCounter + 1.U
        when(tick) {
            tickCounter := 0.U
        }

        val slowCount = RegInit(0.U(2.W))
        when(tick) {
            slowCount := slowCount + 1.U
        }

        io.out := slowCount

    }
```
## Shift Register: `##`
1. Delay Register: the output is 4 cycle delay of input
    ```Scala
    class DelayRegister extends Module {
        val io = IO(new Bundle {
            val din = Input(UInt(1.W))
            val dout = Output(UInt(1.W))
        })
    
        val shiftReg = Reg(UInt(4.W))
        shiftReg := shiftReg(2, 0) ## io.din
    
        io.dout := shiftReg(3)
    }
    ```
2. Parallel Register: change serial into parallel output
    ```Scala
    class ParallelRegister extends Module {
        val io = IO(new Bundle {
            val din = Input(UInt(1.W))
            val dout = Output(UInt(4.W))
        })
    
        val parallelReg = RegInit(0.U(4.W))
        parallelReg := io.din ## parallelReg(3, 1)
        io.dout := parallelReg
    }
    ```
## Memory: `SyncReadMem`
1. Simple Memory
    ```Scala
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
    ```
2. Forwarding Memory: forwarding the write_data to read_data when read and write address are the same
    ```Scala
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
    ```


# 硬件生成器Hardware Generator
## 参数设置
### 可变宽度
使用Scala的UInt作为构造函数的参数，然后利用该参数指定数据的宽度
```Scala
class ParamAdder(n: Int) extends Module { // n可以指定任意宽度
    val io = IO(new Bundle{
    val a = Input(UInt(n.W))
    val b = Input(UInt(n.W))
    val c = Output(UInt(n.W))
    })
    io.c := io.a + io.b
}
```
### 可变类型
指定不同的参数类型:`T <: Data`. 

- we used `WireDefault` to create a wire with
the type T with a default value
- If we need to create a wire just of the Chisel type
without using a default value, we can use `cloneType` to get the Chisel type
```Scala
class NocRouter[T <: Data](dt: T, n: Int) extends Module {
  val io = IO(new Bundle {
    val inPort = Input(Vec(n, dt))
    val address = Input(Vec(n, UInt(8.W)))
    val outPort = Output(Vec(n, dt))
  })
  io.outPort := io.inPort
}

// data type
class Payload extends Bundle {
  val data = UInt(16.W) // set data width
  val flag = Bool()
}

object GetVerilog extends App{
    print("get verilog code\n")
    (new chisel3.stage.ChiselStage).emitVerilog(new NocRouter(new Payload,2))
}
```
得到的Verilog代码如下：
```Verilog
module NocRouter(
  input         clock,
  input         reset,
  input  [15:0] io_inPort_0_data,
  input         io_inPort_0_flag,
  input  [15:0] io_inPort_1_data,
  input         io_inPort_1_flag,
  input  [7:0]  io_address_0,
  input  [7:0]  io_address_1,
  output [15:0] io_outPort_0_data, // 两组data_in和data_out
  output        io_outPort_0_flag,
  output [15:0] io_outPort_1_data,
  output        io_outPort_1_flag
);
  assign io_outPort_0_data = io_inPort_0_data; // @[NocRouter.scala 15:14]
  assign io_outPort_0_flag = io_inPort_0_flag; // @[NocRouter.scala 15:14]
  assign io_outPort_1_data = io_inPort_1_data; // @[NocRouter.scala 15:14]
  assign io_outPort_1_flag = io_inPort_1_flag; // @[NocRouter.scala 15:14]
endmodule
```
### 读取文件`fromFile("data.txt")`

```Scala
import chisel3._
import scala.io.Source

class FileReader extends Module {
  val io = IO(new Bundle {
    val address = Input(UInt(8.W))
    val data = Output(UInt(8.W))
  })
  val array = new Array[Int](256)
  var idx = 0
// read the data into a Scala array
  val source = Source.fromFile("data.txt")
  printf("I want to printf something")
  for (line <- source.getLines()) {
    array(idx) = line.toInt // get Scala Int
    idx += 1
  }
// convert the Scala integer array
// into a vector of Chisel UInt
  val table = VecInit(array.map(_.U(8.W)))
// use the table
  io.data := table(io.address)
}
```

## 继承和测试Inheritance and it's test
Define a `trait TickerTestFunc`, 该trait定义了一个方法，来测试不同类型的Ticker，不同类型的Ticker继承了原始的Ticker（一个抽象的类，即接口）。

see file `IneritanceScala` and `IneritanceTest.scala`

# Debug
Chisel测试支持以下特性：
1. 多线程测试: `fork`, `join`
    ```Scala
    it should "work with multiple threads" in {
        test(new BubbleFifo(8, 4)) { dut =>
        val enq = fork {
        while (dut.io.enq.full.peek.litToBoolean)
        dut.clock.step()
        dut.io.enq.din.poke(42.U)
        dut.io.enq.write.poke(true.B)
        dut.clock.step()
        dut.io.enq.write.poke(false.B)
        }
        while (dut.io.deq.empty.peek.litToBoolean)
        dut.clock.step()
        dut.io.deq.dout.expect(42.U)
        dut.io.deq.read.poke(true.B)
        dut.clock.step()
        dut.io.deq.empty.expect(true.B)
        enq.join
        }
    }
    ```
2. 默认*生成波形*的仿真工具是**Threadle**，支持使用第三方仿真工具：**Verilator**, **VCS**, **Iverilator**. 
   
    参考[chiseltest的介绍和实例 by 赵兄-RISCV in CSDN](https://blog.csdn.net/weixin_44134090/article/details/126837447)
    - [treadle](https://github.com/chipsalliance/treadle): default, fast startup times, slow execution for larger circuits, supports only VCD
    
    - [verilator](https://www.veripool.org/wiki/verilato): enable with `VerilatorBackendAnnotation`, slow startup, fast execution, supports VCD and FST
    
        ```scala
        test(new xxx)
            .withAnnotations(Seq(VerilatorBackendAnnotation, WriteVcdAnnotation))
        ```
    
        Verilator is a socalled *synchronous simulator*, 有如下的缺点：
    
        - *updates only at the rising edge* of the clock and thus 
        - *does not support latches*. 
        - Does not officially support *multiple clocks*
    
    - [iverilog](http://iverilog.icarus.com/): open-source, enable with `IcarusBackendAnnotation`, supports VCD, FST and LXT
    
    - [vcs](https://www.synopsys.com/verification/simulation/vcs.html): commercial, enable with `VcsBackendAnnotation`, supports VCD and FSDB
    

# 声明
本项目参考有:
1. [schoeberl/chisel-examples](https://github.com/schoeberl/chisel-examples)
2. [Scala Cheetsheet](https://allaboutscala.com/scala-cheatsheet/)
3. [scalaTest的初步使用](https://blog.csdn.net/debang2014010/article/details/102327031?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&utm_relevant_index=9)
4. [chiseltest的介绍和实例 by 赵兄-RISCV in CSDN](https://blog.csdn.net/weixin_44134090/article/details/126837447)