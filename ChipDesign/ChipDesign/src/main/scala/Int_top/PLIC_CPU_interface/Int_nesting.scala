package Int_top.PLIC_CPU_interface
import chisel3._
import chisel3.util.{Cat, Fill}
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
    }.elsewhen(io.act.asBool) {
      Priority := io.pri_in
      Int_ID := io.ID_in
    }
  }.otherwise
  {
    when(io.denest===1.U)
    {
      Status:=1.U
    }
  }
}


class Int_nesting(IDLen:Int,PriWidth:Int,NestPriPosi:Int) extends Module {
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
  val EnNest=WireDefault(UInt(1.W),0.U)
  val DeNest=WireDefault(UInt(1.W),0.U)
  val StatusAct=WireDefault(UInt(4.W),0.U)
  val StatusDeact=WireDefault(UInt(4.W),0.U)
  val StatusNest=WireDefault(UInt(4.W),0.U)
  val StatusDenest=WireDefault(UInt(4.W),0.U)
  val StatusPriIn=new Array[Data](4)
  val StatusIDIn=new Array[Data](4)
  for(i<- 0 until 4)
    {
      StatusIDIn(i)= WireDefault(UInt(IDLen.W),0.U)
      StatusPriIn(i)= WireDefault(UInt(PriWidth.W),0.U)

    }

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
    val en_nest=Output(UInt(1.W))
    val de_nest=Output(UInt(1.W))
    val is_pending=Input(UInt(1.W))
    val int_fin=Input(UInt(1.W))
  })


  //io connection
  io.empty:=(StatusPtr===0.U)&(Status(0).io.status===0.U)
  io.current_ID:=CurrentID
  io.current_pri:=CurrentPri
  io.is_nesting:=(StatusPtr=/=0.U)
  io.nested_ID:=NestedID
  io.nested_pri:=NestedPri
  io.en_nest:=EnNest
  io.de_nest:=DeNest
  //reg&submodule connection
  when(io.nest_disable===0.U)
  {
    when(io.is_pending.asBool)
    {
      when((StatusPtr===0.U)&(Status(0).io.status===0.U))
      {
        StatusAct:=1.U
        StatusIDIn(0):=io.coming_ID
        StatusPriIn(0):=io.coming_pri
      }.elsewhen((StatusPtr===0.U)&(Status(0).io.status===1.U))
      {
        when(io.int_fin===1.U)
        {
          StatusAct:=1.U
          StatusIDIn(0) := io.coming_ID
          StatusPriIn(0) := io.coming_pri
        }.elsewhen(io.coming_pri(PriWidth-1,NestPriPosi)>CurrentPri(PriWidth-1,NestPriPosi))
        {
          StatusPtr:=1.U
          StatusAct:=2.U
          StatusNest:=1.U
          StatusIDIn(1):= io.coming_ID
          StatusPriIn(1) := io.coming_pri
          EnNest:=1.U
        }
      }.elsewhen(StatusPtr===3.U)
      {
        when(io.int_fin === 1.U)
        {
          when(io.coming_pri(PriWidth-1,NestPriPosi)>NestedPri(PriWidth-1,NestPriPosi))
          {
            StatusAct:=8.U
            StatusIDIn(3):= io.coming_ID
            StatusPriIn(3):= io.coming_pri
          }.otherwise
          {
            StatusDeact:=8.U
            StatusDenest:=4.U
            StatusPtr:=2.U
            DeNest:=1.U
          }
        }
      }.elsewhen(StatusPtr===1.U)
      {
        when(io.int_fin === 1.U)
        {
          when(io.coming_pri(PriWidth - 1, NestPriPosi) > NestedPri(PriWidth - 1, NestPriPosi))
          {
            StatusAct:= 2.U
            StatusIDIn(1) := io.coming_ID
            StatusPriIn(1) := io.coming_pri
          }.otherwise
          {
            StatusDeact:= 2.U
            StatusDenest:=1.U
            StatusPtr := 0.U
            DeNest := 1.U
          }
        }.otherwise
        {
          when(io.coming_pri(PriWidth - 1, NestPriPosi) > CurrentPri(PriWidth - 1, NestPriPosi))
          {
            StatusIDIn(2):= io.coming_ID
            StatusPriIn(2):= io.coming_pri
            StatusAct:=4.U
            StatusNest:=2.U
            EnNest := 1.U
            StatusPtr:=2.U
          }
        }
      }.otherwise
      {
        when(io.int_fin === 1.U)
        {
          when(io.coming_pri(PriWidth - 1, NestPriPosi) > NestedPri(PriWidth - 1, NestPriPosi))
          {
            StatusAct:=4.U
            StatusIDIn(2) := io.coming_ID
            StatusPriIn(2) := io.coming_pri
          }.otherwise
          {
            StatusDeact := 4.U
            StatusPtr := 2.U
            DeNest := 1.U
          }
        }.otherwise
        {
          when(io.coming_pri(PriWidth - 1, NestPriPosi) > CurrentPri(PriWidth - 1, NestPriPosi))
          {
            StatusIDIn(3):= io.coming_ID
            StatusPriIn(3):= io.coming_pri
            StatusNest:=4.U
            StatusAct:=8.U
            StatusPtr:=3.U
            EnNest := 1.U
          }
        }
      }
    }.elsewhen(io.int_fin.asBool)
    {
      when(StatusPtr===0.U)
      {
        StatusDeact:=1.U
      }.otherwise
      {
        StatusDeact := Cat(Cat(StatusPtr === 3.U, StatusPtr === 2.U), Cat(StatusPtr === 1.U, 0.U(1.W)))
        StatusDenest := Cat(Cat(0.U(1.W), StatusPtr === 3.U), Cat(StatusPtr === 2.U, StatusPtr === 1.U))
        StatusPtr:=StatusPtr-1.U
      }
    }
  }
  for(i<-0 until 4)
    {
      Status(i).io.act:=StatusAct(i)
      Status(i).io.deact:=StatusDeact(i)
      Status(i).io.nest:=StatusNest(i)
      Status(i).io.denest:=StatusDenest(i)
      Status(i).io.pri_in:=StatusPriIn(i)
      Status(i).io.ID_in:=StatusIDIn(i)
    }

  //wire connection
  CurrentID := (Fill(IDLen, StatusPtr === 0.U) & (Status(0).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 1.U) & (Status(1).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 2.U) & (Status(2).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 3.U) & (Status(3).io.ID_out))
  CurrentPri := (Fill(PriWidth, StatusPtr === 0.U) & (Status(0).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 1.U) & (Status(1).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 2.U) & (Status(2).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 3.U) & (Status(3).io.pri_out))
  NestedID := 0.U(IDLen.W) |
    (Fill(IDLen, StatusPtr === 1.U) & (Status(0).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 2.U) & (Status(1).io.ID_out)) |
    (Fill(IDLen, StatusPtr === 3.U) & (Status(2).io.ID_out))
  NestedPri := 0.U(PriWidth.W)|
    (Fill(PriWidth, StatusPtr === 1.U) & (Status(0).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 2.U) & (Status(1).io.pri_out)) |
    (Fill(PriWidth, StatusPtr === 3.U) & (Status(2).io.pri_out))

}


object multi extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Int_nesting(4,5,3))
}
