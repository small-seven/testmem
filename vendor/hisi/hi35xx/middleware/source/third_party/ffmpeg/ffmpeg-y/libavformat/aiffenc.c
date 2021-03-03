#include <stdint.h>
#include "libavutil/intfloat.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "aiff.h"
#include "avio_internal.h"
#include "isom.h"
#include "id3v2.h"
typedef struct AIFFOutputContext {
    const AVClass *class;
    int64_t form;
    int64_t frames;
    int64_t ssnd;
    int audio_stream_idx;
    AVPacketList *pict_list;
    int write_id3v2;
    int id3v2_version;
} AIFFOutputContext;
#define OFFSET(x) offsetof(AIFFOutputContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
