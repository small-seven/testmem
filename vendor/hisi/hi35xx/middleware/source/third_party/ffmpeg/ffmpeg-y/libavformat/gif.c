#include "avformat.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/gif.h"
typedef struct GIFContext {
    AVClass *class;
    int loop;
    int last_delay;
    int duration;
    int64_t last_pos;
    int have_end;
    AVPacket *prev_pkt;
} GIFContext;
#define OFFSET(x) offsetof(GIFContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
