#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixelutils.h"
#include "libavutil/timestamp.h"
#include "avfilter.h"
#include "internal.h"
#include "formats.h"
#include "video.h"
typedef struct DecimateContext {
    const AVClass *class;
    int lo, hi;                    ///< lower and higher threshold number of differences
                                   ///< values for 8x8 blocks

    float frac;                    ///< threshold of changed pixels over the total fraction

    int max_drop_count;            ///< if positive: maximum number of sequential frames to drop
                                   ///< if negative: minimum number of frames between two drops

    int drop_count;                ///< if positive: number of frames sequentially dropped
                                   ///< if negative: number of sequential frames which were not dropped

    int hsub, vsub;                ///< chroma subsampling values
    AVFrame *ref;                  ///< reference picture
    av_pixelutils_sad_fn sad;      ///< sum of absolute difference function
} DecimateContext;
#define OFFSET(x) offsetof(DecimateContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
