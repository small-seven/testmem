#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/log.h"
#include "avcodec.h"
#include "internal.h"
#include "mathops.h"
#define AES3_HEADER_LEN 4
typedef struct S302Context {
    AVClass *class;
    int non_pcm_mode;
} S302Context;
#define FLAGS AV_OPT_FLAG_AUDIO_PARAM|AV_OPT_FLAG_DECODING_PARAM
