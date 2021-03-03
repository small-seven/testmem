#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "lavfutils.h"
#define MAX_MIPMAPS 5
typedef struct FOCContext {
    AVClass *class;
    float threshold;
    int mipmaps;
    int xmin, ymin, xmax, ymax;
    char *obj_filename;
    int last_x, last_y;
    AVFrame *obj_frame;
    AVFrame *needle_frame[MAX_MIPMAPS];
    AVFrame *haystack_frame[MAX_MIPMAPS];
} FOCContext;
#define OFFSET(x) offsetof(FOCContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
