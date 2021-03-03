#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct FieldHintContext {
    const AVClass *class;

    char *hint_file_str;
    FILE *hint;
    int mode;

    AVFrame *frame[3];

    int64_t line;
    int nb_planes;
    int eof;
    int planewidth[4];
    int planeheight[4];
} FieldHintContext;
#define OFFSET(x) offsetof(FieldHintContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
