TOPNAME = top
INC_PATH ?=

VERILATOR = verilator
# VERILATOR_CFLAGS += -Wall --trace # write by myself
VERILATOR_CFLAGS +=  --trace # enable waveform 
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
# IMG ?=riscvtest/test.bin
# IMG ?=riscvtest/addi.bin
# IMG ?=riscvtest/slti.bin
# IMG ?=riscvtest/sltiu.bin
# IMG ?=riscvtest/xori.bin
# IMG ?=riscvtest/ori.bin
# IMG ?=riscvtest/andi.bin
# IMG ?=riscvtest/slli.bin
# IMG ?=riscvtest/srli.bin
# IMG ?=riscvtest/srai.bin
# IMG ?=riscvtest/auipc.bin
# IMG ?=riscvtest/lui.bin

# IMG ?=riscvtest/add.bin
# IMG ?=riscvtest/sub.bin
# IMG ?=riscvtest/slt.bin
# IMG ?=riscvtest/sltu.bin
# IMG ?=riscvtest/xor.bin
# IMG ?=riscvtest/or.bin
# IMG ?=riscvtest/and.bin
# IMG ?=riscvtest/sll.bin
# IMG ?=riscvtest/srl.bin
# IMG ?=riscvtest/sra.bin

# IMG ?=riscvtest/jalr.bin
# IMG ?=riscvtest/jal.bin
# IMG ?=riscvtest/beq.bin
# IMG ?=riscvtest/bne.bin
# IMG ?=riscvtest/blt.bin
# IMG ?=riscvtest/bge.bin
# IMG ?=riscvtest/bltu.bin
# IMG ?=riscvtest/bgeu.bin

IMG ?=riscvtest/lb.bin
# IMG ?=riscvtest/lh.bin
# IMG ?=riscvtest/lw.bin
# IMG ?=riscvtest/lbu.bin
# IMG ?=riscvtest/lhu.bin
# IMG ?=riscvtest/sb.bin
# IMG ?=riscvtest/sh.bin
# IMG ?=riscvtest/sw.bin

# IMG ?=riscvtest/div.bin
# IMG ?=riscvtest/divu.bin
# IMG ?=riscvtest/mul.bin
# IMG ?=riscvtest/mulh.bin
# IMG ?=riscvtest/mulhsu.bin
# IMG ?=riscvtest/mulhu.bin
# IMG ?=riscvtest/rem.bin
# IMG ?=riscvtest/remu.bin

ARGS_DIFF = --diff=so/riscv32-spike-so
# ARGS_DIFF = --diff=/home/fujie/Developer/git_repos/diff/demo2/nemu/tools/spike-diff/build/riscv32imc-spike-so
# ARGS_DIFF = --diff=/so/riscv64-spike-so

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

# asm = addi slti sltiu xori ori andi slli srli srai auipc lui \
#       add sub slt slt xor or and sll srl sra \
#       jalr jal beq bne blt bge bltu bgeu \

  asm = lb lh lw lbu lhu sb sh sw \
	  
# div divu mul mulh mulhsu mulhu rem remu
#       rvc
# asm=mul

image_path=./riscvtest/
result= $(addprefix ${image_path}, ${asm})
asm_images=${addsuffix .bin, ${result}}

test_all: $(BIN_ALL)
	@echo "==========make test_all =============="
	@echo "==========make test_all =============="
	@echo "==========make test_all =============="
	@-rm -rf result.log
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
MCU_SRC_DIR = ../rtl
VSRC_DIR ?=./vsrc
MCU_FILES = $(shell find $(MCU_SRC_DIR) -name "*.v" -or -name "*.vh") 
MCU_RTL=$(filter-out %tb.v, $(MCU_FILES))
install:
	@echo "Copy RTL codes to verification folder"
	cp ${MCU_RTL} ${VSRC_DIR}
# <<< install files from MCU_HOME <<< 
# >>> uninstall files from MCU_HOME >>>
uninstall:
	@echo "remove mcu rtl files from "
	-rm ${VSRC_DIR}/*
copy_back:
	@echo "copy verified files back to rtl folder"
	cp ${VSRC_DIR}/* ${MCU_SRC_DIR}
waveform:
	gtkwave dump.vcd &
# <<< uninstall files from MCU_HOME <<< 

.PHONY: default all clean run sim install uninstall gdb copy_back waveform
