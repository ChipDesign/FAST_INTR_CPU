#include "obj_dir/VpipelineMEM.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

#define MAX_SIM_TIME 10
vluint64_t sim_time = 0;

// void dut_reset(VpipelineMEM *dut, vluint64_t sim_time) {
//   dut->resetn = 1;
//   if (sim_time > 3 && sim_time < 6) {
//     dut->resetn = 0; // reset dut
//     dut->in = 0;
//     dut->clk = 0;
//   }
// }

void clock_step(VpipelineMEM *dut, VerilatedVcdC *vcd, vluint64_t &sim_time) {
  dut->clk ^= 1;
  dut->eval();
  vcd->dump(sim_time);
  sim_time++;

  dut->clk ^= 1;
  dut->eval();
  vcd->dump(sim_time);
  sim_time++;
}
int main(int argc, char *argv[]) {
  VerilatedVcdC *vcd = new VerilatedVcdC;
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);

  VpipelineMEM *dut = new VpipelineMEM;
  dut->trace(vcd, 0);
  vcd->open("pipelineMEM_tb.vcd");

  // while (sim_time < MAX_SIM_TIME) {
  //
  //   // reset dut
  //   dut_reset(dut, sim_time);
  //
  //   dut->clk ^= 1;
  //   dut->eval();
  //
  //   std::cout << "clk= " << sim_time << std::endl;
  //   vcd->dump(sim_time);
  //   sim_time++;
  // }

  // reset test
  sim_time = 0;
  dut->resetn = 0;
  dut->clk = 1;
  clock_step(dut, vcd, sim_time);

  dut->resetn = 1;
  clock_step(dut, vcd, sim_time);

  clock_step(dut, vcd, sim_time);

  clock_step(dut, vcd, sim_time);

  clock_step(dut, vcd, sim_time);

  vcd->close();
  delete dut;
  // std::exit(EXIT_SUCCESS);
  return 0;
}
