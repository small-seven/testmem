#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include "mathops.h"
#include "audio_frame_queue.h"
#define NB_FILTERS 2
#define FILTER_TAPS 16
typedef struct {
    int pos;
    int32_t buffer[2*FILTER_TAPS];
} FilterSignal;
typedef struct {
    FilterSignal outer_filter_signal[NB_FILTERS];
    FilterSignal inner_filter_signal[NB_FILTERS][NB_FILTERS];
} QMFAnalysis;
typedef struct {
    int32_t quantized_sample;
    int32_t quantized_sample_parity_change;
    int32_t error;
} Quantize;
typedef struct {
    int32_t quantization_factor;
    int32_t factor_select;
    int32_t reconstructed_difference;
} InvertQuantize;
typedef struct {
    int32_t prev_sign[2];
    int32_t s_weight[2];
    int32_t d_weight[24];
    int32_t pos;
    int32_t reconstructed_differences[48];
    int32_t previous_reconstructed_sample;
    int32_t predicted_difference;
    int32_t predicted_sample;
} Prediction;
typedef struct {
    int32_t codeword_history;
    int32_t dither_parity;
    int32_t dither[NB_SUBBANDS];

    QMFAnalysis qmf;
    Quantize quantize[NB_SUBBANDS];
    InvertQuantize invert_quantize[NB_SUBBANDS];
    Prediction prediction[NB_SUBBANDS];
} Channel;
typedef struct {
    int hd;
    int block_size;
    int32_t sync_idx;
    Channel channels[NB_CHANNELS];
    AudioFrameQueue afq;
} AptXContext;
typedef const struct {
    const int32_t *quantize_intervals;
    const int32_t *invert_quantize_dither_factors;
    const int32_t *quantize_dither_factors;
    const int16_t *quantize_factor_select_offset;
    int tables_size;
    int32_t factor_max;
    int32_t prediction_order;
} ConstTables;
#define RSHIFT_SIZE(size)                                                     \
#if CONFIG_APTX_DECODER
#endif
#if CONFIG_APTX_HD_DECODER
#endif
#if CONFIG_APTX_ENCODER
#endif
#if CONFIG_APTX_HD_ENCODER
#endif
