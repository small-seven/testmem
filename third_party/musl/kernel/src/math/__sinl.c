#include "libm.h"
#if (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define POLY(z) (S2+z*(S3+z*(S4+z*(S5+z*(S6+z*(S7+z*S8))))))
#elif LDBL_MANT_DIG == 113
#define POLY(z) (S2+z*(S3+z*(S4+z*(S5+z*(S6+z*(S7+z*(S8+ \
#endif
#endif
