#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DedotContext {
    const AVClass *class;
    int m;
    float lt;
    float tl;
    float tc;
    float ct;

    const AVPixFmtDescriptor *desc;
    int depth;
    int max;
    int luma2d;
    int lumaT;
    int chromaT1;
    int chromaT2;

    int eof;
    int eof_frames;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];

    AVFrame *frames[5];

    int (*dedotcrawl)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
    int (*derainbow)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} DedotContext;
#define DEFINE_DEDOTCRAWL(name, type, div)                       \
typedef struct ThreadData {
    AVFrame *out;
    int plane;
} ThreadData;
#define DEFINE_DERAINBOW(name, type, div)                    \
#define OFFSET(x) offsetof(DedotContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
