#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "mathops.h"
#include "vp8dsp.h"
#define MK_IDCT_DC_ADD4_C(name)                                               \
#if CONFIG_VP7_DECODER
#endif /* CONFIG_VP7_DECODER */
#if CONFIG_VP8_DECODER
#define MUL_20091(a) ((((a) * 20091) >> 16) + (a))
#define MUL_35468(a)  (((a) * 35468) >> 16)
#endif /* CONFIG_VP8_DECODER */
#define LOAD_PIXELS                                                           \
#define clip_int8(n) (cm[(n) + 0x80] - 0x80)
#define NORMAL_LIMIT(vpn)                                                     \
#define LOOP_FILTER(vpn, dir, size, stridea, strideb, maybe_inline)           \
#define UV_LOOP_FILTER(vpn, dir, stridea, strideb)                            \
#define LOOP_FILTER_SIMPLE(vpn)                                               \
#define LOOP_FILTERS(vpn)                \
#define PUT_PIXELS(WIDTH)                                                     \
#define FILTER_6TAP(src, F, stride)                                           \
#define FILTER_4TAP(src, F, stride)                                           \
#define VP8_EPEL_H(SIZE, TAPS)                                                \
#define VP8_EPEL_V(SIZE, TAPS)                                                \
#define VP8_EPEL_HV(SIZE, HTAPS, VTAPS)                                       \
#define VP8_BILINEAR(SIZE)                                                    \
#define VP78_MC_FUNC(IDX, SIZE)                                               \
#define VP78_BILINEAR_MC_FUNC(IDX, SIZE)                                      \
#if CONFIG_VP7_DECODER
#endif /* CONFIG_VP7_DECODER */
#if CONFIG_VP8_DECODER
#endif /* CONFIG_VP8_DECODER */
