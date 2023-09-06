#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context* (*user_handler)(Event, Context*) = NULL;

Context* __am_irq_handle(Context *c) {
  printf("c.mcause:%x c.mstatus:%d c.mepc:%x\n", c->mcause, c->mstatus, c->mepc);
  if (user_handler) {
    Event ev = {0};
    switch (c->mcause) {
      case 0xb : c->mepc = c->mepc + 4; ev.event = EVENT_YIELD; break;
      default: ev.event = EVENT_ERROR; break;
    }

    c = user_handler(ev, c);
    assert(c != NULL);
  }

  return c;
}

extern void __am_asm_trap(void);

// 第一件就是设置异常入口地址:直接将异常入口地址设置到mtvec寄存器中即可.
// 第二件事是注册一个事件处理回调函数, 这个回调函数由Nanos-lite提供.
bool cte_init(Context*(*handler)(Event, Context*)) {
  // initialize exception entry
  asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap)); // 内联汇编格式; csrw等同于 csrrs x0, csr, rs1

  // register event handler
  user_handler = handler;

  return true;
}

Context *kcontext(Area kstack, void (*entry)(void *), void *arg) {
  return NULL;
}

void yield() {
  asm volatile("li a7, -1; ecall");
}

bool ienabled() {
  return false;
}

void iset(bool enable) {
}
