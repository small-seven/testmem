#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/avassert.h"
#include "avfilter.h"
#include "internal.h"
#include "tinterlace.h"
#define OFFSET(x) offsetof(TInterlaceContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define FULL_SCALE_YUVJ_FORMATS \
#define FIELD_UPPER           0
#define FIELD_LOWER           1
#define FIELD_UPPER_AND_LOWER 2
