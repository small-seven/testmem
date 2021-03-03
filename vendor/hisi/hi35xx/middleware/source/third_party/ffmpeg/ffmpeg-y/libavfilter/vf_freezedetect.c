#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "filters.h"
#include "scene_sad.h"
typedef struct FreezeDetectContext {
    const AVClass *class;

    ptrdiff_t width[4];
    ptrdiff_t height[4];
    ff_scene_sad_fn sad;
    int bitdepth;
    AVFrame *reference_frame;
    int64_t n;
    int64_t reference_n;
    int frozen;

    double noise;
    int64_t duration;            ///< minimum duration of frozen frame until notification
} FreezeDetectContext;
#define OFFSET(x) offsetof(FreezeDetectContext, x)
#define V AV_OPT_FLAG_VIDEO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
