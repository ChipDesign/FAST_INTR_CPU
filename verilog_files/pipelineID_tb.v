`include "pipelineID.v"
module pipelineID_tb();

  reg clk,resetn;
  integer i, counter;


  // generate clock
  initial begin
    clk<=0;
    counter <= 0;
    forever begin 
      #1; clk<=~clk;
    end
  end
  
  // begin test
  always@(posedge clk) begin 
    if(counter==0)begin
      resetn <= 0;
    end

    if(counter==1)begin
      resetn <= 1;
    end

    if(counter==2)begin
        enable <= 1'b1;
        reg_write_en_w_i    <=1'h0;
        rd_idx_w_i          <=5'h0;
        write_back_data_w_i <= 32'h0;
        rs1_depended_h_i    <= 1'h0; 
        flush_i             <= 1'h0;
        src1_sel_d_i        <= 2'h0;
        src2_sel_d_i        <= 2'h0;
        bypass_e_o          <= 32'h0;
        bypass_m_o          <= 32'h0;

        instruction_f_i        <= 32'h00000013;
        redirection_pc_e_i     <= 32'h0;
        redirection_e_i        <= 1'h0;
        pc_next_next_taken_e_i <= 1'h0;
    end
    if(counter==3) begin
        instruction_f_i        <= 32'h00000013;
    end
    if(counter==4) begin
            
    end
    if(counter==5) begin
        // redirection_pc_e_i     <= 32'hFFFFFFFF;
        // redirection_e_i        <= 1'h1;
        pc_next_next_taken_e_i <= 1'h0;
            
    end
    if(counter==6) begin
        pc_next_next_taken_e_i <= 1'h1;
            
    end
    if(counter==10) begin
        instruction_f_i        <= 32'hfe5012e3;
    end
    

    if(counter==20)begin
      $finish();
    end

    counter+=1;
  end

  initial begin
    $dumpfile("pipelineID_tb.vcd");
    $dumpvars(0, pipelineID_tb);
  end

  
wire [31:0]	redirection_d_o;
wire 	taken_d_o;
wire 	flush_jal_d_o;
wire 	is_compressed_d_o;
wire [1:0]	mul_state_d_o;
wire 	div_last_d_o;
wire 	d_advance_d_o;
wire 	d_init_d_o;
wire 	fin_d_o;
wire [20:0]	alu_op_d_o;
wire [31:0]	rs1_d_o;
wire [31:0]	rs2_d_o;
wire 	beq_d_o;
wire 	blt_d_o;
wire 	jalr_d_o;
wire [31:0]	pc_next_d_o;
wire 	compressed_d_o;
wire [2:0]	dmem_type_d_o;
wire [31:0]	extended_imm_d_o;
wire [31:0]	pc_plus4_d_o;
wire 	reg_write_en_d_o;
wire [4:0]	rd_idx_d_o;
wire [3:0]	result_src_d_o;
wire 	instr_illegal_d_o;
wire 	is_d_d_o;
wire 	is_m_d_o;
wire 	is_b_d_o;
wire 	is_j_d_o;
wire 	is_load_d_o;
wire 	dst_en_d_o;
wire 	fin_w_d_o;
wire 	pre_taken_d_o;
wire [4:0]	r_dst_d_o;
wire [4:0]	r_src1_d_o;
wire [4:0]	r_src2_d_o;


reg        enable                ;
reg [31:0] instruction_f_i       ;
reg [31:0] redirection_pc_e_i    ;
reg        redirection_e_i       ;
reg        pc_next_next_taken_e_i;
reg        reg_write_en_w_i      ;
reg [ 4:0] rd_idx_w_i            ;
reg [31:0] write_back_data_w_i   ;
reg        rs1_depended_h_i      ;
reg        flush_i               ;
reg [ 1:0] src1_sel_d_i          ;
reg [ 1:0] src2_sel_d_i          ;
reg [31:0] bypass_e_o            ;
reg [31:0] bypass_m_o            ;








pipelineID u_pipelineID(
	//ports
	.clk                    		( clk                    		),
	.resetn                 		( resetn                 		),
	.enable                 		( enable                 		),
	.instruction_f_i        		( instruction_f_i        		),
	.redirection_pc_e_i     		( redirection_pc_e_i     		),
	.redirection_e_i        		( redirection_e_i        		),
	.pc_next_next_taken_e_i 		( pc_next_next_taken_e_i 		),
	.reg_write_en_w_i       		( reg_write_en_w_i       		),
	.rd_idx_w_i             		( rd_idx_w_i             		),
	.write_back_data_w_i    		( write_back_data_w_i    		),
	.rs1_depended_h_i       		( rs1_depended_h_i       		),
	.flush_i                		( flush_i                		),
	.src1_sel_d_i           		( src1_sel_d_i           		),
	.src2_sel_d_i           		( src2_sel_d_i           		),
	.bypass_e_o             		( bypass_e_o             		),
	.bypass_m_o             		( bypass_m_o             		),
	.redirection_d_o        		( redirection_d_o        		),
	.taken_d_o              		( taken_d_o              		),
	.flush_jal_d_o          		( flush_jal_d_o          		),
	.is_compressed_d_o      		( is_compressed_d_o      		),
	.mul_state_d_o          		( mul_state_d_o          		),
	.div_last_d_o           		( div_last_d_o           		),
	.d_advance_d_o          		( d_advance_d_o          		),
	.d_init_d_o             		( d_init_d_o             		),
	.fin_d_o                		( fin_d_o                		),
	.alu_op_d_o             		( alu_op_d_o             		),
	.rs1_d_o                		( rs1_d_o                		),
	.rs2_d_o                		( rs2_d_o                		),
	.beq_d_o                		( beq_d_o                		),
	.blt_d_o                		( blt_d_o                		),
	.jalr_d_o               		( jalr_d_o               		),
	.pc_next_d_o            		( pc_next_d_o            		),
	.compressed_d_o         		( compressed_d_o         		),
	.dmem_type_d_o          		( dmem_type_d_o          		),
	.extended_imm_d_o       		( extended_imm_d_o       		),
	.reg_write_en_d_o       		( reg_write_en_d_o       		),
	.rd_idx_d_o             		( rd_idx_d_o             		),
	.result_src_d_o         		( result_src_d_o         		),
	.instr_illegal_d_o      		( instr_illegal_d_o      		),
	.is_d_d_o               		( is_d_d_o               		),
	.is_m_d_o               		( is_m_d_o               		),
	.is_b_d_o               		( is_b_d_o               		),
	.is_j_d_o               		( is_j_d_o               		),
	.is_load_d_o            		( is_load_d_o            		),
	.dst_en_d_o             		( dst_en_d_o             		),
	.fin_w_d_o              		( fin_w_d_o              		),
	.pre_taken_d_o          		( pre_taken_d_o          		),
	.r_dst_d_o              		( r_dst_d_o              		),
	.r_src1_d_o             		( r_src1_d_o             		),
	.r_src2_d_o             		( r_src2_d_o             		)
);

endmodule
