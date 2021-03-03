#include "libavcodec/get_bits.h"
#include "libavcodec/put_bits.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/mpeg4audio.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "apetag.h"
#include "id3v2.h"
#define ADTS_HEADER_SIZE 7
typedef struct ADTSContext {
    AVClass *class;
    int write_adts;
    int objecttype;
    int sample_rate_index;
    int channel_conf;
    int pce_size;
    int apetag;
    int id3v2tag;
    uint8_t pce_data[MAX_PCE_SIZE];
} ADTSContext;
#define ADTS_MAX_FRAME_BYTES ((1 << 13) - 1)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
#define OFFSET(obj) offsetof(ADTSContext, obj)
