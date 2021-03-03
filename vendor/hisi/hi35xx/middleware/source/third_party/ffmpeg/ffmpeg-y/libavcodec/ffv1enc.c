#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timer.h"
#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
#include "rangecoder.h"
#include "golomb.h"
#include "mathops.h"
#include "ffv1.h"
#define put_rac(C, S, B)                        \
#undef put_rac
#define TYPE int16_t
#define RENAME(name) name
#include "ffv1enc_template.c"
#undef TYPE
#undef RENAME
#define TYPE int32_t
#define RENAME(name) name ## 32
#include "ffv1enc_template.c"
#define COST(old, new)                                      \
#define COST2(old, new)                         \
#if FF_API_CODER_TYPE
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODED_FRAME
#endif
#define STATS_OUT_SIZE 1024 * 1024 * 6
#define NB_Y_COEFF 15
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(FFV1Context, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_CODER_TYPE
#endif
#if FF_API_CODER_TYPE
#endif
