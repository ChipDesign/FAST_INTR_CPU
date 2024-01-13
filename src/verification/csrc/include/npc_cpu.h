#ifndef __NPC_CPU_H__
#define __NPC_CPU_H__

#define RESET_VECTOR 0x80000000

// ----------- state -----------

enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

typedef struct {
  int state;
  uint64_t halt_pc=0x80000000;
  uint32_t halt_ret=0x80000000;
} NPCState;
extern NPCState npc_state;

typedef struct {
  // uint64_t gpr[32];
  // uint64_t pc;
  uint32_t gpr[32];
  uint32_t pc;
} CPU_state;
extern CPU_state cpu; // cpu是一个状态机，由pc和寄存器的值可以唯一确定一个cpu的状态

void sdb_mainloop();
void npc_exec(uint64_t n);
void reset();
void top_close();
void sim_init();

void dump_gpr();
void display_gpr(int i);

int is_itrace_printf();

#endif 
