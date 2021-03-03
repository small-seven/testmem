#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define SPLIT (0x1p32L+1)
#elif LDBL_MANT_DIG == 113
#define SPLIT (0x1p57L+1)
#endif
#endif
