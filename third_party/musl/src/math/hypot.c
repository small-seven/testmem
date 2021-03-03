#include <math.h>
#include <stdint.h>
#include <float.h>
#if FLT_EVAL_METHOD > 1U && LDBL_MANT_DIG == 64
#define SPLIT (0x1p32 + 1)
#else
#define SPLIT (0x1p27 + 1)
#endif
