#ifndef __NPC_MEMORY_H__
#define __NPC_MEMORY_H__

#define CONFIG_MSIZE 0x8000000
#define CONFIG_MBASE 0x80000000

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

uint8_t* guest_to_host(uint32_t paddr);
uint32_t host_to_guest(uint8_t *haddr);

// static inline bool in_pmem(uint64_t addr) {
//   return (addr >= 0x80000000) && (addr - 0x80000000 < (uint64_t)0x80000000);
// }

int pmem_read(int addr, int len);

void pmem_write(int addr, int len, int data);

static inline bool in_pmem(uint32_t addr) {
  return (addr >= CONFIG_MBASE) && (addr - CONFIG_MSIZE < (int)CONFIG_MBASE);
}
#endif
