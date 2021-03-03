#include "opusenc.h"
#include "opus_pvq.h"
#include "opusenc_psy.h"
#include "opustab.h"
#include "libavutil/float_dsp.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "bytestream.h"
#include "audio_frame_queue.h"
typedef struct OpusEncContext {
    AVClass *av_class;
    OpusEncOptions options;
    OpusPsyContext psyctx;
    AVCodecContext *avctx;
    AudioFrameQueue afq;
    AVFloatDSPContext *dsp;
    MDCT15Context *mdct[CELT_BLOCK_NB];
    CeltPVQ *pvq;
    struct FFBufQueue bufqueue;

    uint8_t enc_id[64];
    int enc_id_bits;

    OpusPacketInfo packet;

    int channels;

    CeltFrame *frame;
    OpusRangeCoder *rc;

    /* Actual energy the decoder will have */
    float last_quantized_energy[OPUS_MAX_CHANNELS][CELT_MAX_BANDS];

    DECLARE_ALIGNED(32, float, scratch)[2048];
} OpusEncContext;
#define OPUSENC_FLAGS AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM
