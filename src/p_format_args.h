#ifndef P_FORMAT_ARGS_H
#define P_FORMAT_ARGS_H

#include "common.h"

typedef struct {
  bool minus, plus, whitespace;
} format_flags;

typedef struct {
  bool h, l;
} length_modifiers;

typedef struct {
  bool c, d, f, s, u, percentage;
} format_specifiers;

typedef struct {
  bool flags, width, precision, length, specifier;
} specified_format_arg_types;  // [flags][width][.precision][length]specifier.

typedef struct {
  format_flags flags;
  unsigned width;
  unsigned precision;
  length_modifiers length_modifier;
  format_specifiers specifier;

  specified_format_arg_types specified_format_arg_types;
} p_format_args;

bool is_signed_number(const format_specifiers *specifier);
bool is_number(const format_specifiers *specifier);

#endif  // P_FORMAT_ARGS_H