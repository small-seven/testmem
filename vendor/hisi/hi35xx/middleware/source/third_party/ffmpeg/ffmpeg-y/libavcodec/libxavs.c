#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <float.h>
#include <xavs.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#define END_OF_STREAM 0x001
#define XAVS_PART_I8X8 0x002 /* Analyze i8x8 (requires 8x8 transform) */
#define XAVS_PART_P8X8 0x010 /* Analyze p16x8, p8x16 and p8x8 */
#define XAVS_PART_B8X8 0x100 /* Analyze b16x8, b*/
typedef struct XavsContext {
    AVClass        *class;
    xavs_param_t    params;
    xavs_t         *enc;
    xavs_picture_t  pic;
    uint8_t        *sei;
    int             sei_size;
    int             end_of_stream;
    float crf;
    int cqp;
    int b_bias;
    float cplxblur;
    int direct_pred;
    int aud;
    int fast_pskip;
    int motion_est;
    int mbtree;
    int mixed_refs;
    int b_frame_strategy;
    int chroma_offset;
    int scenechange_threshold;
    int noise_reduction;

    int64_t *pts_buffer;
    int out_frame_count;
} XavsContext;
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_PRIVATE_OPT
#endif
#define OFFSET(x) offsetof(XavsContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
