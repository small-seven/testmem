#include "libavutil/imgutils.h"
#include "avfilter.h"
#include "internal.h"
typedef struct RepeatFieldsContext {
    const AVClass *class;
    int state;
    int nb_planes;
    int linesize[4];
    int planeheight[4];
    AVFrame *frame;
} RepeatFieldsContext;
