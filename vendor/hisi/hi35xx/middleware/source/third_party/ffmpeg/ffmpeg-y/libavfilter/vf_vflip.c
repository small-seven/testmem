#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "internal.h"
#include "video.h"
typedef struct FlipContext {
    const AVClass *class;
    int vsub;   ///< vertical chroma subsampling
} FlipContext;
