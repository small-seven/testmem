#include "avcodec.h"
#include "diracdsp.h"
#define FILTER(src, stride)                                     \
#define PIXOP_BILINEAR(PFX, OP, WIDTH)                                  \
#define OP_PUT(dst, val) (dst) = (val)
#define OP_AVG(dst, val) (dst) = (((dst) + (val) + 1)>>1)
#define op_scale1(x)  block[x] = av_clip_uint8( (block[x]*weight + (1<<(log2_denom-1))) >> log2_denom)
#define op_scale2(x)  dst[x] = av_clip_uint8( (src[x]*weights + dst[x]*weightd + (1<<(log2_denom-1))) >> log2_denom)
#define DIRAC_WEIGHT(W)                                                 \
#define ADD_OBMC(xblen)                                                 \
#define PUT_SIGNED_RECT_CLAMPED(PX)                                                                     \
#define DEQUANT_SUBBAND(PX)                                                                \
#define PIXFUNC(PFX, WIDTH)                                             \
