#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/timecode.h"
#include "libavutil/stereo3d.h"
#include "avcodec.h"
#include "bytestream.h"
#include "mathops.h"
#include "mpeg12.h"
#include "mpeg12data.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#define A53_MAX_CC_COUNT 0x1f
#if FF_API_PRIVATE_OPT
#endif
#define OFFSET(x) offsetof(MpegEncContext, x)
#define VE AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#define COMMON_OPTS                                                           \
#define mpeg12_class(x)                                 \
