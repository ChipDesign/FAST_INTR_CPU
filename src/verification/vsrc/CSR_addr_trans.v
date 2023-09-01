

module CSR_addr_trans(
    input wire [11:0] csr_addr,
    
    output reg [4:0] csr_index
);

always @(*)
begin
    case(csr_addr)
        12'hF11:begin
		csr_index <= 5'h01;
		end
		12'hF12:begin
		csr_index <= 5'h02;
		end
		12'hF13:begin
		csr_index <= 5'h03;
		end
		12'hF14:begin
		csr_index <= 5'h04;
		end
		12'h300:begin
		csr_index <= 5'h05;
		end
		12'h301:begin
		csr_index <= 5'h06;
		end
		12'h304:begin
		csr_index <= 5'h07;
		end
		12'h305:begin
		csr_index <= 5'h08;
		end
		12'h310:begin
		csr_index <= 5'h09;
		end
		12'h340:begin
		csr_index <= 5'h0A;
		end
		12'h341:begin
		csr_index <= 5'h0B;
		end
		12'h342:begin
		csr_index <= 5'h0C;
		end
		12'h343:begin
		csr_index <= 5'h0D;
		end
		12'h344:begin
		csr_index <= 5'h0E;
		end
		12'hB00:begin
		csr_index <= 5'h0F;
		end
		12'hB02:begin
		csr_index <= 5'h10;
		end
		12'hB03:begin
		csr_index <= 5'h11;
		end
		12'hB80:begin
		csr_index <= 5'h12;
		end
		12'hB82:begin
		csr_index <= 5'h13;
		end
		12'hB83:begin
		csr_index <= 5'h14;
		end
		12'h320:begin
		csr_index <= 5'h15;
		end
		12'h323:begin
		csr_index <= 5'h16;
		end
		
        default: begin
            csr_index <= 7'b0;
        end
    endcase
end



endmodule
