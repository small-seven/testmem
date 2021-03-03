#include <stddef.h>
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "qcelpdata.h"
#include "celp_filters.h"
#include "acelp_filters.h"
#include "acelp_vectors.h"
#include "lsp.h"
typedef enum {
    I_F_Q = -1,    /**< insufficient frame quality */
    SILENCE,
    RATE_OCTAVE,
    RATE_QUARTER,
    RATE_HALF,
    RATE_FULL
} qcelp_packet_rate;
typedef struct QCELPContext {
    GetBitContext     gb;
    qcelp_packet_rate bitrate;
    QCELPFrame        frame;    /**< unpacked data frame */

    uint8_t  erasure_count;
    uint8_t  octave_count;      /**< count the consecutive RATE_OCTAVE frames */
    float    prev_lspf[10];
    float    predictor_lspf[10];/**< LSP predictor for RATE_OCTAVE and I_F_Q */
    float    pitch_synthesis_filter_mem[303];
    float    pitch_pre_filter_mem[303];
    float    rnd_fir_filter_mem[180];
    float    formant_mem[170];
    float    last_codebook_gain;
    int      prev_g1[2];
    int      prev_bitrate;
    float    pitch_gain[4];
    uint8_t  pitch_lag[4];
    uint16_t first16bits;
    uint8_t  warned_buf_mismatch_bitrate;

    /* postfilter */
    float    postfilter_synth_mem[10];
    float    postfilter_agc_mem;
    float    postfilter_tilt_mem;
} QCELPContext;
