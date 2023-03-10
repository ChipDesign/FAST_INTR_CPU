class pdpair(p:Double,d:Double)
{
  val P=p
  val D=d
  var posi=0;
}

class digit(digitLen:Int,diginit:Int)
{
  var digs=new Array[Int](digitLen)
  val digitLength=digitLen
  var temp=math.abs(diginit)
  for(i <- 0 until digitLen-1)
    {
      digs(i)=temp%2
      temp=temp/2
    }
    digs(digitLen-1)=0
  def digAddorSub(adder_in:digit,add:Boolean): Unit =
  {
    val adder=new digit(this.digitLength,adder_in.get_dec)
    var c=0;
    if(!add)
      c=1
    for(i<- 0 until digitLength)
      {
        if(!add)
          {
            if(adder.digs(i)==0)
              adder.digs(i)=1
            else
              adder.digs(i)=0
          }
        val temp1=this.digs(i)^adder.digs(i)^c
        if (this.digs(i) + adder.digs(i) + c >= 2)
          c = 1
        else
          c = 0
        this.digs(i)=temp1
      }

      return 0
  }
  if(diginit<0)
    {
      for(i <- 0 until digitLength)
        if(digs(i)==1)
          digs(i)=0
        else
          digs(i)=1
      digAddorSub(new digit(digitLen,1),true)
    }

  def sla(n:Int): Unit =
  {
    for(i <- 1 until digitLength-n)
      {
        this.digs(digitLength-1-i)=this.digs(digitLength-1-i-n)
      }
    for(i<- 0 until n)
      {
        this.digs(i)=0
      }
  }

  def sra(n: Int): Unit = {
    for (i <- 0 until digitLength - n) {
      this.digs(i) = this.digs(i + n)
    }
    for (i <- 0 until n) {
      this.digs(digitLength-1-i) = this.digs(digitLength-1)
    }
  }


  def get_dec: Int = {
    var ans=0
    for(i <- 0 until digitLen)
      {
        ans=ans*2
        ans+=this.digs(31-i)
      }
    return ans
  }
  def printbin: Unit =
  {
    for(i<- 0 until digitLength)
      {
        print(this.digs(digitLength-1-i))
        if(i%4==3)
          print("\t")
      }
      print("\n")
  }
  def digSubWithQuot(adder: digit,quot: Int): Unit =
  {
    if(quot==(-2))
      {
        this.digAddorSub(adder,true)
        this.digAddorSub(adder,true)
      }
    else if(quot==(-1))
      {
        this.digAddorSub(adder,true)
      }
    else if(quot==1)
      {
        this.digAddorSub(adder, false)
      }
    else if(quot==2)
      {
        this.digAddorSub(adder,false)
        this.digAddorSub(adder,false)
      }
  }

}

class QDS
{
  val d = new Array[Double](16)
  val p = new Array[Double](32)
  for(i <- 0 until 8)
    d(i)=0.5+i*1.0/16
  for (i <- 8 until 16)
    d(i) = (-1.5) + i * 1.0 / 16
  for(i<- 0 until 16)
    p(i)=i*0.125
  for(i<- 16 until 32)
    p(i)=i*0.125-4

  val bond = Array.ofDim[Double](16, 4)
  val selecList = Array.ofDim[Int](16, 32)

  //---------------------
  bond(0) = Array(-0.75,  -0.25,  0.25,   0.75)
  bond(1) = Array(-0.875, -0.25,  0.25,   0.875)
  bond(2) = Array(-1.0,   -0.25,  0.25,   1.0)
  bond(3) = Array(-1.0,   -0.25,  0.25,   1.0)
  bond(4) = Array(-1.125, -0.375, 0.375,  1.125)
  bond(5) = Array(-1.25,  -0.375, 0.375,  1.25)
  bond(6) = Array(-1.375, -0.375, 0.375,  1.375)
  bond(7) = Array(-1.375, -0.375, 0.375,  1.375)
  //------------------------
  bond(8) =  Array(1.5, 0.375, -0.375, -1.5)
  bond(9) =  Array(1.375, 0.375, -0.375, -1.375)
  bond(10) = Array(1.25, 0.375, -0.375, -1.25)
  bond(11) = Array(1.125, 0.375, -0.375, -1.125)
  bond(12) = Array(1.0, 0.25, -0.25, -1.0)
  bond(13) = Array(1.0, 0.25, -0.25, -1.0)
  bond(14) = Array(0.875, 0.25, -0.25, -0.875)
  bond(15) = Array(0.75, 0.25, -0.25, -0.75)
  //----------------------------
  for(i<- 0 until 32) {
    for(j<- 0 until 8)
      {
        if(p(i)<=bond(j)(0))
          selecList(j)(i)=(-2)
        if(p(i)<=bond(j)(1)&&p(i)>bond(j)(0))
          selecList(j)(i)=(-1)
        if(p(i)<bond(j)(2)&&p(i)>bond(j)(1))
          selecList(j)(i)=0
        if(p(i)<bond(j)(3)&&p(i)>=bond(j)(2))
          selecList(j)(i)=1
        if(p(i)>=bond(j)(3))
          selecList(j)(i)=2
      }
    for (j <- 8 until 16) {
      if (p(i) > bond(j)(0))
        selecList(j)(i) = (-2)
      if (p(i) > bond(j)(1)&&p(i) <= bond(j)(0))
        selecList(j)(i) = (-1)
      if (p(i) >= bond(j)(2)&&p(i) <= bond(j)(1))
        selecList(j)(i) = 0
      if (p(i) >= bond(j)(3)&&p(i) < bond(j)(2))
        selecList(j)(i) = 1
      if(p(i) < bond(j)(3))
        selecList(j)(i) = 2
    }
  }


  def QuotSelect(dividend: digit, divisor: digit): Int = {
    var a=0
    var b=0
    for(i <- 0 until 6) {
      if(i!=1)
        a=a*2+dividend.digs(dividend.digitLength-1-i)
    }
    for(i<- 0 until 5) {
      if(i!=1)
        b=b*2+divisor.digs(divisor.digitLength-1-i)
    }
    dividend.printbin
    divisor.printbin
    if(dividend.digs(dividend.digitLength-1)!=dividend.digs(dividend.digitLength-2))
      return 2*math.ceil(math.pow((-1),(dividend.digs(dividend.digitLength-1)+divisor.digs(divisor.digitLength-1)))).toInt
    else
      return selecList(b)(a)
  }
}

class SRT_Sim {
  val qds=new QDS
  def get_ans(dividendin:Int,divisorin:Int):Int={
    val dividend = new digit(34, dividendin)
    val initsign = dividend.digs(31)
    val divisor = new digit(32, divisorin)
    //divisor.printbin
    // normalize divisor
    var norm_cnt = 0
    var i = 0
    while (divisor.digs(30 - i) == divisor.digs(31)) {
      norm_cnt += 1
      i += 1
    }
    val divs_len = 31 - norm_cnt
    divisor.sla(norm_cnt)
    var s_cont=0
    val Qarray = new Array[Int](16)
    for (j <- 0 until norm_cnt / 2+1) {
      Qarray(j) = qds.QuotSelect(dividend, divisor)
      print(Qarray(j) + "\n")
      dividend.digSubWithQuot(divisor, Qarray(j))
      print("ans:")
      dividend.printbin
      if(j!=(norm_cnt/2))
        {
          dividend.sla(2)
          s_cont+=2
        }
      else
        {
          if(norm_cnt % 2 == 1) {
            dividend.sla(1)
            s_cont+=1
          }
        }

    }
    print("scont:"+s_cont+"\n")
    if (norm_cnt % 2 == 1) {
      Qarray(norm_cnt / 2 + 2) = qds.QuotSelect(dividend, divisor)
      print("***"+Qarray(norm_cnt / 2+2) + "\n")
      if(Qarray(norm_cnt / 2+2) !=1||Qarray(norm_cnt / 2+2) !=(-1))
        dividend.digSubWithQuot(divisor, Qarray(norm_cnt / 2+2))
    }
    dividend.printbin
    print("\n")
    var q = 0
    var remsign = dividend.digs(33)
    val divsign = divisor.digs(31)

    for (j <- 0 until norm_cnt / 2+1) {
      q = q * 4 + Qarray(j)
    }
    print(norm_cnt + "\n")
    print(q + "\n")
    if(norm_cnt%2==1) {
      q = q * 2 + Qarray(norm_cnt / 2 + 2)
      print("c1\n")
    }

    print(q + "**\n")
    while (remsign != initsign) {
      dividend.digAddorSub(divisor, divsign != remsign)
      if (divsign != remsign) {
        q = q - 1
        print("d1\n")
      } else {
        q = q + 1
      print("d2\n")}
      remsign=dividend.digs(33)
    }
    dividend.sra(norm_cnt)
    dividend.printbin
    return q
  }


}

object sim_main {
  def main(args: Array[String]): Unit = {
    val a = new SRT_Sim
    var dividend = 0
    var divisor = 0
    var ans = 0
    var srtans = 0
    var i = 0
    val flag = true
    if (flag) {
      while (ans == srtans && i < 100) {
        dividend = util.Random.nextInt(4094 + 1)
        divisor = util.Random.nextInt(4094 + 1)
        ans = dividend / divisor
        srtans = a.get_ans(dividend, divisor)
        print((ans == srtans) + "\t")
        i = i + 1
        if (i % 10 == 0)
          print("\n")
      }
      print("\n")
      print(dividend + "\t" + divisor + "\t" + ans + "\t" + srtans)
    }
    else {
      dividend = 1587
      divisor = 108
      ans = dividend / divisor
      srtans = a.get_ans(dividend, divisor)
      print(dividend + "\t" + divisor + "\t" + ans + "\t" + srtans)
    }
  }
}