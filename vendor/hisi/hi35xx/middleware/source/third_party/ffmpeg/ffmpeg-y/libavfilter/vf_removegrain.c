#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/qsort.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "removegrain.h"
#include "video.h"
#define OFFSET(x) offsetof(RemoveGrainContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define REMOVE_GRAIN_SORT_AXIS       \
typedef struct ThreadData {
    AVFrame *in, *out;
    int plane;
} ThreadData;
