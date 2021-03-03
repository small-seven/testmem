#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
typedef struct {
    FFDemuxSubtitlesQueue q;
} STLContext;
