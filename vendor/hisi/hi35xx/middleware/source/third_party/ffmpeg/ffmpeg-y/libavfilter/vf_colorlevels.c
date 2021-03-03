#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define R 0
#define G 1
#define B 2
#define A 3
typedef struct Range {
    double in_min, in_max;
    double out_min, out_max;
} Range;
typedef struct ColorLevelsContext {
    const AVClass *class;
    Range range[4];
    int nb_comp;
    int bpp;
    int step;
    uint8_t rgba_map[4];
    int linesize;
} ColorLevelsContext;
#define OFFSET(x) offsetof(ColorLevelsContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define LOAD_COMMON\
