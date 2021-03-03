#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#define MAX_LINESIZE 2048
typedef struct {
    const AVClass *class;
    FFDemuxSubtitlesQueue q;
    AVRational frame_rate;
} MicroDVDContext;
#define SKIP_FRAME_ID                                       \
#define OFFSET(x) offsetof(MicroDVDContext, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM|AV_OPT_FLAG_DECODING_PARAM
