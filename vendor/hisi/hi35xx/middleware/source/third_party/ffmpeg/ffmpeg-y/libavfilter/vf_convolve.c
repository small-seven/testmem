#include <float.h>
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/avfft.h"
#include "avfilter.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
#define MAX_THREADS 16
typedef struct ConvolveContext {
    const AVClass *class;
    FFFrameSync fs;

    FFTContext *fft[4][MAX_THREADS];
    FFTContext *ifft[4][MAX_THREADS];

    int fft_bits[4];
    int fft_len[4];
    int planewidth[4];
    int planeheight[4];

    FFTComplex *fft_hdata[4];
    FFTComplex *fft_vdata[4];
    FFTComplex *fft_hdata_impulse[4];
    FFTComplex *fft_vdata_impulse[4];

    int depth;
    int planes;
    int impulse;
    float noise;
    int nb_planes;
    int got_impulse[4];

    int (*filter)(AVFilterContext *ctx, void *arg, int jobnr, int nb_jobs);
} ConvolveContext;
#define OFFSET(x) offsetof(ConvolveContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
typedef struct ThreadData {
    FFTComplex *hdata, *vdata;
    int plane, n;
} ThreadData;
#if CONFIG_CONVOLVE_FILTER
#endif /* CONFIG_CONVOLVE_FILTER */
#if CONFIG_DECONVOLVE_FILTER
#endif /* CONFIG_DECONVOLVE_FILTER */
