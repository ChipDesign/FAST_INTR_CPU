/*VERILATOR INCLUDE*/
#include "verilated.h" // 核心头文件
#include "verilated_vcd_c.h" // 波形生成头文件
// #include "Vysyx_22040663_top.h" // verilator根据.v文件生成的头文件
#include "Vtop.h" // verilator根据.v文件生成的头文件

#include "svdpi.h" // verilator的DPI-C机制需要的头文件
#include "verilated_dpi.h"
// #include "Vysyx_22040663_top__Dpi.h" // verilator的DPI-C机制需要的头文件
#include "Vtop__Dpi.h" // verilator的DPI-C机制需要的头文件

/*SIMULATION INCLUDE*/
#include <npc_common.h>
#include <npc_memory.h>
#include <npc_cpu.h>
#include <npc_utils.h>
#include <stdio.h>
#include <npc_config.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

// 一个输出RTL中通用寄存器的值的示例
uint32_t *cpu_gpr = NULL;
void set_gpr_ptr(const svOpenArrayHandle r) {
  cpu_gpr = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());  
}
void dump_gpr() {
  for (int i = 0; i < 32; i++) {
    cpu.gpr[i] = cpu_gpr[i]; // i-1 to make index correct in DPI-C
  }
}
void display_gpr(int i) {
  printf("%s:\tgpr[%d]:\t0x%lx\n", regs[i], i, cpu.gpr[i]);
}

// Construct the Verilated model, from Vtop.h generated from Verilating "top.v"
// Vtop* top = new Vtop;
static Vtop* top;
NPCState npc_state = { .state = NPC_STOP };
CPU_state cpu;
uint64_t g_nr_guest_inst = 0;

// waveform
static VerilatedVcdC* tfp;
vluint64_t clk_time=0;
// waveform

// posedge of clock
void single_cycle() {
    // printf("DUT step one cycle, ID instr= 0x%x\n", top->id_instr);
    top->clk = 0; top->eval(); // Evaluate model
    tfp->dump(clk_time); clk_time++;  // waveform
    // printf("C-> 0-1\n");
    top->clk = 1; top->eval();
    tfp->dump(clk_time); clk_time++;  // waveform
}
void reset() {
  top->resetn = 0;
  single_cycle();
  top->resetn = 1;
  cpu.pc = RESET_VECTOR;
  cpu.gpr[0] = 0;
  npc_state.state = NPC_RUNNING;
}
void sim_init(){
  top = new Vtop;  // instantiating module top
  Verilated::traceEverOn(true);
  printf("# Enabling waves ...\n");
  tfp = new VerilatedVcdC;  //instantiating .vcd object
  top->trace(tfp, 1);  //trace 99 levels of hierarchy
  tfp->open("dump.vcd");
}
void top_close() {
  top->final(); // Final model cleanup
  delete top; // Destroy model
  delete tfp; // delete waveform pointer 
}
void ebreak() {
  if (top->pc != 0x0) {
    printf("C-> EBREAK\n");
    npc_state.state = NPC_END;
    npc_state.halt_pc = top->pc;
  }
}
void unknow() {
  if (top->pc != 0x0) {
    printf("C-> UNKNOW at pc = %x\n", top->pc);
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = top->pc;
  }
}

// Simulate one step, TOP read instruction
void exec_once() {
    // 取址
    if (top->pc >= 0x80000000) {
        top->instr = pmem_read(top->imem_addr, 4); // read instruction from I-Memory
        // top->instr = 0x12345678;
    }else {
        top->instr = 0x00000013; // nop instruction
    }

  /*itrace begin*/
  char logbuf[128];
  void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
  disassemble(logbuf, 96, top->pc, (uint8_t *)&top->instr, 4);
  if(is_itrace_printf()) _Log("NO.%ld-> pc: 0x%x, instr: 0x%lx, asm: %s\n", g_nr_guest_inst, top->imem_addr, top->instr, logbuf);
  else _Lognoprintf("NO.%ld-> pc: 0x%x, instr: 0x%lx, asm: %s\n", g_nr_guest_inst, top->pc, top->instr, logbuf);
  /*itrace end*/

  #ifdef CONFIG_RTRACE
  display_gpr(14);
  display_gpr(15);
  #endif

  // 译码 + 执行
  single_cycle();
}

static void execute(uint64_t n) {
  for (;n > 0; n --) {
    g_nr_guest_inst ++;

    // printf("Top: resetn= %d, pc= 0x%x, instr = 0x%x\n",top->resetn, top->pc, top->instr);
    exec_once(); // dut run one cycle
    /* difftest begin */
    cpu.pc = top->pc; // pc存入cpu结构体
    dump_gpr(); // 寄存器值存入cpu结构体
    // show dut registers
    // printf("dut regfiles after exec_once:\n");
    // run difftest
    #ifdef CONFIG_DIFF
      if(top->commit_en){
        #ifdef CONFIG_DTRACE
          _Log("- - - - run difftest,pc=0x%lx, because commit_en = %d\n",top->pc, top->commit_en);
        #endif
          difftest_step(top->pc);
      }
    #endif
    // else {
    //     printf("don't run difftest, because commit_en = %d\n",top->commit_en);
    // }
    if (npc_state.state != NPC_RUNNING) break;
  }
}

static void statistic() {
  Log("total guest instructions = %ld", g_nr_guest_inst);
  top_close();
}

void npc_exec(uint64_t n) {
  // printf("C-> npc_exec\n");
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }

  execute(n); //执行指令

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("NPC: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
      // fall through
    case NPC_QUIT: statistic();
  }
}

int is_exit_status_bad() {
  int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
    (npc_state.state == NPC_QUIT);
  return !good;
}
