#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#include "vf_pp7.h"
#define OFFSET(x) offsetof(PP7Context, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define N0 4
#define N1 5
#define N2 10
#define SN0 2
#define SN1 2.2360679775
#define SN2 3.16227766017
#define N (1 << 16)
