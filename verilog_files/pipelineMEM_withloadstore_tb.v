`include "pipelineMEM_withloadstore.v"
module pipelineMEM_withloadstore_tb(
    
);
    reg         clk, resetn; 
    wire [31:0]	mem_read_data_m_o;
    wire [31:0]	alu_result_m_o;
    wire [31:0]	extended_imm_m_o;
    wire [31:0]	pc_plus_m_o;
    wire 	    reg_write_en_m_o;
    wire [ 4:0]	rd_idx_m_o;
    wire [ 3:0]	result_src_m_o;

    reg  [31:0] alu_result_e_i;
    reg  [ 3:0] dmem_type_e_i;
    reg  [31:0] rs1_e_i;
    reg  [31:0] extended_imm_e_i;
    reg  [31:0] pc_plus_e_i;
    reg         reg_write_en_e_i;
    reg  [ 4:0] rd_idx_e_i;
    reg  [ 3:0] result_src_e_i;



    integer count;

    // periodic time
    initial begin
        clk<=0;
        count<=0;
        forever begin 
          #1; clk<=~clk;
        end
    end

    always @(posedge clk ) begin 

        if(count == 0) begin
            resetn <= 1'b0;
        end
        if(count == 1) begin
            resetn           <= 1'b1;
            alu_result_e_i   <= 32'h0;
            extended_imm_e_i <= 32'h0;
            pc_plus_e_i      <= 32'h0;
            reg_write_en_e_i <= 1'b0;
            rd_idx_e_i       <= 5'b0;
            result_src_e_i   <= 4'b0;
        end
        if(count == 2) begin
            // write into memory
            dmem_type_e_i <= `DMEM_SW;
            alu_result_e_i<= 32'b100;
            rs1_e_i       <= 32'h12345678;
        end
        if(count == 3) begin
            // no operation
            dmem_type_e_i <= `DMEM_NO;
        end
        if(count == 4) begin
            // read from memory
            // dmem_type_e_i <= `DMEM_LW;
            // alu_result_e_i<= 32'b100;
            dmem_type_e_i <= `DMEM_LW;
            alu_result_e_i<= 32'b100;
        end
        if(count == 5) begin
            // write into memory
            dmem_type_e_i <= `DMEM_SH;
            alu_result_e_i<= 32'b110;
            rs1_e_i       <= 32'hffffffff;
        end
        if(count == 6) begin
            // read from memory
            // dmem_type_e_i <= `DMEM_LHU;
            // alu_result_e_i<= 32'b110;
            dmem_type_e_i <= `DMEM_LW;
            alu_result_e_i<= 32'b100;
        end
        if(count == 7) begin
            // write into memory
            dmem_type_e_i <= `DMEM_SB;
            alu_result_e_i<= 32'b111;
            rs1_e_i       <= 32'haaaaaaaa;
        end
        if(count == 8) begin
            // read from memory
            // // dmem_type_e_i <= `DMEM_LW;
            // dmem_type_e_i <= `DMEM_LBU;
            // alu_result_e_i<= 32'b111;
            dmem_type_e_i <= `DMEM_LW;
            alu_result_e_i<= 32'b100;
        end
        // now the memory data is 0xAAFF5678
        if(count == 9) begin
            // read from memory
            dmem_type_e_i <= `DMEM_LW;
            alu_result_e_i<= 32'b100;
        end
        if(count == 10) begin
            // read from memory
            dmem_type_e_i <= `DMEM_LH;
            alu_result_e_i<= 32'b110;
        end
        if(count == 11) begin
            // read from memory
            dmem_type_e_i <= `DMEM_LHU;
            alu_result_e_i<= 32'b100;
        end
        if(count == 12) begin
            // read from memory
            dmem_type_e_i <= `DMEM_LB;
            alu_result_e_i<= 32'b101;
        end
        if(count == 13) begin
            // read from memory
            dmem_type_e_i <= `DMEM_LBU;
            alu_result_e_i<= 32'b111;
        end
        
        if(count == 20)
            $finish(0);
        count = count +1;
    end

    // =========================================================================
    // ============================ testing =============================
    // =========================================================================
    pipelineMEM_withloadstore u_pipelineMEM_withloadstore(
        //ports
        .clk               		( clk               		),
        .resetn            		( resetn            		),
        .alu_result_e_i    		( alu_result_e_i    		),
        .dmem_type_e_i     		( dmem_type_e_i     		),
        .rs1_e_i           		( rs1_e_i           		),
        .extended_imm_e_i  		( extended_imm_e_i  		),
        .pc_plus_e_i      		( pc_plus_e_i      	    	),
        .reg_write_en_e_i  		( reg_write_en_e_i  		),
        .rd_idx_e_i        		( rd_idx_e_i        		),
        .result_src_e_i    		( result_src_e_i    		),
        .mem_read_data_m_o 		( mem_read_data_m_o 		),
        .alu_result_m_o    		( alu_result_m_o    		),
        .extended_imm_m_o  		( extended_imm_m_o  		),
        .pc_plus_m_o      		( pc_plus_m_o        		),
        .reg_write_en_m_o  		( reg_write_en_m_o  		),
        .rd_idx_m_o        		( rd_idx_m_o        		),
        .result_src_m_o    		( result_src_m_o    		)
    );

    // generate waveforms
    initial begin
      $dumpfile("pipelineMEM_withloadstore_tb.vcd");
      $dumpvars(0, pipelineMEM_withloadstore_tb);
    end
endmodule
