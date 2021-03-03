#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
typedef struct CLJRContext {
    AVClass        *avclass;
    int             dither_type;
} CLJRContext;
#define OFFSET(x) offsetof(CLJRContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
