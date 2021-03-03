#define AOM_DISABLE_CTRL_TYPECHECKS 1
#include <aom/aom_encoder.h>
#include <aom/aomcx.h>
#include "libavutil/avassert.h"
#include "libavutil/base64.h"
#include "libavutil/common.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "av1.h"
#include "avcodec.h"
#include "internal.h"
#include "profiles.h"
typedef struct AOMEncoderContext {
    AVClass *class;
    AVBSFContext *bsf;
    struct aom_codec_ctx encoder;
    struct aom_image rawimg;
    struct aom_fixed_buf twopass_stats;
    struct FrameListData *coded_frame_list;
    int cpu_used;
    int auto_alt_ref;
    int arnr_max_frames;
    int arnr_strength;
    int aq_mode;
    int lag_in_frames;
    int error_resilient;
    int crf;
    int static_thresh;
    int drop_threshold;
    int denoise_noise_level;
    int denoise_block_size;
    uint64_t sse[4];
    int have_sse; /**< true if we have pending sse[] */
    uint64_t frame_number;
    int rc_undershoot_pct;
    int rc_overshoot_pct;
    int minsection_pct;
    int maxsection_pct;
    int frame_parallel;
    int tile_cols, tile_rows;
    int tile_cols_log2, tile_rows_log2;
    aom_superblock_size_t superblock_size;
    int uniform_tiles;
    int row_mt;
    int enable_cdef;
    int enable_global_motion;
    int enable_intrabc;
} AOMContext;
#ifdef AOM_CTRL_AV1E_SET_ROW_MT
#endif
#ifdef AOM_CTRL_AV1E_SET_DENOISE_NOISE_LEVEL
#endif
#ifdef AOM_CTRL_AV1E_SET_DENOISE_BLOCK_SIZE
#endif
#ifdef AOM_CTRL_AV1E_SET_MAX_REFERENCE_FRAMES
#endif
#ifdef AOM_CTRL_AV1E_SET_ENABLE_GLOBAL_MOTION
#endif
#ifdef AOM_CTRL_AV1E_SET_ENABLE_INTRABC
#endif
#ifdef UENUM1BYTE
#else
#endif
static av_cold int aom_free(AVCodecContext *avctx)
{
    AOMContext *ctx = avctx->priv_data;

    aom_codec_destroy(&ctx->encoder);
    av_freep(&ctx->twopass_stats.buf);
    av_freep(&avctx->stats_out);
    free_frame_list(ctx->coded_frame_list);
    av_bsf_free(&ctx->bsf);
    return 0;
}
#ifdef AOM_FRAME_IS_INTRAONLY
#else
#endif
#ifdef AOM_CTRL_AV1E_SET_DENOISE_NOISE_LEVEL
#endif
#ifdef AOM_CTRL_AV1E_SET_DENOISE_BLOCK_SIZE
#endif
#ifdef AOM_CTRL_AV1E_SET_ENABLE_GLOBAL_MOTION
#endif
#ifdef AOM_CTRL_AV1E_SET_MAX_REFERENCE_FRAMES
#endif
#ifdef AOM_CTRL_AV1E_SET_ROW_MT
#endif
#ifdef AOM_CTRL_AV1E_SET_ENABLE_INTRABC
#endif
#ifdef AOM_FRAME_IS_INTRAONLY
#endif
#ifdef AOM_FRAME_IS_INTRAONLY
#endif
#ifdef AOM_FRAME_IS_INTRAONLY
#endif
#define OFFSET(x) offsetof(AOMContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
