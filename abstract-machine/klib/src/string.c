#include <klib.h>
#include <klib-macros.h>
#include <stdint.h>

#if !defined(__ISA_NATIVE__) || defined(__NATIVE_USE_KLIB__)

// 计算字符串 s 的长度，直到空结束字符，但不包括空结束字符
size_t strlen(const char *s) {
  size_t i = 0;
  while (*s != '\0') {
    s++;
    i++;
  }
  return i;
}

// 把 src 所指向的字符串复制到 dst
char *strcpy(char *dst, const char *src) {
  for (size_t i = 0; src[i]; i++) dst[i] = src[i];
  return dst;
}

char *strncpy(char *dst, const char *src, size_t n) {
  panic("Not implemented");
}

// 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾
char *strcat(char *dst, const char *src) {
  int i;
  size_t len = strlen(dst);
  for (i = 0; src[i] != '\0'; i++) dst[len + i] = src[i];
  dst[len + i] = '\0';
  return dst;
}

// 把 str1 所指向的字符串和 str2 所指向的字符串进行比较
int strcmp(const char *s1, const char *s2) {
  int i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) i++;
  if (s1[i] == '\0' && s2[i] == '\0') return 0;
  if ((s1[i] == '\0' && s2[i] != '\0') || (s1[i] < s2[i])) return -1;
  if ((s1[i] != '\0' && s2[i] == '\0') || (s1[i] > s2[i])) return 1;
  panic("error in strcmp, should not reach here");
}

int strncmp(const char *s1, const char *s2, size_t n) {
  panic("Not implemented");
}

// 复制字符 c（一个无符号字符）到参数 s 所指向的字符串的前 n 个字符
void *memset(void *s, int c, size_t n) {
  char *str_s = (char *) s;
  for (int i = 0; i < n; i++) str_s[i] = c;
  return s;
}

void *memmove(void *dst, const void *src, size_t n) {
  panic("Not implemented");
}

void *memcpy(void *out, const void *in, size_t n) {
  panic("Not implemented");
}

// 把存储区 str1 和存储区 str2 的前 n 个字节进行比较
int memcmp(const void *s1, const void *s2, size_t n) {
  char *str_s1 = (char *) s1;
  char *str_s2 = (char *) s2;
  for (int i = 0; i < n; i++) {
    if (str_s1[i] == str_s2[i]) continue;
    if (str_s1[i] > str_s2[i]) return 1;
    if (str_s1[i] < str_s2[i]) return -1;
  }
  return 0;
}

#endif
