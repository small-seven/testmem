#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DelogoContext {
    const AVClass *class;
    int x, y, w, h, band, show;
}  DelogoContext;
#define OFFSET(x) offsetof(DelogoContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#if LIBAVFILTER_VERSION_MAJOR < 7
#endif
#define CHECK_UNSET_OPT(opt)                                            \
#if LIBAVFILTER_VERSION_MAJOR < 7
#else
#endif
