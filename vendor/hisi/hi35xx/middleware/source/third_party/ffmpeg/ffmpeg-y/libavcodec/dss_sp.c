#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#define SUBFRAMES 4
#define PULSE_MAX 8
#define DSS_SP_FRAME_SIZE        42
#define DSS_SP_SAMPLE_COUNT     (66 * SUBFRAMES)
#define DSS_SP_FORMULA(a, b, c) ((int)((((a) * (1 << 15)) + (b) * (unsigned)(c)) + 0x4000) >> 15)
typedef struct DssSpSubframe {
    int16_t gain;
    int32_t combined_pulse_pos;
    int16_t pulse_pos[7];
    int16_t pulse_val[7];
} DssSpSubframe;
typedef struct DssSpFrame {
    int16_t filter_idx[14];
    int16_t sf_adaptive_gain[SUBFRAMES];
    int16_t pitch_lag[SUBFRAMES];
    struct DssSpSubframe sf[SUBFRAMES];
} DssSpFrame;
typedef struct DssSpContext {
    AVCodecContext *avctx;
    int32_t excitation[288 + 6];
    int32_t history[187];
    DssSpFrame fparam;
    int32_t working_buffer[SUBFRAMES][72];
    int32_t audio_buf[15];
    int32_t err_buf1[15];
    int32_t lpc_filter[14];
    int32_t filter[15];
    int32_t vector_buf[72];
    int noise_state;
    int32_t err_buf2[15];

    int pulse_dec_mode;

    DECLARE_ALIGNED(16, uint8_t, bits)[DSS_SP_FRAME_SIZE +
                                       AV_INPUT_BUFFER_PADDING_SIZE];
} DssSpContext;
