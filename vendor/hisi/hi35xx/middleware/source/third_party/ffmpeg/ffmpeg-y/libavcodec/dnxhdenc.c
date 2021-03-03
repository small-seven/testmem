#include "libavutil/attributes.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/timer.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "fdctdsp.h"
#include "internal.h"
#include "mpegvideo.h"
#include "pixblockdsp.h"
#include "profiles.h"
#include "dnxhdenc.h"
#define DNX10BIT_QMAT_SHIFT 18
#define RC_VARIANCE 1 // use variance or ssd for fast rc
#define LAMBDA_FRAC_BITS 10
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if FF_API_CODED_FRAME
#endif
#define BUCKET_BITS 8
#define RADIX_PASSES 4
#define NBUCKETS (1 << BUCKET_BITS)
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
