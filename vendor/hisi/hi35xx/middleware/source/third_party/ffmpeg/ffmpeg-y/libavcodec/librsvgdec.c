#include "avcodec.h"
#include "internal.h"
#include "libavutil/opt.h"
#include "librsvg-2.0/librsvg/rsvg.h"
typedef struct LibRSVGContext {
    AVClass *class;

    int width;
    int height;
    int keep_ar;
} LibRSVGContext;
#define OFFSET(x) offsetof(LibRSVGContext, x)
#define DEC (AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
