#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/lfg.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "vf_noise.h"
#include "video.h"
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
#define OFFSET(x) offsetof(NoiseContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define NOISE_PARAMS(name, x, param)                                                                                             \
#define RAND_N(range) ((int) ((double) range * av_lfg_get(lfg) / (UINT_MAX + 1.0)))
