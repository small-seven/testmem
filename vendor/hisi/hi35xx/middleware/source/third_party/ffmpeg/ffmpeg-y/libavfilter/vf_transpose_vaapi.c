#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "transpose.h"
#include "vaapi_vpp.h"
typedef struct TransposeVAAPIContext {
    VAAPIVPPContext vpp_ctx; // must be the first field
    int passthrough;         // PassthroughType, landscape passthrough mode enabled
    int dir;                 // TransposeDir

    int rotation_state;
    int mirror_state;
} TransposeVAAPIContext;
#define OFFSET(x) offsetof(TransposeVAAPIContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
