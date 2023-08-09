#ifndef __NPC_MONITOR_H__
#define __NPC_MONITOR_H__

// calculate the length of an array
#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

void init_monitor(int argc, char *argv[]);
void sdb_set_batch_mode();
int is_exit_status_bad();

#endif