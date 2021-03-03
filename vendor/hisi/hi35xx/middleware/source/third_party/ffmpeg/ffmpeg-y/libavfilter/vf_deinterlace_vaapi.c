#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "vaapi_vpp.h"
#define MAX_REFERENCES 8
typedef struct DeintVAAPIContext {
    VAAPIVPPContext vpp_ctx; // must be the first field

    int                mode;
    int                field_rate;
    int                auto_enable;

    VAProcFilterCapDeinterlacing
                       deint_caps[VAProcDeinterlacingCount];
    int             nb_deint_caps;
    VAProcPipelineCaps pipeline_caps;

    int                queue_depth;
    int                queue_count;
    AVFrame           *frame_queue[MAX_REFERENCES];
    int                extra_delay_for_timestamps;
} DeintVAAPIContext;
#define D(name) case VAProcDeinterlacing ## name: return #name
#undef D
#define OFFSET(x) offsetof(DeintVAAPIContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM)
