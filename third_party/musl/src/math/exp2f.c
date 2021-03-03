#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "exp2f_data.h"
#define N (1 << EXP2F_TABLE_BITS)
#define T __exp2f_data.tab
#define C __exp2f_data.poly
#define SHIFT __exp2f_data.shift_scaled
