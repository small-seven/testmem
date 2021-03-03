#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
#define MAXGAML 1755.455L
#define MAXSTIR 1024.0L
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
#endif
