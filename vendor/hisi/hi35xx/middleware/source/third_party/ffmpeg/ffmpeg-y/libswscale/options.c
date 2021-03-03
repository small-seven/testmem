#include "libavutil/avutil.h"
#include "libavutil/opt.h"
#include "libavutil/pixfmt.h"
#include "swscale.h"
#include "swscale_internal.h"
#define OFFSET(x) offsetof(SwsContext, x)
#define DEFAULT 0
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
