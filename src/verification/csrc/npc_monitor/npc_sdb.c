#include <readline/readline.h>
#include <readline/history.h>

#include <npc_common.h>
#include <npc_monitor.h>
#include <npc_memory.h>
#include <npc_cpu.h>
#include <stdio.h>

static int is_batch_mode = false;
static int itrace_printf = true; // 默认打印itrace

/* We use the `readline' library to provide more flexibility to read from stdin. */
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }
  return line_read;
}

static int cmd_help(char *args);
static int cmd_c(char *args) {
  npc_exec(-1);
  return 0;
}
static int cmd_q(char *args) {
  npc_state.state = NPC_QUIT;
  return -1;
}
/* 让程序单步执行N条指令后暂停执行,
当N没有给出时, 缺省为1 */
static int cmd_si(char *args) {
  /* 分解字符串 str 为一组字符串，NULL的作用只是为了使得每次调用时，都不是从 args 的头开始，
  而是从上次调用时查找所停止的位置开始，如此循环下去，直到无法再找到匹配" "的时候位置 */
  char *arg = strtok(NULL, " ");
  int i, number;

  if (arg == NULL) {
    npc_exec(1);
  }
  else {
    number = atoi(arg);
    for (i = 0; i < number;i ++) {
      npc_exec(1);
    }
  }
  return 0;
}
/* 打印程序状态，info r 为打印寄存器状态，info w 为打印监视点信息 */
static int cmd_info(char *args) {
  char *arg = strtok(NULL, " "); /* 按照ascii码比较arg和r的每个字符如果二者完全相同返回0 */
  if (arg == NULL){
    printf("Unknown command %s\n", args);
  }
  else{
    if (strcmp(arg, "r") == 0) { //打印寄存器状态
      for (int i = 0; i < 32; i++) {
        display_gpr(i);
      }
    }
    // else if(strcmp(arg, "w") == 0) { //打印监视点信息
    //   char *arg2 = strtok(NULL, " ");
    //   int NO = strtol(arg2, NULL, 16);
    //   display_wp(NO);
    // }
  }
  return 0;
}
/* 扫描内存：求出表达式EXPR的值, 将结果作为起始内存
地址, 以十六进制形式输出连续的N个4字节*/
static int cmd_x(char *args) {
  char *arg = strtok(NULL, " ");
  int N = atoi(arg);
  char *arg2 = strtok(NULL, " ");
  unsigned int EXPR;
  sscanf(arg2,"%x",&EXPR); // 16进制字符串转16进制int整型
  for (int i = 0; i < N; i++){
    printf("0x%x: 0x%llx\n", EXPR, pmem_read(EXPR, 4));
    EXPR = EXPR + 4;
  }
  return 0;
}

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display informations about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "q", "Exit NPC", cmd_q },

  /* TODO: Add more commands */
  { "si", "单步执行", cmd_si },
  { "info", "打印程序状态", cmd_info },
  { "x", "扫描内存", cmd_x},
  // { "p", "表达式求职", cmd_p},
  // { "w", "设置监视点", cmd_w},
  // { "d", "删除监视点", cmd_d},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}

void sdb_set_batch_mode() {
  is_batch_mode = true;
  itrace_printf = false;
}

int is_itrace_printf(){ // 把 itrace_printf 传给npc_exec
  return itrace_printf;
}

void sdb_mainloop() {
  if (is_batch_mode) {
    cmd_c(NULL);
    return;
  }

  #ifdef TEST_ALL
  cmd_table[1].handler(NULL);
  #else
  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }
    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
  #endif
}

// void init_sdb() {
//   /* Compile the regular expressions. */
//   init_regex();

//   /* Initialize the watchpoint pool. */
//   init_wp_pool();
// }
