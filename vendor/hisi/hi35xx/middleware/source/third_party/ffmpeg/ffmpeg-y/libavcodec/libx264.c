#include "libavutil/eval.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "libavutil/stereo3d.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#if defined(_MSC_VER)
#define X264_API_IMPORTS 1
#endif
#include <x264.h>
#include <float.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MB_SIZE 16
typedef struct X264Context {
    AVClass        *class;
    x264_param_t    params;
    x264_t         *enc;
    x264_picture_t  pic;
    uint8_t        *sei;
    int             sei_size;
    char *preset;
    char *tune;
    char *profile;
    char *level;
    int fastfirstpass;
    char *wpredp;
    char *x264opts;
    float crf;
    float crf_max;
    int cqp;
    int aq_mode;
    float aq_strength;
    char *psy_rd;
    int psy;
    int rc_lookahead;
    int weightp;
    int weightb;
    int ssim;
    int intra_refresh;
    int bluray_compat;
    int b_bias;
    int b_pyramid;
    int mixed_refs;
    int dct8x8;
    int fast_pskip;
    int aud;
    int mbtree;
    char *deblock;
    float cplxblur;
    char *partitions;
    int direct_pred;
    int slice_max_size;
    char *stats;
    int nal_hrd;
    int avcintra_class;
    int motion_est;
    int forced_idr;
    int coder;
    int a53_cc;
    int b_frame_strategy;
    int chroma_offset;
    int scenechange_threshold;
    int noise_reduction;

    char *x264_params;

    int nb_reordered_opaque, next_reordered_opaque;
    int64_t *reordered_opaque;
} X264Context;
#if X264_BUILD >= 145
#endif
#if X264_BUILD >= 153
#else
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#define OPT_STR(opt, param)                                                   \
#if CONFIG_LIBX264RGB_ENCODER
#endif
#ifdef X264_CSP_NV21
#endif
#ifdef X264_CSP_I400
#endif
#define PARSE_X264_OPT(name, var)\
#if CONFIG_LIBX262_ENCODER
#endif
#if X264_BUILD >= 153
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODER_TYPE
#endif
#if X264_BUILD >= 142
#else
#endif
#ifdef X264_CSP_NV21
#endif
#ifdef X264_CSP_NV21
#endif
#ifdef X264_CSP_I400
#endif
#if CONFIG_LIBX264RGB_ENCODER
#endif
#if X264_BUILD < 153
#else
#endif
#define OFFSET(x) offsetof(X264Context, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#if X264_BUILD >= 144
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODER_TYPE
#endif
#if CONFIG_LIBX264_ENCODER
#endif
#if CONFIG_LIBX264RGB_ENCODER
#endif
#if CONFIG_LIBX262_ENCODER
#endif
