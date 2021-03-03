#include "libavutil/avassert.h"
#undef avg
#undef ss
#if SS_W == 0
#define ss 444
#define avg(a,b,c,d) (a)
#elif SS_H == 0
#define ss 422
#define avg(a,b,c,d) (((a) + (b) + 1) >> 1)
#else
#define ss 420
#define avg(a,b,c,d) (((a) + (b) + (c) + (d) + 2) >> 2)
#endif
#undef fn
#undef fn2
#undef fn3
#define fn3(a,b,c) a##_##c##p##b##_c
#define fn2(a,b,c) fn3(a,b,c)
#define fn(a) fn2(a, BIT_DEPTH, ss)
#undef pixel
#undef av_clip_pixel
#if BIT_DEPTH == 8
#define pixel uint8_t
#define av_clip_pixel(x) av_clip_uint8(x)
#else
#define pixel uint16_t
#define av_clip_pixel(x) av_clip_uintp2(x, BIT_DEPTH)
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#if SS_W == 1
#if SS_H == 1
#endif
#endif
#undef IN_BIT_DEPTH
#undef OUT_BIT_DEPTH
#define OUT_BIT_DEPTH BIT_DEPTH
#define IN_BIT_DEPTH 8
#include "colorspacedsp_yuv2yuv_template.c"
#undef IN_BIT_DEPTH
#define IN_BIT_DEPTH 10
#include "colorspacedsp_yuv2yuv_template.c"
#undef IN_BIT_DEPTH
#define IN_BIT_DEPTH 12
#include "colorspacedsp_yuv2yuv_template.c"
