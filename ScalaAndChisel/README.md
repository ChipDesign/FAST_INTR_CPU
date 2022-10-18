# ScalaAndChisel 项目介绍
> 本项目记录从学习Scala开始，再学习Chisel，最后使用Chisel实现一个简单的ALU并且验证的过程



在学习Scala和Chisel语法的时候，使用的源文件是使用jupyter notebook，该notebook采用Scala作为kernel。使用jupyter notebook是为了在记录代码的同时，很好的添加文档说明。

在具体做Chisel项目的时候，使用**sbt**作为项目build和test的工具。

本文档分为以下几部分：
1. [Scala基础](https://github.com/ChipDesign/FAST_INTR_CPU/blob/main/ScalaPractice/ScalaBasicSyntax.ipynb)：在jupyter的notebook中，大致描述了Scala的基础语法知识
2. [Chisel基础](https://github.com/ChipDesign/FAST_INTR_CPU/blob/main/ScalaPractice/ChiselBasic.ipynb)：在jupyter的notebook中，大致描述了Chisel的基础语法知识
3. [ChiselBookDemo](https://github.com/timemeansalot/FAST_INTR_CPU/tree/main/ScalaAndChisel/ChiselBookDemo)：Chisel Book是一本Chisel的入门书籍，从零开始介绍了如何使用Chisel构建硬件电路并且验证。此项目包含如下内容：
    - 运行一个简单的chisel项目
    - Chisel实现组合逻辑电路: decoder, encoder, arbiter, etc...
    - Chisel实现时序逻辑电路：counter, shiftRegister, memory
4. **[Chisel ALU项目](https://github.com/timemeansalot/FAST_INTR_CPU/tree/main/ScalaAndChisel/ChiselALU)**：通过Chisel实现并验证一个简单的ALU，该ALU接受两个输入参数`SrcA`, `SrcB`，一个控制信号`ALUControl`，得到一个输出`ALUResult`

**推荐的阅读顺序**

可以*直接阅读Chisel ALU项目*，阅读过程中如果有不同的地方可以在前三部分中查找相应的问题。

# 申明

本项目的参考资料如下：
1. [西安交大一位研究生写的较为完整 Chisel 教程，从 Scala 到 Chisel，以及一些高级功能的介绍](https://blog.csdn.net/qq_34291505/article/details/86744581)
2. [Chilse-Book: 一本从零开始讲解Chisel的PDF书](http://www.imm.dtu.dk/~masca/chisel-book.pdf)

3. [schoeberl/chisel-examples](https://github.com/schoeberl/chisel-examples)
4. [Scala Cheetsheet](https://allaboutscala.com/scala-cheatsheet/)
5. [scalaTest的初步使用](https://blog.csdn.net/debang2014010/article/details/102327031?spm=1001.2101.3001.6650.8&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ERate-8-102327031-blog-83315498.pc_relevant_aa_2&utm_relevant_index=9)
6. [chiseltest的介绍和实例 by 赵兄-RISCV in CSDN](https://blog.csdn.net/weixin_44134090/article/details/126837447)
