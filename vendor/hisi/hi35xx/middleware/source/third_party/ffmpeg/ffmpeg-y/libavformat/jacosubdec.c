#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavcodec/internal.h"
#include "libavcodec/jacosub.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/intreadwrite.h"
typedef struct {
    int shift;
    unsigned timeres;
    FFDemuxSubtitlesQueue q;
} JACOsubContext;
#define SSEP "%*1[.:]"
#undef SSEP
