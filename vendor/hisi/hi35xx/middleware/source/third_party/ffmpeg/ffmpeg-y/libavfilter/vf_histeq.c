#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define LCG_A 4096
#define LCG_C 150889
#define LCG_M 714025
#define LCG(x) (((x) * LCG_A + LCG_C) % LCG_M)
#define LCG_SEED 739187
typedef struct HisteqContext {
    const AVClass *class;
    float strength;
    float intensity;
    int antibanding;               ///< HisteqAntibanding
    int in_histogram [256];        ///< input histogram
    int out_histogram[256];        ///< output histogram
    int LUT[256];                  ///< lookup table derived from histogram[]
    uint8_t rgba_map[4];           ///< components position
    int bpp;                       ///< bytes per pixel
} HisteqContext;
#define OFFSET(x) offsetof(HisteqContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, INT_MIN, INT_MAX, FLAGS, unit }
#define R 0
#define G 1
#define B 2
#define A 3
#define GET_RGB_VALUES(r, g, b, src, map) do { \
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
