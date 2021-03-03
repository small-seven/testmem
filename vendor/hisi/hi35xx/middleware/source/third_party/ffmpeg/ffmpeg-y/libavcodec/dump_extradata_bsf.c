#include <string.h>
#include "avcodec.h"
#include "bsf.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
typedef struct DumpExtradataContext {
    const AVClass *class;
    AVPacket pkt;
    int freq;
} DumpExtradataContext;
#define OFFSET(x) offsetof(DumpExtradataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
