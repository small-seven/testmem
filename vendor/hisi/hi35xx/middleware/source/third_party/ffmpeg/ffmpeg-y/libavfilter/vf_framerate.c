#define DEBUG
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
#include "filters.h"
#include "framerate.h"
#include "scene_sad.h"
#define OFFSET(x) offsetof(FrameRateContext, x)
#define V AV_OPT_FLAG_VIDEO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
#define FRAMERATE_FLAG_SCD 01
typedef struct ThreadData {
    AVFrame *copy_src1, *copy_src2;
    uint16_t src1_factor, src2_factor;
} ThreadData;
