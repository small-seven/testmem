#include "libm.h"
#if LDBL_MANT_DIG == 53 && LDBL_MAX_EXP == 1024
#elif LDBL_MANT_DIG == 64 && LDBL_MAX_EXP == 16384
#define NXT 32
#define MEXP (NXT*16384.0L)
#define MNEXP (-NXT*(16384.0L+64.0L))
#define LOG2EA 0.44269504088896340735992L
#define F W
#define Fa Wa
#define Fb Wb
#define G W
#define Ga Wa
#define Gb u
#define H W
#define Ha Wb
#define Hb Wb
#elif LDBL_MANT_DIG == 113 && LDBL_MAX_EXP == 16384
#endif
