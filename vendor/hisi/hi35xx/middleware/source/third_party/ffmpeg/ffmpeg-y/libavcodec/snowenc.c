#include "libavutil/intmath.h"
#include "libavutil/libm.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "internal.h"
#include "snow_dwt.h"
#include "snow.h"
#include "rangecoder.h"
#include "mathops.h"
#include "mpegvideo.h"
#include "h263.h"
#if FF_API_PRIVATE_OPT
#endif
#define P_LEFT P[1]
#define P_TOP P[2]
#define P_TOPRIGHT P[3]
#define P_MEDIAN P[4]
#define P_MV1 P[9]
#define FLAG_QPEL   1 //must be 1
#if FRAC_BITS >= LOG2_OBMC_MAX
#else
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_STAT_BITS
#endif
#if FF_API_ERROR_FRAME
#endif
#define OFFSET(x) offsetof(SnowContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
