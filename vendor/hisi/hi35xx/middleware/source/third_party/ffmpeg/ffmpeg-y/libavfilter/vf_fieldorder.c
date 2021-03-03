#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct FieldOrderContext {
    const AVClass *class;
    int dst_tff;               ///< output bff/tff
    int          line_size[4]; ///< bytes of pixel data per line for each plane
} FieldOrderContext;
#define OFFSET(x) offsetof(FieldOrderContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
