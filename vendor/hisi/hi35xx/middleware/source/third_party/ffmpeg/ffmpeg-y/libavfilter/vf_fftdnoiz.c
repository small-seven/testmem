#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#include "libavcodec/avfft.h"
typedef struct PlaneContext {
    int planewidth, planeheight;
    int nox, noy;
    int b;
    int o;
    float n;

    float *buffer[BSIZE];
    FFTComplex *hdata, *vdata;
    int data_linesize;
    int buffer_linesize;

    FFTContext *fft, *ifft;
} PlaneContext;
typedef struct FFTdnoizContext {
    const AVClass *class;

    float sigma;
    float amount;
    int   block_bits;
    float overlap;
    int   nb_prev;
    int   nb_next;
    int   planesf;

    AVFrame *prev, *cur, *next;

    int depth;
    int nb_planes;
    PlaneContext planes[4];

    void (*import_row)(FFTComplex *dst, uint8_t *src, int rw);
    void (*export_row)(FFTComplex *src, uint8_t *dst, int rw, float scale, int depth);
} FFTdnoizContext;
#define OFFSET(x) offsetof(FFTdnoizContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    float *src, *dst;
} ThreadData;
