#include <check.h>
#include <stdlib.h>  // For exit status.

#include "../src/s21_trim.h"

#define BUFFSIZE 1024

START_TEST(src_is_null_returns_null) {
  const char *expected_str = NULL;
  const char *src = NULL;
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_ptr_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(src_is_empty_returns_copy_of_empty_src) {
  const char *expected_str = "";
  const char *src = "";
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_is_null_1) {
  const char *expected_str = "str";
  const char *src = "str";
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_is_null_2) {
  const char *expected_str = "str";
  const char *src = " \t\n\t str";
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_is_null_3) {
  const char *expected_str = "str";
  const char *src = "str \t\n\t ";
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_is_null_4) {
  const char *expected_str = "str";
  const char *src = " \t\n\t str \t\n\t ";
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_is_null_5) {
  const char *expected_str = "str \t str";
  const char *src = " \t\n\t str \t str \t\n\t ";
  const char *trim_chars = NULL;

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_isnt_null_1) {
  const char *expected_str = "   123str321   ";
  const char *src = "   123str321   ";
  const char *trim_chars = "0123456789";

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_isnt_null_2) {
  const char *expected_str = "str";
  const char *src = "123str321";
  const char *trim_chars = "0123456789";

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

START_TEST(trim_chars_isnt_null_3) {
  const char *expected_str = "";
  const char *src = "abcdeffedcba";
  const char *trim_chars = "abcdef";

  char *actual_str = (char *)s21_trim(src, trim_chars);

  ck_assert_str_eq(expected_str, actual_str);

  free(actual_str);
}
END_TEST

Suite *s21_trim_suite(void) {
  Suite *sts_s = suite_create("s21_trim_suite");

  TCase *sec_tc = tcase_create("src_edge_case");
  tcase_add_test(sec_tc, src_is_null_returns_null);
  tcase_add_test(sec_tc, src_is_empty_returns_copy_of_empty_src);
  suite_add_tcase(sts_s, sec_tc);

  TCase *tin_tc = tcase_create("trim_chars_is_null");
  tcase_add_test(tin_tc, trim_chars_is_null_1);
  tcase_add_test(tin_tc, trim_chars_is_null_2);
  tcase_add_test(tin_tc, trim_chars_is_null_3);
  tcase_add_test(tin_tc, trim_chars_is_null_4);
  tcase_add_test(tin_tc, trim_chars_is_null_5);
  suite_add_tcase(sts_s, tin_tc);

  TCase *tinn_tc = tcase_create("trim_chars_isn't_null");
  tcase_add_test(tin_tc, trim_chars_isnt_null_1);
  tcase_add_test(tin_tc, trim_chars_isnt_null_2);
  tcase_add_test(tin_tc, trim_chars_isnt_null_3);
  suite_add_tcase(sts_s, tinn_tc);

  return sts_s;
}

int main(void) {
  int n_failed = 0;
  Suite *sts_s = s21_trim_suite();
  SRunner *sr = srunner_create(sts_s);

  srunner_run_all(sr, CK_NORMAL);
  n_failed = srunner_ntests_failed(sr);

  srunner_free(sr);
  return (n_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}