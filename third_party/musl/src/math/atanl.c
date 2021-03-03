#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define EXPMAN(u) ((u.i.se & 0x7fff)<<8 | (u.i.m>>55 & 0xff))
#elif LDBL_MANT_DIG == 113
#define EXPMAN(u) ((u.i.se & 0x7fff)<<8 | u.i.top>>8)
#endif
#endif
