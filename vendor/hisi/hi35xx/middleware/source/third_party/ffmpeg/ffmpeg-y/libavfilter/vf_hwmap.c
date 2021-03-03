#include "libavutil/buffer.h"
#include "libavutil/hwcontext.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct HWMapContext {
    const AVClass *class;

    AVBufferRef   *hwframes_ref;

    int            mode;
    char          *derive_device_type;
    int            reverse;
} HWMapContext;
#define OFFSET(x) offsetof(HWMapContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM)
