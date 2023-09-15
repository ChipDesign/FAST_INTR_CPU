`ifndef __CSR__
`define __CSR__

`include"CSR_addr_trans.v"
module CSR(
    input wire [11:0] raddr,
    input wire [11:0] waddr,
    input wire [31:0] wdata,
    input wire resetn,
    input wire clk,
    input wire wen,
    input wire ex_happen,
    input wire intr_happen,
    input wire inst_commit,
    input wire [31:0] extra_massage,
    input wire trap_fin,
    input wire soft_pending,
    input wire time_pending,
    input wire ext_pending,
    input wire [31:0] cause_input,
    input wire [31:0] wb_pc,
    input wire [31:0] mem_pc,
    input wire trap_flush_t_i,
    input wire [31:0] event_happens,

    output wire [31:0] rdata,
    output wire [31:0] trap_vector,
    output wire [31:0] epc_ret,
    output wire [31:0] context_ptr,
    output wire [31:0] mie,
    output wire [31:0] mip,
    output wire [31:0] mstatus
);
//TODO read write fence
reg [31:0] CSRs [26:0];
wire throughput,throughput1,throughput2;
//TODO illegal write fence fo through put
//delay the write to write back stage
reg [31:0] wdata1,wdata2;
reg [11:0] waddr1,waddr2;
reg wen1,wen2;

wire [4:0] windex,rindex;
wire event_trig3;
wire [63:0] cycle,instret,hpmc3;

always@(posedge clk)
begin
    if(~resetn||trap_flush_t_i)
    begin
        wdata1<=32'b0;
        wdata2<=32'b0;
        wen1<=1'b0;
        wen2<=1'b0;
        waddr1<=12'b0;
        waddr2<=12'b0;
    end
    else
    begin
        wdata1<=wdata;
        wdata2<=wdata1;
        wen1<=wen;
        wen2<=wen1;
        waddr1<=waddr;
        waddr2<=waddr1;
    end
end


//unchangable CSRs initialized as vender:ff, archid:cc, impid:ee, hartid:0,
//isa: 40001104 for rv32imc
always @(posedge clk)
begin
   if(~resetn)
   begin
	CSRs[0] <= 32'h0;
	CSRs[1] <= 32'hff;
	CSRs[2] <= 32'hcc;
	CSRs[3] <= 32'hee;
	CSRs[4] <= 32'h0;
	CSRs[6] <= 32'h40001104;
   end 
end

//mstatus
always @(posedge clk)
begin
   if(~resetn)
   begin
        CSRs[5] <= 32'h1888;//TODO: initialization
	CSRs[9] <= 32'b0;//statush
   end
   else if(wen2&waddr2 == 12'h300)
   begin
	CSRs[5] <= wdata2;
   end
   else if(wen2&waddr2 == 12'h310)
   begin
	CSRs[9] <= wdata2;
   end
   else if(intr_happen|ex_happen)
   begin
	CSRs[5][3] <= 1'b0;
    CSRs[5][7] <= CSRs[5][3];
    CSRs[5][12:11] <= 2'b11;
   end
   else if(trap_fin)
   begin
	CSRs[5][7] <= 1'b1;
    CSRs[5][3] <= CSRs[5][7];
    CSRs[5][12:11] <= 2'b11;
   end
end

//mie
always @(posedge clk)
begin
    if(~resetn)
    begin
	CSRs[7] <= 32'h00000888;// initialized as all m-mode interrupt enable
    end
    else if(wen2&waddr2 == 12'h304)
    begin
	CSRs[7] <= wdata2&(32'h0000aaaa);
    end
end

//mtvec
always @(posedge clk)
begin
    if(~resetn)
    begin
	CSRs[8] <= 32'b0;//initialized as zero, to be reset by booting software
    end
    else if(wen2&waddr2 == 12'h305)
    begin
	CSRs[8] <= wdata2;
    end
end

//mscratch
always @(posedge clk)
begin
    if(~resetn)
    begin
	CSRs[10] <= 32'b0;
    end
    else if(wen2&waddr2 ==12'h340)
    begin
	CSRs[10] <= wdata2;
    end
end


//mepc
always @(posedge clk)
begin
    if( ~resetn)
    begin
	CSRs[11] <= 32'b0;
    end
    else if(ex_happen)
    begin
	CSRs[11] <= wb_pc;
    end
    else if(intr_happen)
    begin
	CSRs[11] <= mem_pc;
    end
    else if(wen2&waddr2== 12'h341)
    begin
	CSRs[11] <= wdata2;
    end
end


//mcause
always @(posedge clk)
begin
    if(~resetn)
    begin
	CSRs[12] <= 32'b0;
    end
    else if(intr_happen&ex_happen)
    begin
	CSRs[12] <= cause_input;
    end
    else if(wen2&waddr2 ==12'h342)
    begin
	CSRs[12] <= wdata2;
    end
end

//mtval
always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[13] <= 32'b0;
    end
    else if(intr_happen&ex_happen)
    begin
        CSRs[13] <= extra_massage;
    end
    else if(wen2&waddr2 ==12'h343)
    begin
        CSRs[13] <= wdata2;
    end
end

//TODO to figure out why it is need
reg test_ext_pending;
always@(*)
begin
    test_ext_pending=ext_pending;
end

//mip
always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[14] <= 32'b0;
    end
    else
    begin
	    CSRs[14][3]<= soft_pending; 
      	CSRs[14][7]<= time_pending;
	    CSRs[14][11]<= test_ext_pending;	
    end
    
end



//mcycle/h

assign cycle={CSRs[18],CSRs[15]}+1;
always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[15] <= 32'b0;
	CSRs[18] <= 32'b0;
    end
    else if(wen2&waddr2==12'hb00)
    begin
	CSRs[15] <= wdata2;
    end
    else if(wen2&waddr2==12'hb80)
    begin
	CSRs[18] <= wdata2;
	if(~CSRs[21][0])
	begin
	    CSRs[15] <= CSRs[15]+1;
	end
    end
    else if(~CSRs[21][0])
    begin
	CSRs[15]<=cycle[31:0];
	CSRs[18]<=cycle[63:32];
    end
end

//minstret/h
assign instret={CSRs[19],CSRs[16]}+1;
always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[16] <= 32'b0;
	CSRs[19] <= 32'b0;
    end
    else if(wen2&waddr2==12'hb02)
    begin
	CSRs[16] <= wdata2;
    end
    else if(wen2&waddr2==12'hb82)
    begin
	CSRs[19] <= wdata2;
	if(inst_commit&~CSRs[21][2])
	begin
	    CSRs[16] <= CSRs[16]+1;
	end
    end
    else if( inst_commit&~CSRs[21][2])
    begin
	CSRs[16]<=instret[31:0];
	CSRs[16]<=instret[63:32];
    end
end

//mhpmcount3&mhpmcount3h
assign hpmc3={CSRs[20],CSRs[17]}+1;
always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[17] <= 32'b0;
	CSRs[20] <= 32'b0;
    end
    else if(wen2&waddr2==12'hb03)
    begin
	CSRs[17] <= wdata2;
    end
    else if(wen2&waddr2==12'hb83)
    begin
	CSRs[20] <= wdata2;
	if(event_trig3&~CSRs[21][3])
	begin
	    CSRs[17] <= CSRs[17]+1;
	end
    end
    else if( event_trig3&~CSRs[21][2])
    begin
	CSRs[17]<=hpmc3[31:0];
	CSRs[17]<=hpmc3[63:32];
    end
end

//mcountinhibit


always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[21] <= 32'h0;
    end
    else if(wen2&waddr2==12'h320)
    begin
	CSRs[21] <= wdata2&32'hd;
    end
end

//mhpmevent3

always @(posedge clk)
begin
    if(~resetn)
    begin
        CSRs[22] <= 32'h0;
    end
    else if(wen2&waddr2==12'h323)
    begin
	CSRs[22] <= wdata2;
    end
end

/*
| id | ex | mem | wb |
| r  | w  | w1  | w2 |

*/

assign mie=CSRs[7];
assign mip=CSRs[14];
assign mstatus=CSRs[5];

assign event_trig3 = (event_happens==CSRs[22])&(event_happens!=0);
assign context_ptr =CSRs[10];
assign epc_ret = CSRs[11];
assign trap_vector =CSRs[8];
assign throughput=(raddr==waddr)&wen;
assign throughput1=(raddr==waddr1)&wen1;
assign throughput2=(raddr==waddr2)&wen2;
assign rdata=throughput ?wdata:
                        (throughput1 ? wdata1:
                                    (throughput2 ? wdata2:
                                                    CSRs[rindex]));


CSR_addr_trans rtrans(
    .csr_addr( raddr ),
    .csr_index( rindex)
);
//TODO zimm all zero then no write





endmodule
`endif