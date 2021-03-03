#include "motion_estimation.h"
#include "libavcodec/mathops.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/motion_vector.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#include "scene_sad.h"
#define ME_MODE_BIDIR 0
#define ME_MODE_BILAT 1
#define MC_MODE_OBMC 0
#define MC_MODE_AOBMC 1
#define SCD_METHOD_NONE 0
#define SCD_METHOD_FDIFF 1
#define NB_FRAMES 4
#define NB_PIXEL_MVS 32
#define NB_CLUSTERS 128
#define ALPHA_MAX 1024
#define CLUSTER_THRESHOLD 4
#define PX_WEIGHT_MAX 255
#define COST_PRED_SCALE 64
typedef struct Cluster {
    int64_t sum[2];
    int nb;
} Cluster;
typedef struct Block {
    int16_t mvs[2][2];
    int cid;
    uint64_t sbad;
    int sb;
    struct Block *subs;
} Block;
typedef struct PixelMVS {
    int16_t mvs[NB_PIXEL_MVS][2];
} PixelMVS;
typedef struct PixelWeights {
    uint32_t weights[NB_PIXEL_MVS];
} PixelWeights;
typedef struct PixelRefs {
    int8_t refs[NB_PIXEL_MVS];
    int nb;
} PixelRefs;
typedef struct Frame {
    AVFrame *avf;
    Block *blocks;
} Frame;
typedef struct MIContext {
    const AVClass *class;
    AVMotionEstContext me_ctx;
    AVRational frame_rate;
    enum MIMode mi_mode;
    int mc_mode;
    int me_mode;
    int me_method;
    int mb_size;
    int search_param;
    int vsbmc;

    Frame frames[NB_FRAMES];
    Cluster clusters[NB_CLUSTERS];
    Block *int_blocks;
    PixelMVS *pixel_mvs;
    PixelWeights *pixel_weights;
    PixelRefs *pixel_refs;
    int (*mv_table[3])[2][2];
    int64_t out_pts;
    int b_width, b_height, b_count;
    int log2_mb_size;

    int scd_method;
    int scene_changed;
    ff_scene_sad_fn sad;
    double prev_mafd;
    double scd_threshold;

    int log2_chroma_w;
    int log2_chroma_h;
    int nb_planes;
} MIContext;
#define OFFSET(x) offsetof(MIContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define CONST(name, help, val, unit) { name, help, 0, AV_OPT_TYPE_CONST, {.i64=val}, 0, 0, FLAGS, unit }
#define ADD_PRED(preds, px, py)\
#define ADD_PIXELS(b_weight, mv_x, mv_y)\
