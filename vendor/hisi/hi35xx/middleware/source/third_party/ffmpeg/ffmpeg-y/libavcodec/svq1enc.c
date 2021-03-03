#include "avcodec.h"
#include "hpeldsp.h"
#include "me_cmp.h"
#include "mpegvideo.h"
#include "h263.h"
#include "internal.h"
#include "mpegutils.h"
#include "svq1.h"
#include "svq1enc.h"
#include "svq1enc_cb.h"
#include "libavutil/avassert.h"
#define QUALITY_THRESHOLD    100
#define THRESHOLD_MULTIPLIER 0.6
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(struct SVQ1EncContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
