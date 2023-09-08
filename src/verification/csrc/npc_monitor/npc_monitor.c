#include <getopt.h>
#include <npc_common.h>
#include <npc_memory.h>
#include <npc_utils.h>
#include <npc_monitor.h>

FILE *log_fp = NULL;
static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb"); // 读方式打开一个二进制文件，不允许写数据，文件必须存在

  fseek(fp, 0, SEEK_END); // 查找文件的结尾,偏移0个指针
  long size = ftell(fp);

  fseek(fp, 0, SEEK_SET); // 查找文件的开头,偏移0个指针
  int ret = fread(guest_to_host(0x80000000), size, 1, fp);
  assert(ret == 1);
    // printf("first 20 bits of Image is loaded:\n");
    // for(int j= 0; j<40; j++){
    //     printf("image[%d] = 0x%02x\n",j, *(guest_to_host(0x80000000+j)));
    // }

  fclose(fp);
  return size;
}

void init_log(const char *log_file) {
  log_fp = stdout;
  if (log_file != NULL) {
    FILE *fp = fopen(log_file, "w");
    assert(fp);
    log_fp = fp;
  }
  printf("Log is written to %s\n", log_file);
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      // case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_disasm(const char *triple);
void init_monitor(int argc, char *argv[]) {
/* Perform some global initialization. */

  /* Check the contents of argv */
  for (int i = 0; i < argc; i ++) {
    printf("argv[%d]:%s\n", i, argv[i]);
  }

  /* Parse arguments. */
  parse_args(argc, argv);

  /* Open the log file. */
  init_log(log_file);

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();
    printf("# Pass load image\n");

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  // init_sdb();

  init_disasm("riscv64-pc-linux-gnu");
    // printf("pass disasm\n");
}
