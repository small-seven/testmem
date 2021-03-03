#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "h264chroma.h"
#include "qpeldsp.h"
#include "rnd_avg.h"
#include "vc1dsp.h"
#include "startcode.h"
#define VC1_MSPEL_FILTER_16B(DIR, TYPE)                                       \
#define VC1_MSPEL_MC(OP, OP4, OPNAME)                                         \
#define op_put(a, b) (a) = av_clip_uint8(b)
#define op_avg(a, b) (a) = ((a) + av_clip_uint8(b) + 1) >> 1
#define op4_avg(a, b) (a) = rnd_avg32(a, b)
#define op4_put(a, b) (a) = (b)
#define PUT_VC1_MSPEL(a, b)                                                   \
#define chroma_mc(a) \
#define avg2(a, b) (((a) + (b) + 1) >> 1)
#if CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER
#endif /* CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER */
#define FN_ASSIGN(X, Y) \
#if CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER
#endif /* CONFIG_WMV3IMAGE_DECODER || CONFIG_VC1IMAGE_DECODER */
