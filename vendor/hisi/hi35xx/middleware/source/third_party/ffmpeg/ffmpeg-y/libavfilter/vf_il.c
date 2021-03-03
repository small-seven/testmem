#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
typedef struct IlContext {
    const AVClass *class;
    int luma_mode, chroma_mode, alpha_mode; ///<FilterMode
    int luma_swap, chroma_swap, alpha_swap;
    int nb_planes;
    int linesize[4], chroma_height;
    int has_alpha;
} IlContext;
#define OFFSET(x) offsetof(IlContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
