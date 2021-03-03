#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct EntropyContext {
    const AVClass *class;

    int mode;

    int nb_planes;
    int planeheight[4];
    int planewidth[4];
    int depth;
    int is_rgb;
    uint8_t rgba_map[4];
    char planenames[4];
    int64_t *histogram;
} EntropyContext;
#define OFFSET(x) offsetof(EntropyContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
