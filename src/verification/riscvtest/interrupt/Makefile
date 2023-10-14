CROSS_COMPILE = riscv64-unknown-elf-
# CFLAGS = -nostdlib -fno-builtin -march=rv32g -mabi=ilp32 -g -Wall
CFLAGS = -nostdlib -fno-builtin -march=rv32ima -mabi=ilp32 -g -Wall

QEMU = qemu-system-riscv32
QFLAGS = -nographic -smp 1 -machine virt -bios none

GDB = gdb-multiarch
CC = ${CROSS_COMPILE}gcc
OBJCOPY = ${CROSS_COMPILE}objcopy
OBJDUMP = ${CROSS_COMPILE}objdump




.DEFAULT_GOAL := all
all: os.elf

SRCS_ASM = \
	trap.S \
	test.S

# OBJS = $(SRCS_ASM:.S=.o)
OBJS = test.S

# start.o must be the first in dependency!
# ${CC} ${CFLAGS} -o os.elf $^
os.elf: ${OBJS}
	${CC} ${CFLAGS} -T os.ld -o os.elf $^
	${OBJCOPY} -O binary os.elf os.bin

%.o : %.S
	${CC} ${CFLAGS} -c -o $@ $<

.PHONY : code
code: all
	@${OBJDUMP} -S os.elf | nvim
.PHONY : clean
clean:
	rm -rf *.o *.bin *.elf
