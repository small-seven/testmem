#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct HistogramContext {
    const AVClass *class;               ///< AVClass context for log and options purpose
    unsigned       histogram[256*256];
    int            histogram_size;
    int            mult;
    int            ncomp;
    int            dncomp;
    uint8_t        bg_color[4];
    uint8_t        fg_color[4];
    int            level_height;
    int            scale_height;
    int            display_mode;
    int            levels_mode;
    const AVPixFmtDescriptor *desc, *odesc;
    int            components;
    float          fgopacity;
    float          bgopacity;
    int            planewidth[4];
    int            planeheight[4];
} HistogramContext;
#define OFFSET(x) offsetof(HistogramContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
