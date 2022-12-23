# 付杰-周报-20221221

# 当前工作内容

- [x]  果壳&香山的所有工具链、开发流程；目前已经掌握的流程、后续需要继续研究的流程。有时间可以看看Makefile具体是怎么编译的, [GCC工具链也是编译的](https://xiangshan-doc.readthedocs.io/zh_CN/latest/compiler/gnu_toolchain/)。
- [x]  后端版图的设计、功耗面积的测试、时钟树等；如何导入FPGA进行测试
- [x]  MCU配套的软件驱动、寄存器的配置信息（具体看PDF）



# 香山敏捷开发框架

## **香山核RTL仿真流程**

![work flow.drawio](https://s2.loli.net/2022/12/22/CQk4fiYGcqxZVWr.png)

1. Chisel 生成 Verilog
2. Verilator/VCS 将生成的Verilog转换为C++源文件→使用riscv64-gnu-toolchain编译仿真器生成的C++源码得到可执行程序(emu)。**emu就是模拟的硬件**
3. 使用AM生成workload
4. 在emu上运行workload



## NEMU(NJU Emulator)

> NEMU 作为硬件模拟器, 被用来与处理器核作对比仿真验证
> 

```python
											
  											 +---------------------+  +---------------------+
                         |     Super Mario     |  |    "Hello World"    |
                         +---------------------+  +---------------------+
                         |    Simulated NES    |  |      Simulated      |
                         |       hardware      |  |       hardware      |
+---------------------+  +---------------------+  +---------------------+
|    "Hello World"    |  |     NES Emulator    |  |        NEMU         |
+---------------------+  +---------------------+  +---------------------+
|      GNU/Linux      |  |      GNU/Linux      |  |      GNU/Linux      |
+---------------------+  +---------------------+  +---------------------+
|    Real hardware    |  |    Real hardware    |  |    Real hardware    |
+---------------------+  +---------------------+  +---------------------+
          (a)                      (b)                     (c)
```

- (a)展示了"在GNU/Linux中运行Hello World"的情况. GNU/Linux操作系统直接运行在真实的计算机硬件上, 对计算机底层硬件进行了抽象, 同时向上层的用户程序提供接口和服务. Hello World程序输出信息的时候, 需要用到操作系统提供的接口, 因此Hello World程序并不是直接运行在真实的计算机硬件上, 而是运行在操作系统(在这里是GNU/Linux)上.
- (b)展示了"在GNU/Linux中通过红白机模拟器玩超级玛丽"的情况. 在GNU/Linux看来, 运行在其上的红白机模拟器NES Emulator和上面提到的Hello World程序一样, 都只不过是一个用户程序而已. 神奇的是, 红白机模拟器的功能是负责模拟出一套完整的红白机硬件, 让超级玛丽可以在其上运行. 事实上, 对于超级玛丽来说, 它并不能区分自己是运行在真实的红白机硬件之上, 还是运行在模拟出来的红白机硬件之上, 这正是"模拟"的障眼法.
- (c)展示了"在GNU/Linux中通过NEMU执行Hello World"的情况. 在GNU/Linux看来, 运行在其上的NEMU和上面提到的Hello World程序一样, 都只不过是一个用户程序而已. 但NEMU的功能是负责模拟出一套计算机硬件, 让程序可以在其上运行. 

## AM(Abstract Machine)：把程序和架构解耦

> [AM (Abstract Machine)](https://nju-projectn.github.io/ics-pa-gitbook/ics2019/2.3.html) 是一个向程序提供运行时环境的包装库, 它提供了一个面向金属的运行时环境, 把程序与体系结构进行了解耦. 我们只要在 AM 的框架下编写好程序, 就能方便地运行在 NEMU 和 Nutshel 之上. AM 在一生一芯项目中被用来包装一系列测试程序从而验证核心的正确性.

应用程序的运行都需要[运行时环境](http://en.wikipedia.org/wiki/Runtime_system)的支持, 包括加载, 销毁程序, 以及提供程序运行时的各种动态链接库(你经常使用的库函数就是运行时环境提供的)等.
**最简单的运行时环境**：只要把程序放在正确的内存位置, 然后让PC指向第一条指令, 计算机就会自动执行这个程序, 永不停止。此外，运行时环境需要向程序提供一种结束运行的方法，如neum中的`nemu_trap`指令。

### 抽象API

假如我们需要为两个硬件架构A、B编写测试程序hello World。在需要停止Hello World的时候，由于A、B架构的不同，需要调用的trap指令也是不同的，因此实际我们需要编写两个版本的Hello World程序。

为了避免这种情况，我们可以定义一个程序结束的API，如`void _halt()`, **它对不同架构上程序的不同结束方式进行了抽象**: 程序只要调用`_halt()`就可以结束运行, 而不需要关心自己运行在哪一个架构上. 然后, 不同的架构分别实现自己的`_halt()`，就可以把程序和架构解耦了。

将程序运行时的需求收集起来，将它们抽象成统一的API提供给程序, 这样我们就得到了一个可以支撑各种程序运行在各种架构上的库了!具体地, 每个架构都按照它们的特性实现这组API; 应用程序只需要直接调用这组API即可, 无需关心自己将来运行在哪个架构上. 由于这组统一抽象的API代表了程序运行对计算机的需求, 所以我们把这组API称为**抽象计算机(AM)**.

南大的AM项目就是在这样的思想下诞生的，它根据程序运行需求将库分为以下模块：

```python
AM = TRM + IOE + CTE + VME + MPE
```

- TRM(Turing Machine) - 图灵机, 最简单的运行时环境, 为程序提供基本的计算能力
- IOE(I/O Extension) - 输入输出扩展, 为程序提供输出输入的能力
- CTE(Context Extension) - 上下文扩展, 为程序提供上下文管理的能力
- VME(Virtual Memory Extension) - 虚存扩展, 为程序提供虚存管理的能力
- MPE(Multi-Processor Extension) - 多处理器扩展, 为程序提供多处理器通信的能力

<aside>
💡 有了AM之后，我们可以编写测试程序时不用关心底层的硬件架构，此外我们还可以方便的将Linux Kernel移植到硬件架构上。


</aside>

### 自定义workload

> 自定义workload可以是简单的C程序、benchmark甚至是Linux镜像
> 
1. 在AM项目下指定目录编写C程序，如：
   
    ```c
    // $AM_HOME/apps/hello/src/hello.c
    #include <klib.h>
    
    int main() {
      printf("Hello Sylincom!\n");
      printf("Hello Sylincom!\n");
      printf("Hello Sylincom!\n");
      printf("Hello Sylincom!\n");
      return 0;
    }
    ```
    
2. 编写makefile指导workload编译，如：
   
    ```makefile
    # $AM_HOME/apps/hello/Makefile
    NAME = hello
    SRCS = $(shell find -L ./src/ -name "*.c")
    include $(AM_HOME)/Makefile.app
    ```
    
3. 编译得到workload
   
    ```bash
    make ARCH=riscv64-xs # 编译基于riscv-64 ISA的香山硬件下的workload
    
    make ARCH=riscv32-nutshell # 编译基于riscv-32 ISA的果壳硬件下的workload
    ```
    
    编译完成之后，会在build目录下的到可执行的二进制文件`xxx.bin`
    
4. 运行workload：可以在nemu、xs-emu或者是fpga上运行workload。
   在香山模拟器上云新hello world的workload：
   
    ```bash
    $NOOP_HOME/build/emu -i $AM_HOME/apps/hello/build/hello-riscv64-xs.bin
    ```
   
    输入内容如下：
   
    ```bash
    Emu compiled at Nov 23 2022, 14:54:28
    Using simulated 32768B flash
    [warning]no valid flash bin path, use preset flash instead
    The image is ../nexus-am/apps/hello/build/hello-riscv64-xs.bin
    Using simulated 8192MB RAM
    --diff is not given, try to use $(NEMU_HOME)/build/riscv64-nemu-interpreter-so by default
    NemuProxy using /home/fujie/Developer/git_repos/xs-env/NEMU/build/riscv64-nemu-interpreter-so
    The first instruction of core 0 has commited. Difftest enabled. 
    [NEMU] Can not find flash image: (null)
    [NEMU] Use built-in image instead
    [src/device/io/mmio.c:38,add_mmio_map] Add mmio map 'flash' at [0x0000000010000000, 0x00000000100fffff]
    Hello, Sylincom !
    Hello, Sylincom !
    Hello, Sylincom !
    Hello, Sylincom !
    Hello, Sylincom !
    Hello, Sylincom !
    Core 0: HIT GOOD TRAP at pc = 0x80000174
    total guest instructions = 3,736
    instrCnt = 3,736, cycleCnt = 13,830, IPC = 0.270137
    ```
   
    在香山模拟器上运行预设的Linux Kernel：
   
    ```bash
    $NOOP_HOME/build/emu -i ready-to-run/linux.bin
    ```
   
    输出内容如下：
   
    ```bash
    Emu compiled at Nov 23 2022, 14:54:28
    Using simulated 32768B flash
    [warning]no valid flash bin path, use preset flash instead
    The image is ready-to-run/linux.bin
    Using simulated 8192MB RAM
    --diff is not given, try to use $(NEMU_HOME)/build/riscv64-nemu-interpreter-so by default
    NemuProxy using /home/fujie/Developer/git_repos/xs-env/NEMU/build/riscv64-nemu-interpreter-so
    The first instruction of core 0 has commited. Difftest enabled. 
    [NEMU] Can not find flash image: (null)
    [NEMU] Use built-in image instead
    [src/device/io/mmio.c:38,add_mmio_map] Add mmio map 'flash' at [0x0000000010000000, 0x00000000100fffff]
    bbl loader
    freq-mhz = 500
    CLINT: set frequency to 500 MHz
                  vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
                      vvvvvvvvvvvvvvvvvvvvvvvvvvvv
    rrrrrrrrrrrrr       vvvvvvvvvvvvvvvvvvvvvvvvvv
    rrrrrrrrrrrrrrrr      vvvvvvvvvvvvvvvvvvvvvvvv
    rrrrrrrrrrrrrrrrrr    vvvvvvvvvvvvvvvvvvvvvvvv
    rrrrrrrrrrrrrrrrrr    vvvvvvvvvvvvvvvvvvvvvvvv
    rrrrrrrrrrrrrrrrrr    vvvvvvvvvvvvvvvvvvvvvvvv
    rrrrrrrrrrrrrrrr      vvvvvvvvvvvvvvvvvvvvvv  
    rrrrrrrrrrrrr       vvvvvvvvvvvvvvvvvvvvvv    
    rr                vvvvvvvvvvvvvvvvvvvvvv      
    rr            vvvvvvvvvvvvvvvvvvvvvvvv      rr
    rrrr      vvvvvvvvvvvvvvvvvvvvvvvvvv      rrrr
    rrrrrr      vvvvvvvvvvvvvvvvvvvvvv      rrrrrr
    rrrrrrrr      vvvvvvvvvvvvvvvvvv      rrrrrrrr
    rrrrrrrrrr      vvvvvvvvvvvvvv      rrrrrrrrrr
    rrrrrrrrrrrr      vvvvvvvvvv      rrrrrrrrrrrr
    rrrrrrrrrrrrrr      vvvvvv      rrrrrrrrrrrrrr
    rrrrrrrrrrrrrrrr      vv      rrrrrrrrrrrrrrrr
    rrrrrrrrrrrrrrrrrr          rrrrrrrrrrrrrrrrrr
    rrrrrrrrrrrrrrrrrrrr      rrrrrrrrrrrrrrrrrrrr
    rrrrrrrrrrrrrrrrrrrrrr  rrrrrrrrrrrrrrrrrrrrrr
    
           INSTRUCTION SETS WANT TO BE FREE
    [    0.000000] OF: fdt: Ignoring memory range 0x80000000 - 0x80200000
    [    0.000000] Linux version 4.18.0-00046-g2ba394515c09-dirty (wkf@xiangshan-05) (gcc version 9.2.0 (GCC)) #113 Thu Feb 4 21:45:54 CST 2021
    [    0.000000] bootconsole [early0] enabled
    [    0.000000] Initial ramdisk at: 0x(____ptrval____) (23552 bytes)
    [    0.000000] Zone ranges:
    [    0.000000]   DMA32    empty
    [    0.000000]   Normal   [mem 0x0000000080200000-0x0000000081ffffff]
    [    0.000000] Movable zone start for each node
    [    0.000000] Early memory node ranges
    [    0.000000]   node   0: [mem 0x0000000080200000-0x0000000081ffffff]
    [    0.000000] Initmem setup node 0 [mem 0x0000000080200000-0x0000000081ffffff]
    [    0.000000] Cannot allocate SWIOTLB buffer
    [    0.000000] elf_hwcap is 0x112d
    [    0.000000] Built 1 zonelists, mobility grouping on.  Total pages: 7575
    [    0.000000] Kernel command line: root=/dev/mmcblk0 rootfstype=ext4 ro rootwait earlycon
    [    0.000000] Dentry cache hash table entries: 4096 (order: 3, 32768 bytes)
    [    0.000000] Inode-cache hash table entries: 2048 (order: 2, 16384 bytes)
    [    0.000000] Sorting __ex_table...
    [    0.000000] Memory: 29140K/30720K available (666K kernel code, 80K rwdata, 102K rodata, 88K init, 98K bss, 1580K reserved, 0K cma-reserved)
    [    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=1, Nodes=1
    [    0.000000] NR_IRQS: 0, nr_irqs: 0, preallocated irqs: 0
    [    0.000000] clocksource: riscv_clocksource: mask: 0xffffffffffffffff max_cycles: 0x1d854df40, max_idle_ns: 3526361616960 ns
    [    0.000000] console [hvc0] enabled
    [    0.000000] console [hvc0] enabled
    [    0.000000] bootconsole [early0] disabled
    [    0.000000] bootconsole [early0] disabled
    [    0.000000] Calibrating delay loop (skipped), value calculated using timer frequency.. 2.00 BogoMIPS (lpj=10000)
    [    0.000000] pid_max: default: 4096 minimum: 301
    [    0.000000] Mount-cache hash table entries: 512 (order: 0, 4096 bytes)
    [    0.000000] Mountpoint-cache hash table entries: 512 (order: 0, 4096 bytes)
    [    0.000000] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 19112604462750000 ns
    [    0.010000] clocksource: Switched to clocksource riscv_clocksource
    [    0.010000] Unpacking initramfs...
    [    0.020000] workingset: timestamp_bits=62 max_order=13 bucket_order=0
    [    0.020000] random: get_random_bytes called from 0xffffffff8001998a with crng_init=0
    [    0.020000] Freeing unused kernel memory: 88K
    [    0.020000] This architecture does not have kernel memory protection.
    Hello, RISC-V World!
    Core 0: HIT GOOD TRAP at pc = 0x100cc
    total guest instructions = 4,141,950
    instrCnt = 4,141,950, cycleCnt = 5,417,791, IPC = 0.764509
    ```
   

## DiffTest(Differential Testing)

核心思想：

- 对于根据同一规范的两种实现, 给定相同的有定义的输入, 它们的行为应当一致。在我们验证硬件功能是否正确的时候，选择模拟器作为标准参考(golden model)，如果对于同样的输入，模拟器的输出和硬件设计的输出不同，则说明硬件设计有错；
- 同时DiffTest可以将二者每条指令的输出都做比较，那么就可以迅速定位到出错的指令，方面debug

![Untitled](https://s2.loli.net/2022/12/23/pg6MQcolOaf94Nm.png)

# 软件驱动程序

![Untitled 1](https://s2.loli.net/2022/12/23/b1tdkmYSKiFfB7u.png)

主要包括三部分：

1. 启动文件：
   
    在启动文件中需要开辟堆栈地址，给出汇编语言转换到 C语言的程序入口。
    
    启动文件是使用 Cortex-M3 内核支持的汇编指令编写的基本程序，当MCU 上电启动时，会首先执行启动文件中的汇编程序，从而建立起C 语言的运行环境；启动程序的主要功能包括：初始化堆栈指针 SP、初始化程序计数器指针 PC、设置堆、 栈的大小、初始化中断向量表和设置C语言库的分支入口“main”（用来调用 main 函数）。
    
2. 配置头文件
   
    在头文件中需要根据设计为不同的外设模块中的寄存器分配地址，从而实现 C语言程序对硬件的控制。
    
3. 主函数设计
   
    在软件端的主函数中对 ADC 控制器、FFT 硬件加速模块、UART 和 SPI数据传输接口以及 GPIO 和 Timer 等一系列外围设备的寄存器进行数据配置。在主函数中可按设计需求配置 MCU 对外输出一系列信号。
    

## 板级验证

![Untitled](https://s2.loli.net/2022/12/22/m8SOjKDNsEA7Ccx.png)

1. 首先将经过 Modelsim 仿真检查无误后的硬件代码通过 Vivado 软件编译并烧录进 FPGA 开发板中搭建出 MCU 的硬件平台
2. 然后通过 Keil 下载器将编写完成的软件驱动程序的.Hex 文件烧录进 FPGA 的 BRAM 存储器中，随后便可启动 MCU 开始工作
3. MCU启动后将按照软件驱动程序的设计控制外设进行工作

# 逻辑综合及后端物理设计

使用 Design Compiler 进行综合，逻辑综合包括以下三部分：

1. 转换：综合工具把使用硬件描述语言描述的行为级电路转换成只包含逻辑功能模块和它们之间连接关系的网表，该网表文件不包含任何工艺信息
2. 映射：将此网表文件映射到指定的工艺库中（如 CMOS 65 nm 或 180 nm 工艺），使其成为一个带有实体电路信息的门级网表
3. 优化：综合工具再根据设计所施加的时序、面积和功耗等约束条件，对该门级网表进行优化。

后端物理设计：在完成逻辑综合后，还需进行芯片版图的物理设计实现，并经过设计规则检查后，才能将 GDSI文件交付给工艺厂商完成芯片制造。论文中作者通过使用 Innovus数字后端工具调用 180 nm 工艺的标准单元库来完成芯片的后端物理设计。
后端设计主要包括：

1. 布图(Floor Plan)、布局(Placement)：主要完成 PAD 布局、电源规划、电压降预估、拥塞预估和标准单元的预布局
2. 时钟树综合(Clock Tree Synthesis, CTS)：时钟的布线
3. 布线(Place & Route)：普通信号布线，将分布在芯片核内的模块、标准单元和输入输出接口单元按逻辑关系进行互联
4. 版图后仿：在完成版图设计后，具体电路模块的位置以及它们之间的连线关系就己经明确，这时可从版图中提取出带实际电路延时信息的.sdf 文件进行版图后仿真，观察经过版图实现后的芯片的功能是否正常。
5. 版图物理验证：电路规则检查 LVS (Layout Vs Schematic） 和设计规则检查 DRC (Design Rule Checking) 是物理验证的两项主要工作。论文中作者采用的 LVS/DRC 工具是 Mentor 公司的 Caibre。

# To Be Done

1. 目前AM支持的riscv ISA的xs和nutshell以及x86, mips的一些其他硬件实现。但是针对我们的基于riscv MCU，如果选择的riscv指令集子集不同，则需要往AM的API进行完善。目前AM只开源了部分的源码。
2. 在编写驱动程序的时候，如果直接通过指针控制硬件寄存器，从而控制MCU，则好像不用通过AM。但是如何将驱动程序编译成可以运行在MCU上的二进制文件，还不知道，论文里面也没有提。
3. 在通过AM编译workload的时候，目前已经掌握了如何将C源代码编译成workload，但是如何将Linux Kernel(如Debian)编译成workload，还没有试过。好在香山文档里给出了教程。
4. 由于目前跑的workload是基于已经验证过的香山的源代码，因此DiffTest是不会报错的，因此我还不知道DiffTest如果捕捉到了错误，该如何快速对Chisel源代码进行错误定位、Debug。
5. 目前只在服务器上，在编译得到的香山模拟器上跑了C workload、预编译的Linux kernel，还没有尝试过在FPGA上跑
6. 如果需要流片的话，我们是否需要在现在考虑将来逻辑综合和后端物理设计的问题
7. 对于MCU微架构的设计，需要综合考虑开源项目、论文、处理器调度进行设计、输出设计文档进行讨论
8. 服务器可能需要联系IT配置相应的访问端口，供连接VPN时访问

PS：在GitHub仓库里新建了一个[`weeklyReport`](https://github.com/timemeansalot/FAST_INTR_CPU/tree/master/weeklyReport)文件夹，以后可以用于记录每周的周报，方便追踪项目的进度，如下图所示：

![Untitled](https://s2.loli.net/2022/12/22/Fv4IXGL3tf6zDTY.png)

# 英文缩写对照表

| 缩写 | 全拼 |
| --- | --- |
| AM | Abstract Machine |
| NEMU | NJU Emulator |
| DiffTest | Differential Testing |
| RISCV-PK | RISC-V Proxy Kernel |
| BBL | Berkeley Boot Loader |
| CTS | Clock Tree Synthesis |
| LVS | Layout Vs Schematic |
| DRC | Design Rule Checking |

# 声明

本文的参考资料如下：

[果壳Github仓库](https://github.com/OSCPU/NutShell)

[果壳快速上手教程](https://oscpu.github.io/NutShell-doc/%E4%BB%8B%E7%BB%8D/NutShell-tutorial.html)

[程序, 运行时环境与AM](https://nju-projectn.github.io/ics-pa-gitbook/ics2019/2.3.html)

[使用 AM 生成自定义 workload](https://xiangshan-doc.readthedocs.io/zh_CN/latest/tools/gen-workload-with-am/)

[Linux Kernel for XiangShan in EMU](https://xiangshan-doc.readthedocs.io/zh_CN/latest/tools/linux-kernel-for-xs/)

[DiffTest 介绍](https://oscpu.github.io/ysyx/events/2021-07-17_Difftest/DiffTest-%E4%B8%80%E7%A7%8D%E9%AB%98%E6%95%88%E7%9A%84%E5%A4%84%E7%90%86%E5%99%A8%E9%AA%8C%E8%AF%81%E6%96%B9%E6%B3%95.pdf)

[可执行文件（ELF）格式的理解_五山小新新的博客-CSDN博客](https://blog.csdn.net/Al_xin/article/details/38613367)