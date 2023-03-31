.PHONY: clean all run waveform

DEFAULT_GOAL:=all
all: ${src}.v ${src}_tb.v
	@iverilog -o ${src}_tb.vvp ${src}_tb.v # @ means don't echo this command to terminal, just run it.

run: all 
	vvp ${src}_tb.vvp

waveform: run
	@gtkwave ${src}_tb.vcd -a gtkwave_setup.gtkw

clean:
	-rm *vcd *vvp
