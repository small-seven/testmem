#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#include <fenv.h>
#if LDBL_MANT_DIG == 64
#define LASTBIT(u) (u.i.m & 1)
#define SPLIT (0x1p32L + 1)
#elif LDBL_MANT_DIG == 113
#define LASTBIT(u) (u.i.lo & 1)
#define SPLIT (0x1p57L + 1)
#endif
#ifdef FE_INEXACT
#endif
#ifdef FE_UNDERFLOW
#endif
#ifdef FE_TOWARDZERO
#endif
#ifdef FE_DOWNWARD
#endif
#ifdef FE_UPWARD
#endif
#if defined(FE_INEXACT) && defined(FE_UNDERFLOW)
#endif
#if defined(FE_INEXACT) && defined(FE_UNDERFLOW)
#endif
#endif
