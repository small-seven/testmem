#include <float.h>
#include "libavutil/opt.h"
#include "libavutil/eval.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#include "libavutil/mathematics.h"
#include "formats.h"
#include "internal.h"
#include "avfilter.h"
#include "libavcodec/avcodec.h"
#include "libavformat/avformat.h"
#include "qsvvpp.h"
#define OFFSET(x) offsetof(VPPContext, x)
#define FLAGS (AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM)
#define ENH_FILTERS_COUNT (5)
typedef struct VPPContext{
    const AVClass *class;

    QSVVPPContext *qsv;

    /* Video Enhancement Algorithms */
    mfxExtVPPDeinterlacing  deinterlace_conf;
    mfxExtVPPFrameRateConversion frc_conf;
    mfxExtVPPDenoise denoise_conf;
    mfxExtVPPDetail detail_conf;
    mfxExtVPPProcAmp procamp_conf;

    int out_width;
    int out_height;
    /**
     * Output sw format. AV_PIX_FMT_NONE for no conversion.
     */
    enum AVPixelFormat out_format;

    AVRational framerate;       /* target framerate */
    int use_frc;                /* use framerate conversion */
    int deinterlace;            /* deinterlace mode : 0=off, 1=bob, 2=advanced */
    int denoise;                /* Enable Denoise algorithm. Value [0, 100] */
    int detail;                 /* Enable Detail Enhancement algorithm. */
                                /* Level is the optional, value [0, 100] */
    int use_crop;               /* 1 = use crop; 0=none */
    int crop_w;
    int crop_h;
    int crop_x;
    int crop_y;

    /* param for the procamp */
    int    procamp;            /* enable procamp */
    float  hue;
    float  saturation;
    float  contrast;
    float  brightness;

    char *cx, *cy, *cw, *ch;
    char *ow, *oh;
    char *output_format_str;
} VPPContext;
#define PASS_EXPR(e, s) {\
#define CALC_EXPR(e, v, i) {\
#undef PASS_EXPR
#undef CALC_EXPR
