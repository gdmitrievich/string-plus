#ifndef SPRINTF_VARARG_H
#define SPRINTF_VARARG_H

#include "common.h"

typedef union {
  unsigned long long ull;
  const void *cvptr;
  double d;
} value;

typedef struct {
  value value;       // Contains only positive number.
  bool is_positive;  // Hold the sign of the number.
} sprintf_vararg;

#endif  // SPRINTF_VARARG_H