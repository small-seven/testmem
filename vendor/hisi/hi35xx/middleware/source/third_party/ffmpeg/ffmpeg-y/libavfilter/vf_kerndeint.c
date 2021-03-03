#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct KerndeintContext {
    const AVClass *class;
    int           frame; ///< frame count, starting from 0
    int           thresh, map, order, sharp, twoway;
    int           vsub;
    int           is_packed_rgb;
    uint8_t       *tmp_data    [4];  ///< temporary plane data buffer
    int            tmp_linesize[4];  ///< temporary plane byte linesize
    int            tmp_bwidth  [4];  ///< temporary plane byte width
} KerndeintContext;
#define OFFSET(x) offsetof(KerndeintContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
