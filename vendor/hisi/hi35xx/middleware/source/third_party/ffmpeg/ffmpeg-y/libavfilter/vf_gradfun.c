#include "libavutil/imgutils.h"
#include "libavutil/common.h"
#include "libavutil/cpu.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "gradfun.h"
#include "internal.h"
#include "video.h"
#define OFFSET(x) offsetof(GradFunContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
