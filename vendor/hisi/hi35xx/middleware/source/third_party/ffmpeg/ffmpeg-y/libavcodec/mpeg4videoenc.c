#include "libavutil/attributes.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "h263.h"
#include "mpeg4video.h"
#define UNI_MPEG4_ENC_INDEX(last, run, level) ((last) * 128 * 64 + (run) * 128 + (level))
#define OFFSET(x) offsetof(MpegEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
