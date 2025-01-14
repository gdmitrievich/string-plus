#ifndef COMMON_H
#define COMMON_H

typedef unsigned long s21_size_t;
#define S21_NULL (void*)0

typedef enum { false, true } bool;

void* allocate_with_memset(s21_size_t size);
bool contains(char ch, const char* char_array);

#endif  // COMMON_H