#include "libavfilter/internal.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/avfft.h"
#include "libavutil/eval.h"
#define MAX_PLANES 4
typedef struct FFTFILTContext {
    const AVClass *class;

    int eval_mode;
    int depth;
    int nb_planes;
    int planewidth[MAX_PLANES];
    int planeheight[MAX_PLANES];

    RDFTContext *hrdft[MAX_PLANES];
    RDFTContext *vrdft[MAX_PLANES];
    RDFTContext *ihrdft[MAX_PLANES];
    RDFTContext *ivrdft[MAX_PLANES];
    int rdft_hbits[MAX_PLANES];
    int rdft_vbits[MAX_PLANES];
    size_t rdft_hlen[MAX_PLANES];
    size_t rdft_vlen[MAX_PLANES];
    FFTSample *rdft_hdata[MAX_PLANES];
    FFTSample *rdft_vdata[MAX_PLANES];

    int dc[MAX_PLANES];
    char *weight_str[MAX_PLANES];
    AVExpr *weight_expr[MAX_PLANES];
    double *weight[MAX_PLANES];

    void (*rdft_horizontal)(struct FFTFILTContext *s, AVFrame *in, int w, int h, int plane);
    void (*irdft_horizontal)(struct FFTFILTContext *s, AVFrame *out, int w, int h, int plane);
} FFTFILTContext;
#define OFFSET(x) offsetof(FFTFILTContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
