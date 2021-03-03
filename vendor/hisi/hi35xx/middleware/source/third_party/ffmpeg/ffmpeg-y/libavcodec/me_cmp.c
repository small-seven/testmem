#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "copy_block.h"
#include "simple_idct.h"
#include "me_cmp.h"
#include "mpegvideo.h"
#include "config.h"
#define avg2(a, b) (((a) + (b) + 1) >> 1)
#define avg4(a, b, c, d) (((a) + (b) + (c) + (d) + 2) >> 2)
#define V(x) (pix1[x] - pix2[x])
#undef V
#define V(x) (pix1[x] - pix2[x])
#undef V
#if CONFIG_DWT
#endif
#define BUTTERFLY2(o1, o2, i1, i2)              \
#define BUTTERFLY1(x, y)                        \
#define BUTTERFLYA(x, y) (FFABS((x) + (y)) + FFABS((x) - (y)))
#if CONFIG_GPL
#define DCT8_1D                                         \
#define SRC(x) dct[i][x]
#define DST(x, v) dct[i][x] = v
#undef SRC
#undef DST
#define SRC(x) dct[x][i]
#define DST(x, v) sum += FFABS(v)
#undef SRC
#undef DST
#endif
#define VSAD_INTRA(size)                                                \
#define VSAD(size)                                                             \
#define SQ(a) ((a) * (a))
#define VSSE_INTRA(size)                                                \
#define VSSE(size)                                                             \
#define WRAPPER8_16_SQ(name8, name16)                                   \
#if CONFIG_GPL
#endif
#if HAVE_MMX || HAVE_ALTIVEC
#endif
#define SET_CMP_FUNC(name)                      \
#if CONFIG_GPL
#endif
#if CONFIG_SNOW_DECODER || CONFIG_SNOW_ENCODER
#endif
