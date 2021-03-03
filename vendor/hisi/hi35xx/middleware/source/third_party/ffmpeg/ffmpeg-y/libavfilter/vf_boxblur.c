#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "boxblur.h"
typedef struct BoxBlurContext {
    const AVClass *class;
    FilterParam luma_param;
    FilterParam chroma_param;
    FilterParam alpha_param;

    int hsub, vsub;
    int radius[4];
    int power[4];
    uint8_t *temp[2]; ///< temporary buffer used in blur_power()
} BoxBlurContext;
#define BLUR(type, depth)                                                   \
#undef BLUR
#define OFFSET(x) offsetof(BoxBlurContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
