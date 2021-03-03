#include "get_bits.h"
#include "hevcdec.h"
#include "bit_depth_template.c"
#include "hevcdsp.h"
#define SET(dst, x)   (dst) = (x)
#define SCALE(dst, x) (dst) = av_clip_int16(((x) + add) >> shift)
#define TR_4x4_LUMA(dst, src, step, assign)                             \
#undef TR_4x4_LUMA
#define TR_4(dst, src, dstep, sstep, assign, end)                 \
#define TR_8(dst, src, dstep, sstep, assign, end)                 \
#define TR_16(dst, src, dstep, sstep, assign, end)                \
#define TR_32(dst, src, dstep, sstep, assign, end)                \
#define IDCT_VAR4(H)                                              \
#define IDCT_VAR8(H)                                              \
#define IDCT_VAR16(H)   IDCT_VAR8(H)
#define IDCT_VAR32(H)   IDCT_VAR8(H)
#define IDCT(H)                                                   \
#define IDCT_DC(H)                                                \
#undef TR_4
#undef TR_8
#undef TR_16
#undef TR_32
#undef SET
#undef SCALE
#define CMP(a, b) (((a) > (b)) - ((a) < (b)))
#undef CMP
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#define QPEL_FILTER(src, stride)                                               \
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#define EPEL_FILTER(src, stride)                                               \
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#if BIT_DEPTH < 14
#else
#endif
#define P3 pix[-4 * xstride]
#define P2 pix[-3 * xstride]
#define P1 pix[-2 * xstride]
#define P0 pix[-1 * xstride]
#define Q0 pix[0 * xstride]
#define Q1 pix[1 * xstride]
#define Q2 pix[2 * xstride]
#define Q3 pix[3 * xstride]
#define TP3 pix[-4 * xstride + 3 * ystride]
#define TP2 pix[-3 * xstride + 3 * ystride]
#define TP1 pix[-2 * xstride + 3 * ystride]
#define TP0 pix[-1 * xstride + 3 * ystride]
#define TQ0 pix[0  * xstride + 3 * ystride]
#define TQ1 pix[1  * xstride + 3 * ystride]
#define TQ2 pix[2  * xstride + 3 * ystride]
#define TQ3 pix[3  * xstride + 3 * ystride]
#undef P3
#undef P2
#undef P1
#undef P0
#undef Q0
#undef Q1
#undef Q2
#undef Q3
#undef TP3
#undef TP2
#undef TP1
#undef TP0
#undef TQ0
#undef TQ1
#undef TQ2
#undef TQ3
