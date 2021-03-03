#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "sgi.h"
#include "rle.h"
#define SGI_SINGLE_CHAN 2
#define SGI_MULTI_CHAN 3
typedef struct SgiContext {
    AVClass *class;

    int rle;
} SgiContext;
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODER_TYPE
#endif
#define OFFSET(x) offsetof(SgiContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
