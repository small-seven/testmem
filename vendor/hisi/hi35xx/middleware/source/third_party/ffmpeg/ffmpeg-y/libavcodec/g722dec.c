#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "get_bits.h"
#include "g722.h"
#include "internal.h"
#define OFFSET(x) offsetof(G722Context, x)
#define AD AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_DECODING_PARAM
