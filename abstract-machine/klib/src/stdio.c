#include <am.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdarg.h>
#include <stdio.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

char* my_itoa(unsigned unum, char* str, int n) {
  // printf("my_itoa: %d\n", num);
  // 判断整数正负
  // long unsigned unum;
  int i = 0;
  // if (num < 0) {
  //   unum = (long unsigned)-num;
  //   str[i++] = '-';
  // }
  // else unum = (long unsigned)num;

  // 查找表的方式给字符串赋值
  char index[] = "0123456789abcdef";
  do {
    str[i++] = index[unum % n];
    unum /= n;
  } while (unum);
  str[i] = '\0';

  // 调换字符串顺序
  char temp;
  int j, k;
  // if (num < 0) k = 1;
  // else k = 0;
  k = 0;
  for (j = k;j <= (i - 1) / 2; j++) {
    temp = str[j];
    str[j] = str[i - 1 + k - j];
    str[i - 1 + k - j] = temp;
  }
  return str;
}

int printf(const char *fmt, ...) {
  va_list ap; //定义一个可变参数的（字符指针）

  int res = 0; //返回值

  int val = 0;
  char *s;
  char str[4096] = "";
  char temp[2] = "";

  va_start (ap,fmt); //初始化ap

  while (*fmt != '\0') {
    if (*fmt != '%') {
      temp[0] = *fmt;
      temp[1] = '\0';
      putstr(temp);
      res++;
    }
    else {
      fmt++;
      switch(*fmt) {
        case 's':
          s = va_arg(ap, char *);
          putstr(s);
          res += strlen(s);
          break;
        case 'd':
          val = va_arg(ap, int);
          s = my_itoa(val, str, 10);
          putstr(s);
          res += strlen(s);
          break;
        case 'x':
          val = va_arg(ap, int); // 输出的值为补码，并自动填充最高位
          // if (val == 0x800008cb) {printf("00\n");}
          // s = va_arg(ap, char *);
          // if (strcmp(s, "0x800008cb")) {printf("00\n");}

          // //transfrom
          // int sig=1;
          // ++s;
          // ++s;
          // for(int i =1;i<8; ++i) {
          //   sig*=16;
          // }
          // for(int i=0; i<8; ++i) {
          //   if(i==7) {
          //     if('a'<=*s&&*s<='f') {
          //       val+=(*s-'a')+10;
          //       continue;
          //     }
          //     val+= (*s-'0');
          //   }
          //    else {
          //     if('a'<=*s&&*s<='f') {
          //       val+=((*s-'a')+10)*sig;
          //       sig/=16;
          //       continue;
          //     }
          //       val += (*s-'0')*sig;
          //       sig/=16;
          //   }
          // }
          // val=2147485899;
          // printf("val is %d \n",val);
          s = my_itoa(val, str, 16);
          putstr(s);
          res += strlen(s);
          break;
        default: break;
      }
    }
    fmt++;
  }

  va_end(ap);

  return res;
}

int vsprintf(char *out, const char *fmt, va_list ap) {
  panic("Not implemented");
}

int sprintf(char *out, const char *fmt, ...) {

  memset(out, 0, sizeof(out)); // 消除out原有数据的影响

  int n;
  char *s;
  char n_to_s[4096] = "";
  char temp[2] = "";

  va_list ap; //定义一个可变参数的（字符指针）
  va_start (ap,fmt); //初始化ap

  while (*fmt != '\0') {
    if (*fmt != '%') {
      temp[0] = *fmt;
      temp[1] = '\0';
      strcat(out, temp);
    }
    else {
      fmt++;
      switch(*fmt) {
        case '%':
          break;
        case 's':
          s = va_arg(ap, char *);
          strcat(out, s);
          break;
        case 'd':
          n = va_arg(ap, int);
          s = my_itoa(n, n_to_s, 10);
          strcat(out, n_to_s);
          break;
        default: break;
      } // endswitch
    } // endelse
    fmt++;
  }

  va_end(ap);

  return 1;
}

int snprintf(char *out, size_t n, const char *fmt, ...) {
  panic("Not implemented");
}

int vsnprintf(char *out, size_t n, const char *fmt, va_list ap) {
  panic("Not implemented");
}

#endif
