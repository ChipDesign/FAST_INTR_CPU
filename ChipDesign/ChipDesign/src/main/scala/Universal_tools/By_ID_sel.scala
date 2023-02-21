package Universal_tools
import chisel3._
import chisel3.util._

class By_ID_sel (Size:Int,IDLen: Int,IDInit:Seq[UInt]) extends Module
{
  val IDs=Reg(Vec(Size,UInt(IDLen.W)))
  withReset(reset)
  {
    for(i<-0 until Size)
      {
        IDs(i):=IDInit(i)
      }
  }
  val io=IO(new Bundle{
    val sel_sig= Output(Vec(Size,UInt(1.W)))
    val ID_in=Input(UInt(IDLen.W))
  })
  for(i<-0 until Size)
    {
      io.sel_sig(i):=(io.ID_in===IDs(i))
    }
}
