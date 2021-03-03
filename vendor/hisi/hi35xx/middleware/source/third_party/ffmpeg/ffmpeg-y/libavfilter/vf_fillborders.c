#include "libavutil/colorspace.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct Borders {
    int left, right, top, bottom;
} Borders;
typedef struct FillBordersContext {
    const AVClass *class;
    int left, right, top, bottom;
    int mode;

    int nb_planes;
    int depth;
    Borders borders[4];
    int planewidth[4];
    int planeheight[4];
    uint8_t fill[4];
    uint8_t yuv_color[4];
    uint8_t rgba_color[4];

    void (*fillborders)(struct FillBordersContext *s, AVFrame *frame);
} FillBordersContext;
#define OFFSET(x) offsetof(FillBordersContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
