#include "libavutil/avassert.h"
#undef opixel
#define opixel pixel
#undef ipixel
#if IN_BIT_DEPTH == 8
#define ipixel uint8_t
#else
#define ipixel uint16_t
#endif
#undef fn
#undef fn2
#undef fn3
#define fn3(a,b,c,d) a##_##d##p##b##to##c##_c
#define fn2(a,b,c,d) fn3(a,b,c,d)
#define fn(a) fn2(a, IN_BIT_DEPTH, OUT_BIT_DEPTH, ss)
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
