#ifndef __NPC_MEMORY_H__
#define __NPC_MEMORY_H__

#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

uint8_t* guest_to_host(uint64_t paddr);
uint64_t host_to_guest(uint8_t *haddr);

// static inline bool in_pmem(uint64_t addr) {
//   return (addr >= 0x80000000) && (addr - 0x80000000 < (uint64_t)0x80000000);
// }

long long pmem_read(long long addr, int len);

void pmem_write(long long addr, int len, long long data);

static inline bool in_pmem(long long addr) {
  return (addr >= CONFIG_MBASE) && (addr - CONFIG_MSIZE < (long long)CONFIG_MBASE);
}
#endif
