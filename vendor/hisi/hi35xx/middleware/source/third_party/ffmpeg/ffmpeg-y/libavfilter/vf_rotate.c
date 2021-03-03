#include "libavutil/avstring.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "internal.h"
#include "video.h"
#include <float.h>
typedef struct RotContext {
    const AVClass *class;
    double angle;
    char *angle_expr_str;   ///< expression for the angle
    AVExpr *angle_expr;     ///< parsed expression for the angle
    char *outw_expr_str, *outh_expr_str;
    int outh, outw;
    uint8_t fillcolor[4];   ///< color expressed either in YUVA or RGBA colorspace for the padding area
    char *fillcolor_str;
    int fillcolor_enable;
    int hsub, vsub;
    int nb_planes;
    int use_bilinear;
    float sinx, cosx;
    double var_values[VAR_VARS_NB];
    FFDrawContext draw;
    FFDrawColor color;
    uint8_t *(*interpolate_bilinear)(uint8_t *dst_color,
                                    const uint8_t *src, int src_linesize, int src_linestep,
                                    int x, int y, int max_x, int max_y);
} RotContext;
typedef struct ThreadData {
    AVFrame *in, *out;
    int inw,  inh;
    int outw, outh;
    int plane;
    int xi, yi;
    int xprime, yprime;
    int c, s;
} ThreadData;
#define OFFSET(x) offsetof(RotContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define FIXP (1<<16)
#define FIXP2 (1<<20)
#define INT_PI 3294199 //(M_PI * FIXP2)
#define SET_SIZE_EXPR(name, opt_name) do {                                         \
#define TS2T(ts, tb) ((ts) == AV_NOPTS_VALUE ? NAN : (double)(ts)*av_q2d(tb))
