`include "decoder.v"
// `include "sprf1024x32m4b1_wem.v"
module decoder_tb(); 
    reg clk;

    reg  [31:0] instruction_i;
    wire [20:0] alu_op_o;
    wire rs1_sel_o, rs2_sel_o;
    wire [2:0] imm_type_o;
    wire beq, blt, branchBType_o, branchJAL_o, branchJALR_o;
    wire [2:0] dmem_type_o;
    wire [3:0] wb_src_o;
    wire wb_en_o;
    wire instr_illegal_o;
    
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
            instruction_i <= 32'h00400093; // addi x1, x0, 4    
        end
        if(count == 1) begin
            instruction_i <= 32'hfe628ee3; // beq x5, x6, _start    
        end
        if(count == 2) begin
            instruction_i <= 32'hfe629ee3; // beq x5, x6, _start    
        end
        if(count == 3) begin
            instruction_i <= 32'hfe62cee3; // blt x5, x6, _start    
        end
        if(count == 4) begin
            instruction_i <= 32'hfe62eee3; // bltu x5, x6, _start    
        end
        if(count == 5) begin
            instruction_i <= 32'hfe62dee3; // bge x5, x6, _start    
        end
        if(count == 6) begin
            instruction_i <= 32'hfe62fee3; // bgeu x5, x6, _start    
        end
        
        
        
        if(count == 20)
            $finish(0);
        count = count +1;

        $display("data is %h", u_decoder.alu_calculation );
    end

    // =========================================================================
    // ============================ testing =============================
    // =========================================================================
    decoder u_decoder(
       .instruction_i(instruction_i), 
       .alu_op_o(alu_op_o),
       .rs1_sel_o(rs1_sel_o), 
       .rs2_sel_o(rs2_sel_o), 
       .imm_type_o(imm_type_o),
       .branchBType_o(branchBType_o), 
       .branchJAL_o(branchJAL_o),
       .branchJALR_o(branchJALR_o),
       .dmem_type_o(dmem_type_o), 
       .wb_src_o(wb_src_o), 
       .wb_en_o(wb_en_o),  
       .instr_illegal_o(instr_illegal_o)
    );
    

    // generate waveforms
    initial begin
      $dumpfile("decoder_tb.vcd");
      $dumpvars(0, decoder_tb);
    end

endmodule
