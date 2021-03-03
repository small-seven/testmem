#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bsf.h"
typedef struct RemoveExtradataContext {
    const AVClass *class;
    int freq;

    AVCodecParserContext *parser;
    AVCodecContext *avctx;
} RemoveExtradataContext;
#define OFFSET(x) offsetof(RemoveExtradataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
