#include "s21_string.h"

#include <stdio.h>  // ВРЕМЕННО ПОКА НЕТ s21_sprintf

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *result = S21_NULL;
  if (str) {
    unsigned char *ch = (unsigned char *)str;
    int flag = 0;
    while (n > 0 && flag == 0) {
      if (*ch == c) {
        result = ch;
        flag = 1;
      }
      ch += 1;
      n -= 1;
    }
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *ch_1 = (const unsigned char *)str1;
  const unsigned char *ch_2 = (const unsigned char *)str2;

  int result = 0;
  int flag = 0;
  while (n > 0 && !flag) {
    if (*ch_1 != *ch_2) {
      result = *ch_1 - *ch_2;
      flag = 1;
    }
    ch_1 += 1;
    ch_2 += 1;
    n -= 1;
  }
  return result;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *d = (unsigned char *)dest;
  const unsigned char *s = (unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    d[i] = s[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *s = (unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    s[i] = (unsigned char)c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *dest_new = dest;
  if (dest && src) {
    while (*dest != '\0') {
      dest += 1;
    }

    s21_size_t i = 0;
    while (i < n && *src != '\0') {
      *dest = *src;
      dest += 1;
      src += 1;
      i += 1;
    }
    *dest = '\0';
  }
  return dest_new;
}

char *s21_strchr(const char *str, int c) {
  const char *res = S21_NULL;
  if (str) {
    int flag = 0;
    while (*str != '\0' && flag == 0) {
      if (*str == (char)c) {
        res = str;
        flag = 1;
      }
      str += 1;
    }

    if (c == '\0') {
      res = str;
    }
  }
  return (char *)res;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = 0;
  if (str1) {
    int flag = 0;
    if (!str2) {
      result = 1;
      flag = 1;
    }
    while (!flag && n > 0) {
      if (*str1 != *str2) {
        result = *str1 - *str2;
        flag = 1;
      }
      if (!flag && *str1 == '\0') {
        result = 0;
        flag = 1;
      }
      str1 += 1;
      str2 += 1;
      n -= 1;
    }
  } else
    result = (str2) ? -1 : 0;
  return result;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  if (dest && src) {
    s21_size_t i = 0;
    while (i < n && src[i] != '\0') {
      dest[i] = src[i];
      i += 1;
    }

    while (i < n) {
      dest[i] = '\0';
      i += 1;
    }
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  const char *b = str1;
  int flag = 0;
  if (!(str1 && str2)) flag = 1;

  while (!flag && *b) {
    const char *a = str2;
    int found = 0;

    while (!flag && *a) {
      if (*b == *a && !flag) {
        found = 1;
        flag = 1;
      }
      a += 1;
    }

    if (found) {
      flag = 1;
    } else {
      count += 1;
    }
    b += 1;
  }

  return count;
}

char *s21_strerror(int errnum) {
  static char result[512] = {'\0'};

  if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST) {
    // s21_sprintf(result, "%s%d", ERROR, errnum); (РАЗКОММЕНТИТЬ!!!!)
    sprintf(result, "%s%d", ERROR, errnum);  // ВРЕМЕННО ПОКА НЕТ s21_sprintf
  } else {
    s21_size_t err_length = s21_strlen(errorList[errnum]);
    s21_strncpy(result, errorList[errnum], err_length + 1);
  }

  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t count = 0;
  if (str) {
    const char *a = str;

    while (*a != '\0') {
      count += 1;
      a += 1;
    }
  }
  return count;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  int flag = 0;
  if (!str1 || !str2) flag = 1;
  char *result = S21_NULL;
  while (!flag && *str1) {
    const char *temp = str2;
    while (*temp && flag == 0) {
      if (*str1 == *temp) {
        flag = 1;
        result = (char *)str1;
      }
      temp += 1;
    }
    str1 += 1;
  }

  return result;
}

char *s21_strrchr(const char *str, int c) {
  const char *res = S21_NULL;
  if (str) {
    while (*str != '\0') {
      if (*str == (char)c) {
        res = str;
      }
      str += 1;
    }
    if (c == '\0') {
      res = str;
    }
  }
  return (char *)res;
}

char *s21_strstr(const char *haystack, const char *needle) {
  int flag = 0;
  char *result = S21_NULL;
  if (!(haystack && needle)) flag = 1;
  if (!flag && *needle == '\0') {
    result = (char *)haystack;
    flag = 1;
  }
  if (!flag) {
    while (flag == 0 && *haystack) {
      const char *h = haystack;
      const char *n = needle;
      while (*h && *n && (*h == *n)) {
        h += 1;
        n += 1;
      }
      if (*n == '\0') {
        flag = 1;
        result = (char *)haystack;
      }
      haystack += 1;
    }
  }
  return result;
}
char *s21_strtok(char *str, const char *delim) {
  static char *next_tok = S21_NULL;
  char *tok = S21_NULL;
  char *result = S21_NULL;
  int flag = 0;

  if (str != S21_NULL) {
    next_tok = str;
  }
  if (next_tok == S21_NULL) {
    result = S21_NULL;
    flag = 1;
  }
  while (!flag && *next_tok && s21_strchr(delim, *next_tok)) {
    next_tok += 1;
  }
  if (!flag && *next_tok == '\0') {
    flag = 1;
    result = 0;
  }

  tok = next_tok;

  while (!flag && *next_tok && !s21_strchr(delim, *next_tok)) {
    next_tok += 1;
  }
  if (!flag && *next_tok) {
    *next_tok = '\0';
    next_tok += 1;
  }

  if (flag == 0) result = tok;

  return result;
}
