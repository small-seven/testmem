#include "libavutil/opt.h"
#include "avfilter.h"
#include "internal.h"
#define HIST_SIZE (3*256)
typedef struct ThumbContext {
    const AVClass *class;
    int n;                      ///< current frame
    int n_frames;               ///< number of frames for analysis
    struct thumb_frame *frames; ///< the n_frames frames
    AVRational tb;              ///< copy of the input timebase to ease access
} ThumbContext;
#define OFFSET(x) offsetof(ThumbContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
