> 学习果壳项目时的相关笔记



![图1：果壳整体的微结构设计](https://s2.loli.net/2022/11/07/HRToyx8v9XMhSi5.png)

<!--more-->

[TOC]

# 前端(Front End)设计

前端主要完成以下的功能：

1. 在“**分支预测**”中计算下一条PC的值，如果分支预测判断不跳转，则PC+8
2. 根据PC从**指令缓存(I-Cache)**中读取一个Cache Line(64 bits)的数据，可以转化成两条普通的32 bits指令或者4条压缩的16 bits指令
3. 得到的指令会被压入到**指令对齐缓冲(IBF)**，为了处理引入 RISC-V 压缩指令 RVC 后的指令对齐问题，前端设置了单独的指令对齐缓冲。它执行以下的功能：
   1. 判断指令的长度并将不同的指令分离
   2. 如果有指令横跨两次 ICache 结果, 指令对齐缓冲会负责将其拼接成一条指令
   
   指令对齐缓冲得到的指令会交给指令译码单元(IDU)进行译码

## 分支预测(Branch Prediction)

### 概述

1. 使用 **Next-Line** 分支预测器 (NLP)
2. 预测不跳转的时候，PC+8，因为一次读取一个Cache Line的数据是64 bits，按照字节寻址
3. 默认使用**两位饱和计数(Bimodal Counter)**进行预测
4. ~~分支预测器在后端跳转指令写回时更新~~
5. ~~提供 512 项的跳转目标缓存 (BTB) 和 16 项的返回地址栈 (RAS)~~
6. 针对 64 bits 的取指宽度, NLP 会*返回 4 bits 的跳转预测向量*，跳转预测向量标识在哪条指令处可能发生跳转。指令对齐缓冲将使用跳转预测向量来选择有效的指令

分支预测模块的主要信号输入有：

1. clock, reset
2. 取指令模块(IFU)：当前周期的PC值
3. 控制模块(ctrl)：当前周期是否暂停取指
4. 后端(Back End)：提供对分支预测器的最终更新

分支预测的输出信号给IFU，用于判断：

1. 是否跳转
2. 预测的下一周期的取指地址

### NLP(Next Line Predictor)

> 在转移指令的<u>取指阶段预测出指令跳转的方向和目标地址</u>, 并从预测的目标地址处继续取指令执行, 在一定程度上减轻指令流水线中转移指令引起的阻塞

<img src="https://s2.loli.net/2022/11/07/HSBR3mr61fo27td.png" alt="图2：NLP的原理图" style="zoom:50%;" />

1. NLP的结构如上图所示，其中各部分的作用如下：

   - BTB(branch target buffer)：用来记录指令跳转的历史。如果某条PC对应的指令是跳转指令，在该PC会被记录到BTB中，对应的指令的跳转信息也会被记录到BTB中。当下一次该PC出现的时候，则该PC可以在BTB中找到对应的跳转信息。
   - RAS(return address stack)：当BTB中分支跳转指令的类型是**ret**指令时，则选择RAS栈顶的地址作为跳转目的PC
   - PHT(pattern history table)：当BTB中分支跳转指令的类型是**条件跳转指令**时，需要访问模式历史表 (PHT) 来判断是否跳转。PHT中存放条件跳转指令是否跳转的记录。

2. BTB的结构

   <img src="https://s2.loli.net/2022/11/07/LWypxSu26etGsT9.png" alt="图3：BTB的表结构" style="zoom: 50%;" />

   - PC跟tag进行匹配，如果匹配成功了，则可以根据BTB对应的表项来执行相应的跳转操作
   - 如果匹配的类型type是*直接跳转指令*或者*间接跳转指令*，则跳转的目标是target字段的值；如果匹配的类型是*ret指令*，则跳转的目标是RAS的栈顶的值
   - 更新操作：初始化时BTB是空的，跳转指令第一次被取出时都会按不跳转来处理；后端的执行单元发现指令跳转目标错误或者方向错误时会刷新流水线, 同时更新BTB相应的表项。当PC对应的表项无效或者是被占用的时候，会更新对应的BTB表项
   - BTB 由于面积较大而通过快速 SRAM 来实现

   TBD: 补充PC判断逻辑的流程图

3. RAS的结构：RAS主要是针对于子程序调用时的返回。由于子程序的位置是固定的，所以多个程序调用某一个子程序是，可以直接在指令中通过offset来指定，但是子程序为了正确的返回，则需要将父程序的地址存在RAS中

   <img src="../../../../Pictures/TyporaFiles/image-20221107152817922.png" alt="image-20221107152817922" style="zoom: 50%;" />

   - 更新操作：后端每执行一条函数调用指令 (call) 或函数返回指令 (ret), 也会将相关信息传给分支预测器. 如果该指令是 call 指令, 则根据指令的宽度 (4 字节或 2 字节) 计算返回地址并写入 RAS 栈顶; 如果该指令是 ret 指令, 则将RAS的栈顶弹出
   - 同步写异步读的寄存器来实现

4. PHT的结构如下图所示：采用PC中的某几位去PHT匹配某一项，如果匹配成功则可以查询得到**该PC之前执行的条件分支指令是否跳转**

   <img src="https://s2.loli.net/2022/11/07/Tebfj9RtZhaHJBL.png" alt="image-20221107152043819" style="zoom:50%;" />

   PHT中的每一项，都是两位饱和计数(Bimodal Counter)，其状态转移图如下所示

   <img src="https://s2.loli.net/2022/11/07/9Xb4zZMALgB7to8.png" alt="图4：两位饱和计数器" style="zoom:50%;" />

   - 分支预测：当前PC的部分位定位PHT表项，如果该表项BIM大于等于2,则预测为跳转，否则预测为不跳转
   - 更新操作：后端执行条件分支指令, 都会将正确跳转方向和分支目标等信息返回给分支预测单元：如果是分支指令，并且分支是taken, 则饱和计算器 +1、如果是分支指令，但是分支没有taken, 则饱和计算器 -1
   - 同步写异步读的寄存器来实现



# 多核处理器

## 多核处理器的挑战

共享内存式的多核处理器需要解决两个主要问题：

（1） Cache一致性问题：由于同一份数据在整个系统中存在多份，分布在不同的处理器的cache中，如果一个处理器修改了自己的那份数据，则其它处理器的数据就不是最新有效的了。如果保证核间的cache一致性是多核处理器设计的一个重要方面。

（2） 核间互联：多核之间通过**共享内存通信**是通过往全局内存中写入数据和读取数据来完成的，当多个处理器同时访问（写入或者读取）共享内存时会导致总线上的竞争，从而导致系统性能恶化，所以优化总线结构设计也是提升多核性能的一个关键技术。

当然其它方面的问题，比如任务在**多个核之间的调度管理**也是一个专题。



# 声明

本文档的参考资料如下：

1. [NutShell 文档](https://oscpu.github.io/NutShell-doc/%E5%8A%9F%E8%83%BD%E9%83%A8%E4%BB%B6/bpu.html)：果壳项目，简要的设计文档
2. [RISC-V CPU侧信道攻击原理与实践（3）-- 微架构](https://zhuanlan.zhihu.com/p/393449780)：从微架构的角度讲解了Pipeline, Branch Prediction, Reorder Buffer
3. [自己动手写RISC-V CPU -（4）增加分支预测功能](https://zhuanlan.zhihu.com/p/457620455): 具体讲解了NLP分支预测器
4. [谈谈多核处理器](https://zhuanlan.zhihu.com/p/427398869)：介绍了多核处理器的优点、分类和需要解决的问题
5. [Chipyard开发环境配置](https://zhuanlan.zhihu.com/p/393108711)：配置仿真验证环境
6. [RISCV-BOOM](https://docs.boom-core.org/en/latest/index.html)：伯克利乱序处理器的文档