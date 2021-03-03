#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct ShowPaletteContext {
    const AVClass *class;
    int size;
} ShowPaletteContext;
#define OFFSET(x) offsetof(ShowPaletteContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
