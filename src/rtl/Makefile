# =========================================================================
# ======================== makefile source files ==========================
# =========================================================================
# rtlSrc is used for rtl source file, asmSrc is used for ams source file
rtlSrc = decoder
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
	@${CC} ${CFLAGS} ${asmSrc}.s -Ttext=0x80000000 -o ${EXEC}.elf
	@${OBJCOPY} -O binary ${EXEC}.elf ${EXEC}.bin

run: all
	@echo "Press Ctrl-A and then X to exit QEMU"
	@echo "------------------------------------"
	@echo "No output, please run 'make debug' to see details"
	@${QEMU} ${QFLAGS} -kernel ./${EXEC}.elf

debug: all
	@echo "Press Ctrl-C and then input 'quit' to exit GDB and QEMU"
	@echo "-------------------------------------------------------"
	@${QEMU} ${QFLAGS} -kernel ${EXEC}.elf -s -S &
	@${GDB} ${EXEC}.elf -q -x ${GDBINIT}

code: all
	@${OBJDUMP} -S ${EXEC}.elf | less

hex: all
	@hexdump -C ${EXEC}.bin

asmClean:
	@-rm -rf *.o *.bin *.elf

# make rtl code targets
# DEFAULT_GOAL:=rtlAll
rtlAll: ${rtlSrc}.v ${rtlSrc}_tb.v
	@iverilog -o ${rtlSrc}_tb.vvp ${rtlSrc}_tb.v # @ means don't echo this command to terminal, just rtlRun it.

rtlRun: rtlAll 
	vvp ${rtlSrc}_tb.vvp

waveform: rtlRun
	@gtkwave ${rtlSrc}_tb.vcd -a gtkwave_setup.gtkw

clean: asmClean
	@echo "clean all rtl and asm intermediate files finish"
	@-rm -rf *.vcd *.vvp
