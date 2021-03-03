#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct DeblockContext {
    const AVClass *class;
    const AVPixFmtDescriptor *desc;
    int filter;
    int block;
    int planes;
    float alpha;
    float beta;
    float gamma;
    float delta;

    int ath;
    int bth;
    int gth;
    int dth;
    int max;
    int depth;
    int bpc;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];

    void (*deblockh)(uint8_t *dst, ptrdiff_t dst_linesize, int block,
                     int ath, int bth, int gth, int dth, int max);
    void (*deblockv)(uint8_t *dst, ptrdiff_t dst_linesize, int block,
                     int ath, int bth, int gth, int dth, int max);
} DeblockContext;
#define WEAK_HFILTER(name, type, ldiv)                                              \
#define WEAK_VFILTER(name, type, ldiv)                                              \
#define STRONG_HFILTER(name, type, ldiv)                                           \
#define STRONG_VFILTER(name, type, ldiv)                                           \
#define OFFSET(x) offsetof(DeblockContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_FILTERING_PARAM
