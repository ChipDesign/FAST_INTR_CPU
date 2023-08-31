`include "PLIC_gateway.v"
`include "PLIC_core.v"
module PLIC_top_unmod(
    input wire clk,
    input wire rstn,

    input wire [127:0] intr_bundle,
    input wire core_wen,
    input wire [23:0] core_addr,
    input wire [31:0] core_wdata,
    input wire core_ren,
    
    output wire [31:0] core_rdata,
    output wire plic_notif
);


wire [127:0] int_end;
wire [127:0] int_req;

wire [127:0] gateway_notif;

genvar intr;
generate
    for(intr=0;intr<128;intr=intr+1)
    begin
        PLIC_gateway gateway_i(
            .clk(clk),
            .rstn(rstn),
            .int_sig(intr_bundle[intr]),
            .int_end(int_end[intr]),

            .int_req(int_req[intr]),
            .gateway_notif(gateway_notif[intr])
        );
    end
endgenerate

reg test_plic_notif;
always@(posedge clk)
begin
    test_plic_notif<=plic_notif;
end



PLIC_core plic_core(
    .clk(clk),
    .rstn(rstn),
    .int_req_pack(int_req),
    .gateway_notif(|gateway_notif[127:0]),
    .reg_wen(core_wen),
    .reg_ren(core_ren),
    .reg_addr(core_addr),
    .reg_wdata(core_wdata),
    
    .notif(plic_notif),
    .reg_rdata(core_rdata),
    .int_end(int_end)
);


endmodule