#include <opus.h>
#include <opus_multistream.h>
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "libopus.h"
#include "vorbis.h"
#include "audio_frame_queue.h"
typedef struct LibopusEncOpts {
    int vbr;
    int application;
    int packet_loss;
    int complexity;
    float frame_duration;
    int packet_size;
    int max_bandwidth;
    int mapping_family;
#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
    int apply_phase_inv;
#endif
} LibopusEncOpts;
typedef struct LibopusEncContext {
    AVClass *class;
    OpusMSEncoder *enc;
    int stream_count;
    uint8_t *samples;
    LibopusEncOpts opts;
    AudioFrameQueue afq;
    const uint8_t *encoder_channel_map;
} LibopusEncContext;
#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
#endif
#ifdef OPUS_FRAMESIZE_120_MS
#endif
#ifdef OPUS_FRAMESIZE_120_MS
#else
#endif
#define OFFSET(x) offsetof(LibopusEncContext, opts.x)
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#ifdef OPUS_SET_PHASE_INVERSION_DISABLED_REQUEST
#endif
