#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DetelecineContext {
    const AVClass *class;
    int first_field;
    char *pattern;
    int start_frame;
    int init_len;
    unsigned int pattern_pos;
    unsigned int nskip_fields;
    int64_t start_time;

    AVRational pts;
    AVRational ts_unit;
    int occupied;

    int nb_planes;
    int planeheight[4];
    int stride[4];

    AVFrame *frame[2];
    AVFrame *temp;
} DetelecineContext;
#define OFFSET(x) offsetof(DetelecineContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
