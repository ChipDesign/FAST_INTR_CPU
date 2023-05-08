# =========================================================================
# ======================== makefile source files ==========================
# =========================================================================
# rtlSrc is used for rtl source file, asmSrc is used for ams source file
rtlSrc = top
asmSrc = test

# =========================================================================
# =========================== makefile config =============================
# =========================================================================
# gdb config
GDBINIT = ./gdbinit

# compile rules
CROSS_COMPILE = riscv64-unknown-elf-
CFLAGS = -nostdlib -fno-builtin -march=rv32ima -mabi=ilp32 -g -Wall
# CFLAGS = -nostdlib -fno-builtin -march=rv32imac -mabi=ilp32 -g -Wall

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 1 -machine virt -bios none

GDB = riscv64-unknown-elf-gdb
# GDB = gdb-multiarch
CC = ${CROSS_COMPILE}gcc
OBJCOPY = ${CROSS_COMPILE}objcopy
OBJDUMP = ${CROSS_COMPILE}objdump


# =========================================================================
# =========================== makefile targets ============================
# =========================================================================

.PHONY: rtlClean rtlAll rtlRun waveform all run debug code hex clean
# make assemble code targets
all:
	@${CC} ${CFLAGS} ${asmSrc}.s -Ttext=0x80000000 -o ${asmSrc}.elf
	@${OBJCOPY} -O binary ${asmSrc}.elf ${asmSrc}.bin

# get pure machine code of asm file
machine: all 
	@echo "Finish generating pure machine code to i-memory.txt"
	@${OBJDUMP} -D --section .text ${asmSrc}.elf | grep '[0-9a-f]:'|grep -v 'file' | cut -d: -f2| cut -d" " -f1 | sed 's/^\t *//g'> i-memory.txt
	
run: all
	@echo "Press Ctrl-A and then X to exit QEMU"
	@echo "------------------------------------"
	@echo "No output, please run 'make debug' to see details"
	@${QEMU} ${QFLAGS} -kernel ./${asmSrc}.elf

debug: all
	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel ${asmSrc}.elf -s -S &
	@${GDB} ${asmSrc}.elf -q -x ${GDBINIT}

# get assemble code from binary codes
code: all
	@${OBJDUMP} -S ${asmSrc}.elf | less

# convert binary file into hex file for easy reading by human
hex: all
	@hexdump -C ${asmSrc}.bin

# clean all trash files when compiling asm file
asmClean:
	@-rm -rf *.o *.bin *.elf

# compile rtl source code to get executable file 
rtlAll: ${rtlSrc}.v ${rtlSrc}_tb.v
	@iverilog -o ${rtlSrc}_tb.vvp ${rtlSrc}_tb.v # @ means don't echo this command to terminal, just rtlRun it.

# rtl simulation
rtlRun: rtlAll machine
	vvp ${rtlSrc}_tb.vvp

# show waveform in gtkwave
waveform: rtlRun
	@gtkwave ${rtlSrc}_tb.vcd -a gtkwave_setup.gtkw

# clean all rtl and asm trash files
clean: asmClean
	@echo "Finish clean all rtl and asm intermediate files"
	@-rm -rf *.vcd *.vvp
