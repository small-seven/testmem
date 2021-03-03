#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavcodec/avfft.h"
#include "avfilter.h"
#include "filters.h"
#include "formats.h"
#include "framesync.h"
#include "internal.h"
#include "video.h"
#define MAX_NB_THREADS 32
typedef struct ThreadData {
    const uint8_t *src;
    int src_linesize;
    const uint8_t *ref;
    int ref_linesize;
    int plane;
} ThreadData;
typedef struct PosCode {
    int x, y;
} PosCode;
typedef struct PosPairCode {
    double score;
    int x, y;
} PosPairCode;
typedef struct SliceContext {
    DCTContext *gdctf, *gdcti;
    DCTContext *dctf, *dcti;
    FFTSample *bufferh;
    FFTSample *bufferv;
    FFTSample *bufferz;
    FFTSample *buffer;
    FFTSample *rbufferh;
    FFTSample *rbufferv;
    FFTSample *rbufferz;
    FFTSample *rbuffer;
    float *num, *den;
    PosPairCode match_blocks[256];
    int nb_match_blocks;
    PosCode *search_positions;
} SliceContext;
typedef struct BM3DContext {
    const AVClass *class;

    float sigma;
    int block_size;
    int block_step;
    int group_size;
    int bm_range;
    int bm_step;
    float th_mse;
    float hard_threshold;
    int mode;
    int ref;
    int planes;

    int depth;
    int max;
    int nb_planes;
    int planewidth[4];
    int planeheight[4];
    int group_bits;
    int pgroup_size;

    SliceContext slices[MAX_NB_THREADS];

    FFFrameSync fs;
    int nb_threads;

    void (*get_block_row)(const uint8_t *srcp, int src_linesize,
                          int y, int x, int block_size, float *dst);
    double (*do_block_ssd)(struct BM3DContext *s, PosCode *pos,
                           const uint8_t *src, int src_stride,
                           int r_y, int r_x);
    void (*do_output)(struct BM3DContext *s, uint8_t *dst, int dst_linesize,
                      int plane, int nb_jobs);
    void (*block_filtering)(struct BM3DContext *s,
                            const uint8_t *src, int src_linesize,
                            const uint8_t *ref, int ref_linesize,
                            int y, int x, int plane, int jobnr);
} BM3DContext;
#define OFFSET(x) offsetof(BM3DContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define SQR(x) ((x) * (x))
