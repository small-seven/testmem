#include "avcodec.h"
#include "huffyuv.h"
#include "huffman.h"
#include "huffyuvencdsp.h"
#include "internal.h"
#include "lossless_videoencdsp.h"
#include "put_bits.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#define STATS_OUT_SIZE 21*MAX_N*3 + 4
#if FF_API_CODED_FRAME
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#define LOAD4\
#define LOADEND\
#define LOADEND_14\
#define LOADEND_16\
#define STATEND\
#define STATEND_16\
#define WRITEEND\
#define WRITEEND_16\
#define LOAD2\
#define LOAD2_14\
#define LOAD2_16\
#define STAT2\
#define STAT2_16\
#define WRITE2\
#define WRITE2_16\
#undef LOAD2
#undef STAT2
#undef WRITE2
#define LOAD2\
#define STAT2\
#define WRITE2\
#define LOAD_GBRA                                                       \
#define STAT_BGRA                                                       \
#define WRITE_GBRA                                                      \
#define OFFSET(x) offsetof(HYuvContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#define COMMON_OPTIONS \
#if CONFIG_FFVHUFF_ENCODER
#endif
