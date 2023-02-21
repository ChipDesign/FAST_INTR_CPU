package Universal_tools
import  chisel3._



abstract class FIFO(Size:Int,SizeWidth:Int) extends MultiIOModule{

  val Elem:Bundle
  val FifoQueue=Reg(Vec(Size,Elem))
  val ElemNum=RegInit(UInt(SizeWidth.W),0.U)
  val Empty=Wire(UInt(1.W))
  val Full=Wire(UInt(1.W))


  val io=IO(new Bundle{
    val empty=Output(UInt(1.W))
    val full=Output(UInt(1.W))
    val elem_num=Output(UInt())
    val head_data=Output(Elem)
    val en_queue=Input(UInt(1.W))
    val de_queue=Input(UInt(1.W))
    val en_queue_data=Input(Elem)
  })

  def EnDeQueue:UInt={
    when(io.de_queue === 1.U) {
      for (i <- 1 until Size)
        FifoQueue(i - 1) := FifoQueue(i)
      when(io.en_queue.asBool) {
        ElemNum := ElemNum
        FifoQueue(ElemNum) := io.en_queue_data
      }.otherwise {
        ElemNum := ElemNum - 1.U
      }
    }.elsewhen(io.en_queue === 1.U) {
      ElemNum := ElemNum + 1.U
      FifoQueue(ElemNum) := io.en_queue_data
    }
    return 0.U
  }

  when((io.de_queue|io.en_queue).asBool)
  {
    EnDeQueue
  }

  Empty:= (ElemNum===0.U)
  Full:= (ElemNum===Size.asUInt)
  io.head_data:=FifoQueue(0)
  io.empty:=Empty
  io.full:=Full
  io.elem_num:=ElemNum

}
