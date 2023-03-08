package Int_top.PLIC_CPU_interface
import chisel3._
import chisel3.util.Fill
class Int_nesting(IDLen:Int,PriWidth:Int) extends Module {
  //statement
  val Status=new Array[Int_status](4)
  for(i<-0 until 4)
    {
      Status(i)=Module(new Int_status(IDLen, PriWidth))
    }
  val StatusPtr=RegInit(UInt(2.W),0.U)
  val CurrentID=Wire(UInt(IDLen.W))
  val CurrentPri=Wire(UInt(PriWidth.W))
  val NestedID=Wire(UInt(IDLen.W))
  val NestedPri=Wire(UInt(PriWidth.W))


  val io=IO(new Bundle{
    val empty=Output(UInt(1.W))
    val current_pri=Output(UInt(PriWidth.W))
    val nest_disable=Input(UInt(1.W))
    val nested_pri=Output(UInt(PriWidth.W))
    val coming_pri=Input(UInt(PriWidth.W))
    val is_nesting=Output(UInt(1.W))
    val current_ID=Output(UInt(IDLen.W))
    val coming_ID=Input(UInt(IDLen.W))
    val nested_ID=Output(UInt(IDLen.W))
    val do_nest=Output(UInt(1.W))
  })


  //io connection
  io.empty:=(StatusPtr===0.U)&(Status(0).io.status==0.U)
  io.current_ID:=CurrentID
  io.current_pri:=CurrentPri

  //reg&submodule connection

  //wire connection
  CurrentID := (Fill(IDLen, StatusPtr === 0.U) & (Status(0).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 1.U) & (Status(1).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 2.U) & (Status(2).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 3.U) & (Status(3).io.ID_out))
  CurrentPri := (Fill(PriWidth, StatusPtr === 0.U) & (Status(0).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 1.U) & (Status(1).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 2.U) & (Status(2).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 3.U) & (Status(3).io.pri_out))

}
// not finished

class Int_status(IDLen:Int,PriWidth:Int) extends Module{
  //statement
  val Priority=RegInit(UInt(PriWidth.W),0.U)
  val Int_ID=RegInit(UInt(IDLen.W),0.U)
  val Status=RegInit(UInt(2.W),0.U)

  val io=IO(new Bundle{
    val pri_in=Input(UInt(PriWidth.W))
    val pri_out=Output(UInt(PriWidth.W))
    val ID_in=Input(UInt(IDLen.W))
    val ID_out=Output(UInt(IDLen.W))
    val act=Input(UInt(1.W))
    val deact=Input(UInt(1.W))
    val nest=Input(UInt(1.W))
    val denest=Input(UInt(1.W))
    val status=Output(UInt(1.W))//0 for deactivated, 1 for activated, 3 for nested, 2 is illegal
  })
  //io connection
  io.pri_out:=Priority
  io.ID_out:=Int_ID
  io.status:=Status
  //reg update
  when(Status===0.U)
  {
    when(io.act.asBool)
    {
      Priority:=io.pri_in
      Int_ID:=io.ID_in
      Status:=1.U
    }
  }.elsewhen(Status===1.U)
  {
    when(io.deact.asBool)
    {
      Priority:=0.U
      Int_ID:=0.U
      Status:=0.U
    }.elsewhen(io.nest===1.U)
    {
      Status:=3.U
    }
  }.otherwise
  {
    when(io.denest===1.U)
    {
      Status:=1.U
    }
  }
}
