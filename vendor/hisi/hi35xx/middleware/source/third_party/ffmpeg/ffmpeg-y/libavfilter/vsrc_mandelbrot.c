#include "avfilter.h"
#include "formats.h"
#include "video.h"
#include "internal.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include <float.h>
#include <math.h>
#define SQR(a) ((a)*(a))
typedef struct Point {
    double p[2];
    uint32_t val;
} Point;
typedef struct MBContext {
    const AVClass *class;
    int w, h;
    AVRational frame_rate;
    uint64_t pts;
    int maxiter;
    double start_x;
    double start_y;
    double start_scale;
    double end_scale;
    double end_pts;
    double bailout;
    int outer;
    int inner;
    int cache_allocated;
    int cache_used;
    Point *point_cache;
    Point *next_cache;
    double (*zyklus)[2];
    uint32_t dither;

    double morphxf;
    double morphyf;
    double morphamp;
} MBContext;
#define OFFSET(x) offsetof(MBContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define Z_Z2_C(outr,outi,inr,ini)\
#define Z_Z2_C_ZYKLUS(outr,outi,inr,ini, Z)\
