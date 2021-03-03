#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
typedef union
{
  double value;
  uint64_t bits64;
  uint32_t bits32[2];
} double_bits_t;
#define INF INFINITY
#include "test-libm.inc.h"
