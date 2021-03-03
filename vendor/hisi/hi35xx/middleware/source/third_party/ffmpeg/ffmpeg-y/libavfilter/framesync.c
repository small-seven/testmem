#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "filters.h"
#include "framesync.h"
#include "internal.h"
#define OFFSET(member) offsetof(FFFrameSync, member)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
