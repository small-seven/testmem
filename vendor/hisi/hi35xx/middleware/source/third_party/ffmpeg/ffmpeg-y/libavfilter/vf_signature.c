#include <float.h>
#include "libavcodec/put_bits.h"
#include "libavformat/avformat.h"
#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "internal.h"
#include "signature.h"
#include "signature_lookup.c"
#define OFFSET(x) offsetof(SignatureContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#define BLOCK_LCM (int64_t) 476985600
