#include "obj_dir/Vshifter32.h" // dut(device under test) header file
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>    // used for time(NULL) function
#include <stdio.h>  // used for input/output
#include <stdlib.h> // used for srand and rand function
#include <verilated.h>
#include <verilated_vcd_c.h>

#define SHOW_PRINT 0
#define DEBUG_RANDOM 0
#define MAX 0xffffffff
int main(int argc, char *argv[], char **env) {

  srand(time(NULL));
  VerilatedContext *contextp = new VerilatedContext;
  VerilatedVcdC *vcdTrace = new VerilatedVcdC; // vcd object pointer
  Vshifter32 *dut = new Vshifter32{contextp};
  int d_in, shift, leftOrRight, arithOrLogic;
  bool error = false, match = false;

  contextp->commandArgs(argc, argv);
  contextp->traceEverOn(true);    // turn on trace function
  dut->trace(vcdTrace, 0);        // set trace object and level
  vcdTrace->open("waveform.vcd"); // set vcd file name

  // while (!contextp->gotFinish()) {
  while (contextp->time() < 100) { // stop after 100 cycle
#if !DEBUG_RANDOM
    // handcraft test data
    d_in = 0xc2df962a;
    shift = 0x14;
    leftOrRight = 0x1;
    arithOrLogic = 0x1;
#endif           // DEBUG_RANDOM
#if DEBUG_RANDOM // generate random test data
    d_in = rand() & MAX;
    shift = rand() & 0x1f;
    leftOrRight = rand() & 0x1;
    arithOrLogic = rand() & 0x1;
#endif // ~DEBUG_RANDOM
    if (contextp->time() % 2) {
      d_in = -d_in; // make more random input data
    }

    // drive data into dut
    dut->d_in = d_in;
    dut->shift = shift;
    dut->arithOrLogic = arithOrLogic;
    dut->leftOrRight = leftOrRight;
    dut->eval(); // evaluates all the signal in the dut
    // printf("a = 0x%8x, b = 0x%8x, f = 0x%8x\n", a, b, dut->d_out);

    vcdTrace->dump(contextp->time()); // write all the traced signal values into
                                      // the waveform file
    contextp->timeInc(1);             // increate time by 1 clock

    // check if dut result match with expected result
    if (leftOrRight) {
      if (arithOrLogic) {
        // SRL
        if (dut->d_out == (((unsigned)d_in >> shift) & MAX)) {
          match = true;
        } else {
          match = false;
        }
      } else {
        // SRA
        if (dut->d_out == (((signed)d_in >> shift) & MAX)) {
          match = true;
        } else {
          match = false;
        }
      }
    } else {
      // SLL
      if (dut->d_out == ((d_in << shift) & MAX)) {
        match = true;
      } else {
        match = false;
      }
    }
    if (!match) { // in c++ `1` is logic inverse, `~` is bitwise reverse
      printf("mismatch\n");
      error = true;
    }

    // some printf for debug
#if SHOW_PRINT
    if (match) {
      if (arithOrLogic) // 1 for SRA
        printf("expected d_out = 0x%8x\n", ((unsigned)d_in >> shift) & MAX);
      else
        printf("expected d_out = 0x%8x\n", ((signed)d_in >> shift) & MAX);
      printf("PASS: shift= 0x%2x, leftOrRight= %d, arithOrLogic = %d, d_in= "
             "0x%8x, dout= 0x%8x\n",
             shift, leftOrRight, arithOrLogic, d_in, dut->d_out);
    } else {
      if (arithOrLogic) // 1 for SRA
        printf("expected d_out = 0x%8x\n", ((unsigned)d_in >> shift) & MAX);
      else
        printf("expected d_out = 0x%8x\n", ((signed)d_in >> shift) & MAX);
      printf("FAIL: shift= 0x%2x, leftOrRight= %d, arithOrLogic = %d, d_in= "
             "0x%8x, dout= 0x%8x\n",
             shift, leftOrRight, arithOrLogic, d_in, dut->d_out);
    }
#endif // SHOW_PRINT
  }    // end while


  // delete pointers to free memory
  delete dut;
  vcdTrace->close();
  delete contextp;

  if (error)
    printf("TEST FAIL\n");
  else
    printf("TEST PASS\n");
  return 0;
}
