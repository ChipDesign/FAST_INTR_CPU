# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vtop.mk

default: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/build/top_all

### Constants...
# Perl executable (from $PERL)
PERL = perl
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?= 
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?= 

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Design prefix (from --prefix)
VM_PREFIX = Vtop
# Module prefix (from --prefix)
VM_MODPREFIX = Vtop
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
	-g \
	-I/home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/include \
	-DTOP_NAME="Vtop" \
	-I/usr/lib/llvm-14/include \
	-std=c++14 \
	-fno-exceptions \
	-D_GNU_SOURCE \
	-D__STDC_CONSTANT_MACROS \
	-D__STDC_FORMAT_MACROS \
	-D__STDC_LIMIT_MACROS \
	-fPIE \
	-D \
	TEST_ALL \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
	-lreadline \
	-lLLVM-14 \
	-ldl \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
	npc_exec \
	npc_memory \
	disasm \
	npc_difftest \
	npc_main \
	npc_monitor \
	npc_sdb \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
	/home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc \
	/home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_cpu \
	/home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_difftest \
	/home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_monitor \


### Default rules...
# Include list of all generated classes
include Vtop_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

npc_exec.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_cpu/npc_exec.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
npc_memory.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_cpu/npc_memory.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
disasm.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_difftest/disasm.cc
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
npc_difftest.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_difftest/npc_difftest.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
npc_main.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_main.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
npc_monitor.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_monitor/npc_monitor.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<
npc_sdb.o: /home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/csrc/npc_monitor/npc_sdb.c
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST) -c -o $@ $<

### Link rules... (from --exe)
/home/fujie/Developer/git_repos/FAST_INTR_CPU/src/verification/build/top_all: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_HIER_LIBS)
	$(LINK) $(LDFLAGS) $^ $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@


# Verilated -*- Makefile -*-
