> 记录Chisel的一些重要数据类型和函数

1. Chisel包含多个数据类型，其中最重要的是: UInt, SInt, Bool。关于她们之间相互转化有以下函数：`asUInt, asSInt, asBool, asBools, asClock`

2. 向量Vec, 关于向量有以下方法

   - Vec(amount, type)，如：`val myVec = Wire(Vec(3, UInt(32.W)))`: 

   - **`VecInit[T]`，通过接收一个`Seq[T]`（这里的Seq包括`seq、array、list、tuple、queue`等集合）**，如：

     ```Scala
       val Vec1 = VecInit(1.U, 2.U, 3.U, 4.U)//重复参数
       val Vec2 = VecInit(Seq.fill(8)(0.U(8.W)))//序列
     ```

   - UInt->Vec: `asBools`, Vec->UInt: `asUInt`

   - **子字赋值**：Chisel只对变量的某几位赋值，不可以直接通过下标操作来实现，必须先将对应的元素转化为Vec类型，然后对该Vec进行某几位的赋值，最后调用该Vec的`asUInt`方法

     ```Scala
     class TestModule extends Module {
        val io = IO(new Bundle {
            val in = Input(UInt(10.W))
            val bit = Input(Bool())
            val out = Output(UInt(10.W))
        })
        val bools = VecInit(io.in.asBools)
        bools(0) := io.bit
        io.out := bools.asUInt
     }
     ```

3. Bundle

   类似C里的struct

   - Bundle->UInt: asUInt

     ```scala
     class MyBundle extends Bundle {
        val foo = UInt(4.W)  // 高位
        val bar = UInt(4.W)  // 低位
     }
     
     val bundle = Wire(new MyBundle)
     bundle.foo := 0xc.U
     bundle.bar := 0x3.U
     val uint = bundle.asUInt  // 12*16 + 3 = 195
     ```

   - UInt->Bundle: asTypeOf

     ```scala
     class MyBundle extends Bundle {
        val foo = UInt(4.W)  // 高位
        val bar = UInt(4.W)  // 低位
     }
     
     val uint = 0xb4.U
     val bundle = uint.asTypeOf(new MyBundle)  // foo = 11, bar = 4
     ```

4. 例化模块

   定义好模块之后，可以利用该模块来生成对应的实例，例化的方法如下：

   - 例化一个模块：`val m0 = Module(new Mux2)`，不能只用new来创建一个对象，**还需要再把实例的对象传递给单例对象Module的apply方法**。
   - 例化多个模块，使用VecInit，`val m = VecInit(Seq.fill(3)(Module(new Mux2)))`

5. 简化代码的方法：

   - 在伴生对象中定义工厂方法
   - 获取位宽度：`log2Ceil、log2Floor、log2Up和log2Down、unsignedBitLength`
   - 翻转：`Reverse("b1101".U)  *// 等于"b1011".U* `
   - 位拼接：`Cat("b101".U, "b11".U)  *// 等于"b10111".U* `
   - 1计数器：`PopCount("b1011".U)  *// 等于3.U* `
   - 独热码转换器：`OHToUInt("b1000".U)  *// 等于3.U* , UIntToOH(3.U)  *// 等于"b1000".U* `

6. [FSM](https://blog.csdn.net/qq_39507748/article/details/118243315)：使用Chisel的枚举Enum来写有限状态机

7. [FIR](https://blog.csdn.net/qq_39507748/article/details/118293466)：系数固定的时候的FIR滤波器比较好写，当系数个数不固定的时候的FIR滤波器可以用scala的集合或者chisel的Vec来实现