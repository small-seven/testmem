#include "libavutil/lfg.h"
#include "libavutil/opt.h"
#include "libavutil/random_seed.h"
#include "audio.h"
#include "video.h"
typedef struct PermsContext {
    const AVClass *class;
    AVLFG lfg;
    int64_t random_seed;
    int mode;
} PermsContext;
#define OFFSET(x) offsetof(PermsContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM | AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_APERMS_FILTER
#define aperms_options options
#endif /* CONFIG_APERMS_FILTER */
#if CONFIG_PERMS_FILTER
#define perms_options options
#endif /* CONFIG_PERMS_FILTER */
