#include "libavutil/avstring.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "audio.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
typedef struct StreamSelectContext {
    const AVClass *class;
    int nb_inputs;
    char *map_str;
    int *map;
    int nb_map;
    int is_audio;
    int64_t *last_pts;
    AVFrame **frames;
    FFFrameSync fs;
} StreamSelectContext;
#define OFFSET(x) offsetof(StreamSelectContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
#define astreamselect_options streamselect_options
