#include "obj_dir/Vshifter4.h" // dut(device under test) header file
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>    // used for time(NULL) function
#include <stdio.h>  // used for input/output
#include <stdlib.h> // used for srand and rand function
#include <verilated.h>
#include <verilated_vcd_c.h>

#define SHOW_PRINT 0
#define DEBUG_ONCE 0
int main(int argc, char *argv[], char **env) {

  srand(time(NULL));
  VerilatedContext *contextp = new VerilatedContext;
  VerilatedVcdC *vcdTrace = new VerilatedVcdC; // vcd object pointer
  Vshifter4 *dut = new Vshifter4{contextp};
  int d_in, shift, leftOrRight, arithOrLogic;
  bool error = false;

  contextp->commandArgs(argc, argv);
  contextp->traceEverOn(true);    // turn on trace function
  dut->trace(vcdTrace, 0);        // set trace object and level
  vcdTrace->open("waveform.vcd"); // set vcd file name

#if DEBUG_ONCE
  // handcraft test data
  d_in = 0x5;
  shift = 0x3;
  leftOrRight = 0x0;
  arithOrLogic = 0x1;
#endif // DEBUG_ONCE
  // while (!contextp->gotFinish()) {
  while (contextp->time() < 100) { // stop after 100 cycle
#if !DEBUG_ONCE                    // generate random test data
    d_in = rand() & 0xf;
    shift = rand() & 0x3;
    leftOrRight = rand() & 0x1;
    arithOrLogic = 1;
#endif // ~DEBUG_ONCE

    // drive data into dut
    dut->d_in = d_in;
    dut->shift = shift;
    dut->arithOrLogic = arithOrLogic;
    dut->leftOrRight = leftOrRight;
    dut->eval(); // evaluates all the signal in the dut
    // printf("a = 0x%x, b = 0x%x, f = 0x%x\n", a, b, dut->d_out);

    vcdTrace->dump(contextp->time()); // write all the traced signal values into
                                      // the waveform file
    contextp->timeInc(1);             // increate time by 1 clock

    // assert(dut->f==(a^b)); // checker
#if SHOW_PRINT
    if ((leftOrRight && dut->d_out == ((d_in >> shift) & 0xf)) ||
        (~leftOrRight && dut->d_out == ((d_in << shift) & 0xf))) {
      printf("PASS: shift=0x%x, leftOrRight= %d, d_in= 0x%x, dout= 0x%x\n",
             shift, leftOrRight, d_in, dut->d_out);
    } else {
      printf("FAIL: shift=0x%x, leftOrRight= %d, d_in= 0x%x, dout= 0x%x\n",
             shift, leftOrRight, d_in, dut->d_out);
    }
#endif // SHOW_PRINT
       // check if dut is correct
    if ((leftOrRight && dut->d_out == ((d_in >> shift) & 0xf)) ||
        (~leftOrRight && dut->d_out == ((d_in << shift) & 0xf))) {
      error = false;
    } else {
      error = true;
      // break;
    }
  }
  delete dut;
  vcdTrace->close();
  delete contextp;

  if (error)
    printf("TEST FAIL\n");
  else
    printf("TEST PASS\n");
  return 0;
}
