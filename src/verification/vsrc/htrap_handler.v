`ifndef __HTRAP_HANDLER__
`define __HTRAP_HANDLER__

//this module is basically a package to handle PLIC's signal
//actually it is not so necessary to use a independent module
//But to keep the clear and well-organzed top module, it is implement here
module htrap_handler
(
    //input
    input wire clk,
    input wire resetn,
    //CSR communication
    input wire [31:0] mie,
    input wire [31:0] mip,
    input wire [31:0] mstatus,

    

    //pipeline communication
    input wire mret_commit,

    //output
    //CSR communication
    output reg intr_happen,
    output reg ex_happen,
    output wire [31:0] trap_cause,
    output wire time_pending,
    output wire soft_pending,
    output wire trap_fin,

    //PLIC communication


    //pipeline communication
    output reg trap_flush


);


reg [31:0] cause;
reg intr_triggered;

assign trap_fin=mret_commit;
assign trap_cause=cause;
assign time_pending=1'b0;
assign soft_pending=1'b0;

always@(posedge clk)
begin
    if(~resetn)
    begin
        intr_happen<=1'b0;
        ex_happen<=1'b0;
        cause<=32'b0;
        trap_flush<=1'b0;
        intr_triggered<=1'b0;
    end
    //TODO: put excepetion handle here
    else if(intr_triggered)
    begin
        trap_flush<=1'b0;
        intr_happen<=1'b0;
        intr_triggered<=1'b0;
    end
    else if(mstatus[3])
    begin
        ex_happen<=1'b0;
        if(mip[11]&mie[11])
        begin
            cause<={1'b1,19'b0,1'b1,11'b0};
            trap_flush<=1'b1;
            intr_happen<=1'b1;
            intr_triggered<=1'b1;
        end
        else if(mip[7]&mie[7])
        begin
            cause<={1'b1,23'b0,1'b1,7'b0};
            trap_flush<=1'b1;
            intr_happen<=1'b1;
            intr_triggered<=1'b1;
        end
        else if(mip[3]&mie[3])
        begin
            cause<={1'b1,27'b0,1'b1,3'b0};
            trap_flush<=1'b1;
            intr_happen<=1'b1;
            intr_triggered<=1'b1;
        end
        else
        begin
            intr_happen<=1'b0;
            trap_flush<=1'b0;
            cause<=32'b0;
        end
    end
    else
    begin
        intr_happen<=1'b0;
        ex_happen<=1'b0;
        cause<=32'b0;
        trap_flush<=1'b0;
    end
end






endmodule
`endif