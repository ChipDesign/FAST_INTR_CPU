#include <npc_common.h>
#include <npc_cpu.h>
#include <npc_memory.h>
#include <npc_monitor.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  sim_init();
  reset(); // 复位RTL部分的pc值
  printf("# Finish reset MCU\n");

  init_monitor(argc, argv);
  printf("# Pass init_monitor\n");

  sdb_mainloop();
  printf("# Pass sdb_mainloop\n");

#ifdef TEST_ALL
  char *str = argv[2];
  char *token = strtok(str, "/");
  char *pre;
  char *name;

  // Keep printing tokens while one of the
  // delimiters present in str[].
  while (token != NULL)
  {
    pre = token;
    token = strtok(NULL, "/");
  }
  printf("pre=%s\n", pre);
  name = strtok(pre, ".");
  printf("name=%s\n", name);

  FILE *fp;
  fp = fopen("result.log", "a+");
  if (fp == NULL)
    return -1;
  if (npc_state.state == NPC_END)
  {
    fprintf(fp, "PASS: %s\n", name);
  }
  else if (npc_state.state == NPC_ABORT)
  {
    fprintf(fp, "FAIL: %s\n", name);
  }
  fclose(fp);
#endif
  return is_exit_status_bad();
}
