include $(AM_HOME)/scripts/isa/riscv32.mk

AM_SRCS := riscv/fic/start.S \
           riscv/fic/trm.c \
           riscv/fic/ioe.c \
           riscv/fic/timer.c \
           riscv/fic/input.c \
           riscv/fic/cte.c \
           riscv/fic/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"
NEMUFLAGS += -l $(shell dirname $(IMAGE).elf)/fic-log.txt
.PHONY: $(AM_HOME)/am/src/riscv/fic/trm.c

image: $(IMAGE).elf
	@$(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@$(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin

run: image
	$(MAKE) -C $(FIC_HOME) run ARGS="$(NEMUFLAGS)" IMG=$(IMAGE).bin