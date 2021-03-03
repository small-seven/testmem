#include <inttypes.h>
#include <stdint.h>
#include <string.h>
#include "avformat.h"
#include "internal.h"
#include "lrc.h"
#include "metadata.h"
#include "subtitles.h"
#include "libavutil/bprint.h"
#include "libavutil/dict.h"
typedef struct LRCContext {
    FFDemuxSubtitlesQueue q;
    int64_t ts_offset; // offset metadata item
} LRCContext;
