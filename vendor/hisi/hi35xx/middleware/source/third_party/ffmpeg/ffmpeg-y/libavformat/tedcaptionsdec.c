#include "libavutil/bprint.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "subtitles.h"
typedef struct {
    AVClass *class;
    int64_t start_time;
    FFDemuxSubtitlesQueue subs;
} TEDCaptionsDemuxer;
#define BETWEEN(a, amin, amax) ((unsigned)((a) - (amin)) <= (amax) - (amin))
#define HEX_DIGIT_TEST(c) (BETWEEN(c, '0', '9') || BETWEEN((c) | 32, 'a', 'z'))
#define HEX_DIGIT_VAL(c) ((c) <= '9' ? (c) - '0' : ((c) | 32) - 'a' + 10)
#define ERR_CODE(c) ((c) < 0 ? (c) : AVERROR_INVALIDDATA)
