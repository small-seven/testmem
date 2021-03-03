#include <limits.h>
#include "libavutil/crc.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#define BITSTREAM_READER_LE
#include "ttadata.h"
#include "ttadsp.h"
#include "avcodec.h"
#include "get_bits.h"
#include "thread.h"
#include "unary.h"
#include "internal.h"
#define FORMAT_SIMPLE    1
#define FORMAT_ENCRYPTED 2
typedef struct TTAContext {
    AVClass *class;
    AVCodecContext *avctx;
    const AVCRC *crc_table;

    int format, channels, bps;
    unsigned data_length;
    int frame_length, last_frame_length;

    int32_t *decode_buffer;

    uint8_t crc_pass[8];
    uint8_t *pass;
    TTAChannel *ch_ctx;
    TTADSPContext dsp;
} TTAContext;
#define PRED(x, k) (int32_t)((((uint64_t)(x) << (k)) - (x)) >> (k))
#define OFFSET(x) offsetof(TTAContext, x)
#define DEC (AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM)
