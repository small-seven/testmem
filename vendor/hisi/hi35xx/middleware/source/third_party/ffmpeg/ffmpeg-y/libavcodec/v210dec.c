#include "avcodec.h"
#include "internal.h"
#include "v210dec.h"
#include "libavutil/bswap.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/intreadwrite.h"
#define READ_PIXELS(a, b, c)         \
#define V210DEC_FLAGS AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_VIDEO_PARAM
