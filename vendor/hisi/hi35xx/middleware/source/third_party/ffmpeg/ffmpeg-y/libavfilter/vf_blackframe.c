#include <stdio.h>
#include <inttypes.h>
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct BlackFrameContext {
    const AVClass *class;
    int bamount;          ///< black amount
    int bthresh;          ///< black threshold
    unsigned int frame;   ///< frame number
    unsigned int nblack;  ///< number of black pixels counted so far
    unsigned int last_keyframe; ///< frame number of the last received key-frame
} BlackFrameContext;
#define SET_META(key, format, value) \
#define OFFSET(x) offsetof(BlackFrameContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
