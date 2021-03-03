#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct ShuffleFramesContext {
    const AVClass *class;
    char *mapping;
    AVFrame **frames;
    int *map;
    int64_t *pts;
    int in_frames;
    int nb_frames;
} ShuffleFramesContext;
#define OFFSET(x) offsetof(ShuffleFramesContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
