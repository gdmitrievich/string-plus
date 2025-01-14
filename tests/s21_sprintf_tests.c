#include <check.h>
#include <limits.h>
#include <locale.h>  // For setlocale().
#include <stdio.h>   // For sprintf().
#include <stdlib.h>  // For exit status.

#include "../src/s21_sprintf.h"

#define BUFFSIZE 1024

void s21_init_compared_strs(char* expected_str, char* actual_str) {
  memset(expected_str, '\0', BUFFSIZE);
  memset(actual_str, '\0', BUFFSIZE);
}

START_TEST(empty_format_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plain_text_on_format_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str plain text str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str plain text str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_positive_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_positive_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_negative_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+d";
  int arg = -123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_negative_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+f";
  double arg = -123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_positive_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_positive_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_negative_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% d";
  int arg = -123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_negative_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% f";
  double arg = -123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_plus_and_positive_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% +d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(minus_with_width_gt_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%-4d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(minus_with_space_and_width_gt_n_digits_on_unsigned_int) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%- 10u";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_space_and_width_gt_n_digits_on_unsigned_int) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+ 10u";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_minus_and_width_gt_n_digits_on_unsigned_int) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+-10u";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_positive_int_num_and_precision_gt_n_num_digits) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+.5d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(plus_with_positive_int_num_and_width_gt_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%+7d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_positive_int_num_and_precision_gt_n_num_digits) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% .5d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(space_with_positive_int_num_and_width_gt_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "% 7d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(
    space_with_minus_flag_and_positive_int_num_and_width_gt_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%- 7d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(width_gt_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%5d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(width_eq_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%3d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(width_lt_len_of_formated_arg) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%2d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_lt_n_int_num_digits) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.2d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_eq_n_int_num_digits) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.3d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_gt_n_int_num_digits) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.4d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_lt_n_digits_on_fract_part_of_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.1f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_eq_n_digits_on_fract_part_of_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.3f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_gt_n_digits_on_fract_part_of_double_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.5f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_lt_n_chars_on_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.3s";
  const char* arg = "string";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_eq_n_chars_on_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.6s";
  const char* arg = "string";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_gt_n_chars_on_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.10s";
  const char* arg = "string";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_lt_n_converted_chars_from_wide_char_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.1ls";
  const wchar_t* arg = L"w四Э";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_lt_n_converted_chars_from_wide_char_str_partial) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.2ls";
  const wchar_t* arg = L"w四Э";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_eq_n_converted_chars_from_wide_char_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.7ls";
  const wchar_t* arg = L"w四Э";  // 1 + 4 + 2 bytes needed.
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(precision_gt_n_converted_chars_from_wide_char_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.10ls";
  const wchar_t* arg = L"w四Э";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(only_dot_as_zero_precision) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(zero_precision_with_zero_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.d";
  int arg = 0;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(zero_precision_with_non_zero_int_num) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(short_int_overflow) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%hd";
  int arg = SHRT_MAX + 1;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(unsigned_short_int_overflow) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%hd";
  int arg = USHRT_MAX + 1;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(long_int_overflow) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%ld";
  long int arg = LONG_MAX;
  int expected_n_written_chars = sprintf(expected_str, format, arg + 1);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg + 1);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(unsigned_long_int_max_val) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%lu";
  unsigned long arg = ULONG_MAX;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(wide_char) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%lc";
  wint_t arg = L'四';
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(wide_char_with_inappropriate_locale) {
  setlocale(LC_ALL, "C");
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%lc";
  wint_t arg = L'四';
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);

  setlocale(LC_ALL, "C.UTF-8");
}
END_TEST

START_TEST(wide_char_str_with_inappropriate_locale) {
  setlocale(LC_ALL, "C");
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%ls";
  const wchar_t* arg = L"四四四";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);

  setlocale(LC_ALL, "C.UTF-8");
}
END_TEST

START_TEST(zero_wide_char) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%lc";
  wint_t arg = L'\0';
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(zero_wide_char_with_text_around_only_left_hand_side_text_written) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "str %lc str";
  wint_t arg = L'\0';
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(zero_wide_char_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%ls";
  const wchar_t* arg = L"";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(only_percent) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "%%", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "%%", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(zero_int_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%d";
  int arg = 0;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(only_int_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%d";
  int arg = 123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(int_min_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%d";
  int arg = INT_MIN;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(int_max_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%d";
  int arg = INT_MAX;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(uint_max_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%u";
  unsigned int arg = UINT_MAX;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(uint_negative_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%u";
  int arg = -100;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(basic_char_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%c";
  unsigned char arg = 'a';
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(zero_char_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%c";
  unsigned char arg = '\0';
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(negative_char_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%c";
  int arg = -123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(uchar_max_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%c";
  const char arg = UCHAR_MAX;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(empty_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%s";
  const char* arg = "";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(only_str) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%s";
  const char* arg = "string";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(str_with_null_terminator_in_the_middle) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%s";
  const char* arg = "str\0str";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(str_with_multibyte_chars) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%s";
  const char* arg = "привет";
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(double_with_default_precision) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%f";
  double arg = 123.12345678;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(huge_precision_gt_n_digits_on_fract_part_of_double) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.50f";
  double arg = 123.123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(huge_precision_lt_n_digits_on_fract_part_of_double) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%.20f";
  double arg = 123.123123123123123123213123;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(double_nan_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%f";
  double arg = NAN;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(double_infinity_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%f";
  double arg = INFINITY;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(double_negative_infinity_value) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  const char* format = "%f";
  double arg = -INFINITY;
  int expected_n_written_chars = sprintf(expected_str, format, arg);

  int actual_n_written_chars = s21_sprintf(actual_str, format, arg);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(percent_with_width) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "%5%", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "%5%", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(spurious_trailing_percent_at_end_of_format) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "%", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "%", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(conversion_lacks_type_at_end_of_format) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "%12.3l", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "%12.3l", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(order_of_all_flags_specified_multiple_times_on_error) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %++--  2=d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %++--  2=d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(order_of_minus_space_flags_specified_multiple_times_on_error) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %--  2=d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %--  2=d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(order_of_plus_space_flags_specified_multiple_times_on_error) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %++  2=d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %++  2=d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(order_of_plus_minus_flags_specified_multiple_times_on_error) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %++--2=d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %++--2=d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(unknown_conversion_type_char_in_flag_position) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %=1.2d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %=1.2d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(negative_precision_error) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %.-3ld str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %.-3ld str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(unknown_conversion_type_char_in_length_modifier_position) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %l3d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %l3d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(unknown_length_modifier) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %yd str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %yd str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(too_much_len_modifiers_error) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %12lhd str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %12lhd str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(unknown_specifier) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %y str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %y str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(conversion_lacks_type_at_the_middle_of_format) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %2.3l str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %2.3l str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(format_arg_specified_on_the_wrong_order) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "str %2.3l+d str", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "str %2.3l+d str", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

START_TEST(conversion_lacks_type_at_end_of_format_with_format_error_before) {
  char expected_str[BUFFSIZE];
  char actual_str[BUFFSIZE];
  s21_init_compared_strs(expected_str, actual_str);
  int expected_n_written_chars = sprintf(expected_str, "%. %23.5", S21_NULL);

  int actual_n_written_chars = s21_sprintf(actual_str, "%. %23.5", S21_NULL);

  ck_assert_str_eq(expected_str, actual_str);
  ck_assert_int_eq(expected_n_written_chars, actual_n_written_chars);
}
END_TEST

Suite* without_conversion_specification(void) {
  Suite* wcs_s = suite_create(
      "format_str_without_conversion_specification (compared_with_sprintf)");

  TCase* pt_tc = tcase_create("fswcs:plain_text");
  tcase_add_test(pt_tc, empty_format_str);
  tcase_add_test(pt_tc, plain_text_on_format_str);
  suite_add_tcase(wcs_s, pt_tc);

  return wcs_s;
}

Suite* one_conversion_specification(void) {
  Suite* ocs_s = suite_create(
      "format_str_with_one_conversion_specification (compared_with_sprintf)");

  TCase* fafa_tc = tcase_create("fswocs:flag_as_format_arg");
  tcase_add_test(fafa_tc, plus_with_positive_int_num);
  tcase_add_test(fafa_tc, plus_with_positive_double_num);
  tcase_add_test(fafa_tc, plus_with_negative_int_num);
  tcase_add_test(fafa_tc, plus_with_negative_double_num);

  tcase_add_test(fafa_tc, space_with_positive_int_num);
  tcase_add_test(fafa_tc, space_with_positive_double_num);
  tcase_add_test(fafa_tc, space_with_negative_int_num);
  tcase_add_test(fafa_tc, space_with_negative_double_num);
  suite_add_tcase(ocs_s, fafa_tc);

  TCase* fwofa_tc = tcase_create("fswocs:flag_with_other_format_args");
  tcase_add_test(fwofa_tc, space_with_plus_and_positive_int_num);
  tcase_add_test(fwofa_tc, minus_with_width_gt_len_of_formated_arg);
  suite_add_tcase(ocs_s, fwofa_tc);

  TCase* fec_tc = tcase_create("fswocs:flag_edge_case");
  tcase_add_test(fec_tc,
                 plus_with_positive_int_num_and_precision_gt_n_num_digits);
  tcase_add_test(fec_tc,
                 plus_with_positive_int_num_and_width_gt_len_of_formated_arg);

  tcase_add_test(fec_tc,
                 space_with_positive_int_num_and_precision_gt_n_num_digits);
  tcase_add_test(fec_tc,
                 space_with_positive_int_num_and_width_gt_len_of_formated_arg);
  tcase_add_test(
      fec_tc,
      space_with_minus_flag_and_positive_int_num_and_width_gt_len_of_formated_arg);

  tcase_add_test(fwofa_tc,
                 minus_with_space_and_width_gt_n_digits_on_unsigned_int);
  tcase_add_test(fwofa_tc,
                 plus_with_space_and_width_gt_n_digits_on_unsigned_int);
  tcase_add_test(fwofa_tc,
                 plus_with_minus_and_width_gt_n_digits_on_unsigned_int);
  suite_add_tcase(ocs_s, fec_tc);

  TCase* wafa_tc = tcase_create("fswocs:width_as_format_arg");
  tcase_add_test(wafa_tc, width_gt_len_of_formated_arg);
  tcase_add_test(wafa_tc, width_eq_len_of_formated_arg);
  tcase_add_test(wafa_tc, width_lt_len_of_formated_arg);
  suite_add_tcase(ocs_s, wafa_tc);

  TCase* pafa_tc = tcase_create("fswocs:precision_as_format_arg");
  tcase_add_test(pafa_tc, precision_lt_n_int_num_digits);
  tcase_add_test(pafa_tc, precision_eq_n_int_num_digits);
  tcase_add_test(pafa_tc, precision_gt_n_int_num_digits);

  tcase_add_test(pafa_tc, precision_lt_n_digits_on_fract_part_of_double_num);
  tcase_add_test(pafa_tc, precision_eq_n_digits_on_fract_part_of_double_num);
  tcase_add_test(pafa_tc, precision_gt_n_digits_on_fract_part_of_double_num);

  tcase_add_test(pafa_tc, precision_lt_n_chars_on_str);
  tcase_add_test(pafa_tc, precision_eq_n_chars_on_str);
  tcase_add_test(pafa_tc, precision_gt_n_chars_on_str);

  tcase_add_test(pafa_tc, precision_lt_n_converted_chars_from_wide_char_str);
  tcase_add_test(pafa_tc,
                 precision_lt_n_converted_chars_from_wide_char_str_partial);
  tcase_add_test(pafa_tc, precision_eq_n_converted_chars_from_wide_char_str);
  tcase_add_test(pafa_tc, precision_gt_n_converted_chars_from_wide_char_str);
  suite_add_tcase(ocs_s, pafa_tc);

  TCase* pec_tc = tcase_create("fswocs:precision_edge_case");
  tcase_add_test(pec_tc, only_dot_as_zero_precision);
  tcase_add_test(pec_tc, zero_precision_with_zero_int_num);
  tcase_add_test(pec_tc, zero_precision_with_non_zero_int_num);
  suite_add_tcase(ocs_s, pec_tc);

  TCase* lmafa_tc = tcase_create("fswocs:length_modifier_as_format_arg");
  tcase_add_test(lmafa_tc, short_int_overflow);
  tcase_add_test(lmafa_tc, unsigned_short_int_overflow);

  tcase_add_test(lmafa_tc, long_int_overflow);
  tcase_add_test(lmafa_tc, unsigned_long_int_max_val);

  tcase_add_test(lmafa_tc, wide_char);
  suite_add_tcase(ocs_s, lmafa_tc);

  TCase* lmec_tc = tcase_create("fswocs:length_modifier_edge_case");
  tcase_add_test(lmec_tc, wide_char_with_inappropriate_locale);
  tcase_add_test(lmec_tc, wide_char_str_with_inappropriate_locale);
  tcase_add_test(lmec_tc, zero_wide_char);
  tcase_add_test(
      lmec_tc,
      zero_wide_char_with_text_around_only_left_hand_side_text_written);
  tcase_add_test(lmec_tc, zero_wide_char_str);
  suite_add_tcase(ocs_s, lmec_tc);

  TCase* safa_tc = tcase_create("fswocs:specifier_as_format_arg");
  tcase_add_test(safa_tc, only_percent);

  tcase_add_test(safa_tc, zero_int_value);
  tcase_add_test(safa_tc, only_int_value);
  tcase_add_test(safa_tc, int_min_value);
  tcase_add_test(safa_tc, int_max_value);

  tcase_add_test(safa_tc, uint_max_value);
  tcase_add_test(safa_tc, uint_negative_value);

  tcase_add_test(safa_tc, basic_char_value);
  tcase_add_test(safa_tc, zero_char_value);
  tcase_add_test(safa_tc, negative_char_value);
  tcase_add_test(safa_tc, uchar_max_value);

  tcase_add_test(safa_tc, empty_str);
  tcase_add_test(safa_tc, only_str);
  tcase_add_test(safa_tc, str_with_null_terminator_in_the_middle);
  tcase_add_test(safa_tc, str_with_multibyte_chars);

  tcase_add_test(safa_tc, double_with_default_precision);
  tcase_add_test(safa_tc, huge_precision_gt_n_digits_on_fract_part_of_double);
  tcase_add_test(safa_tc, huge_precision_lt_n_digits_on_fract_part_of_double);
  suite_add_tcase(ocs_s, safa_tc);

  TCase* swofa_tc = tcase_create("fswocs:specifier_with_other_format_args");
  tcase_add_test(swofa_tc, percent_with_width);
  suite_add_tcase(ocs_s, swofa_tc);

  TCase* sec_tc = tcase_create("fswocs:specifier_edge_case");
  tcase_add_test(sec_tc, spurious_trailing_percent_at_end_of_format);
  tcase_add_test(sec_tc, conversion_lacks_type_at_end_of_format);

  tcase_add_test(safa_tc, double_nan_value);
  tcase_add_test(safa_tc, double_infinity_value);
  tcase_add_test(safa_tc, double_negative_infinity_value);
  suite_add_tcase(ocs_s, sec_tc);

  TCase* ifanateof_tc =
      tcase_create("fswocs:incorrect_format_arg_not_at_the_end_of_format");
  tcase_add_test(ifanateof_tc,
                 order_of_all_flags_specified_multiple_times_on_error);
  tcase_add_test(ifanateof_tc,
                 order_of_minus_space_flags_specified_multiple_times_on_error);
  tcase_add_test(ifanateof_tc,
                 order_of_plus_space_flags_specified_multiple_times_on_error);
  tcase_add_test(ifanateof_tc,
                 order_of_plus_minus_flags_specified_multiple_times_on_error);
  tcase_add_test(ifanateof_tc, unknown_conversion_type_char_in_flag_position);
  tcase_add_test(ifanateof_tc, negative_precision_error);
  tcase_add_test(ifanateof_tc,
                 unknown_conversion_type_char_in_length_modifier_position);
  tcase_add_test(ifanateof_tc, unknown_length_modifier);
  tcase_add_test(ifanateof_tc, too_much_len_modifiers_error);
  tcase_add_test(ifanateof_tc, unknown_specifier);
  tcase_add_test(ifanateof_tc, conversion_lacks_type_at_the_middle_of_format);
  tcase_add_test(ifanateof_tc, format_arg_specified_on_the_wrong_order);
  suite_add_tcase(ocs_s, ifanateof_tc);

  return ocs_s;
}

Suite* two_or_more_conversion_specifications(void) {
  Suite* wcs_s = suite_create(
      "two_or_more_conversion_specifications (compared_with_sprintf)");

  TCase* pt_tc = tcase_create("tomcs:format_error");
  tcase_add_test(
      pt_tc, conversion_lacks_type_at_end_of_format_with_format_error_before);
  suite_add_tcase(wcs_s, pt_tc);

  return wcs_s;
}

int main(void) {
  setlocale(LC_ALL, "C.UTF-8");

  int n_failed = 0;
  Suite* wcs_s = without_conversion_specification();
  SRunner* sr = srunner_create(wcs_s);
  srunner_add_suite(sr, one_conversion_specification());
  srunner_add_suite(sr, two_or_more_conversion_specifications());

  srunner_run_all(sr, CK_NORMAL);
  n_failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}