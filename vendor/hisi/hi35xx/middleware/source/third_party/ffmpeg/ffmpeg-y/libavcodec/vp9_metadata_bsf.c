#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "bsf.h"
#include "cbs.h"
#include "cbs_vp9.h"
typedef struct VP9MetadataContext {
    const AVClass *class;

    CodedBitstreamContext *cbc;
    CodedBitstreamFragment fragment;

    int color_space;
    int color_range;

    int color_range_rgb_warned;
} VP9MetadataContext;
#define OFFSET(x) offsetof(VP9MetadataContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_BSF_PARAM)
