#include <float.h>
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct FrameData {
    uint8_t *paddedp[3];
    int padded_stride[3];
    int padded_width[3];
    int padded_height[3];

    uint8_t *dstp[3];
    int dst_stride[3];

    int field[3];

    int32_t *lcount[3];
    float *input;
    float *temp;
} FrameData;
typedef struct NNEDIContext {
    const AVClass *class;

    char *weights_file;

    AVFrame *src;
    AVFrame *second;
    AVFrame *dst;
    int eof;
    int64_t cur_pts;

    AVFloatDSPContext *fdsp;
    int nb_planes;
    int linesize[4];
    int planeheight[4];

    float *weights0;
    float *weights1[2];
    int asize;
    int nns;
    int xdia;
    int ydia;

    // Parameters
    int deint;
    int field;
    int process_plane;
    int nsize;
    int nnsparam;
    int qual;
    int etype;
    int pscrn;
    int fapprox;

    int max_value;

    void (*copy_pad)(const AVFrame *, FrameData *, struct NNEDIContext *, int);
    void (*evalfunc_0)(struct NNEDIContext *, FrameData *);
    void (*evalfunc_1)(struct NNEDIContext *, FrameData *);

    // Functions used in evalfunc_0
    void (*readpixels)(const uint8_t *, const int, float *);
    void (*compute_network0)(struct NNEDIContext *s, const float *, const float *, uint8_t *);
    int32_t (*process_line0)(const uint8_t *, int, uint8_t *, const uint8_t *, const int, const int, const int);

    // Functions used in evalfunc_1
    void (*extract)(const uint8_t *, const int, const int, const int, float *, float *);
    void (*dot_prod)(struct NNEDIContext *, const float *, const float *, float *, const int, const int, const float *);
    void (*expfunc)(float *, const int);
    void (*wae5)(const float *, const int, float *);

    FrameData frame_data;
} NNEDIContext;
#define OFFSET(x) offsetof(NNEDIContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define NUM_NSIZE 7
#define NUM_NNS 5
