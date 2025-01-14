#include <stdlib.h>  // malloc().

#include "s21_string.h"

void *allocate_with_memset(s21_size_t size) {
  void *ptr = malloc(size);
  if (ptr) s21_memset(ptr, 0, size);
  return ptr;
}

bool contains(char ch, const char *char_array) {
  bool is_found = false;
  while (*char_array && !is_found) {
    if (*char_array == ch) is_found = true;
    char_array++;
  }
  return is_found;
}