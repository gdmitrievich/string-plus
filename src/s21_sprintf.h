#ifndef S21_SPRINTF_H
#define S21_SPRINTF_H

#include <stdarg.h>
#include <wchar.h>

#include "common.h"
#include "p_format_args.h"
#include "sprintf_vararg.h"

/// @return Return the number of characters printed (excluding the null byte).
/// If an output error is encountered, a negative value is returned.
int s21_sprintf(char* str, const char* format, ...);

bool read_format_args_and_write_modified_vararg_to_str(
    const char* cur_format_pos, char* cur_str_pos,
    va_list* s21_sprintf_va_list_ptr,
    s21_size_t* n_read_chars_from_format_str_ptr,
    s21_size_t* n_written_chars_to_str_ptr);

/// @brief Reads format arguments given in 'format_substr' until specifier
/// argument will found and stores them in object pointed by 'pfa_ptr'.
/// @param format_substr Pointer to the part of the format string, that points
/// to the character followed immediately after '%'.
/// @param pfa_ptr Pointer, that will store read format arguments.
/// @param n_read_chars_ptr Will store a number of read chars.
/// @return true, if there are no errors while parsing 'format_substring',
/// otherwise false.
bool read_substr_of_format_line_needed_for_arg(const char* format_substr,
                                               p_format_args* pfa_ptr,
                                               s21_size_t* n_read_chars_ptr);

bool read_arg_if_found(const char* cur_pos_on_format_substr,
                       p_format_args* pfa_ptr,
                       int format_arg_type_being_processed_idx,
                       bool* is_arg_read, s21_size_t* step);

bool is_flag_arg(char ch);
void set_flag_arg(char format_char, p_format_args* pfa_ptr);

bool is_digit_char(char ch);
s21_size_t set_width_or_precision_arg_from_str(
    const char* str, unsigned* where_to_store_read_num,
    bool* is_format_arg_type_specified);
/// @brief Convert a sequence of character digits that can be stored on unsigned
/// long long int type. Starts from the first character pointed by 'line'.
/// @param read_num_ptr Pointer to the number that will store converted value.
/// @param line Line, that starts with the digits that should be converted.
/// @return Returns the number of read characters.
s21_size_t read_positive_num_from_line(unsigned long long int* read_num_ptr,
                                       const char* line);
s21_size_t get_len_of_num_from_line(const char* line);

s21_size_t strspn(const char* dest, const char* src);

unsigned long long int pow_of_ten(unsigned power);

bool is_dot_char(char ch);

bool is_length_arg(char ch);
void set_length_arg(char format_char, p_format_args* pfa_ptr);

bool is_specifier_arg(char ch);
void set_specifier_arg(char format_char, p_format_args* pfa_ptr);

void set_default_precision_for_specifier(unsigned* precision,
                                         format_specifiers* specifier,
                                         bool* is_precision_set);

s21_size_t append_str_with_wrong_conversion_specification(
    char* str, const p_format_args* pfa_ptr);
void write_char_with_null_terminator(char* str, unsigned char ch);
s21_size_t append_flags_to_str(char* str, const p_format_args* pfa_ptr);
/// @brief Writes 'num' converted to its character representation to 'str'.
/// @return Returns number of written characters (number of 'num' digits).
s21_size_t write_ull_to_str(unsigned long long int num, char* str);
s21_size_t get_digits_count(unsigned long long int num);

s21_size_t append_str_with_vararg_modified_with_its_format_args_as_line(
    char* str, va_list* s21_sprintf_va_list, const p_format_args* pfa_ptr);

sprintf_vararg retrieve_vararg_corresponding_to_specifier(
    va_list* s21_sprintf_va_list, const p_format_args* pfa_ptr);

bool check_is_num_positive_and_set_its_module_value(long long* place_to_set,
                                                    long long num);

s21_size_t set_modified_vararg_with_its_format_args_as_line(
    char* line_to_set, sprintf_vararg* vararg_ptr,
    const p_format_args* pfa_ptr);

bool is_nan_double(const format_specifiers* specifier,
                   const sprintf_vararg* vararg_ptr);

/// @return Returns the number of written chars. 1 if - or (space) flags given,
/// otherwise 0.
s21_size_t add_flag_char_to_str(char* str, const format_flags* flags);

s21_size_t write_data_to_str(char* str, const p_format_args* pfa_ptr,
                             const sprintf_vararg* vararg_ptr);

/// @return Returns the number of written chars.
s21_size_t write_num_with_precision_to_str(char* str,
                                           const p_format_args* pfa_ptr,
                                           const sprintf_vararg* vararg_ptr);

/// @return Returns the number of written chars.
s21_size_t convert_double_num_with_precision_to_str(double num,
                                                    unsigned precision,
                                                    char* str);

/// @return Returns the number of written chars.
s21_size_t write_special_double_value_to_str(char* str,
                                             const char* special_value_as_str);

/// @brief Writes only digits from fractional part of 'num' without dot on
/// 'str'. If fract part equals to zero, then nothing be written. The resulting
/// byte string is null-terminated.
/// @param num
/// @param str
/// @return Returns number of digits written to 'str' (number of digits on
/// fractional part of 'num').
s21_size_t fract_part_to_str(double num, char* str);

/// @brief Rounds double given as string 'double_as_str' with a certain
/// 'precision'. Note, that first char pointed by 'double_as_str' should be
/// empty for dot and carry one. Example (with precision = 1): 99.99 -> 100.0. 1
/// goes on the next unit.
/// @param double_as_str Points to the string in which double stored. The first
/// char should be empty.
/// @param fract_part_ptr Points to the first digit of the fractional part of
/// double.
/// @param precision
void round_double_given_on_str(char* double_as_str, char* fract_part_ptr,
                               unsigned int precision);

void* memmove(void* dest, const void* src, s21_size_t count);

int char_to_digit(char ch);
char digit_to_char(int digit);

/// @brief Writes num to str. If precision is bigger than number of digits on
/// 'num', insignificant zeroes will be written.
/// @return Returns the number of written chars.
s21_size_t pad_with_insignificant_zeroes_integer_num_and_write_to_str(
    char* str, unsigned long long num, unsigned precision);

s21_size_t write_insignificant_zeroes_of_integer_num(char* str,
                                                     unsigned long long num,
                                                     unsigned precision);

/// @return Returns the number of written chars on success, otherwise
/// (s21_size_t)-1.
s21_size_t write_char_or_wide_char_to_str(
    char* str, const length_modifiers* length_modifier,
    const sprintf_vararg* vararg_ptr);

/// @return Returns the number of written bytes on multibyte sequence on
/// success, otherwise (s21_size_t)-1.
s21_size_t write_to_str_converted_chars_from_wide_char(char* str,
                                                       wchar_t wchar);

/// @return Returns the number of written chars on success, otherwise
/// (s21_size_t)-1.
s21_size_t write_string_or_wide_string_to_str(char* str,
                                              const p_format_args* pfa_ptr,
                                              const sprintf_vararg* vararg_ptr);
/// @return Returns the number of copied chars from src to dest.
s21_size_t copy_n_chars_or_up_to_null_terminator(char* dest, const char* src,
                                                 s21_size_t count);

/// @return Returns the number of written bytes from parsed wide char array on
/// success, otherwise (s21_size_t)-1.
s21_size_t write_wide_char_string_parsed_to_basic_string_to_str(
    char* str, unsigned precision, const wchar_t* wide_char_str);

void format_str_width(char* str, const p_format_args* pfa_ptr,
                      s21_size_t meaningfull_part_len);

#endif  // S21_SPRINTF_H