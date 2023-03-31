`include "definitions.vh"
module decoder(
  input wire [31:0] instructionD,
  output reg [4:0] aluOperation,
  output reg regWriteEnD
);

  wire [4:0] opcode;
  wire [2:0] funct3;
  wire funct7;

  reg [2:0] instructionType;

  assign opcode = instructionD[6:2];
  assign funct3 = instructionD[14:12];
  assign funct7 = instructionD[30];

  always@(*)begin
    case(opcode)
      5'b01100: instructionType = `R_Type;
      5'b00100: instructionType = `I_Type;
      default: instructionType = `Error_Type;
    endcase
    case(instructionType)
      `R_Type: begin
        case(funct3)
          3'b000: begin
              case(funct7)
                1'b0: aluOperation = `ALU_ADD;
                1'b1: aluOperation = `ALU_SUB;
              endcase
            end
          default: aluOperation = `ALU_Op_Error;
        endcase
        regWriteEnD = 1'b1;
      end
      `I_Type: begin
        case(funct3)
          3'b000: aluOperation = `ALU_ADDI;
          default : aluOperation = `ALU_Op_Error;
        endcase
        regWriteEnD = 1'b1;
      end
      default: begin
        aluOperation = `ALU_Op_Error;
        regWriteEnD = 1'b0;
      end
    endcase
  end

endmodule
