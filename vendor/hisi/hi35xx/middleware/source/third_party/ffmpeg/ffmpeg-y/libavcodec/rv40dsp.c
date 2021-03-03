#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "h264qpel.h"
#include "mathops.h"
#include "pixels.h"
#include "rnd_avg.h"
#include "rv34dsp.h"
#include "libavutil/avassert.h"
#define RV40_LOWPASS(OPNAME, OP) \
#define RV40_MC(OPNAME, SIZE) \
#define op_avg(a, b)  a = (((a)+cm[b]+1)>>1)
#define op_put(a, b)  a = cm[b]
#undef op_avg
#undef op_put
#define PIXOP2(OPNAME, OP)                                              \
#define op_avg(a, b) a = rnd_avg32(a, b)
#define op_put(a, b) a = b
#undef op_avg
#undef op_put
#define RV40_CHROMA_MC(OPNAME, OP)\
#define op_avg(a, b) a = (((a)+((b)>>6)+1)>>1)
#define op_put(a, b) a = ((b)>>6)
#define RV40_WEIGHT_FUNC(size) \
#define CLIP_SYMM(a, b) av_clip(a, -(b), b)
