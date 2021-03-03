#include "libm.h"
#if (LDBL_MANT_DIG == 64 || LDBL_MANT_DIG == 113) && LDBL_MAX_EXP == 16384
#if LDBL_MANT_DIG == 64
#define SMALL(u) (((u.i.se & 0x7fffU)<<16 | u.i.m>>48) < ((0x3fff + 25)<<16 | 0x921f>>1 | 0x8000))
#define QUOBITS(x) ((uint32_t)(int32_t)x & 0x7fffffff)
#define ROUND1 22
#define ROUND2 61
#define NX 3
#define NY 2
#elif LDBL_MANT_DIG == 113
#define SMALL(u) (((u.i.se & 0x7fffU)<<16 | u.i.top) < ((0x3fff + 45)<<16 | 0x921f))
#define QUOBITS(x) ((uint32_t)(int64_t)x & 0x7fffffff)
#define ROUND1 51
#define ROUND2 119
#define NX 5
#define NY 3
#endif
#endif
