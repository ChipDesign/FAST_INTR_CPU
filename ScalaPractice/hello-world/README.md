# Chisel Hello World

# 项目介绍
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

# 声明
本项目参考:[schoeberl/chisel-examples](https://github.com/schoeberl/chisel-examples)