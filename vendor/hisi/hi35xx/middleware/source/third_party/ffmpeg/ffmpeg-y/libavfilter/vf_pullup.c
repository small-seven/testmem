#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "vf_pullup.h"
#define F_HAVE_BREAKS   1
#define F_HAVE_AFFINITY 2
#define BREAK_LEFT  1
#define BREAK_RIGHT 2
#define OFFSET(x) offsetof(PullupContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define ABS(a) (((a) ^ ((a) >> 31)) - ((a) >> 31))
