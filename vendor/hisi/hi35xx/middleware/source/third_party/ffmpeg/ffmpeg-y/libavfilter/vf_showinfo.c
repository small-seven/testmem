#include <inttypes.h>
#include "libavutil/adler32.h"
#include "libavutil/display.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/spherical.h"
#include "libavutil/stereo3d.h"
#include "libavutil/timestamp.h"
#include "libavutil/timecode.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct ShowInfoContext {
    const AVClass *class;
    int calculate_checksums;
} ShowInfoContext;
#define OFFSET(x) offsetof(ShowInfoContext, x)
#define VF AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
