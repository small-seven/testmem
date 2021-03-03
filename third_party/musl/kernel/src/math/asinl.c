#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#include "__invtrigl.h"
#if LDBL_MANT_DIG == 64
#define CLOSETO1(u) (u.i.m>>56 >= 0xf7)
#define CLEARBOTTOM(u) (u.i.m &= -1ULL << 32)
#elif LDBL_MANT_DIG == 113
#define CLOSETO1(u) (u.i.top >= 0xee00)
#define CLEARBOTTOM(u) (u.i.lo = 0)
#endif
#endif
