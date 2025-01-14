#ifndef S21_STRING_EXTRA_H
#define S21_STRING_EXTRA_H

#include "common.h"

char *s21_to_upper(const char *str);
char *s21_to_lower(const char *str);
s21_size_t min(s21_size_t a, s21_size_t b);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);

void *s21_trim(const char *src, const char *trim_chars);
void set_bounds_on_trimmed_src(const char *src, const char *trim_chars,
                               const char **l_ptr, const char **r_ptr);
const char *get_right_boundary(const char *src, const char *trim_chars);

#endif // S21_STRING_EXTRA_H