##include ../Makefile # fujie: comment this

# TOPNAME = ysyx_22040663_top
TOPNAME = top
INC_PATH ?=

VERILATOR = verilator
# VERILATOR_CFLAGS += -Wall --trace # write by myself
VERILATOR_CFLAGS +=  --trace # write by myself
VERILATOR_CFLAGS += -MMD --build -cc --trace\
	-O3 --x-assign fast --x-initial fast --noassert

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

# project source
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

INCV_PATH = $(abspath ./vsrc)
INC_PATH += $(abspath ./csrc/include)

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CFLAGS += -g $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""
# LDFLAGS += -lSDL2 -lSDL2_image

# connect to the `readline' library
LDFLAGS += -lreadline

#connect to llvm
CFLAGS += $(shell llvm-config --cxxflags) -fPIE
LDFLAGS += $(shell llvm-config --libs)

LDFLAGS += -ldl

# ARGS ?=/home/fujie/Developer/git_repos/diff/demo2/npc/build/top

# Command to execute NPC
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/test.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/addi.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/slti.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sltiu.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/xori.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/ori.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/andi.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/slli.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/srli.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/srai.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/auipc.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/lui.bin

# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/add.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sub.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/slt.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sltu.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/xor.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/or.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/and.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sll.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/srl.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sra.bin

# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/jalr.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/jal.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/beq.bin
IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/bne.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/blt.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/bge.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/bltu.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/bgeu.bin

# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/lb.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/lh.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/lw.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/lbu.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/lhu.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sb.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sh.bin
# IMG ?=/home/fujie/Developer/git_repos/riscv-operating-system-mooc/code/asm/riscvtest/sw.bin

ARGS_DIFF = --diff=so/riscv32-spike-so
# ARGS_DIFF = --diff=./so/riscv64-spike-so
# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/ysyx/ysyx-workbench/nemu/tools/spike-diff/build/riscv32-spike-so
# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/diff/riscv64-spike-so

# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/diff/riscv64-spike-so
# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/diff/so/nemu/tools/spike-diff/build/spike-so
# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/diff/so/shifeng/nemu/tools/spike-diff/build/riscv32-spike-so
# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/diff/xs-env/NEMU/build/riscv64-nemu-interpreter-so

# ARGS_DIFF = --diff=/home/s/ysyx-workbench/nemu/build/riscv64-nemu-interpreter-so

$(BIN): $(VSRCS) $(CSRCS)
	@echo "==========make bin =============="
	@echo "==========make bin =============="
	@echo "==========make bin =============="
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ -I$(INCV_PATH) \
		$(addprefix -CFLAGS , $(CFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		$(addprefix -LIBS, $(LIBS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))

run: $(BIN)
	@echo "==========make run =============="
	@echo "==========make run =============="
	@echo "==========make run =============="
	$^ $(ARGS) $(ARGS_DIFF) $(IMG)

# TEST_ALL >>>>>>>>>>>>>>>>
BIN_ALL = $(BUILD_DIR)/$(TOPNAME)_all
${BIN_ALL}: $(VSRCS) $(CSRCS)
	@echo "==========make bin_all =============="
	@echo "==========make bin_all =============="
	@echo "==========make bin_all =============="
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ -I$(INCV_PATH) \
		$(addprefix -CFLAGS , $(CFLAGS)) \
		$(addprefix -CFLAGS , -D TEST_ALL) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		$(addprefix -LIBS, $(LIBS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN_ALL))

asm = addi slti sltiu xori ori andi slli srli srai auipc lui \
      add sub slt slt xor or and sll srl sra \
      jalr jal beq bne blt bge bltu bgeu \
      lb lh lw lbu lhu sb sh sw \
#div divu divuw divw mul mulh mulhsu mulhu mulw rem remu remuw remw \
#rvc 

image_path=./riscvtest/
result= $(addprefix ${image_path}, ${asm})
asm_images=${addsuffix .bin, ${result}}

test_all: $(BIN_ALL)
	@echo "==========make test_all =============="
	@echo "==========make test_all =============="
	@echo "==========make test_all =============="
	@-rm result.log
	for i in ${asm_images}; do $^ $(ARGS) $(ARGS_DIFF) $${i}; done
# TEST_ALL >>>>>>>>>>>>>>>>

gdb:
# gdb ./build/top --args $(ARGS) $(ARGS_DIFF)
	@echo "==========make gdb =============="
	@echo "==========make gdb =============="
	@echo "==========make gdb =============="
	gdb -s build/top args build/top 
	
all:default
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "Write this Makefile by your self."

clean:
	rm -rf $(BUILD_DIR)

# >>> install files from MCU_HOME >>>
MCU_HOME ?=/home/fujie/Developer/git_repos/FAST_INTR_CPU
MCU_SRC_DIR = ${MCU_HOME}/src/rtl
VSRC_DIR ?=./vsrc
MCU_FILES = $(shell find $(MCU_SRC_DIR) -name "*.v" -or -name "*.vh") 
MCU_RTL=$(filter-out %tb.v, $(MCU_FILES))
install:
	@echo "copy mcu rtl files from Fast_Interrupt_MCU"
	@cp ${MCU_RTL} ${VSRC_DIR}
# <<< install files from MCU_HOME <<< 
# >>> uninstall files from MCU_HOME >>>
uninstall:
	@echo "remove mcu rtl files from "
	@-rm ${VSRC_DIR}/*
# <<< uninstall files from MCU_HOME <<< 

.PHONY: default all clean run sim install uninstall gdb
