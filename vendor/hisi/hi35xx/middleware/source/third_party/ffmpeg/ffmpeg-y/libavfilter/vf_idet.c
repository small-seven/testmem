#include <float.h> /* FLT_MAX */
#include "libavutil/cpu.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "vf_idet.h"
#define OFFSET(x) offsetof(IDETContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define PRECISION 1048576
