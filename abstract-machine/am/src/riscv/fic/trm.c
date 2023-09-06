#include <am.h>
#include "fic.h"

extern char _heap_start;
int main(const char *args);

// 写在了头文件npc.h中
// extern char _pmem_start;
// #define PMEM_SIZE (128 * 1024 * 1024)
// #define PMEM_END  ((uintptr_t)&_pmem_start + PMEM_SIZE)

Area heap = RANGE(&_heap_start, PMEM_END);
#ifndef MAINARGS
#define MAINARGS ""
#endif
static const char mainargs[] = MAINARGS;

void putch(char ch) {
  outb(SERIAL_PORT, ch);
}

void halt(int code) {
  npc_trap(code);

  // main的return0调用halt，进入while循环，先执行ret，再jal循环
  while (1);
}

void _trm_init() {
  int ret = main(mainargs);
  halt(ret);
}
