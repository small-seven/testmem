#include "libavutil/avstring.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct ConvolutionContext {
    const AVClass *class;

    char *matrix_str[4];
    float rdiv[4];
    float bias[4];
    int mode[4];
    float scale;
    float delta;
    int planes;

    int size[4];
    int depth;
    int max;
    int bpc;
    int nb_planes;
    int nb_threads;
    int planewidth[4];
    int planeheight[4];
    int matrix[4][49];
    int matrix_length[4];
    int copy[4];

    void (*setup[4])(int radius, const uint8_t *c[], const uint8_t *src, int stride,
                     int x, int width, int y, int height, int bpc);
    void (*filter[4])(uint8_t *dst, int width,
                      float rdiv, float bias, const int *const matrix,
                      const uint8_t *c[], int peak, int radius,
                      int dstride, int stride);
} ConvolutionContext;
#define OFFSET(x) offsetof(ConvolutionContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
typedef struct ThreadData {
    AVFrame *in, *out;
} ThreadData;
#if CONFIG_CONVOLUTION_FILTER
#endif /* CONFIG_CONVOLUTION_FILTER */
#if CONFIG_PREWITT_FILTER
#endif /* CONFIG_PREWITT_FILTER */
#if CONFIG_SOBEL_FILTER
#endif /* CONFIG_SOBEL_FILTER */
#if CONFIG_ROBERTS_FILTER
#endif /* CONFIG_ROBERTS_FILTER */
