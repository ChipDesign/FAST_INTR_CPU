# Verilator example makefile
# Norbertas Kremeris 2021
MODULE=pipelineMEM

.PHONY:sim
sim: getWaveform

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/V$(MODULE)

.PHONY:waves
waves: getWaveform
	@echo "### WAVES ###"
	gtkwave $(MODULE)_tb.vcd

getWaveform: ./obj_dir/V$(MODULE)
	@echo "### SIMULATING ###"
	./obj_dir/V$(MODULE) +verilator+rand+reset+2 

./obj_dir/V$(MODULE): .stamp.verilate
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(MODULE).v $(MODULE)_tb.cpp
	@echo "### VERILATING ###"
	# verilator -Wall --trace --x-assign unique --x-initial unique -cc $(MODULE).v --exe $(MODULE)_tb.cpp
	verilator -Wno-fatal --trace --x-assign unique --x-initial unique -cc $(MODULE).v --exe $(MODULE)_tb.cpp
	@touch .stamp.verilate

.PHONY:lint
lint: $(MODULE).v
	verilator --lint-only $(MODULE).v

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf getWaveform
