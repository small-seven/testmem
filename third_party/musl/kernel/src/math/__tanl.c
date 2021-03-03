#include "libm.h"
#if (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define RPOLY(w) (T5 + w * (T9 + w * (T13 + w * (T17 + w * (T21 + \
#define VPOLY(w) (T7 + w * (T11 + w * (T15 + w * (T19 + w * (T23 + \
#elif LDBL_MANT_DIG == 113
#define RPOLY(w) (T5 + w * (T9 + w * (T13 + w * (T17 + w * (T21 + \
#define VPOLY(w) (T7 + w * (T11 + w * (T15 + w * (T19 + w * (T23 + \
#endif
#endif
