`ifndef __DEFINITIONS__
`define __DEFINITIONS__

    // enable DIFFTEST 
    `define DIFFTEST

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
    `define OPCODE_LOAD     7'b0000011
    `define OPCODE_OP_IMM   7'b0010011
    `define OPCODE_AUIPC    7'b0010111
    `define OPCODE_STORE    7'b0100011
    `define OPCODE_RTYPE    7'b0110011
    `define OPCODE_LUI      7'b0110111
    `define OPCODE_BRANCH   7'b1100011
    `define OPCODE_JALR     7'b1100111
    `define OPCODE_JAL      7'b1101111
    `define OPCODE_SYSTEM   7'b1110011
    `define OPCODE_ERROR    7'b1111111

    // Immdiate type in Instruction
    `define IMM_U           3'b000
    `define IMM_J           3'b001
    `define IMM_I           3'b010
    `define IMM_B           3'b100
    `define IMM_S           3'b101
    `define IMM_NO          3'b110

    // ALU Operations types
    `define ALUOP_ADD         18'h00001
    `define ALUOP_SUB         18'h00002
    `define ALUOP_SLL         18'h00004
    `define ALUOP_SRL         18'h00008
    `define ALUOP_SRA         18'h00010
    `define ALUOP_OR          18'h00020
    `define ALUOP_AND         18'h00040
    `define ALUOP_XOR         18'h00080
    `define ALUOP_SLT         18'h00100 
    `define ALUOP_SLTU        18'h00200 
    `define ALUOP_MUL         18'h00400 
    `define ALUOP_MULH        18'h00800 
    `define ALUOP_MULHU       18'h01000 
    `define ALUOP_MULHSU      18'h02000 
    `define ALUOP_DIV         18'h04000 
    `define ALUOP_DIVU        18'h08000 
    `define ALUOP_REM         18'h10000 
    `define ALUOP_REMU        18'h20000 

    // alu source seletct
    `define RS1SEL_RF       1'b0 
    `define RS1SEL_PC       1'b1 
    `define RS2SEL_RF       1'b0 
    `define RS2SEL_IMM      1'b1 

    // write back source
    `define WBSRC_ALU      4'b0001 
    `define WBSRC_IMM      4'b0010
    `define WBSRC_MEM      4'b0100
    `define WBSRC_PC       4'b1000

    // data memory type
    `define DMEM_SB  4'b0001
    `define DMEM_SH  4'b0010
    `define DMEM_SW  4'b0011
    `define DMEM_LB  4'b0100
    `define DMEM_LH  4'b0101
    `define DMEM_LW  4'b0110
    `define DMEM_LBU 4'b0111
    `define DMEM_LHU 4'b1000
    `define DMEM_NO  4'b0000
`endif
