#include "libavcodec/get_bits.h"
#include "libavcodec/put_bits.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/mpeg4audio.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "internal.h"
#include "rawenc.h"
#define MAX_EXTRADATA_SIZE 1024
typedef struct LATMContext {
    AVClass *av_class;
    int off;
    int channel_conf;
    int object_type;
    int counter;
    int mod;
    uint8_t buffer[0x1fff + MAX_EXTRADATA_SIZE + 1024];
} LATMContext;
