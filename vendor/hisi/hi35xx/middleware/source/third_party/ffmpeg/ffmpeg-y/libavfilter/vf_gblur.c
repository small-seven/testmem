#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "gblur.h"
#include "internal.h"
#include "video.h"
#define OFFSET(x) offsetof(GBlurContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    int height;
    int width;
} ThreadData;
