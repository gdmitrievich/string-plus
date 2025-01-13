#include "s21_string.h"

bool is_signed_number(const format_specifiers* specifier) {
  return specifier->d || specifier->f;
}

bool is_number(const format_specifiers* specifier) {
  return is_signed_number(specifier) || specifier->u;
}