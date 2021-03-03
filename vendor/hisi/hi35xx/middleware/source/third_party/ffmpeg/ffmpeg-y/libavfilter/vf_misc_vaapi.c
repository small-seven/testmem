#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "vaapi_vpp.h"
#define DENOISE_MIN            0
#define DENOISE_MAX            64
#define DENOISE_DEFAULT        0
#define SHARPNESS_MIN          0
#define SHARPNESS_MAX          64
#define SHARPNESS_DEFAULT      44
typedef struct DenoiseVAAPIContext {
    VAAPIVPPContext vpp_ctx; // must be the first field

    int denoise;         // enable denoise algo.
} DenoiseVAAPIContext;
typedef struct SharpnessVAAPIContext {
    VAAPIVPPContext vpp_ctx; // must be the first field

    int sharpness;       // enable sharpness.
} SharpnessVAAPIContext;
#define DOFFSET(x) offsetof(DenoiseVAAPIContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
#define SOFFSET(x) offsetof(SharpnessVAAPIContext, x)
