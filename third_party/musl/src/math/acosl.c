#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#include "__invtrigl.h"
#if LDBL_MANT_DIG == 64
#define CLEARBOTTOM(u) (u.i.m &= -1ULL << 32)
#elif LDBL_MANT_DIG == 113
#define CLEARBOTTOM(u) (u.i.lo = 0)
#endif
#endif
