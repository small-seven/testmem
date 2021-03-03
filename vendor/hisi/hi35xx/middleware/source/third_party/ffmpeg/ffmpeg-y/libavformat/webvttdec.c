#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavutil/bprint.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
typedef struct {
    const AVClass *class;
    FFDemuxSubtitlesQueue q;
    int kind;
} WebVTTContext;
#define SET_SIDE_DATA(name, type) do {                                  \
#define OFFSET(x) offsetof(WebVTTContext, x)
#define KIND_FLAGS AV_OPT_FLAG_SUBTITLE_PARAM|AV_OPT_FLAG_DECODING_PARAM
