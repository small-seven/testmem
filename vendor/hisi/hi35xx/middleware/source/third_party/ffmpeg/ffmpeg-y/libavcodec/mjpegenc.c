#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "jpegtables.h"
#include "mjpegenc_common.h"
#include "mpegvideo.h"
#include "mjpeg.h"
#include "mjpegenc.h"
#include "profiles.h"
#if CONFIG_AMV_ENCODER
#define V_MAX 2
#endif
#define OFFSET(x) offsetof(MpegEncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if CONFIG_MJPEG_ENCODER
#endif
#if CONFIG_AMV_ENCODER
#endif
