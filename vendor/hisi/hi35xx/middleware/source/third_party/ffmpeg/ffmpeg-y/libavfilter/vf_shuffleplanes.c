#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixfmt.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct ShufflePlanesContext {
    const AVClass *class;

    /* number of planes in the selected pixel format */
    int planes;

    /* mapping indices */
    int map[4];

    /* set to 1 if some plane is used more than once, so we need to make a copy */
    int copy;
} ShufflePlanesContext;
#define OFFSET(x) offsetof(ShufflePlanesContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
