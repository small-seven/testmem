#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "idctdsp.h"
#include "proresdsp.h"
#include "simple_idct.h"
#define CLIP_MIN (1 << 2)                     ///< minimum value for clipping resulting pixels
#define CLIP_MAX_10 (1 << 10) - CLIP_MIN - 1  ///< maximum value for clipping resulting pixels
#define CLIP_MAX_12 (1 << 12) - CLIP_MIN - 1  ///< maximum value for clipping resulting pixels
#define CLIP_10(x) (av_clip((x), CLIP_MIN, CLIP_MAX_10))
#define CLIP_12(x) (av_clip((x), CLIP_MIN, CLIP_MAX_12))
