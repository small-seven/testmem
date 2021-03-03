#define VPX_DISABLE_CTRL_TYPECHECKS 1
#define VPX_CODEC_DISABLE_COMPAT    1
#include <vpx/vpx_encoder.h>
#include <vpx/vp8cx.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/avassert.h"
#include "libvpx.h"
#include "profiles.h"
#include "libavutil/avstring.h"
#include "libavutil/base64.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
typedef struct VPxEncoderContext {
    AVClass *class;
    struct vpx_codec_ctx encoder;
    struct vpx_image rawimg;
    struct vpx_codec_ctx encoder_alpha;
    struct vpx_image rawimg_alpha;
    uint8_t is_alpha;
    struct vpx_fixed_buf twopass_stats;
    int deadline; //i.e., RT/GOOD/BEST
    uint64_t sse[4];
    int have_sse; /**< true if we have pending sse[] */
    uint64_t frame_number;
    struct FrameListData *coded_frame_list;

    int cpu_used;
    int sharpness;
    /**
     * VP8 specific flags, see VP8F_* below.
     */
    int flags;
#define VP8F_ERROR_RESILIENT 0x00000001 ///< Enable measures appropriate for streaming over lossy links
#define VP8F_AUTO_ALT_REF    0x00000002 ///< Enable automatic alternate reference frame generation

    int auto_alt_ref;

    int arnr_max_frames;
    int arnr_strength;
    int arnr_type;

    int tune;

    int lag_in_frames;
    int error_resilient;
    int crf;
    int static_thresh;
    int max_intra_rate;
    int rc_undershoot_pct;
    int rc_overshoot_pct;

    char *vp8_ts_parameters;

    // VP9-only
    int lossless;
    int tile_columns;
    int tile_rows;
    int frame_parallel;
    int aq_mode;
    int drop_threshold;
    int noise_sensitivity;
    int vpx_cs;
    float level;
    int row_mt;
    int tune_content;
    int corpus_complexity;
    int tpl_model;
} VPxContext;
#if CONFIG_LIBVPX_VP9_ENCODER
#if VPX_ENCODER_ABI_VERSION >= 11
#endif
#if VPX_ENCODER_ABI_VERSION >= 12
#endif
#ifdef VPX_CTRL_VP9E_SET_ROW_MT
#endif
#ifdef VPX_CTRL_VP9E_SET_TUNE_CONTENT
#endif
#ifdef VPX_CTRL_VP9E_SET_TPL
#endif
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if VPX_ENCODER_ABI_VERSION >= 14
#endif
#if VPX_ENCODER_ABI_VERSION >= 12
#endif
static av_cold int vpx_free(AVCodecContext *avctx)
{
    VPxContext *ctx = avctx->priv_data;

#if VPX_ENCODER_ABI_VERSION >= 12
    if (avctx->codec_id == AV_CODEC_ID_VP9 && ctx->level >= 0 &&
        !(avctx->flags & AV_CODEC_FLAG_PASS1)) {
        int level_out = 0;
        if (!codecctl_intp(avctx, VP9E_GET_LEVEL, &level_out))
            av_log(avctx, AV_LOG_INFO, "Encoded level %.1f\n", level_out * 0.1);
    }
#endif

    vpx_codec_destroy(&ctx->encoder);
    if (ctx->is_alpha)
        vpx_codec_destroy(&ctx->encoder_alpha);
    av_freep(&ctx->twopass_stats.buf);
    av_freep(&avctx->stats_out);
    free_frame_list(ctx->coded_frame_list);
    return 0;
}
#if CONFIG_LIBVPX_VP9_ENCODER
#if VPX_ENCODER_ABI_VERSION >= 11
#endif
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if FF_API_PRIVATE_OPT
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#if VPX_ENCODER_ABI_VERSION >= 14
#endif
#endif
#if FF_API_PRIVATE_OPT
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#if VPX_ENCODER_ABI_VERSION >= 11
#endif
#if VPX_ENCODER_ABI_VERSION >= 12
#endif
#ifdef VPX_CTRL_VP9E_SET_ROW_MT
#endif
#ifdef VPX_CTRL_VP9E_SET_TUNE_CONTENT
#endif
#ifdef VPX_CTRL_VP9E_SET_TPL
#endif
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if VPX_IMAGE_ABI_VERSION >= 4
#endif
#define OFFSET(x) offsetof(VPxContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#define COMMON_OPTIONS \
#define LEGACY_OPTIONS \
#if CONFIG_LIBVPX_VP8_ENCODER
#endif
#if CONFIG_LIBVPX_VP9_ENCODER
#if VPX_ENCODER_ABI_VERSION >= 12
#else
#endif
#if VPX_ENCODER_ABI_VERSION >= 12
#endif
#ifdef VPX_CTRL_VP9E_SET_ROW_MT
#endif
#ifdef VPX_CTRL_VP9E_SET_TUNE_CONTENT
#if VPX_ENCODER_ABI_VERSION >= 14
#else
#endif
#if VPX_ENCODER_ABI_VERSION >= 14
#endif
#endif
#if VPX_ENCODER_ABI_VERSION >= 14
#endif
#ifdef VPX_CTRL_VP9E_SET_TPL
#endif
#endif
#undef COMMON_OPTIONS
#undef LEGACY_OPTIONS
#if CONFIG_LIBVPX_VP8_ENCODER
#endif /* CONFIG_LIBVPX_VP8_ENCODER */
#if CONFIG_LIBVPX_VP9_ENCODER
#endif /* CONFIG_LIBVPX_VP9_ENCODER */
