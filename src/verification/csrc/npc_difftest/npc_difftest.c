#include <dlfcn.h>
#include <npc_utils.h>
#include <npc_memory.h>
#include <npc_monitor.h>
#include <npc_cpu.h>
#include <stdio.h>

void (*ref_difftest_memcpy)(uint64_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);
  printf("model so is %s\n", ref_so_file);

  // 打开传入的动态库文件ref_so_file.
  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  // 通过动态链接对动态库中的上述API符号进行符号解析和重定位, 返回它们的地址
  ref_difftest_memcpy = (void (*)(uint64_t, void*, size_t, bool))(dlsym(handle, "difftest_memcpy"));
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void*, bool))(dlsym(handle, "difftest_regcpy"));
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t))(dlsym(handle, "difftest_exec"));
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t))(dlsym(handle, "difftest_raise_intr"));
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)(int) = (void (*)(int))(dlsym(handle, "difftest_init"));
  assert(ref_difftest_init);

  // 对REF的DIffTest功能进行初始化, 具体行为因REF而异.
  ref_difftest_init(port);
  // 将npc的guest memory拷贝到REF中.
  ref_difftest_memcpy(RESET_VECTOR, guest_to_host(RESET_VECTOR), img_size, DIFFTEST_TO_REF);
  // 将npc的寄存器状态拷贝到REF中.
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
}

bool isa_difftest_checkmem(uint32_t addr) {
  long long *buf;
  ref_difftest_memcpy(addr, buf, 8, DIFFTEST_TO_DUT);
  // long long dut = pmem_read(addr, 8);
  // if (dut != *buf) {
  //   return false;
  // }
  return true;
}

static void checkmem(uint32_t addr, uint64_t pc) {
  if (!isa_difftest_checkmem(addr) && npc_state.state != NPC_END) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
  }
}

bool isa_difftest_checkregs(CPU_state *ref_r, uint64_t pc) {
  for (int i = 1; i < 32; i++){
    // if (1) {
    if (cpu.gpr[i] != (ref_r->gpr[i] & 0xffffffff)) {
      // printf("\nDIFFTEST at pc=0x%lx -> ref: 0x%lx != npc: ", pc, ref_r->gpr[i]);
        _Log("=== DIFFTEST MISMATCH AT 0x%lx ===\n", pc);
        display_gpr(i);
        _Log("REF: 0x%lx != DUT: 0x%lx\n", ref_r->gpr[i], cpu.gpr[i]);
        return false;
    }
  }

  // compare CSR regesters
  if((cpu.csr[ 5] != ref_r->csr[300] ) || // compare MSTATUS
     (cpu.csr[ 8] != ref_r->csr[305] ) || // compare MTVEC
     (cpu.csr[11] != ref_r->csr[341] ) || // compare MEPC
     (cpu.csr[12] != ref_r->csr[342] )){  // compare MCAUSE
    _Log("CSR MISMATCH\n");
    return false;
  }
  return true;
}

static void checkregs(CPU_state *ref, uint64_t pc) {
// isa_difftest_checkregs(ref, pc);
    //printf ref regs
    // printf("Display Format: name, ref_value, mcu_value\n");
    // for(int i=0;i<32;i++){
    //    display_gpr(i); // display_gpr gpr name
    //    printf("gpr[%d] ==> ref: 0x%lx, mcu: 0x%lx\n",i, ref->gpr[i], cpu.gpr[i]);
    // }

    //printf ref regs
  if (!isa_difftest_checkregs(ref, pc) && npc_state.state != NPC_END) {
    npc_state.state = NPC_ABORT;
    npc_state.halt_pc = pc;
    printf("!!!!!!!!! Miss Match !!!!!!!!!!\n");
    printf("!!!!!!!!! Miss Match !!!!!!!!!!\n");
    printf("!!!!!!!!! Miss Match !!!!!!!!!!\n");
  }
  else {
    printf("!!!!!!!!! Match !!!!!!!!!!\n");
    printf("!!!!!!!!! Match !!!!!!!!!!\n");
    printf("!!!!!!!!! Match !!!!!!!!!!\n");
  }
}

void difftest_step(uint64_t pc) {
  CPU_state ref_r;
  ref_difftest_exec(1);
  ref_difftest_regcpy(&ref_r, DIFFTEST_TO_DUT); // 从ref中拷贝寄存器状态
  checkregs(&ref_r, pc);
}

void difftest_interrupt(uint64_t pc){
  // ref_difftest_exec(1);
  ref_difftest_raise_intr(1); 
  printf("inside difftest_interrupt\n");
}
