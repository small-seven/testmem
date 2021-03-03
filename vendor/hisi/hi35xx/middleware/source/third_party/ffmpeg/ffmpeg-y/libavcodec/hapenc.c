#include <stdint.h>
#include "snappy-c.h"
#include "libavutil/frame.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "hap.h"
#include "internal.h"
#include "texturedsp.h"
#define HAP_MAX_CHUNKS 64
#define OFFSET(x) offsetof(HapContext, x)
#define FLAGS     AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
