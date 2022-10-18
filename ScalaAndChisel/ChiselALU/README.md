# Chisel ALU

本项目的目的在于实现一个简单的ALU，通过该ALU的实现：
1. 介绍Scala和Chisel的基础知识
2. 介绍如何将硬件设计通过Chisel来实现
3. 介绍如何调试&验证Chisel项目



# ALU介绍

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