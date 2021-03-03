#include <tesseract/capi.h>
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct OCRContext {
    const AVClass *class;

    char *datapath;
    char *language;
    char *whitelist;
    char *blacklist;

    TessBaseAPI *tess;
} OCRContext;
#define OFFSET(x) offsetof(OCRContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
