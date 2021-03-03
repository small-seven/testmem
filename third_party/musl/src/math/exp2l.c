#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
#define TBLBITS 7
#define TBLSIZE (1 << TBLBITS)
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
#define TBLBITS 7
#define TBLSIZE (1 << TBLBITS)
#endif
