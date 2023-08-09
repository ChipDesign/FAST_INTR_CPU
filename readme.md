![5StagePipeline-with-Hazard-Control](./pictures/5-Stage-Pipeline-with-Hazard-Control.svg)

> 一款专门用于5G基带芯片加速器调度的RISC-V MCU，满足快速响应的需求并且能够自主可控

# 项目进度

- [x] 对Scala和Chisel进行学习，使用Chisel完成一个简单的CPU，[项目地址](/ScalaAndChisel)
- [x] 参考开源项目，如果壳、蜂鸟
- [x] 设计Fast Interrupt CPU，[代码仓库](./src/rtl/)
- [ ] 实现Fast Interrupt CPU并且验证, doing
- [ ] 接入到基带芯片中完成测试

# MCU特点

1. 支持RV32-IMC指令集
2. 支持Difftest测试
3. 支持中断嵌套、中断尾链
4. 采用ITCM、DTCM，可配置I-Cache

# MCU验证
1. [验证目录](src/verification/)
2. [验证说明](src/verification/README.md)
