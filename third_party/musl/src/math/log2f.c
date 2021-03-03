#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "log2f_data.h"
#define N (1 << LOG2F_TABLE_BITS)
#define T __log2f_data.tab
#define A __log2f_data.poly
#define OFF 0x3f330000
