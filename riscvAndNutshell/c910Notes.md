> 学习平头哥玄铁C910架构的笔记

# 序篇

# 指令高速缓存

> 指令高速缓存的工作原理是当CPU需要取指令时，会首先在第一级缓存中寻找，通过比较标签（Tag）如果命中则能第一时间返回指令，否则就需要去下一级缓存中进行寻找，并把整个缓存行读入到缓存中，那么当访问该缓存行的指令时，就可以以最快的速度返回指令

1. 玄铁C910的指令高速缓存采用**VIPT**结构，即使用虚拟地址做index，物理地址做tag：这种结构可以在利用虚拟地址索引访问缓存的同时使用TLB/MMU将虚拟地址翻译成物理地址，然后再将物理地址与访问缓存得到的tag作比较，判断是否命中。而如果使用**PIPT**结构，当访问缓存的索引超过页内偏移的大小（即地址的低12位）时，则需要先访问TLB/MMU得到物理地址后再索引缓存，这样访问的延迟较大；而如果想要访问缓存的索引不超过页内偏移的大小，则缓存的大小最大只能为4KB×组相联数*，*这样将大大限制了缓存的容量。因此相比之下，对于容量大于4KB×组相联数的缓存，使用VIPT结构更加有优势，因为VIPT结构可以使访问缓存和虚实地址翻译同时进行，相对速度更快。但是对于采用VIPT结构的缓存，如果访问缓存的索引超过页内偏移的大小（即地址的低12位）就可能会产生alias问题，即多个不同的虚拟地址映射到同一物理地址中，且位于不同的缓存行中。但是由于指令高速缓存是只读的，因此不会引发alias问题，只有当VIPT用在数据高速缓存时才会造成alias问题。
2. 





本章参考：

1. 更多关于高速缓存的基础知识可以参考**《计算机体系结构量化方法》**的第二章和附录B部分
2. 



# 分支预测(BP)

![img](../../../../Pictures/TyporaFiles/v2-966490a76a922705f1f47125e76b75ac_1440w.webp)









本章参考：

[1] S. T. Pan, K. So, and J. T. Rahmeh. Improving the accuracy of dynamic branch prediction using branch correlation. In Proceedings of ASPLOS V, pages 76–84, Boston, MA, October 1992.

[2] McFarling, S. “Combining Branch Predictors,” WRL Technical Note TN-36, Jun. 1993.

[3] C.-C. Lee, I.-C.K. Chen and T.N. Mudge, "The Bi-Mode Branch Predictor", *Proc. MICRO-30*, pp. 4-13, 1997-Dec.

[4] Patterson, David A & Hennessy, John L. (2017). *Computer Architecture: A Quantitative Approach (The Morgan Kaufmann Series in Computer Architecture and Design).*(6th ed.).

[5] 玄铁C910用户手册

[6] [https://github.com/T-head-Semi/openc910](https://link.zhihu.com/?target=https%3A//github.com/T-head-Semi/openc910)

[7] Chen C, Xiang X, Liu C, et al. Xuantie-910: A commercial multi-core 12-stage pipeline out-of-order 64-bit high performance risc-v processor with vector extension: Industrial product[C]//2020 ACM/IEEE 47th Annual International Symposium on Computer Architecture (ISCA). IEEE, 2020: 52-64.





# 加载存储单元(LSU)

<img src="../../../../Pictures/TyporaFiles/v2-d6a471467b386096d3282a580ce7d355_1440w.webp" alt="img" style="zoom: 67%;" />

玄铁C910的12级流水线如上图所示

<img src="../../../../Pictures/TyporaFiles/v2-ca3ba3ff743c889d355d19872caaa57e_1440w.webp" alt="img" style="zoom: 67%;" />

其中LSU模块的4级流水线如上图所示，分为`AG`(`Address generation`)、`DC`(`Data cache`)、`DA`(`Data align`)、`WB`(`Write back`)四个阶段。

将存储指令分成上述两个微操作的好处在于可以减少因为**数据依赖造成的指令延迟发射**的周期，并减少因为**访存地址的RAW依赖造成的流水线刷新**，因为如果存储指令提前完成地址计算并在`SQ`中建立了项，便可以及时发现接下来加载指令的和存储指令的数据依赖，及时抛弃加载指令，避免刷新流水线带来的性能开销[(关于RAW造成的流水线刷新详细见加载指令流水线部分)](https://zhuanlan.zhihu.com/p/471575670)

因为存储指令允许不同位宽的存储操作，所以会根据访问宽度是字节、半字、全字、双字等以及访问位置，选择对应缓存行的字节选择信号，表明会修改对应缓存行的对应字节。

# 申明

参考的资料如下：

1. [玄铁C910微架构学习 by IA&C Lab@Fudan](https://zhuanlan.zhihu.com/p/456409077)
2. [平头哥在GitHub的开源仓库](https://github.com/T-head-Semi/openc910)
3. Patterson, David A & Hennessy, John L. (2017). *Computer Organization and Design: The Hardware/Software Interface, RISC-V Edition.*(5th ed.)
4. Patterson, David A & Hennessy, John L. (2017). *Computer Architecture: A Quantitative Approach (The Morgan Kaufmann Series in Computer Architecture and Design).*(6th ed.).
5. [RISCV-BOOM’s documentation](https://link.zhihu.com/?target=https%3A//docs.boom-core.org/en/latest/index.html)