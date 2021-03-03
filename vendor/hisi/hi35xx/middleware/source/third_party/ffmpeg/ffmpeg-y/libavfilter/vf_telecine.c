#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct TelecineContext {
    const AVClass *class;
    int first_field;
    char *pattern;
    unsigned int pattern_pos;
    int64_t start_time;

    AVRational pts;
    AVRational ts_unit;
    int out_cnt;
    int occupied;

    int nb_planes;
    int planeheight[4];
    int stride[4];

    AVFrame *frame[5];
    AVFrame *temp;
} TelecineContext;
#define OFFSET(x) offsetof(TelecineContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
