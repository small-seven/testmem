#include <stdint.h>
#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
#include "libavcodec/internal.h"
#include "libavutil/bprint.h"
typedef struct ASSContext {
    FFDemuxSubtitlesQueue q;
    unsigned readorder;
} ASSContext;
