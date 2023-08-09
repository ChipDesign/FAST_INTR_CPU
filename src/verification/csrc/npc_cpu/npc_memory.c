#include "svdpi.h" // verilator的DPI-C机制需要的头文件
// #include "Vysyx_22040663_top__Dpi.h" // verilator的DPI-C机制需要的头文件
#include "Vtop__Dpi.h" // verilator的DPI-C机制需要的头文件

#include <npc_common.h>
#include <npc_memory.h>
#include <stdio.h>

static uint8_t pmem[0x8000000] = {};

// npc内存地址和实际内存地址相互转换: host->ubuntu guest->npc
uint8_t* guest_to_host(uint64_t paddr) { return pmem + paddr - 0x80000000; }
uint64_t host_to_guest(uint8_t *haddr) { return haddr - pmem + 0x80000000; }

static inline uint64_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    case 8: return *(uint64_t *)addr;
    default:assert(0);
  }
}

static inline void host_write(void *addr, int len, uint64_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    case 8: *(uint64_t *)addr = data; return;
    default: assert(0);
  }
}

// read data from I-Memory
long long pmem_read(long long addr, int len) {
  long long ret = host_read(guest_to_host(addr), len);
    printf("Read I-Memory:length= %d, addr = 0x%08x, ins= 0x%08x\n",len, addr, ret);
  return ret;
}

// 总是读取地址为`raddr & ~0x7ull`的8字节返回给`rdata`
void pmem_read_rtl(long long raddr, long long *rdata) {
    // avoid pc start from 00000 iverilog
    if(raddr<0x80000000){
        raddr+=0x80000000;
    }
  if (in_pmem(raddr)) {
  // if (1) {
    printf("C-> pmem_read %llx: 0x%llx\n", raddr, *rdata);
    *rdata = pmem_read(raddr, 8);
  }
  else if (raddr == 0xa0000048){
    printf("C-> pmem_read raddr: 0x%llx\n", raddr);
    *rdata = 0; // 返回当前时间
  }
    printf("pmem_read_rtl: raddr = 0x%08x, rdata= %x\n", raddr, *rdata);
}

// input 32bits addr, read 16 bits useful data
void pmem_read16(int raddr, int *rdata) {
    // avoid pc start from 00000 iverilog
    // TODO: fix in the future
    if(raddr<0x80000000){
        raddr+=0x80000000;
    }
  if (in_pmem(raddr)) {
    printf("read data from I-Memory\n");
    *rdata = pmem_read(raddr, 2); // read 16 bits data from I-Memory
  }
  else if (raddr == 0xa0000048){ // upper bound of address
    printf("read data 0 from I-Memory\n");
    *rdata = 0;
  }
}

// 总是往地址为`waddr & ~0x7ull`的8字节按写掩码`wmask`写入`wdata`
// `wmask`中每比特表示`wdata`中1个字节的掩码,
// 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
void pmem_write(long long waddr, long long wdata, char wmask) {
  if (in_pmem(waddr)) {
    // printf("C-> pmem_write %llx: 0x%llx\n", waddr, wdata);
    host_write(guest_to_host(waddr), wmask, wdata);
  }
  else if (waddr == 0xa00003f8){
    // printf("waddr == 0xa00003f8 : %lld\n", wdata);
    putchar(wdata);
  }
}

// static void out_of_bound(uint64_t addr) {
//   panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
//       addr, (uint64_t)0x80000000, (uint64_t)0x80000000 + 0x80000000 - 1, cpu.pc);
// }

// void init_mem() {
//       Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]",
//       (uint64_t)0x80000000, (uint64_t)0x80000000 + 0x80000000 - 1);
// }

// uint64_t paddr_read(uint64_t addr, int len) {
//   if (likely(in_pmem(addr))) return pmem_read(addr, len);
//   //IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
//   out_of_bound(addr);
//   return 0;
// }

// void paddr_write(uint64_t addr, int len, uint64_t data) {
//   if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
//   //IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
//   out_of_bound(addr);
// }
