#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct CropDetectContext {
    const AVClass *class;
    int x1, y1, x2, y2;
    float limit;
    int round;
    int reset_count;
    int frame_nb;
    int max_pixsteps[4];
    int max_outliers;
} CropDetectContext;
#define SET_META(key, value) \
#define FIND(DST, FROM, NOEND, INC, STEP0, STEP1, LEN) \
#define OFFSET(x) offsetof(CropDetectContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
