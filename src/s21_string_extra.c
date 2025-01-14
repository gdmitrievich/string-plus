#include "s21_string_extra.h"
#include "s21_string.h"

char *s21_to_upper(const char *str) {
	if (!str) return S21_NULL;
  s21_size_t len = s21_strlen(str);
  char *result = allocate_with_memset(len + 1);
  if (result) {
	for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      result[i] = str[i] - ('a' - 'A');
    } else {
      result[i] = str[i];
    }
  }
  result[len] = '\0';
  }

  return result;
}

char *s21_to_lower(const char *str) {
	if (!str) return S21_NULL;
  s21_size_t len = s21_strlen(str);
  char *result = allocate_with_memset(len + 1);
  if (result != NULL) {
	for (s21_size_t i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      result[i] = str[i] + ('a' - 'A');
    } else {
      result[i] = str[i];
    }
  }
  result[len] = '\0';
  }

  return result;
}

s21_size_t min(s21_size_t a, s21_size_t b) { return (a > b) ? b : a; }

void* s21_insert(const char* src, const char* str, s21_size_t start_index) {
  char* res = S21_NULL;
  if (src != S21_NULL && str != S21_NULL) {
    s21_size_t len_src = s21_strlen(src);
	s21_size_t len_str = s21_strlen(str);
    char* res = allocate_with_memset(len_src + len_str + 1);
    if (res) {
		start_index = min(start_index, len_src);
      for (s21_size_t i = 0; i < start_index; ++i) {
        res[i] = src[i];
      }
      for (s21_size_t i = 0; i < len_str; ++i) {
        res[i + start_index] = str[i];
      }
      for (s21_size_t i = start_index; i < len_src; ++i) {
        res[i + len_str] = src[i];
      }
      res[len_str + len_src] = '\0';
    }
  }
  return (void*)res;
}


void *s21_trim(const char *src, const char *trim_chars) {
  if (!src) return S21_NULL;

  const char *l_ptr = S21_NULL;
  const char *r_ptr = S21_NULL;
  if (trim_chars) {
    set_bounds_on_trimmed_src(src, trim_chars, &l_ptr, &r_ptr);
  } else {
    set_bounds_on_trimmed_src(src, " \t\n", &l_ptr, &r_ptr);
  }

  s21_size_t n = r_ptr - l_ptr;
  char *trimmed_src = allocate_with_memset(n + 1);
  if (trimmed_src) {
    s21_memcpy(trimmed_src, l_ptr, n);
    trimmed_src[n] = '\0';
  }

  return (void *)trimmed_src;
}

void set_bounds_on_trimmed_src(const char *src, const char *trim_chars,
                               const char **l_ptr, const char **r_ptr) {
  *l_ptr = src + strspn(src, trim_chars);
  *r_ptr = get_right_boundary(src, trim_chars);
}

const char *get_right_boundary(const char *src, const char *trim_chars) {
  s21_size_t l = s21_strlen(src);
  s21_size_t i = l;
  while (i > 0 && contains(src[i - 1], trim_chars)) --i;
  if (i == 0) i = l;
  return src + i;
}