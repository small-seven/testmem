#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "exp_data.h"
#define N (1 << EXP_TABLE_BITS)
#define Shift __exp_data.exp2_shift
#define T __exp_data.tab
#define C1 __exp_data.exp2_poly[0]
#define C2 __exp_data.exp2_poly[1]
#define C3 __exp_data.exp2_poly[2]
#define C4 __exp_data.exp2_poly[3]
#define C5 __exp_data.exp2_poly[4]
