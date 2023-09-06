module PLIC_core(
    input wire clk,
    input wire rstn,
    input wire [127:0] int_req_pack,
    input wire gateway_notif,
    input wire reg_wen,
    input wire reg_ren,
    input wire [23:0] reg_addr,
    input wire [31:0] reg_wdata,
    
    output reg notif,
    output reg [31:0] reg_rdata,
    output reg [127:0] int_end
);

wire [31:0] int_req [3:0];
reg [31:0] intr_priority [127:0];
reg [31:0] threshold,claim;
reg pending_clear;
reg gateway_notif1;
reg [31:0] pri_winner;

reg [31:0] pending [3:0];
reg [31:0] enable [3:0];

reg [31:0] pri_sort [126:0];
reg [31:0] ID_sort [126:0];

wire [6:0] priority_index;
reg [31:0] claimed ; 
wire claim_read;

reg [31:0] pri_en [127:0];

always@(posedge clk)
begin
    notif=(~(pri_winner<threshold))&(|pending[0])|(|pending[1])|(|pending[2])|(|pending[3]);
end
assign claim_read=reg_ren&(reg_addr==24'h200004);

assign int_req[0]=int_req_pack[31:0];
assign int_req[1]=int_req_pack[63:32];
assign int_req[2]=int_req_pack[95:64];
assign int_req[3]=int_req_pack[127:96];



integer i,j,k;

// intr_priority change

assign priority_index=reg_addr[8:2];

always@(posedge clk)
begin
     if(~rstn)
    begin
        for(i=0;i<128;i=i+1)
        begin
            intr_priority[i] <= 32'b0;
        end
    end
    else if(reg_wen&(reg_addr[23:9]==15'b0))
    begin
        if(priority_index!=0)
        begin
            intr_priority[priority_index]<= reg_wdata;
        end
    end

end
     
//pending, it is read only reg

always@(posedge clk)
begin
     if(~rstn)
    begin
        for(j=0;j<4;j=j+1)
        begin
            pending[j] <=32'b0;
        end
    end
    else
    begin
        if(gateway_notif)
        begin
            for(j=0;j<4;j=j+1)
            begin
                pending[j] <= (pending[j]|int_req[j]);
            end
        end
        if(claim_read)
        begin
            pending[claim[6:5]]=pending[claim[6:5]]&(~claimed);
        end
    end

end

//enable

always@(posedge clk)
begin
     if(~rstn)
    begin
        for(k=0;k<4;k=k+1)
        begin
            enable[k] <=32'b0;
        end
    end
    else if(reg_wen&(reg_addr[23:12]==12'h002))
    begin
        if(reg_addr[11:4]==0)
        begin
            enable[reg_addr[3:2]]<=reg_wdata;
        end
    end
end

//threshold 

always@(posedge clk)
begin
     if(~rstn)
    begin
        threshold <= 32'b0;
    end
    else if(reg_wen&(reg_addr==24'h200000))
    begin
        threshold <= reg_wdata;
    end
end

//claim
always@(posedge clk)
begin
     if(~rstn)
    begin
        claim <= 32'b0;
        pending_clear <= 1'b0;
    end
    else if(reg_wen&(reg_addr==24'h200004))
    begin
        claim <= reg_wdata;
        pending_clear <= 1'b1;
    end
    else if(pri_sort[126]>=threshold)
    begin
        claim<=ID_sort[126];
        pending_clear<=0;
    end
    
    else
    begin
        claim<=32'b0;
        pending_clear <= 1'b0;
    end
end






always@(posedge clk)
begin
     if(~rstn)
    begin
        int_end<=128'b0;
    end
    else if(reg_wen&(reg_addr==24'h200004))
    begin
        int_end[reg_wdata[6:0]-:1]<=1'b1;
    end
    else
    begin
        int_end<=128'b0;
    end
end



//intr_priority sorting
integer l0,l1,l2,l3,l4,l5;
always @ (*)
begin
    for(l0=0;l0<32;l0=l0+1)
    begin
        pri_en[l0]=intr_priority[l0]&{32{(pending[0][l0-:1])&(enable[0][l0-:1])}};
        pri_en[l0+32]=intr_priority[l0+32]&{32{(pending[0][l0-:1])&(enable[1][l0-:1])}};
        pri_en[l0+64]=intr_priority[l0+64]&{32{(pending[0][l0-:1])&(enable[2][l0-:1])}};
        pri_en[l0+96]=intr_priority[l0+96]&{32{(pending[0][l0-:1])&(enable[3][l0-:1])}};
    end
    for(l1=0;l1<64;l1=l1+1)
    begin
        pri_sort[l1]= (pri_en[2*l1]>=pri_en[2*l1+1])?(pri_en[2*l1]):(pri_en[2*l1+1]);
        ID_sort[l1]= (pri_en[2*l1]>=pri_en[2*l1+1])?(2*l1):(2*l1+1);
    end
    for(l2=0;l2<32;l2=l2+1)
    begin
        pri_sort[64+l2]=(pri_sort[2*l2]>=pri_sort[2*l2+1])?pri_sort[2*l2]:pri_sort[2*l2+1];
        ID_sort[64+l2]=(pri_sort[2*l2]>=pri_sort[2*l2+1])?ID_sort[2*l2]:ID_sort[2*l2+1];
    end
    for(l3=0;l3<16;l3=l3+1)
    begin
        pri_sort[96+l3]=(pri_sort[2*l3+64]>=pri_sort[2*l3+65])?pri_sort[2*l3+64]:pri_sort[2*l3+65];
        ID_sort[96+l3]=(pri_sort[2*l3+64]>=pri_sort[2*l3+65])?ID_sort[2*l3+64]:ID_sort[2*l3+65];
    end
    for(l4=0;l4<8;l4=l4+1)
    begin
        pri_sort[112+l4]=(pri_sort[2*l4+96]>=pri_sort[2*l4+97])?pri_sort[2*l4+96]:pri_sort[2*l4+97];
        ID_sort[112+l4]=(pri_sort[2*l4+96]>=pri_sort[2*l4+97])?ID_sort[2*l4+96]:ID_sort[2*l4+97];
    end
    for(l5=0;l5<4;l5=l5+1)
    begin
        pri_sort[120+l5]=(pri_sort[2*l5+112]>=pri_sort[2*l5+113])?pri_sort[2*l5+112]:pri_sort[2*l5+113];
        ID_sort[120+l5]=(pri_sort[2*l5+112]>=pri_sort[2*l5+113])?ID_sort[2*l5+112]:ID_sort[2*l5+113];
    end
    pri_sort[124]=(pri_sort[120]>=pri_sort[121])?pri_sort[120]:pri_sort[121];
    ID_sort[124]=(pri_sort[120]>=pri_sort[121])?ID_sort[120]:ID_sort[121];
    pri_sort[125]=(pri_sort[122]>=pri_sort[123])?pri_sort[122]:pri_sort[123];
    ID_sort[125]=(pri_sort[122]>=pri_sort[123])?ID_sort[122]:ID_sort[123];
    pri_sort[126]=(pri_sort[124]>=pri_sort[125])?pri_sort[124]:pri_sort[125];
    ID_sort[126]=(pri_sort[124]>=pri_sort[125])?ID_sort[124]:ID_sort[125];
    pri_winner=pri_sort[126];
end


always@(*)
begin
    claimed=0;
    if(pri_sort[126]>= threshold)
    begin
        claimed[ID_sort[126][4:0]-:1]=1'b1;
    end
end

//TODO reserved 0 address interrupt to be inplemented               

always@(posedge clk)
begin
    if(reg_ren)
    begin
    case(reg_addr[23:12])
        12'b0:
            if(reg_addr[11:9]==0)
            begin
                if(reg_addr[8:2]!=0)
                begin
                reg_rdata <= intr_priority[reg_addr[8:2]];
                end
                else
                begin
                    reg_rdata<= 32'b0;
                end
            end
        12'b1:
            if(reg_addr[11:4]==0)
            begin
                reg_rdata <= pending[reg_addr[3:2]];
            end
            else
            begin
                reg_rdata<= 32'b0;
            end
        12'h002:
            if(reg_addr[11:4]==0)
            begin
                reg_rdata <= enable[reg_addr[3:2]];
            end
            else
            begin
                reg_rdata<= 32'b0;
            end
        12'h200:
            if(reg_addr[11:0]==0)
            begin
                reg_rdata <= threshold;
            end
            else if(reg_addr[11:0]==4)
            begin
                reg_rdata <= claim;
            end
            else
            begin
                reg_rdata<= 32'b0;
            end
        default:
            reg_rdata<=32'b0;
    endcase
    end
end


endmodule