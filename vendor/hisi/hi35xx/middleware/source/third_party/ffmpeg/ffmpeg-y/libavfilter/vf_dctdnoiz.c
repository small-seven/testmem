#include "libavutil/avassert.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "internal.h"
#define MAX_THREADS 8
typedef struct DCTdnoizContext {
    const AVClass *class;

    /* coefficient factor expression */
    char *expr_str;
    AVExpr *expr[MAX_THREADS];
    double var_values[MAX_THREADS][VAR_VARS_NB];

    int nb_threads;
    int pr_width, pr_height;    // width and height to process
    float sigma;                // used when no expression are st
    float th;                   // threshold (3*sigma)
    float *cbuf[2][3];          // two planar rgb color buffers
    float *slices[MAX_THREADS]; // slices buffers (1 slice buffer per thread)
    float *weights;             // dct coeff are cumulated with overlapping; these values are used for averaging
    int p_linesize;             // line sizes for color and weights
    int overlap;                // number of block overlapping pixels
    int step;                   // block step increment (blocksize - overlap)
    int n;                      // 1<<n is the block size
    int bsize;                  // block size, 1<<n
    void (*filter_freq_func)(struct DCTdnoizContext *s,
                             const float *src, int src_linesize,
                             float *dst, int dst_linesize,
                             int thread_id);
    void (*color_decorrelation)(float **dst, int dst_linesize,
                                const uint8_t **src, int src_linesize,
                                int w, int h);
    void (*color_correlation)(uint8_t **dst, int dst_linesize,
                              float **src, int src_linesize,
                              int w, int h);
} DCTdnoizContext;
#define MIN_NBITS 3 /* blocksize = 1<<3 =  8 */
#define MAX_NBITS 4 /* blocksize = 1<<4 = 16 */
#define DEFAULT_NBITS 3
#define OFFSET(x) offsetof(DCTdnoizContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define DEF_FILTER_FREQ_FUNCS(bsize)                                                        \
#define DCT3X3_0_0  0.5773502691896258f /*  1/sqrt(3) */
#define DCT3X3_0_1  0.5773502691896258f /*  1/sqrt(3) */
#define DCT3X3_0_2  0.5773502691896258f /*  1/sqrt(3) */
#define DCT3X3_1_0  0.7071067811865475f /*  1/sqrt(2) */
#define DCT3X3_1_2 -0.7071067811865475f /* -1/sqrt(2) */
#define DCT3X3_2_0  0.4082482904638631f /*  1/sqrt(6) */
#define DCT3X3_2_1 -0.8164965809277261f /* -2/sqrt(6) */
#define DCT3X3_2_2  0.4082482904638631f /*  1/sqrt(6) */
#define DECLARE_COLOR_FUNCS(name, r, g, b)                                          \
typedef struct ThreadData {
    float *src, *dst;
} ThreadData;
