# =========================================================================
# ======================== makefile source files ==========================
# =========================================================================
# rtlTop is used for rtl source file, asmSrc is used for ams source file
rtlTop = top
asmSrc = asm
rtlFiles = $(wildcard *.v)

# =========================================================================
# =========================== makefile config =============================
# =========================================================================
# gdb config
GDBINIT = ./gdbinit

# compile rules
# CROSS_COMPILE = riscv64-unknown-elf-   <- for macos and school server
CROSS_COMPILE = riscv64-linux-gnu-
# CFLAGS = -nostdlib -fno-builtin -march=rv32imac -mabi=ilp32 -g -Wall
CFLAGS = -nostdlib -fno-builtin -march=rv32ima -mabi=ilp32 -g -Wall

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

.PHONY: clean vvp sim waveform all run debug code hex asmClean
# make assemble code targets
all:
	@${CC} ${CFLAGS} ${asmSrc}.s -Ttext=0x80000000 -o ${asmSrc}.elf
	@${OBJCOPY} -O binary ${asmSrc}.elf ${asmSrc}.bin

# get pure machine code of asm file
machine: all 
	@${OBJDUMP} -D --section .text ${asmSrc}.elf | grep '[0-9a-f]:'|grep -v 'file' | cut -d: -f2| cut -d" " -f1 | sed 's/^\t *//g' > i-memory.txt
	@echo "Finish generating pure machine code to i-memory.txt"

verilog: all
	${OBJCOPY} -O verilog ${asmSrc}.bin ${asmSrc}.verilog
	@echo "Finish get verilog files"
	
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
	@${OBJDUMP} -S ${asmSrc}.elf > ${asmSrc}.dump 

# convert binary file into hex file for easy reading by human
hex: all
	@hexdump -C ${asmSrc}.bin

# clean all trash files when compiling asm file
asmClean:
	@-rm -rf *.o *.bin *.elf *.dump *.hex

# compile rtl source code to get executable file vpp target
vvp:
	@iverilog -o ${rtlTop}_tb.vvp ${rtlTop}_tb.v # @ means don't echo this command to terminal, just rtlRun it.
	@echo "Finish compiling RTL source codes"

# rtl simulation
sim: vvp
	@vvp ${rtlTop}_tb.vvp > simulation.log
	@echo "Finish rtl simulation, get simulation result in simulation.log"

# show waveform in gtkwave
waveform: sim 
	@gtkwave ${rtlTop}_tb.vcd -a gtkwave_setup.gtkw &

# clean all rtl and asm trash files
clean: asmClean
	@-rm -rf *.vcd *.vvp *.log
	@echo "Finish clean all rtl and asm intermediate files"
