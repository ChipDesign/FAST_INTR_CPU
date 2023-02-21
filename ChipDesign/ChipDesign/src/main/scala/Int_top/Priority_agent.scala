package Int_top

import chisel3._
import chisel3.util._
import Universal_tools.{By_ID_sel}


class Pri_elem(PriWidth: Int, IDLen: Int,PriInit:UInt,IDInit:UInt) extends Module
{
  //statement
  val io=IO(new Bundle
  {
    val id=Output(UInt(IDLen.W))
    val pri=Output(UInt(PriWidth.W))
    val pri_update=Input(UInt(PriWidth.W))
    val pri_update_sig=Input(UInt(1.W))
    val elem_act=Input(UInt(1.W))
    val elem_deact=Input(UInt(1.W))
    val actevated=Output(UInt(1.W))
  })
  val Pri=RegInit(UInt(PriWidth.W),PriInit)
  val ID=RegInit(UInt(IDLen.W),IDInit)
  val act=RegInit(UInt(1.W),0.U(1.W))

  //io connection
  when(io.pri_update_sig.asBool)
  {
    Pri:=io.pri_update
  }
  io.id:=ID
  io.pri:=Pri
  io.actevated:=act

  //register connection
  when(io.elem_act.asBool)
  {act:=1.U(1.W)}
  when(io.elem_deact.asBool)
  {act:=0.U(1.W)}
  when(io.pri_update_sig.asBool)
  {Pri:=io.pri_update}
}



class Priority_agent(IDLen:Int, FixPriSize:Int, DynPriSize:Int, PriWidth:Int, PriInit:Seq[UInt],DynamDefautPri:UInt) extends Module {
  //statement
  val FixedPri=new Array[Pri_elem](FixPriSize)
  for(i<-0 until FixPriSize)
    {
      FixedPri(i)=Module(new Pri_elem(PriWidth,IDLen,PriInit(i),i.U(IDLen.W)))
    }
  val DynamPri=new Array[Pri_elem](DynPriSize)
  for (i <- 0 until DynPriSize) {
    DynamPri(i) =Module( new Pri_elem(PriWidth, IDLen, DynamDefautPri, (i+FixPriSize).U(IDLen.W)))
  }
  val InitPri=RegInit(UInt(PriWidth.W),DynamDefautPri)
  val Tcnt=RegInit(UInt(3.W),0.U)
  val DynIDList:List[UInt]=List.tabulate(DynPriSize)((n:Int)=>(n+FixPriSize).U(IDLen.W))
  val IntClaimSel=Module(new By_ID_sel(DynPriSize,IDLen, DynIDList))
  val IntOccSel=Module(new By_ID_sel(DynPriSize,IDLen, DynIDList))
  val DynamPriUpdate=Wire(Vec(DynPriSize,UInt(PriWidth.W)))
  val PriUpdateSig=Wire(UInt(1.W))

  val io=IO(new Bundle{
    val dyn_int_claim_sig=Input(UInt(1.W))
    val int_pri=Output(Vec(FixPriSize+DynPriSize,UInt(PriWidth.W)))
    val dyn_int_occ_sig=Input(UInt(1.W))
    val dyn_int_occ_ID=Input(UInt(IDLen.W))
    val dyn_int_claim_ID=Input(UInt(IDLen.W))
  })

  //io connection
  for(i <- 0 until FixPriSize)
  {
    io.int_pri(i):=FixedPri(i).io.pri
  }
  for (i <- 0  until DynPriSize) {
    io.int_pri(i + FixPriSize):=DynamPri(i).io.pri
  }
  IntOccSel.io.ID_in:=io.dyn_int_occ_ID
  IntClaimSel.io.ID_in:=io.dyn_int_claim_ID
  //register&submodule connection
  for (i <- 0 until FixPriSize) {
    FixedPri(i).io.elem_deact:=1.U(1.W)
    FixedPri(i).io.elem_act:=0.U(1.W)
    FixedPri(i).io.pri_update_sig:=0.U(1.W)
    FixedPri(i).io.pri_update:=0.U(PriWidth.W)
  }


  for(i<-0 until DynPriSize)
    {
      DynamPri(i).io.pri_update_sig:=PriUpdateSig
      DynamPri(i).io.pri_update:=(Fill(PriWidth,IntOccSel.io.sel_sig(i))&(InitPri))|
        (Fill(PriWidth,(!IntOccSel.io.sel_sig(i))&PriUpdateSig)&(DynamPriUpdate(i)))
      DynamPri(i).io.elem_act:=io.dyn_int_occ_sig&IntOccSel.io.sel_sig(i)
      DynamPri(i).io.elem_deact:=io.dyn_int_claim_sig&IntClaimSel.io.sel_sig(i)
    }
  //wire connection
  PriUpdateSig:=io.dyn_int_occ_sig|(Tcnt.andR)
  for(i<-0 until DynPriSize)
    {
      DynamPriUpdate(i):=DynamPri(i).io.pri+1.U(PriWidth.W)
    }
}

object multi extends App {
  (new chisel3.stage.ChiselStage).emitVerilog(new Priority_agent(4,8,8,5, List(1.U(5.W), 1.U(5.W), 1.U(5.W), 1.U(5.W), 1.U(5.W), 1.U(5.W), 1.U(5.W), 1.U(5.W), 2.U(5.W), 2.U(5.W), 2.U(5.W), 2.U(5.W), 2.U(5.W), 2.U(5.W), 2.U(5.W), 2.U(5.W))
    , 2.U(5.W)))
}

