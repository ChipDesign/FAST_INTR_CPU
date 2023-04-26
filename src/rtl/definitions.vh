`ifndef definitions
`define definitions
    // Instruction Types
    `define Error_Type        3'b000
    `define R_Type            3'b001
    `define I_Type            3'b010

    // ALU Operations
    `define ALU_ADD           5'b00000
    `define ALU_ADDI          5'b00001
    `define ALU_SUB           5'b00010
    `define ALU_Op_Error      5'b11111

    // MEMORY STORE/LOAD MASK SELECT
    `define MEM_LB            4'b0000
    `define MEM_LH            4'b0001
    `define MEM_LW            4'b0010
    `define MEM_LB_U          4'b0011
    `define MEM_LH_U          4'b0100
    `define MEM_SB            4'b0101
    `define MEM_SH            4'b0110
    `define MEM_SW            4'b0111
    `define NO_MEM            4'b1000

    // 32 bits Instruction OP code type 
    `define OPCODE_OP_IMM   7'b0010011
    `define OPCODE_LOAD     7'b0000011
    `define OPCODE_STORE    7'b0100011
    `define OPCODE_JAL      7'b1101111
    `define OPCODE_LUI      7'b0110111
    `define OPCODE_OP       7'b0110011
    `define OPCODE_BRANCH   7'b1100011
    `define OPCODE_JALR     7'b1100111

`endif
