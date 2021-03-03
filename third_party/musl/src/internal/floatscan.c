#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <float.h>
#include <limits.h>
#include <errno.h>
#include <ctype.h>
#include "shgetc.h"
#include "floatscan.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#define LD_B1B_DIG 2
#define LD_B1B_MAX 9007199, 254740991
#define KMAX 128
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
#define LD_B1B_DIG 3
#define LD_B1B_MAX 18, 446744073, 709551615
#define KMAX 2048
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
#define LD_B1B_DIG 4
#define LD_B1B_MAX 10384593, 717069655, 257060992, 658440191
#define KMAX 2048
#else
#error Unsupported long double representation
#endif
#define MASK (KMAX-1)
