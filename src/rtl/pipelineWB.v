`ifndef __PIPELINEWB__
`define __PIPELINEWB__
module pipelineWB (
  input wire clk,
  input wire resetn,
  
  input wire regWriteEnM,
  input wire [1:0] resultSrcM,
  input wire [31:0] aluResultM,
  input wire [31:0] memReadDataM, // delared as wire, becased the D-memory has 1 cycle delay when reading
  input wire [4:0] rdM,

  output reg regWriteEnW,
  output reg [4:0] rdW,
  output reg [31:0] writeBackDataW
);


always@(posedge clk)begin 
  if(~resetn)begin
    regWriteEnW <= 0;
    rdW <=0;
    writeBackDataW <= 0;
  end
  else begin 
    regWriteEnW <= regWriteEnM;
    rdW <= rdM;
    if(resultSrcM === 2'b00) begin  // alu for resutl
      writeBackDataW <= aluResultM;
    end
    else begin  // load/store for result
      writeBackDataW <= memReadDataM;
    end
  end

end
endmodule
`endif
