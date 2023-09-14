EXEC = test
# EXEC = fence_i
# EXEC = andi
# EXEC = ori
# EXEC = xori
# EXEC = addi
# EXEC = lui
# EXEC = slti
# EXEC = sltiu
# EXEC = slli
# EXEC = srli
# EXEC = srai

# EXEC = add
# EXEC = sub
# EXEC = slt
# EXEC = sltu
# EXEC = xor
# EXEC = or
# EXEC = and
# EXEC = sll
# EXEC = srl
# EXEC = sra

# EXEC = jalr
# EXEC = jal
# EXEC = beq
# EXEC = bne
# EXEC = blt
# EXEC = bge
# EXEC = bltu
# EXEC = bgeu

# EXEC = lb
# EXEC = lh
# EXEC = lw
# EXEC = lbu
# EXEC = lhu
# EXEC = sb
# EXEC = sh
# EXEC = sw

# EXEC = div
# EXEC = divu
# EXEC = mul
# EXEC = mulh
# EXEC = mulhsu
# EXEC = mulhu
# EXEC = rem
# EXEC = remu
# EXEC = rvc

# default to compile all file into bin file
SRC = ${EXEC}.S

GDBINIT = ../gdbinit

include rule.mk

# compile all files
# lb lh lw lbu lhu sb sh sw 
# ASM= addi slti sltiu xori ori andi slli srli srai auipc lui\
# 	 add sub slt sltu xor or and sll srl sra\
# 	 jalr jal beq bne blt bge bltu bgeu\

ASM=div divu mul mulh mulhsu mulhu rem remu rvc

getAll:
	@echo "Compile all ASM files"
	@echo ${ASM}
	for i in ${ASM}; do \
		# echo $$i;	\
		${CC} ${CFLAGS} $$i.S -Ttext=0x80000000 -o $$i.elf;\
		${OBJCOPY} -O binary $$i.elf $$i.bin; \
	done
