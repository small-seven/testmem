#include "libavutil/lfg.h"
#include "libavutil/opt.h"
#include "libavutil/random_seed.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#define MAX_FRAMES 512
typedef struct RandomContext {
    const AVClass *class;

    AVLFG lfg;
    int nb_frames;
    int64_t random_seed;
    int nb_frames_filled;
    AVFrame *frames[MAX_FRAMES];
    int64_t pts[MAX_FRAMES];
    int flush_idx;
} RandomContext;
#define OFFSET(x) offsetof(RandomContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
