#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "w3fdif.h"
typedef struct W3FDIFContext {
    const AVClass *class;
    int filter;           ///< 0 is simple, 1 is more complex
    int deint;            ///< which frames to deinterlace
    int linesize[4];      ///< bytes of pixel data per line for each plane
    int planeheight[4];   ///< height of each plane
    int field;            ///< which field are we on, 0 or 1
    int eof;
    int nb_planes;
    AVFrame *prev, *cur, *next;  ///< previous, current, next frames
    int32_t **work_line;  ///< lines we are calculating
    int nb_threads;
    int max;

    W3FDIFDSPContext dsp;
} W3FDIFContext;
#define OFFSET(x) offsetof(W3FDIFContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, 0, 0, FLAGS, unit }
typedef struct ThreadData {
    AVFrame *out, *cur, *adj;
    int plane;
} ThreadData;
