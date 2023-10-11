#include "svdpi.h" // verilator的DPI-C机制需要的头文件
// #include "Vysyx_22040663_top__Dpi.h" // verilator的DPI-C机制需要的头文件
#include "Vtop__Dpi.h" // verilator的DPI-C机制需要的头文件

#include <npc_common.h>
#include <npc_memory.h>
#include <stdio.h>
#include <npc_config.h>

static uint8_t pmem[0x8000000] = {};

// npc内存地址和实际内存地址相互转换: host->ubuntu guest->npc
uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - 0x80000000; }
uint32_t host_to_guest(uint8_t *haddr) { return haddr - pmem + 0x80000000; }

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default:assert(0);
  }
}

static inline void host_write(void *addr, int len, uint32_t data) {
  // printf("C-> host_write addr:%x, data:%x, len:%d\n",addr, data, len);
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: assert(0);
  }
}

// read data from I-Memory
int pmem_read(int addr, int len) {
  int ret = host_read(guest_to_host(addr), len);
    // printf("Read I-Memory:length= %d, addr = 0x%08x, ins= 0x%08x\n",len, addr, ret);
  return ret;
}

// 总是读取地址为`raddr & ~0x7ull`的4字节返回给`rdata`
void pmem_read32(int raddr, int *rdata) {
  if(raddr<0x80000000) raddr+=0x80000000;
  #ifdef CONFIG_MTRACE
    printf("C-> pmem_read32 raddr:%x, rdata:%x\n",raddr, rdata);
  #endif
  if (in_pmem(raddr)) {
    // printf("read data from D-Memory\n");
    *rdata = pmem_read(raddr, 4);
  }
  else if (raddr == 0xa0000048){
    // printf("read data 0 from D-Memory\n");
    *rdata = 0;
  }
}

// input 32bits addr, read 16 bits useful data
void pmem_read16(int raddr, int *rdata) {
    // avoid pc start from 00000 iverilog
    // TODO: fix in the future
  if(raddr<0x80000000)
      raddr+=0x80000000;

  if (in_pmem(raddr)) {
    // printf("read data from I-Memory\n");
    *rdata = pmem_read(raddr, 2); // read 16 bits data from I-Memory
  }
}

// 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
// `wmask`中每比特表示`wdata`中1个字节的掩码,
// 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变

void pmem_write32(int waddr, int wdata, char wmask) {
  if(waddr<0x80000000) waddr+=0x80000000;

  #ifdef CONFIG_MTRACE
    printf("C-> pmem_write32 waddr:%x, wdata:%x, wmack:%d\n",waddr, wdata, wmask);
  #endif

  if (in_pmem(waddr)) {
    // printf("C-> pmem_write %lx: 0x%lx\n", waddr, wdata);
    host_write(guest_to_host(waddr), wmask, wdata);
  }
  else if (waddr == 0xa00003f8) putchar(wdata); // uart
}
