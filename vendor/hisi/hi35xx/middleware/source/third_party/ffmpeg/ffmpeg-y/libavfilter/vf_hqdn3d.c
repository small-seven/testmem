#include <float.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "vf_hqdn3d.h"
#define LUT_BITS (depth==16 ? 8 : 4)
#define LOAD(x) (((depth == 8 ? src[x] : AV_RN16A(src + (x) * 2)) << (16 - depth))\
#define STORE(x,val) (depth == 8 ? dst[x] = (val) >> (16 - depth) : \
#define denoise(...)                                                          \
#define PARAM1_DEFAULT 4.0
#define PARAM2_DEFAULT 3.0
#define PARAM3_DEFAULT 6.0
#define OFFSET(x) offsetof(HQDN3DContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
