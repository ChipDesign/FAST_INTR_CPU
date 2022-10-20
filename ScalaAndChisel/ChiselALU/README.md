# Chisel ALU

本项目的目的在于实现一个简单的ALU，通过该ALU的实现：
1. 介绍Scala和Chisel的基础知识
2. 介绍如何将硬件设计通过Chisel来实现
3. 介绍如何调试&验证Chisel项目



# 1 ALU介绍

![image-20221017161855031.png](https://s2.loli.net/2022/10/17/kQEJFixXng4vshD.png)

如上图所示，本次实现的ALU接受两个输入参数`SrcA`, `SrcB`，一个控制信号`ALUControl`，得到一个输出`ALUResult`

## 该ALU支持的指令

1. 算数指令：add, sub, mul
2. 逻辑指令: and, or, xor
3. 跳转指令: beq
4. 移位指令: srl
5. 访存指令: lw, sw

针对上述各个指令，ALU的需要具备的计算，及各个计算的`ALUControl`如下：

| 计算名称 | 涉及的指令  | ALUControl |
| -------- | ----------- | ---------- |
| 加法     | add, lw, sw | 000        |
| 减法     | sub, beq    | 001        |
| 乘法     | mul         | 010        |
| 逻辑与   | and         | 011        |
| 逻辑或   | or          | 100        |
| 逻辑异或 | xor         | 101        |
| 逻辑右移 | srl         | 110        |

ALU内部采用补码来表示整数，最高位是符号位，其余的为数值部分。

除此之外，每次计算之后ALU还需要依据计算结果给出zero, overflow, parity, negative等标志位：

1. zero: 计算结果为0，可以用于beq指令的判断。当`ALUResult==0`时，zero判定为1
2. overflow：计算结果溢出。
   - 做加法时，如果srcA和srcB同号，且srcA和ALUResult异号，则溢出
   - 在做减法时，如果srcA和srcB异号，且srcA和ALUResult异号，则溢出
   - TBD：关于乘法时溢出的判断
3. parity：结果中1的个数是否是奇数个，判断标准是`ALUResult[0]==0`
4. negative: 结果是负数，判断标准是标志位`sign==1`



# 2 运行项目

> 运行项目需要首先配置环境，如JVM和SBT。可以参考[此文档](https://github.com/timemeansalot/FAST_INTR_CPU/tree/main/FIC_ENV)进行配置。



1. 克隆项目到本地

   ```bash
   git clone https://github.com/timemeansalot/FAST_INTR_CPU.git
   cd FAST_INTR_CPU/
   ```

   

2. 进入到Chisel ALU文件夹

   ```bash
   cd ScalaAndChisel/ChiselALU/
   tree .
   ```

   可以看到项目的结构如下：

   ```bash
   .
   ├── Makefile
   ├── README.md
   ├── build.sbt
   └── src
       ├── main
       │   └── scala
       │       └── ChiselALU.scala
       └── test
           └── scala
               └── ChiselALUTest.scala
   ```

   其中各个文件的功能如下所示。其中**build.sbt, ChiselALU.scala和ChiselALUTest.scala**文件是项目所必须的。

   - Makefile：用于指示make命令的规则
   - README.md：本项目的介绍文档
   - build.sbt：指明构建项目需要的Scala和Chisel版本，以及依赖的库文件
   - src目录下存放有源文件和测试文件
     - ChiselALU.scala：源文件
     - ChiselALUTest.scala：测试文件

3. 构建项目项目

   ```Bash
   sbt run
   ```

   sbt构建构建项目的规则如下：

   - 构建所有的项目，编译所有的Scala文件：`sbt run`

   - 构建指定的项目，编译指定的Scala文件：`sbt "runMain packegeName.ClassName"`, 该指令可以指定只构建ClassName所命名的项目

   运行`sbt run`命令后，查看当前目录下的文件

   ```Bash
   tree . -L 1
   ```

   ```bash
   .
   ├── ChiselALU.anno.json
   ├── ChiselALU.fir
   ├── ChiselALU.v
   ├── Makefile
   ├── README.md
   ├── build.sbt
   ├── project
   ├── src
   └── target
   
   ```

   得到的目录结构如下，可以看到有3部分新的文件产生了

   1. project文件夹：存放的是sbt根据build.sbt文件，下载的项目依赖
   2. target文件夹：存放的是项目构建过程中产生的文件
   3. **ChiselALU.v, ChiselALU.fir, ChiselALU.anno.json：Chisel项目运行得到的硬件电路源文件**

4. 验证项目

   >  验证项目的过程是将硬件电路的仿真结果同期待值进行比较，可以使用`poke`函数添加激励，使用`expect`函数提供输出的期待值。Chisel默认使用Threadle进行硬件电路的仿真，也可以手动指定使用VCS、Verilator、Iverilator作为硬件电路的仿真工具。

   

   ```Bash
   sbt test
   ```

   sbt验证项目的规则如下：

   - 验证所有的项目，编译所有的Scala文件：`sbt test`

   - 验证指定的项目，编译指定的Scala文件：`sbt "testOnly packegeName.ClassName"`, 该指令可以指定只验证ClassName所命名的项目

   运行`sbt test`命令后，查看当前目录下的文件

   ```Bash
   tree . -L 1
   ```

   ```bash
   .
   ├── ChiselALU.anno.json
   ├── ChiselALU.fir
   ├── ChiselALU.v
   ├── Makefile
   ├── README.md
   ├── build.sbt
   ├── project
   ├── src
   ├── target
   └── test_run_dir
   ```

   得到的目录结构如下，可以看到生成了新文件*test_run_dir*，该文件夹存放着验证过程中生成的波形文件*ChiselALU.vcd*。

5. 产看波形：使用GTKwave、Modelsim或者其它波形查看工具，都可以打开vcd文件查看波形

   ```Bash
   gtkwave
   ```

   使用上述命令可以打开gtkwave的GUI窗口，选择：File->Open New Tab，选择生成的vcd文件，添加波形即可看到对应的波形图

   ![image-20221020113050484](https://s2.loli.net/2022/10/20/gAiMfmyXE2Wo7Tr.png)





# 3 对于源文件和测试文件的说明

> 本节主要用于解释ChiselALU.scala文件和ChiselALUTest.scala文件

## ChiselALU.scala

1. 文件开头使用`package`声明了文件所属的包，使用`import`引入了Chisel项目需要用到的包。
2. 使用`object Types`定义了7种ALU需要执行的计算，使用Enum表示各种计算，每种计算本质上是一个Int变量。
3. **定义了ChiselALU类**：
   - class ChiselALU(width: Int = 32)中的width是一个用于指定数据宽度的变量。在例化的时候，可以通过填入不同的width构造参数来生成不同宽度的ALU；除了可变长度之外，Chisel还可以自定义io端口的数据类型。
   - 其中IO部分定义了ALU的接口：通过`val io`定义了一个io对象，等号后面跟的是对于该IO的描述
   - 函数体部分定义了ALU针对不同control信号所执行的不同计算操作以及对信号Flag的计算操作，信号之间使用`:=`进行连接。
4. 文档末尾*object GetChiselALUVerilog extends App*申明了一个*单例对象*。
   - 该对象继承了App类，进而继承得到了App类内部的main方法。有了main方法之后，就可以作为程序的起始了开始运行了。
   - (new chisel3.stage.ChiselStage).emitVerilog(new ChiselALU(32))：通过emitVerilog函数生成了ChiselALU对应的硬件电路，如果没有调用此函数，则在执行`sbt run`的时候，不会生成.v, .fir和.json文件

```Scala
package chiselProcessor

import chisel3._
import chisel3.util._ // for switch/is

import chiselProcessor.Types._

object Types {
  val add :: sub :: mul :: and :: or :: xor :: srl :: Nil = Enum(7)
}

class ChiselALU(dataWidth: Int = 4, flagWidth: Int = 4) extends Module {
  val io = IO(new Bundle {
    val control = Input(UInt(3.W))
    val srcA = Input(UInt(dataWidth.W))
    val srcB = Input(UInt(dataWidth.W))
    val result = Output(UInt(dataWidth.W))
    val flags = Output(UInt(flagWidth.W))

  })

  val control = io.control
  val a = io.srcA
  val b = io.srcB
  val res = WireDefault(io.srcA)

  /** ALU Operations
    */
  switch(control) {
    is(add) {
      res := a + b
    }
    is(sub) {
      res := a - b
    }
    is(mul) {
      res := a * b
    }
    is(and) {
      res := a & b
    }
    is(or) {
      res := a | b
    }
    is(xor) {
      res := a ^ b
    }
    is(srl) {
      // if(b<32.U)
      res := a >> b
    }

  }
  printf("Hardware Simulation==> Operation=%d, srcA=%d, srcB=%d, ALUResult=%d, 0x%x\n",control, a, b,res,res)

  /** Calculate Flags
    */
  val flagVec = VecInit(0.U(flagWidth.W).asBools)
  val signA = WireInit(io.srcA(dataWidth - 1)) // A的符号
  val signB = WireInit(io.srcB(dataWidth - 1)) // B的符号
  val signRes = WireInit(res(dataWidth - 1))

  // zero
  flagVec(0) := res(dataWidth - 2, 0).orR

  // overflow
  flagVec(
    1
  ) := ((((~(signA ^ signB) && io.control === "b000".U) ||
    (signA ^ signB) && (io.control === "b001".U)) && (signA ^ signRes)))
  // // negative
  flagVec(2) := res(dataWidth - 1)

  // // parity
  // // io.parity:=PopCount(res)
  flagVec(3) := res.xorR()

  /** Get Output Signals
    */
  io.result := res
  io.flags := flagVec.asUInt
}

object GetChiselALUVerilog extends App {
  print("Get Verilog\n")
  (new chisel3.stage.ChiselStage).emitVerilog(new ChiselALU(32))
}

```



## ChiselALUTest.scala

1. 文件开头使用`package`声明了文件所属的包，使用`import`引入了Chisel Test需要用到的包。
2. 定义了一个ChiselALUTest的类，该类继承了AnyFlatSpec和ChiselScalatestTester
   - 继承AnyFlatSpec和ChiselScalatestTester之后，可以在函数体中使用`"ChiselALUTest" should "Pass" in`来指定测试的内容。具体说明可以参考：[chiseltest的介绍和实例 by 赵兄-RISCV in CSDN](https://blog.csdn.net/weixin_44134090/article/details/126837447)。
   - 定义函数`alu(a: Int, b: Int, op: Int): Int`，该函数的计算结果作为ALU的期待值expect。
   - 在"ChiselALUTest" should "Pass" in中定义了测试的内容，分别比较了硬件的输出结果和alu函数计算得到的期待值
   - .withAnnotations(Seq(WriteVcdAnnotation))：可以生成测试时的波形文件；Chisel默认使用Threadle来仿真，还可以使用VCS或者verilator等仿真工具，`.withAnnotations(Seq(VerilatorBackendAnnotation, WriteVcdAnnotation))`命令可以将仿真工具改为Verilator。

```Scala
package chiselProcessor

import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import chiselProcessor.Types._
import dataclass.data

class ChiselALUTest extends AnyFlatSpec with ChiselScalatestTester {
  val dataWidth: Int = 16
  val flagWidth: Int = 4

  /** alu函数返回ALU计算的期待值，用于跟硬件电路的结果进行比较
    */
  def alu(a: Int, b: Int, op: Int): (Int, Int) = {
    var result: Int = 0
    var flags: Int = 0

    /** ALU operations
      */
    op match {
      case 0 => result = a + b
      case 1 => result = a - b
      case 2 => result = a * b
      case 3 => result = a & b
      case 4 => result = a | b
      case 5 => result = a ^ b
      case 6 =>
        if (b >= dataWidth) result = 0
        else result = a >>> b // avoid: x>>>32 = x
    }

    /** Flags
      */
    var min = 1 << (dataWidth - 1)
    var max = min - 1
    var upperBound = (1 << dataWidth) - 1
    // printf("min=%x, max=%x, upb=%x\n", min, max, upperBound)
    // zero
    if ((result & max) == 0) {
      flags = flags & 0
    } else {
      flags = flags | 1
    }
    // overflow
    if (result > upperBound) {
      flags = flags | 2
    } else {
      flags = flags & 13
    }

    // negative
    if ((result & min) == min) {
      // flags= flags | 0100
      flags = flags | 4
    } else {
      // flags = flags & 1011
      flags = flags & 11
    }

    // parity
    def parity(y: Int): Int = {
      var x: Int = y
      var count: Int = 0
      var lsb: Int = x % 2
      var parity: Int = 0
      while (count < dataWidth) {
        lsb = x % 2
        // printf("x=%d, lsb=%d\n", x, lsb)
        parity = parity ^ lsb
        count = count + 1
        x = x >> 1
      }
      parity
    }
    // printf("result=%d, upb= 0x%x\n", result, upperBound)
    if (parity(result & upperBound) == 1) {
      flags = flags | 8
    } else {
      flags = flags & 7
    }

    return (result, flags)

  }

  /** x should in y格式，用于测试：如果y中的内容满足，则x测试通过
    */
  "ChiselALUTest" should "Pass" in {
    test(new ChiselALU(dataWidth))
      .withAnnotations(Seq(WriteVcdAnnotation)) { dut =>

        for (i <- 0 to 6) {
          if (i != 2) // 跳过乘法的测试，目前乘法还不稳定
            for (j <- 0 to 1) {
              var a = scala.util.Random.nextInt(1000)
              var b = scala.util.Random.nextInt(1000)
              println("feed data: " + a + ", " + b + ", " + i)
              dut.io.srcA.poke(a.U)
              dut.io.srcB.poke(b.U)
              dut.io.control.poke(i.U)
              // test ALU Result
              dut.io.result.expect(
                (alu(
                  a,
                  b,
                  i
                )._1.toLong & 0x000000ffffL).U // 对于tuple(a,b), ._1选择a, ._2选择b
              ) // avoid negative value
              // test ALU Flags
              dut.io.flags.expect((alu(a, b, i)._2.toLong & 0x000000ffffL).U)
              dut.clock.step()
              var outResult=dut.io.result.peek()
              var outFlags=dut.io.flags.peek()
              println("get (result, flags)= ("+outResult+", "+outFlags+"\n\n")
            }
        }
        print("ALU Operation and ALU Flags test all PASS\n")
      }
  }
}

```



# 未来工作

- [ ] 补充diff test的内容
- [ ] 完成ALU中乘法器的部分，计划重写乘法器
- [ ] Others







# 附录： 关于RISC-V指令的介绍

## RISC-V  4种基本指令格式

![image-20221017164801800](https://s2.loli.net/2022/10/18/wkO8KNQFJZYpgGT.png)

基本 ISA 中有 4 种核心的指令格式（R / I / S / U）。四者的长度固定为 32 位，在内存中必须按字（４个字节）对齐。

## 具体各种指令的介绍

### LW(Load Word), I-type

> 基础地址+偏移=内存地址，从内存地址中取数

![image-20221017163829475](https://s2.loli.net/2022/10/18/M6sQo9dUjn4hNaw.png)

| 字段名称 | 比特数 | 功能                                         |
| -------- | ------ | -------------------------------------------- |
| imm      | 12     | 偏移offset，需要做sign-extension             |
| rs1      | 5      | 基础寄存器：从该寄存器中读出基础的地址       |
| f3       | 3      | func3 for width                              |
| rd       | 5      | 目标寄存器：从内存中取到的数，放到该寄存器中 |
| op       | 7      | lw的操作码                                   |

ALU在执行LW指令的时候，需要做的是：`result=A+B`，**令加法操作的ALU opcode=000**

### SW(Save Word), S-type

> 将某个寄存器中的数，存到内存的每个地址中

![image-20221017181052292](https://s2.loli.net/2022/10/18/DSIUHPAeCoVBvaz.png)

| 字段名称 | 比特数 | 功能                                   |
| -------- | ------ | -------------------------------------- |
| imm      | 12     | 偏移offset，需要做sign-extension       |
| rs1      | 5      | 基础寄存器：从该寄存器中读出基础的地址 |
| f3       | 3      | func3 for width                        |
| rs2      | 5      | 从该寄存器中取出数，把该数存到内存中   |
| op       | 7      | sw的操作码                             |

ALU在执行LW指令的时候，需要做的是：`result=A+B`，**令加法操作的ALU opcode=000**

### R-type: add, sub, and, or, xor, sll(shift left logic), shr

> 从两个源寄存器读书，计算结果写到第三个寄存器

![image-20221017182249696](https://s2.loli.net/2022/10/18/L4Phf8ubAr5SE7y.png)

| 字段名称 | 比特数 | 功能             |
| -------- | ------ | ---------------- |
| rs1      | 5      | 源寄存器         |
| rs2      | 5      | 源寄存器         |
| rd       | 5      | 目的寄存器       |
| op       | 7      | 操作码           |
| f3       | funct3 | 和op一起指明操作 |
| func7    | funct7 | 和op一起指明操作 |

### BEQ

> 比较两个源寄存器的值，如果相等则PC=PC+offset(有立即数给出），否则PC=PC+4

![image-20221017191528388](https://s2.loli.net/2022/10/18/SsDZ7plthHfxowA.png)

ALU在执行BEQ指令的时候，需要做的是：`result=A-B`，**令加法操作的ALU opcode=001**