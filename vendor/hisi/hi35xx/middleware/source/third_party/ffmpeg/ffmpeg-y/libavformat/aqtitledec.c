#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavutil/opt.h"
typedef struct {
    const AVClass *class;
    FFDemuxSubtitlesQueue q;
    AVRational frame_rate;
} AQTitleContext;
#define OFFSET(x) offsetof(AQTitleContext, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM|AV_OPT_FLAG_DECODING_PARAM
