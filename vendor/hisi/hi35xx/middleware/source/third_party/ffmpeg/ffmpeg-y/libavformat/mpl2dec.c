#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
typedef struct {
    FFDemuxSubtitlesQueue q;
} MPL2Context;
