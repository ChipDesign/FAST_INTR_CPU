# =========================================================================
# ======================== makefile source files ==========================
# =========================================================================
# rtlTop is used for rtl source file
rtlTop = top
rtlFiles = $(wildcard *.v)
machineCodes = test

# =========================================================================
# =========================== makefile targets ============================
# =========================================================================

.PHONY: vvp sim waveform  clean
# compile rtl source code to get executable file vpp target
# TODO: add dependency to avoid unessary compile
vvp:
	@iverilog -o ${rtlTop}_tb.vvp ${rtlTop}_tb.v # @ means don't echo this command to terminal, just run it.
	@echo "Finish compiling RTL source codes"

# rtl simulation
# (cd ../asm && cat ${machineCodes}.verilog > i-memory.txt && cd ../rtl/)
sim: vvp
	@vvp ${rtlTop}_tb.vvp > simulation.log
	@echo "Finish rtl simulation, get simulation result in simulation.log"

# show waveform in gtkwave
waveform: sim
	@gtkwave ${rtlTop}_tb.vcd -a gtkwave_setup.gtkw &
	@echo "Finish showing waveform in gtkwave"

# clean all rtl and asm trash files
clean:
	@-rm -rf *.vcd *.vvp *.log *.hex
	@echo "Finish cleaning"
