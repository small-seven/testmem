#include <AudioToolbox/AudioToolbox.h>
#include "config.h"
#include "avcodec.h"
#include "ac3_parser_internal.h"
#include "bytestream.h"
#include "internal.h"
#include "mpegaudiodecheader.h"
#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/log.h"
#if __MAC_OS_X_VERSION_MIN_REQUIRED < 101100
#define kAudioFormatEnhancedAC3 'ec-3'
#endif
typedef struct ATDecodeContext {
    AVClass *av_class;

    AudioConverterRef converter;
    AudioStreamPacketDescription pkt_desc;
    AVPacket in_pkt;
    AVPacket new_in_pkt;
    char *decoded_data;
    int channel_map[64];

    uint8_t *extradata;
    int extradata_size;

    int64_t last_pts;
    int eof;
} ATDecodeContext;
#if CONFIG_MP1_AT_DECODER || CONFIG_MP2_AT_DECODER || CONFIG_MP3_AT_DECODER
#endif
#if CONFIG_AC3_AT_DECODER || CONFIG_EAC3_AT_DECODER
#endif
#define COPY_SAMPLES(type) \
#if FF_API_PKT_PTS
#endif
#define FFAT_DEC_CLASS(NAME) \
#define FFAT_DEC(NAME, ID, bsf_name) \
