#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/xga_font_data.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct VectorscopeContext {
    const AVClass *class;
    int mode;
    int intensity;
    float fintensity;
    uint16_t bg_color[4];
    int planewidth[4];
    int planeheight[4];
    int hsub, vsub;
    int x, y, pd;
    int is_yuv;
    int size;
    int depth;
    int mult;
    int envelope;
    int graticule;
    float opacity;
    float bgopacity;
    float lthreshold;
    float hthreshold;
    int tmin;
    int tmax;
    int flags;
    int colorspace;
    int cs;
    uint8_t *peak_memory;
    uint8_t **peak;

    void (*vectorscope)(struct VectorscopeContext *s,
                        AVFrame *in, AVFrame *out, int pd);
    void (*graticulef)(struct VectorscopeContext *s, AVFrame *out,
                       int X, int Y, int D, int P);
} VectorscopeContext;
#define OFFSET(x) offsetof(VectorscopeContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
