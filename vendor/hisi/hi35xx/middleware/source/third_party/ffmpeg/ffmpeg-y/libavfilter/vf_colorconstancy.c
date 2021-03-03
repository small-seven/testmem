#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include <math.h>
#define GREY_EDGE "greyedge"
#define SQRT3 1.73205080757
#define NUM_PLANES    3
#define MAX_DIFF_ORD  2
#define MAX_META_DATA 4
#define MAX_DATA      4
#define INDEX_TEMP 0
#define INDEX_DX   1
#define INDEX_DY   2
#define INDEX_DXY  3
#define INDEX_NORM INDEX_DX
#define INDEX_SRC  0
#define INDEX_DST  1
#define INDEX_ORD  2
#define INDEX_DIR  3
#define DIR_X 0
#define DIR_Y 1
typedef struct ThreadData {
    AVFrame *in, *out;
    int meta_data[MAX_META_DATA];
    double  *data[MAX_DATA][NUM_PLANES];
} ThreadData;
typedef struct ColorConstancyContext {
    const AVClass *class;

    int difford;
    int minknorm; /**< @minknorm = 0 : getMax instead */
    double sigma;

    int nb_threads;
    int planeheight[4];
    int planewidth[4];

    int filtersize;
    double *gauss[MAX_DIFF_ORD+1];

    double white[NUM_PLANES];
} ColorConstancyContext;
#define OFFSET(x) offsetof(ColorConstancyContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define GINDX(s, i) ( (i) - ((s) >> 2) )
#define CLAMP(x, mx) av_clip((x), 0, (mx-1))
#define INDX2D(r, c, w) ( (r) * (w) + (c) )
#define GAUSS(s, sr, sc, sls, sh, sw, g) ( (s)[ INDX2D(CLAMP((sr), (sh)), CLAMP((sc), (sw)), (sls)) ] * (g) )
#if CONFIG_GREYEDGE_FILTER
#endif /* CONFIG_GREY_EDGE_FILTER */
