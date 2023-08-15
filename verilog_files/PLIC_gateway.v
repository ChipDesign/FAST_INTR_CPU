module PLIC_gateway(
    input wire rstn,
    input wire clk,
    input wire int_sig,
    input wire int_end,

    output wire int_req
);


reg pending;

always@(posedge clk)
begin
    if(~rstn)
    begin
        pending<=1'b0;
    end
    else
    begin
        if(int_end)
        begin
            pending<=1'b0;
        end
        else if(int_sig)
        begin
            pending<=1'b1;
        end
        
    end
end

assign int_req=pending;


endmodule