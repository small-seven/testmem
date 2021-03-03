#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "filters.h"
#include "internal.h"
#include "video.h"
#include "audio.h"
#define TYPE_ALL 2
typedef struct ConcatContext {
    const AVClass *class;
    unsigned nb_streams[TYPE_ALL]; /**< number of out streams of each type */
    unsigned nb_segments;
    unsigned cur_idx; /**< index of the first input of current segment */
    int64_t delta_ts; /**< timestamp to add to produce output timestamps */
    unsigned nb_in_active; /**< number of active inputs in current segment */
    unsigned unsafe;
    struct concat_in {
        int64_t pts;
        int64_t nb_frames;
        unsigned eof;
    } *in;
#define OFFSET(x) offsetof(ConcatContext, x)
#define A AV_OPT_FLAG_AUDIO_PARAM
#define F AV_OPT_FLAG_FILTERING_PARAM
#define V AV_OPT_FLAG_VIDEO_PARAM
