#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "bsf.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
typedef struct NoiseContext {
    const AVClass *class;
    int amount;
    int dropamount;
    unsigned int state;
} NoiseContext;
#define OFFSET(x) offsetof(NoiseContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_BSF_PARAM)
