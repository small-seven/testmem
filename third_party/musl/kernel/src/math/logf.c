#include <math.h>
#include <stdint.h>
#include "libm.h"
#include "logf_data.h"
#define T __logf_data.tab
#define A __logf_data.poly
#define Ln2 __logf_data.ln2
#define N (1 << LOGF_TABLE_BITS)
#define OFF 0x3f330000
