#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "lavfutils.h"
typedef struct CoverContext {
    AVClass *class;
    int mode;
    char *cover_filename;
    AVFrame *cover_frame;
    int width, height;
} CoverContext;
#define OFFSET(x) offsetof(CoverContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
