#====================================================================
# Makefile for testing MCU
# author: fujie
# time: Mon May 22 16:39:25 CST 2023
#====================================================================

.DEFAULT_GOAL := wave 
#====================================================================
# compile asm source file to get test cases for MCU 
# 1. the target folder is asm/generated
#  - dump file for re-assemble
#  - verilog file for machine code
#====================================================================
asmCode:
	@(cd asm && ./clean.sh && ./regen.sh && cd ..)


#====================================================================
# compile MCU rlt source code to get verilog DUT
#====================================================================
# copy source file before compile 
copy:
	@(rm -rf rtl/*.v && cp ../rtl/*.v rtl)

# simulate DUT, you'd better `make asmCode` first to generated machine code
sim:
	@(cd rtl && make sim)

# show waveform
wave:
	@(cd rtl && make waveform)
	
# regression test 
# TODO: implement in the future. 
# Because MCU can't pass even one test file in riscv-tests now!
# So we don't need to test the whole riscv-tests now.


#====================================================================
# clean intermediate files
#====================================================================
clean:
	@(cd asm && ./clean.sh && cd ../rtl/ && make clean)

# declare phone target
PHONY: clean wave sim copy asmCode
