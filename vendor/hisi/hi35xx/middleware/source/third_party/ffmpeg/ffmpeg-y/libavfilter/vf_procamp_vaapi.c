#include <string.h>
#include "libavutil/avassert.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "vaapi_vpp.h"
#define BRIGHTNESS_MIN     -100.0F
#define BRIGHTNESS_MAX      100.0F
#define BRIGHTNESS_DEFAULT    0.0F
#define CONTRAST_MIN          0.0F
#define CONTRAST_MAX         10.0F
#define CONTRAST_DEFAULT      1.0F
#define HUE_MIN            -180.0F
#define HUE_MAX             180.0F
#define HUE_DEFAULT           0.0F
#define SATURATION_MIN        0.0F
#define SATURATION_MAX       10.0F
#define SATURATION_DEFAULT    1.0F
typedef struct ProcampVAAPIContext {
    VAAPIVPPContext vpp_ctx; // must be the first field

    float bright;
    float hue;
    float saturation;
    float contrast;
} ProcampVAAPIContext;
#define OFFSET(x) offsetof(ProcampVAAPIContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
