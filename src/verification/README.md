> Verification 使用说明

# 目录结构介绍

```bash
    ├── build
    ├── csrc
    ├── dump.vcd
    ├── Makefile
    ├── README.md
    ├── result.log
    ├── riscvtest
    ├── so
    └── vsrc
```

本目录格式如上所示，各个部分介绍如下：

1. build：执行make命令后会编译可执行文件跟中间文件，这些文件都放在build目录下
2. csrc：difftest相关的代码
3. vsrc：MCU的所有verilog文件
4. riscvtest：汇编测试文件，在该目录下可以编译所有的汇编文件得到可执行的bin文件
5. so：golden reference存放目录，该目录下有32位的spike.so文件
6. result.log：对所有的riscvtest测试集做回归方针，每个测试集是否通过会记录在该文件下
7. dump.vcd：波形图

# 编译汇编文件

1. 进入到riscvtest目录下
2. 编译一个文件：在其Makefile中用EXEC指定想要编译的汇编文件名
   - `make`：编译该汇编文件得到elf文件，并且得到bin文件
   - `make code`：查看反汇编文件的内容
3. 编译所有文件: `make getAll`

# 仿真测试

1. 进入到verification目录下
2. 测试一个测试集：在Makefile中用IMG指定想要测试的测试集，然后`make run`即可运行difftest，并且进入到debug模式
   - `si`可以进行单步调试，逐行执行指令
   - `c`可以执行所有指令，直到所有指令执行完毕、或者出现错误
3. 回归测试（测试所有测试集）：
   ```bash
   make test_all 
   ```
   所有测试集通过的情况会记录在`result.log`文件中
> PS: <u>测试一个测试集</u>跟<u>测试所有测试集</u>，需要编译的difftest有些许不同，因此在切换测试模式之前，需要先`make clean`
