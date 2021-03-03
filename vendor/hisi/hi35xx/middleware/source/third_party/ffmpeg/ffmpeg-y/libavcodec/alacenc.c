#include "libavutil/opt.h"
#include "avcodec.h"
#include "put_bits.h"
#include "internal.h"
#include "lpc.h"
#include "mathops.h"
#include "alac_data.h"
#define DEFAULT_FRAME_SIZE        4096
#define ALAC_EXTRADATA_SIZE       36
#define ALAC_FRAME_HEADER_SIZE    55
#define ALAC_FRAME_FOOTER_SIZE    3
#define ALAC_ESCAPE_CODE          0x1FF
#define ALAC_MAX_LPC_ORDER        30
#define DEFAULT_MAX_PRED_ORDER    6
#define DEFAULT_MIN_PRED_ORDER    4
#define ALAC_MAX_LPC_PRECISION    9
#define ALAC_MIN_LPC_SHIFT        0
#define ALAC_MAX_LPC_SHIFT        9
#define ALAC_CHMODE_LEFT_RIGHT    0
#define ALAC_CHMODE_LEFT_SIDE     1
#define ALAC_CHMODE_RIGHT_SIDE    2
#define ALAC_CHMODE_MID_SIDE      3
typedef struct RiceContext {
    int history_mult;
    int initial_history;
    int k_modifier;
    int rice_modifier;
} RiceContext;
typedef struct AlacLPCContext {
    int lpc_order;
    int lpc_coeff[ALAC_MAX_LPC_ORDER+1];
    int lpc_quant;
} AlacLPCContext;
typedef struct AlacEncodeContext {
    const AVClass *class;
    AVCodecContext *avctx;
    int frame_size;                     /**< current frame size               */
    int verbatim;                       /**< current frame verbatim mode flag */
    int compression_level;
    int min_prediction_order;
    int max_prediction_order;
    int max_coded_frame_size;
    int write_sample_size;
    int extra_bits;
    int32_t sample_buf[2][DEFAULT_FRAME_SIZE];
    int32_t predictor_buf[2][DEFAULT_FRAME_SIZE];
    int interlacing_shift;
    int interlacing_leftweight;
    PutBitContext pbctx;
    RiceContext rc;
    AlacLPCContext lpc[2];
    LPCContext lpc_ctx;
} AlacEncodeContext;
#define COPY_SAMPLES(type) do {                             \
#if FF_API_PRIVATE_OPT
#endif
#define OFFSET(x) offsetof(AlacEncodeContext, x)
#define AE AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
