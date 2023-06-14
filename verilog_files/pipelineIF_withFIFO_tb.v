`include "pipelineIF_withFIFO.v"
module pipelineIF_withFIFO_tb();
reg     clk, resetn; 
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
        resetn    <= 1'b0;
    end
    if(count == 1) begin
        resetn    <= 1'b1;
    end
    if(count == 2) begin
        enable          <= 1'b1;
        flush_i         <= 1'h0;
        redirection_e_i <= 32'h0;
        taken_e_i       <= 1'h0;
        // redirection from ID
        redirection_d_i <= 32'h0;
        taken_d_i       <= 1'h1;
        // drain_cnt_d_i   <= 2'h0;
    end
    if(count == 3) begin
        taken_d_i       <= 1'h0;
        // drain_cnt_d_i   <= 2'h0;
    end
    if(count == 4) begin
        drain_cnt_d_i   <= 2'h2;
    end
    if(count == 5) begin
        drain_cnt_d_i   <= 2'h1;
    end
    if(count == 6) begin
        drain_cnt_d_i   <= 2'h0;
    end
    if(count == 7) begin
        drain_cnt_d_i   <= 2'h2;
    end
    if(count == 8) begin
        drain_cnt_d_i   <= 2'h1;
    end
    if(count == 9) begin
        taken_d_i       <= 1'b1;
        redirection_d_i <= 32'h2;
        // drain_cnt_d_i   <= 2'h0;
    end
    if(count == 10) begin
        taken_d_i       <= 1'h0;
    end
    if(count == 11) begin
        // drain_cnt_d_i   <= 2'h0;
        drain_cnt_d_i   <= 2'h2;
    end
    if(count == 12) begin
        enable <= 1'b0;
    end
    if(count == 13) begin
        enable <= 1'b1;
    end

    if(count == 20)
        $finish(0);
    count = count +1;
end

// =========================================================================
// ============================ testing =============================
// =========================================================================
wire [31:0]	instruction_f_o;
reg         enable;
reg  [31:0] redirection_d_i;
reg         taken_d_i      ;
reg  [ 1:0] drain_cnt_d_i  ;
reg  [31:0] redirection_e_i;
reg         taken_e_i      ;
reg         flush_i        ;


pipelineIF_withFIFO u_pipelineIF_withFIFO(
	//ports
	.clk             		( clk             		),
	.resetn          		( resetn          		),
	.enable          		( enable          		),
	.redirection_d_i 		( redirection_d_i 		),
	.taken_d_i       		( taken_d_i       		),
	.drain_cnt_d_i   		( drain_cnt_d_i   		),
	.redirection_e_i 		( redirection_e_i 		),
	.taken_e_i       		( taken_e_i       		),
	.flush_i         		( flush_i         		),
	.instruction_f_o 		( instruction_f_o 		)
);

initial begin
  //格式: readmemh(file, target, start, length)
  $readmemh("i-memory.txt", u_pipelineIF_withFIFO.u_imemory.u_memory_block0.m_array,0,15);
  $readmemh("i-memory.txt", u_pipelineIF_withFIFO.u_imemory.u_memory_block1.m_array,0,15);
end
// generate waveforms
integer k;
initial begin
  $dumpfile("pipelineIF_withFIFO_tb.vcd");
  $dumpvars(0, pipelineIF_withFIFO_tb);
  for(k=0;k<15;k++)begin
      $dumpvars(0, u_pipelineIF_withFIFO.u_imemory.u_memory_block0.m_array[k]);
  end
end
endmodule
