#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavutil/bprint.h"
#include "libavutil/intreadwrite.h"
typedef struct SCCContext {
    FFDemuxSubtitlesQueue q;
} SCCContext;
