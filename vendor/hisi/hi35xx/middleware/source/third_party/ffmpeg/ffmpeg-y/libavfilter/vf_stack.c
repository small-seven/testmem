#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "framesync.h"
#include "video.h"
typedef struct StackItem {
    int x[4], y[4];
    int linesize[4];
    int height[4];
} StackItem;
typedef struct StackContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    int nb_inputs;
    char *layout;
    int shortest;
    int is_vertical;
    int is_horizontal;
    int nb_planes;

    StackItem *items;
    AVFrame **frames;
    FFFrameSync fs;
} StackContext;
#define OFFSET(x) offsetof(StackContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#if CONFIG_HSTACK_FILTER
#define hstack_options stack_options
#endif /* CONFIG_HSTACK_FILTER */
#if CONFIG_VSTACK_FILTER
#define vstack_options stack_options
#endif /* CONFIG_VSTACK_FILTER */
#if CONFIG_XSTACK_FILTER
#endif /* CONFIG_XSTACK_FILTER */
