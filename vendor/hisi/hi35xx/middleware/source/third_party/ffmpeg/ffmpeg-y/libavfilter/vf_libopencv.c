#include "config.h"
#if HAVE_OPENCV2_CORE_CORE_C_H
#include <opencv2/core/core_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#else
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#endif
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/file.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct OCVContext {
    const AVClass *class;
    char *name;
    char *params;
    int (*init)(AVFilterContext *ctx, const char *args);
    void (*uninit)(AVFilterContext *ctx);
    void (*end_frame_filter)(AVFilterContext *ctx, IplImage *inimg, IplImage *outimg);
    void *priv;
} OCVContext;
typedef struct SmoothContext {
    int type;
    int    param1, param2;
    double param3, param4;
} SmoothContext;
#ifdef DEBUG
#endif
typedef struct DilateContext {
    int nb_iterations;
    IplConvKernel *kernel;
} DilateContext;
typedef struct OCVFilterEntry {
    const char *name;
    size_t priv_size;
    int  (*init)(AVFilterContext *ctx, const char *args);
    void (*uninit)(AVFilterContext *ctx);
    void (*end_frame_filter)(AVFilterContext *ctx, IplImage *inimg, IplImage *outimg);
} OCVFilterEntry;
#define OFFSET(x) offsetof(OCVContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
