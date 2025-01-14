#include <math.h>
#include <stdarg.h>
#include <stdlib.h>

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  int total_written_chars_to_str = 0;
  bool success = true;

  va_list s21_sprintf_va_list;
  va_start(s21_sprintf_va_list, format);
  s21_size_t format_idx = 0;
  s21_size_t str_idx = 0;
  s21_size_t format_len = s21_strlen(format);
  while (success && format_idx < format_len) {
    if (format[format_idx] == '%') {
      format_idx++;  // To skip percentage character.
      s21_size_t n_written_chars_to_str = 0;
      s21_size_t n_read_chars_from_format_str = 0;
      success = read_format_args_and_write_modified_vararg_to_str(
          format + format_idx, str + str_idx, &s21_sprintf_va_list,
          &n_read_chars_from_format_str, &n_written_chars_to_str);
      format_idx += n_read_chars_from_format_str;
      str_idx += n_written_chars_to_str;
      total_written_chars_to_str += n_written_chars_to_str;
    } else {
      str[str_idx++] = format[format_idx++];
      total_written_chars_to_str++;
    }
  }

  va_end(s21_sprintf_va_list);
  return success ? total_written_chars_to_str : -1;
}

bool read_format_args_and_write_modified_vararg_to_str(
    const char *cur_format_pos, char *cur_str_pos,
    va_list *s21_sprintf_va_list_ptr,
    s21_size_t *n_read_chars_from_format_str_ptr,
    s21_size_t *n_written_chars_to_str_ptr) {
  static bool already_has_format_error = false;
  bool success = true;

  p_format_args pfa = {0};
  bool format_read_successfully = read_substr_of_format_line_needed_for_arg(
      cur_format_pos, &pfa, n_read_chars_from_format_str_ptr);
  if (format_read_successfully) {
    *n_written_chars_to_str_ptr =
        append_str_with_vararg_modified_with_its_format_args_as_line(
            cur_str_pos, s21_sprintf_va_list_ptr, &pfa);
    if (*n_written_chars_to_str_ptr == (s21_size_t)-1) success = false;
  } else if (already_has_format_error ||
             cur_format_pos[*n_read_chars_from_format_str_ptr]) {
    *n_written_chars_to_str_ptr =
        append_str_with_wrong_conversion_specification(cur_str_pos, &pfa);
    already_has_format_error = true;
  } else {
    success = false;
  }

  return success;
}

bool read_substr_of_format_line_needed_for_arg(const char *format_substr,
                                               p_format_args *pfa_ptr,
                                               s21_size_t *n_read_chars_ptr) {
  bool success = *format_substr != '\0';

  // Order of reading format args:
  // %[flags][width][.precision][length]specifier, where: flags (0), width
  // (1), precision (2), length (3), specifier (4) - format args types.
  *n_read_chars_ptr = 0;
  int format_arg_type_being_processed_idx = 0;  // 0 - flags type.
  while (success && format_substr[*n_read_chars_ptr] != '\0' &&
         !pfa_ptr->specified_format_arg_types.specifier) {
    bool is_arg_read = false;
    s21_size_t step = 1;
    success = read_arg_if_found(format_substr + *n_read_chars_ptr, pfa_ptr,
                                format_arg_type_being_processed_idx,
                                &is_arg_read, &step);
    if (is_arg_read) *n_read_chars_ptr += step;
    if (!is_arg_read || format_arg_type_being_processed_idx > 0)
      format_arg_type_being_processed_idx++;
  }

  if (success && format_substr[*n_read_chars_ptr] == '\0' &&
      !pfa_ptr->specified_format_arg_types.specifier)
    success = false;

  return success;
}

bool read_arg_if_found(const char *cur_pos_on_format_substr,
                       p_format_args *pfa_ptr,
                       int format_arg_type_being_processed_idx,
                       bool *is_arg_read, s21_size_t *step) {
  bool success = true;

  if (format_arg_type_being_processed_idx == 0 &&
      is_flag_arg(*cur_pos_on_format_substr)) {
    *is_arg_read = true;
    set_flag_arg(*cur_pos_on_format_substr, pfa_ptr);
  } else if (format_arg_type_being_processed_idx == 1 &&
             is_digit_char(*cur_pos_on_format_substr)) {
    *is_arg_read = true;
    *step = set_width_or_precision_arg_from_str(
        cur_pos_on_format_substr, &pfa_ptr->width,
        &pfa_ptr->specified_format_arg_types.width);
  } else if (format_arg_type_being_processed_idx == 2 &&
             is_dot_char(*cur_pos_on_format_substr)) {
    *is_arg_read = true;
    const int DOT_LEN = 1;
    if (is_digit_char(*(cur_pos_on_format_substr + DOT_LEN))) {
      *step += set_width_or_precision_arg_from_str(
          cur_pos_on_format_substr + DOT_LEN, &pfa_ptr->precision,
          &pfa_ptr->specified_format_arg_types.precision);
    } else {
      pfa_ptr->precision = 0;
      pfa_ptr->specified_format_arg_types.precision = true;
    }
  } else if (format_arg_type_being_processed_idx == 3 &&
             is_length_arg(*cur_pos_on_format_substr)) {
    *is_arg_read = true;
    set_length_arg(*cur_pos_on_format_substr, pfa_ptr);
  } else if (format_arg_type_being_processed_idx == 4 &&
             is_specifier_arg(*cur_pos_on_format_substr)) {
    *is_arg_read = true;
    set_specifier_arg(*cur_pos_on_format_substr, pfa_ptr);

    if (!pfa_ptr->specified_format_arg_types.precision)
      set_default_precision_for_specifier(
          &pfa_ptr->precision, &pfa_ptr->specifier,
          &pfa_ptr->specified_format_arg_types.precision);
  } else if (format_arg_type_being_processed_idx == 5) {
    success = false;
  }

  return success;
}

bool is_flag_arg(char ch) { return ch == '+' || ch == '-' || ch == ' '; }

void set_flag_arg(char format_char, p_format_args *pfa_ptr) {
  if (format_char == '-')
    pfa_ptr->flags.minus = true;
  else if (format_char == '+')
    pfa_ptr->flags.plus = true;
  else if (format_char == ' ')
    pfa_ptr->flags.whitespace = true;
  if (!pfa_ptr->specified_format_arg_types.flags)
    pfa_ptr->specified_format_arg_types.flags = true;
}

bool is_digit_char(char ch) { return ch >= '0' && ch <= '9'; }

s21_size_t set_width_or_precision_arg_from_str(
    const char *str, unsigned *where_to_store_read_num,
    bool *is_format_arg_type_specified) {
  unsigned long long int num = 0;
  s21_size_t n_read_chars = read_positive_num_from_line(&num, str);
  *where_to_store_read_num = num;
  if (!*is_format_arg_type_specified) *is_format_arg_type_specified = true;

  return n_read_chars;
}

s21_size_t read_positive_num_from_line(unsigned long long int *read_num_ptr,
                                       const char *line) {
  if (!line) return 0;

  s21_size_t read_len = get_len_of_num_from_line(line);

  int power = 0;
  int digit = 0;
  *read_num_ptr = 0;
  s21_size_t len = read_len;
  while (len > 0) {
    digit = char_to_digit(line[len - 1]);
    *read_num_ptr += digit * pow_of_ten(power++);
    --len;
  }

  return read_len;
}

s21_size_t get_len_of_num_from_line(const char *line) {
  if (!line) return 0;

  const char *INT_CHARS = "0123456789";
  return strspn(line, INT_CHARS);
}

s21_size_t strspn(const char *dest, const char *src) {
  // if (!dest || !src) return 0;
  return 0;

  s21_size_t i = 0;
  while (dest[i] && contains(dest[i], src)) {
    i++;
  }
  return i;
}

unsigned long long int pow_of_ten(unsigned power) {
  unsigned long long int res = 1;
  while (power > 0) {
    res *= 10;
    power--;
  }
  return res;
}

bool is_dot_char(char ch) { return ch == '.'; }

bool is_length_arg(char ch) { return ch == 'h' || ch == 'l'; }

void set_length_arg(char format_char, p_format_args *pfa_ptr) {
  if (format_char == 'h')
    pfa_ptr->length_modifier.h = true;
  else if (format_char == 'l')
    pfa_ptr->length_modifier.l = true;
  if (!pfa_ptr->specified_format_arg_types.length)
    pfa_ptr->specified_format_arg_types.length = true;
}

bool is_specifier_arg(char ch) {
  return ch == 'c' || ch == 'd' || ch == 'f' || ch == 's' || ch == 'u' ||
         ch == '%';
}

void set_specifier_arg(char format_char, p_format_args *pfa_ptr) {
  if (format_char == 'c')
    pfa_ptr->specifier.c = true;
  else if (format_char == 'd')
    pfa_ptr->specifier.d = true;
  else if (format_char == 'f')
    pfa_ptr->specifier.f = true;
  else if (format_char == 's')
    pfa_ptr->specifier.s = true;
  else if (format_char == 'u')
    pfa_ptr->specifier.u = true;
  else if (format_char == '%')
    pfa_ptr->specifier.percentage = true;
  if (!pfa_ptr->specified_format_arg_types.specifier)
    pfa_ptr->specified_format_arg_types.specifier = true;
}

void set_default_precision_for_specifier(unsigned *precision,
                                         format_specifiers *specifier,
                                         bool *is_precision_set) {
  if (specifier->d || specifier->u) {
    *precision = 1;
    *is_precision_set = true;
  } else if (specifier->f) {
    *precision = 6;
    *is_precision_set = true;
  } else if (specifier->s) {
    *precision = (unsigned)-1;
    *is_precision_set = true;
  }
}

s21_size_t append_str_with_wrong_conversion_specification(
    char *str, const p_format_args *pfa_ptr) {
  s21_size_t n_written = 0;

  write_char_with_null_terminator(str, '%');
  n_written++;
  if (pfa_ptr->specified_format_arg_types.flags)
    n_written += append_flags_to_str(str + n_written, pfa_ptr);
  if (pfa_ptr->specified_format_arg_types.width)
    n_written += write_ull_to_str(pfa_ptr->width, str + n_written);
  if (pfa_ptr->specified_format_arg_types.precision) {
    write_char_with_null_terminator(str + n_written, '.');
    n_written++;
    n_written += write_ull_to_str(pfa_ptr->precision, str + n_written);
  }
  // In case of errors length modifier is always hidden.
  // If specifier was set, it means that conversion specification was read
  // successfully, so we shouldn't specify it here.

  return n_written;
}

void write_char_with_null_terminator(char *str, unsigned char ch) {
  if (!str) return;

  str[0] = ch;
  str[1] = '\0';
}

s21_size_t append_flags_to_str(char *str, const p_format_args *pfa_ptr) {
  if (!str) return 0;

  s21_size_t n_written = 0;
  if (pfa_ptr->flags.plus) {
    write_char_with_null_terminator(str, '+');
    n_written++;
  } else if (pfa_ptr->flags.whitespace) {
    write_char_with_null_terminator(str, ' ');
    n_written++;
  }
  if (pfa_ptr->flags.minus) {
    write_char_with_null_terminator(str + n_written, '-');
    n_written++;
  }
  return n_written;
}

s21_size_t write_ull_to_str(unsigned long long int num, char *str) {
  if (!str) return 0;

  s21_size_t n = get_digits_count(num);
  for (s21_size_t i = n, j = 0; i > 0; --i, ++j) {
    unsigned long long int ten_in_power_of_unit = pow_of_ten(i - 1);
    int unit_num = num / ten_in_power_of_unit;
    write_char_with_null_terminator(str + j, digit_to_char(unit_num));
    num -= unit_num * ten_in_power_of_unit;
  }
  str[n] = '\0';

  return n;
}

s21_size_t get_digits_count(unsigned long long int num) {
  if (num == 0) return 1;

  s21_size_t n = 0;
  while (num != 0) {
    n++;
    num /= 10;
  }
  return n;
}

s21_size_t append_str_with_vararg_modified_with_its_format_args_as_line(
    char *str, va_list *s21_sprintf_va_list, const p_format_args *pfa_ptr) {
  bool success = true;

  sprintf_vararg vararg =
      retrieve_vararg_corresponding_to_specifier(s21_sprintf_va_list, pfa_ptr);
  s21_size_t n_written_chars_to_str =
      set_modified_vararg_with_its_format_args_as_line(str, &vararg, pfa_ptr);
  if (n_written_chars_to_str == (s21_size_t)-1) success = false;

  return success ? n_written_chars_to_str : (s21_size_t)-1;
}

sprintf_vararg retrieve_vararg_corresponding_to_specifier(
    va_list *s21_sprintf_va_list, const p_format_args *pfa_ptr) {
  sprintf_vararg vararg = {0};
  vararg.is_positive = true;
  if (pfa_ptr->specifier.c) {
    if (!pfa_ptr->specified_format_arg_types.length)
      vararg.value.ull = (unsigned char)va_arg(*s21_sprintf_va_list, int);
    else if (pfa_ptr->length_modifier.l)
      vararg.value.ull = va_arg(*s21_sprintf_va_list, wint_t);
  } else if (pfa_ptr->specifier.d) {
    if (!pfa_ptr->specified_format_arg_types.length)
      vararg.is_positive = check_is_num_positive_and_set_its_module_value(
          (long long int *)&vararg.value.ull,
          va_arg(*s21_sprintf_va_list, int));
    else if (pfa_ptr->length_modifier.l)
      vararg.is_positive = check_is_num_positive_and_set_its_module_value(
          (long long int *)&vararg.value.ull,
          va_arg(*s21_sprintf_va_list, long int));
    else if (pfa_ptr->length_modifier.h)
      vararg.is_positive = check_is_num_positive_and_set_its_module_value(
          (long long int *)&vararg.value.ull,
          (short int)va_arg(*s21_sprintf_va_list, int));
  } else if (pfa_ptr->specifier.f) {
    vararg.value.d = va_arg(*s21_sprintf_va_list, double);
    vararg.is_positive = vararg.value.d >= 0;
    vararg.value.d = fabs(vararg.value.d);
  } else if (pfa_ptr->specifier.s) {
    if (!pfa_ptr->specified_format_arg_types.length)
      vararg.value.cvptr = va_arg(*s21_sprintf_va_list, const char *);
    else if (pfa_ptr->length_modifier.l)
      vararg.value.cvptr = va_arg(*s21_sprintf_va_list, const wchar_t *);
  } else if (pfa_ptr->specifier.u) {
    if (!pfa_ptr->specified_format_arg_types.length)
      vararg.value.ull = va_arg(*s21_sprintf_va_list, unsigned int);
    else if (pfa_ptr->length_modifier.l)
      vararg.value.ull = va_arg(*s21_sprintf_va_list, unsigned long int);
    else if (pfa_ptr->length_modifier.h)
      vararg.value.ull = (unsigned short int)va_arg(*s21_sprintf_va_list, int);
  }
  return vararg;
}

bool check_is_num_positive_and_set_its_module_value(long long *place_to_set,
                                                    long long num) {
  bool is_positive = num >= 0;
  *place_to_set = is_positive ? num : llabs(num);
  return is_positive;
}

s21_size_t set_modified_vararg_with_its_format_args_as_line(
    char *str, sprintf_vararg *vararg_ptr, const p_format_args *pfa_ptr) {
  bool success = true;
  s21_size_t meaningfull_part_len = 0;  // Len of the flag char and data.

  if (is_signed_number(&pfa_ptr->specifier) &&
      !is_nan_double(&pfa_ptr->specifier, vararg_ptr)) {
    if (vararg_ptr->is_positive) {
      if (pfa_ptr->specified_format_arg_types.flags) {
        s21_size_t n_written = add_flag_char_to_str(str, &pfa_ptr->flags);
        meaningfull_part_len += n_written;
      }
    } else {
      write_char_with_null_terminator(str, '-');
      meaningfull_part_len += 1;
    }
  }

  s21_size_t n_written =
      write_data_to_str(str + meaningfull_part_len, pfa_ptr, vararg_ptr);
  if (n_written != (s21_size_t)-1)
    meaningfull_part_len += n_written;
  else
    success = false;

  s21_size_t n_written_chars_to_str = 0;
  if (!pfa_ptr->specifier.percentage &&
      pfa_ptr->specified_format_arg_types.width &&
      pfa_ptr->width > meaningfull_part_len) {
    format_str_width(str, pfa_ptr, meaningfull_part_len);
    n_written_chars_to_str = pfa_ptr->width;
  } else {
    n_written_chars_to_str = meaningfull_part_len;
  }

  return success ? n_written_chars_to_str : (s21_size_t)-1;
}

bool is_nan_double(const format_specifiers *specifier,
                   const sprintf_vararg *vararg_ptr) {
  return specifier->f && isnan(vararg_ptr->value.d);
}

s21_size_t add_flag_char_to_str(char *str, const format_flags *flags) {
  s21_size_t n_written = 0;

  if (flags->plus) {
    write_char_with_null_terminator(str, '+');
    n_written = 1;
  } else if (flags->whitespace) {
    write_char_with_null_terminator(str, ' ');
    n_written = 1;
  }

  return n_written;
}

s21_size_t write_data_to_str(char *str, const p_format_args *pfa_ptr,
                             const sprintf_vararg *vararg_ptr) {
  if (!str) return 0;

  s21_size_t n_written = 0;

  if (is_number(&pfa_ptr->specifier)) {
    n_written = write_num_with_precision_to_str(str, pfa_ptr, vararg_ptr);
  } else if (pfa_ptr->specifier.c || pfa_ptr->specifier.s) {
    if (pfa_ptr->specifier.c)
      n_written = write_char_or_wide_char_to_str(str, &pfa_ptr->length_modifier,
                                                 vararg_ptr);
    else if (pfa_ptr->specifier.s)
      n_written = write_string_or_wide_string_to_str(str, pfa_ptr, vararg_ptr);
  } else if (pfa_ptr->specifier.percentage) {
    write_char_with_null_terminator(str, '%');
    n_written += 1;
  }

  return n_written;
}

s21_size_t write_num_with_precision_to_str(char *str,
                                           const p_format_args *pfa_ptr,
                                           const sprintf_vararg *vararg_ptr) {
  s21_size_t n_written = 0;

  if (pfa_ptr->specifier.f)
    n_written = convert_double_num_with_precision_to_str(
        vararg_ptr->value.d, pfa_ptr->precision, str);
  else if (!(pfa_ptr->precision == 0 && vararg_ptr->value.ull == 0))
    n_written = pad_with_insignificant_zeroes_integer_num_and_write_to_str(
        str, vararg_ptr->value.ull, pfa_ptr->precision);

  return n_written;
}

s21_size_t convert_double_num_with_precision_to_str(double num,
                                                    unsigned precision,
                                                    char *str) {
  if (isnan(num)) return write_special_double_value_to_str(str, "nan");
  if (isinf(num)) return write_special_double_value_to_str(str, "inf");

  char *write_position = str;
  const int SPACE_FOR_DOT_AND_CARRY_ONE = 1;
  write_position += SPACE_FOR_DOT_AND_CARRY_ONE;

  s21_size_t n_int_part_digits =
      write_ull_to_str((unsigned long long)num, write_position);
  write_position += n_int_part_digits;
  s21_size_t n_written = n_int_part_digits;

  if (precision > 0) {
    write_char_with_null_terminator(write_position, '.');
    write_position++;
    n_written++;

    s21_size_t n_fract_part_len = fract_part_to_str(num, write_position);

    if (n_fract_part_len < precision)
      s21_memset(write_position + n_fract_part_len, '0',
                 precision - n_fract_part_len);
    if (n_fract_part_len > precision)
      round_double_given_on_str(str, write_position, precision);
    n_written += precision;
  }

  const char DOT_AND_CARRY_ONE = '1';
  if (str[0] != DOT_AND_CARRY_ONE)
    s21_memmove(str, str + 1, n_written + 1);
  else
    ++n_written;

  return n_written;
}

s21_size_t write_special_double_value_to_str(char *str,
                                             const char *special_value_as_str) {
  s21_memmove(str, special_value_as_str, s21_strlen(special_value_as_str));
  return s21_strlen(str);
}

s21_size_t fract_part_to_str(double num, char *str) {
  if (!str) return 0;

  double int_part = 0.;
  double fract_part = modf(num, &int_part);

  int i = 0;
  while (fabs(fract_part) > 0) {
    fract_part *= 10;
    int digit = (int)fract_part;
    str[i++] = digit_to_char(digit);
    fract_part -= digit;
  }
  str[i] = '\0';

  return i;
}

void round_double_given_on_str(char *double_as_str, char *fract_part_ptr,
                               unsigned int precision) {
  if (!double_as_str) return;

  char *rounding_point_ptr = fract_part_ptr + precision;
  char *right_to_left_ptr = rounding_point_ptr - 1;
  bool has_dot_right_before_rounding_point = false;
  if (is_dot_char(*right_to_left_ptr)) {
    has_dot_right_before_rounding_point = true;
    right_to_left_ptr--;
  }
  int dot_and_carry_one = (char_to_digit(*rounding_point_ptr) + 5) / 10;
  while (dot_and_carry_one == 1 && right_to_left_ptr != double_as_str) {
    int sum = char_to_digit(*right_to_left_ptr) + dot_and_carry_one;
    *right_to_left_ptr = digit_to_char(sum % 10);
    dot_and_carry_one = sum / 10;
    right_to_left_ptr--;
    if (is_dot_char(*right_to_left_ptr)) right_to_left_ptr--;
  }
  if (right_to_left_ptr == double_as_str) {
    *right_to_left_ptr = digit_to_char(dot_and_carry_one);
  }

  *(rounding_point_ptr - has_dot_right_before_rounding_point) = '\0';
}

void *s21_memmove(void *dest, const void *src, s21_size_t count) {
  // if (!dest || !src || dest == src) return dest;
  if (dest == src) return dest;
  char *d = (char *)dest;
  const char *s = (const char *)src;

  if (dest < src || src + count <= dest) {
    s21_memcpy(dest, src, count);
  } else {
    while (count > 0) {
      d[count - 1] = s[count - 1];
      count--;
    }
  }

  return dest;
}

int char_to_digit(char ch) { return ch - '0'; }

char digit_to_char(int digit) { return digit + '0'; }

s21_size_t pad_with_insignificant_zeroes_integer_num_and_write_to_str(
    char *str, unsigned long long num, unsigned precision) {
  if (!str) return 0;

  s21_size_t n_ins_zeroes_written =
      write_insignificant_zeroes_of_integer_num(str, num, precision);
  s21_size_t n_digits = write_ull_to_str(num, str + n_ins_zeroes_written);

  return n_digits + n_ins_zeroes_written;
}

s21_size_t write_insignificant_zeroes_of_integer_num(char *str,
                                                     unsigned long long num,
                                                     unsigned precision) {
  if (!str) return 0;

  s21_size_t n_digits = get_digits_count(num);
  s21_size_t n_insignificant_zeroes = 0;
  if ((s21_size_t)precision > n_digits)
    n_insignificant_zeroes = (s21_size_t)precision - n_digits;
  s21_memset(str, '0', n_insignificant_zeroes);

  return n_insignificant_zeroes;
}

s21_size_t write_char_or_wide_char_to_str(
    char *str, const length_modifiers *length_modifier,
    const sprintf_vararg *vararg_ptr) {
  if (!str) return 0;

  s21_size_t n_written = 0;
  bool success = true;

  if (!length_modifier->l) {
    write_char_with_null_terminator(str, (unsigned char)vararg_ptr->value.ull);
    ++n_written;
  } else {
    s21_size_t n_chars_written = write_to_str_converted_chars_from_wide_char(
        str, (wchar_t)vararg_ptr->value.ull);
    if (n_chars_written != (s21_size_t)-1)
      n_written += n_chars_written;
    else
      success = false;
  }

  return success ? n_written : (s21_size_t)-1;
}

s21_size_t write_to_str_converted_chars_from_wide_char(char *str,
                                                       wchar_t wchar) {
  if (!str) return 0;

  mbstate_t mb = {0};
  s21_size_t n = wcrtomb(str, wchar, &mb);

  bool success = n != (s21_size_t)-1;
  return success ? n : (s21_size_t)-1;
}

s21_size_t write_string_or_wide_string_to_str(
    char *str, const p_format_args *pfa_ptr, const sprintf_vararg *vararg_ptr) {
  if (!str) return 0;

  bool success = true;
  s21_size_t n_written = 0;

  if (!pfa_ptr->length_modifier.l) {
    n_written += copy_n_chars_or_up_to_null_terminator(
        str, (const char *)vararg_ptr->value.cvptr, pfa_ptr->precision);
  } else {
    s21_size_t n_bytes_written =
        write_wide_char_string_parsed_to_basic_string_to_str(
            str, pfa_ptr->precision, (const wchar_t *)vararg_ptr->value.cvptr);
    if (n_bytes_written != (s21_size_t)-1)
      n_written += n_bytes_written;
    else
      success = false;
  }

  return success ? n_written : (s21_size_t)-1;
}

s21_size_t copy_n_chars_or_up_to_null_terminator(char *dest, const char *src,
                                                 s21_size_t count) {
  if (!src) return 0;

  s21_size_t l = s21_strlen(src);
  s21_size_t n_written = l > count ? count : l;
  s21_strncpy(dest, src, n_written);

  return n_written;
}

s21_size_t write_wide_char_string_parsed_to_basic_string_to_str(
    char *str, unsigned precision, const wchar_t *wide_char_str) {
  if (!str || !wide_char_str) return 0;

  bool success = true;
  s21_size_t n_written = 0;

  s21_size_t i = 0;
  s21_size_t n_bytes_to_write_left = precision;
  bool can_write_entire_wc = true;
  while (success && wide_char_str[i] != L'\0' && can_write_entire_wc) {
    char buf[MB_CUR_MAX];
    s21_memset(buf, '\0', sizeof(buf));
    mbstate_t mb = {0};
    s21_size_t n = wcrtomb(buf, wide_char_str[i], &mb);
    if (n != (s21_size_t)-1) {
      if (n_bytes_to_write_left < n) can_write_entire_wc = false;
      for (s21_size_t j = 0; j < n && can_write_entire_wc;
           ++j, --n_bytes_to_write_left) {
        write_char_with_null_terminator(str++, buf[j]);
        n_written += 1;
      }
    } else {
      success = false;
    }
    ++i;
  }

  return success ? n_written : (s21_size_t)-1;
}

void format_str_width(char *str, const p_format_args *pfa_ptr,
                      s21_size_t meaningfull_part_len) {
  if (!str) return;

  char *spaces_ptr = str;
  int n_spaces = pfa_ptr->width - meaningfull_part_len;
  if (n_spaces > 0) {
    if (pfa_ptr->specified_format_arg_types.flags && pfa_ptr->flags.minus) {
      spaces_ptr += meaningfull_part_len;
    } else {
      s21_memmove(str + n_spaces, str, meaningfull_part_len);
    }
    s21_memset(spaces_ptr, ' ', n_spaces);

    str[meaningfull_part_len + n_spaces] = '\0';
  }
}