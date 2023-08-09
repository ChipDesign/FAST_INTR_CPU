module simpleDUT (
  input wire in,
  output wire out
);

  reg [31:0] memory[15:0]; // a 16*32 memory
  assign out=in+1;
  
endmodule
