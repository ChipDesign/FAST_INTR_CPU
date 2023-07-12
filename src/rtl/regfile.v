`ifndef __REGFILE__
`define __REGFILE__
/*
file: register file in ID stage
author: fujie
time: 2023年 4月28日 星期五 16时16分32秒 CST
*/
import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []); // add DPI-C function
module regfile 
    #(parameter REG_DATA_WIDTH      = 32,
      parameter REGFILE_ADDR_WIDTH  = 5,
      parameter REGFILE_DEPTH       = 32
      )
    (
    input  wire                              clk_i,
    input  wire                              resetn_i,

    output wire    [REG_DATA_WIDTH-1 :0]     rs1_data_o, // rd1
    output wire    [REG_DATA_WIDTH-1 :0]     rs2_data_o, // rd2
    
    input  wire    [REGFILE_ADDR_WIDTH-1 :0] rs1_addr_i, // address for rd1
    input  wire    [REGFILE_ADDR_WIDTH-1 :0] rs2_addr_i, // address for rd2
 
    input  wire    [REGFILE_ADDR_WIDTH-1 :0] rd_addr_i,  // address for write
    input  wire    [REG_DATA_WIDTH-1 :0]     rd_wr_data_i,// write data
    input  wire                              rd_wr_en_i // write enable
    );

    


// ===========================================================================
//                    Parameters, Registers, and Wires
// ===========================================================================    
    reg [REG_DATA_WIDTH-1:0] regfile_data [0: REGFILE_DEPTH-1]; // register file
    
   // =========================================================================
   // ============================ implementation =============================
   // ========================================================================= 
    
    integer i;
    // set all registers to 0 on initialization
    // initial begin
    //     for(i=0; i<REGFILE_DEPTH; i=i+1) begin
    //         regfile_data[i] = 0;
    //     end      
    // end
    // if resetn_i is asserted, reset all registers
    always @(posedge clk_i) begin 
        if(~resetn_i) begin
            for(i=0; i<REGFILE_DEPTH-1; i=i+1) begin
                regfile_data[i] <= 0;
            end      
        end
        
    end

    // If a register address is about to be written to and the data is needed
    // for the instruction currently in ID, place write data on output bus
    assign rs1_data_o = ((rs1_addr_i == rd_addr_i) &&
                         (rd_addr_i != 0) &&
                         (rd_wr_en_i))  
                         ? rd_wr_data_i : regfile_data[rs1_addr_i];
    assign rs2_data_o = ((rs2_addr_i == rd_addr_i) &&
                         (rd_addr_i != 0) &&
                         (rd_wr_en_i))     
                         ? rd_wr_data_i : regfile_data[rs2_addr_i];
    // synchronous process for writes
    always@(posedge clk_i) begin
        if((rd_wr_en_i) && (rd_addr_i != 0)) begin
                regfile_data[rd_addr_i] <= rd_wr_data_i;
        end
    end 

    initial set_gpr_ptr(regfile_data);
    
endmodule
`endif
