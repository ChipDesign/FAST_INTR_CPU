#include <am.h>
#include <nemu.h>
#include <stdio.h>

#define W   400
#define H   300
#define SYNC_ADDR (VGACTL_ADDR + 4)
uint32_t *fb = (uint32_t *)(uintptr_t)FB_ADDR;

void __am_gpu_init() {
}

/* 屏幕大小 */
void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = W, .height = H,
    .vmemsz = 0
  };
}

/* 同步屏幕 */
/* AM_GPU_FBDRAW, AM帧缓冲控制器, 可写入绘图信息, 向屏幕(x, y)坐标处绘制w*h的矩形图像.
图像像素按行优先方式存储在pixels中, 每个像素用32位整数以00RRGGBB的方式描述颜色.
若sync为true, 则马上将帧缓冲中的内容同步到屏幕上. */
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  // io_write(AM_GPU_FBDRAW, x * w, y * h, color_buf, w, h, false);
  // AM_DEVREG(11, GPU_FBDRAW,   WR, int x, y; void *pixels; int w, h; bool sync);
  int pixels = 0;
  for (int h = 0; h < ctl->h; h ++) {
    for (int w = 0; w < ctl->w; w ++){
      fb[W * (ctl->y + h) + (ctl->x + w)] = ((uint32_t *)ctl->pixels)[pixels++];
    }
  }
  if (ctl->sync) {
    outl(SYNC_ADDR, 1); // 当sync不为0时，SYNC_ADDR处4位写入1
  }
}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
