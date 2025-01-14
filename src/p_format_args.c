#include "s21_string.h"

bool s21_is_signed_number(const format_specifiers *specifier) {
  return specifier->d || specifier->f;
}

bool s21_is_number(const format_specifiers *specifier) {
  return s21_is_signed_number(specifier) || specifier->u;
}