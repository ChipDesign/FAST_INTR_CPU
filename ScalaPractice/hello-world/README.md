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
2. decoder generator: `Vec`
    ```Scala
    class EncoderGenerator extends Module {
        val io = IO(new Bundle {
            val hotIn = Input(UInt(4.W))
            val code = Output(UInt(2.W))
        })

        val v = Wire(Vec(4, UInt(2.W)))

        v(0) := 0.U
        for (i <- 1 until 4) {
            v(i) := Mux(io.hotIn(i), i.U, 0.U) | v(i - 1)
        }
        io.code := v(3)
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

# 声明
本项目参考有:
1. [schoeberl/chisel-examples](https://github.com/schoeberl/chisel-examples)
2. [Scala Cheetsheet](https://allaboutscala.com/scala-cheatsheet/)
3. [scalaTest的初步使用](https://blog.csdn.net/debang2014010/article/details/102327031?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&utm_relevant_index=9)