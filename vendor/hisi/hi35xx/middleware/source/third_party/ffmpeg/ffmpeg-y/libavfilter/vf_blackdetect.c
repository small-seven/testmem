#include <float.h>
#include "libavutil/opt.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "internal.h"
typedef struct BlackDetectContext {
    const AVClass *class;
    double  black_min_duration_time; ///< minimum duration of detected black, in seconds
    int64_t black_min_duration;      ///< minimum duration of detected black, expressed in timebase units
    int64_t black_start;             ///< pts start time of the first black picture
    int64_t black_end;               ///< pts end time of the last black picture
    int64_t last_picref_pts;         ///< pts of the last input picture
    int black_started;

    double       picture_black_ratio_th;
    double       pixel_black_th;
    unsigned int pixel_black_th_i;

    unsigned int nb_black_pixels;   ///< number of black pixels counted so far
} BlackDetectContext;
#define OFFSET(x) offsetof(BlackDetectContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define YUVJ_FORMATS \
