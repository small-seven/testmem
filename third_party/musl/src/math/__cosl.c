#include "libm.h"
#if (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define POLY(z) (z*(C1+z*(C2+z*(C3+z*(C4+z*(C5+z*(C6+z*C7)))))))
#elif LDBL_MANT_DIG == 113
#define POLY(z) (z*(C1+z*(C2+z*(C3+z*(C4+z*(C5+z*(C6+z*(C7+ \
#endif
#endif
