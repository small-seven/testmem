#include "avformat.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavcodec/png.h"
#include "libavcodec/apng.h"
typedef struct APNGMuxContext {
    AVClass *class;

    uint32_t plays;
    AVRational last_delay;

    uint64_t acTL_offset;
    uint32_t frame_number;

    AVPacket *prev_packet;
    AVRational prev_delay;

    int framerate_warned;

    uint8_t *extra_data;
    int extra_data_size;
} APNGMuxContext;
#define OFFSET(x) offsetof(APNGMuxContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
