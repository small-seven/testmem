#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "internal.h"
#include "yadif.h"
#define OFFSET(x) offsetof(YADIFContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, INT_MIN, INT_MAX, FLAGS, unit }
