#include <inttypes.h>
#include <string.h>
#include "avcodec.h"
#include "libavutil/avutil.h"
#include "get_bits.h"
#include "audiodsp.h"
#include "internal.h"
#include "g729.h"
#include "lsp.h"
#include "celp_math.h"
#include "celp_filters.h"
#include "acelp_filters.h"
#include "acelp_pitch_delay.h"
#include "acelp_vectors.h"
#include "g729data.h"
#include "g729postfilter.h"
#define LSFQ_MIN                   40
#define LSFQ_MAX                   25681
#define LSFQ_DIFF_MIN              321
#define INTERPOL_LEN              11
#define SHARP_MIN                  3277
#define SHARP_MAX                  13017
#define MR_ENERGY 1018156
#define DECISION_NOISE        0
#define DECISION_INTERMEDIATE 1
#define DECISION_VOICE        2
typedef enum {
    FORMAT_G729_8K = 0,
    FORMAT_G729D_6K4,
    FORMAT_COUNT,
} G729Formats;
typedef struct {
    uint8_t ac_index_bits[2];   ///< adaptive codebook index for second subframe (size in bits)
    uint8_t parity_bit;         ///< parity bit for pitch delay
    uint8_t gc_1st_index_bits;  ///< gain codebook (first stage) index (size in bits)
    uint8_t gc_2nd_index_bits;  ///< gain codebook (second stage) index (size in bits)
    uint8_t fc_signs_bits;      ///< number of pulses in fixed-codebook vector
    uint8_t fc_indexes_bits;    ///< size (in bits) of fixed-codebook index entry
    uint8_t block_size;
} G729FormatDescription;
typedef struct {
    /// past excitation signal buffer
    int16_t exc_base[2*SUBFRAME_SIZE+PITCH_DELAY_MAX+INTERPOL_LEN];

    int16_t* exc;               ///< start of past excitation data in buffer
    int pitch_delay_int_prev;   ///< integer part of previous subframe's pitch delay (4.1.3)

    /// (2.13) LSP quantizer outputs
    int16_t  past_quantizer_output_buf[MA_NP + 1][10];
    int16_t* past_quantizer_outputs[MA_NP + 1];

    int16_t lsfq[10];           ///< (2.13) quantized LSF coefficients from previous frame
    int16_t lsp_buf[2][10];     ///< (0.15) LSP coefficients (previous and current frames) (3.2.5)
    int16_t *lsp[2];            ///< pointers to lsp_buf

    int16_t quant_energy[4];    ///< (5.10) past quantized energy

    /// previous speech data for LP synthesis filter
    int16_t syn_filter_data[10];


    /// residual signal buffer (used in long-term postfilter)
    int16_t residual[SUBFRAME_SIZE + RES_PREV_DATA_SIZE];

    /// previous speech data for residual calculation filter
    int16_t res_filter_data[SUBFRAME_SIZE+10];

    /// previous speech data for short-term postfilter
    int16_t pos_filter_data[SUBFRAME_SIZE+10];

    /// (1.14) pitch gain of current and five previous subframes
    int16_t past_gain_pitch[6];

    /// (14.1) gain code from current and previous subframe
    int16_t past_gain_code[2];

    /// voice decision on previous subframe (0-noise, 1-intermediate, 2-voice), G.729D
    int16_t voice_decision;

    int16_t onset;              ///< detected onset level (0-2)
    int16_t was_periodic;       ///< whether previous frame was declared as periodic or not (4.4)
    int16_t ht_prev_data;       ///< previous data for 4.2.3, equation 86
    int gain_coeff;             ///< (1.14) gain coefficient (4.2.4)
    uint16_t rand_value;        ///< random number generator value (4.4.4)
    int ma_predictor_prev;      ///< switched MA predictor of LSP quantizer from last good frame

    /// (14.14) high-pass filter data (past input)
    int hpf_f[2];

    /// high-pass filter data (past output)
    int16_t hpf_z[2];
}  G729ChannelContext;
typedef struct {
    AudioDSPContext adsp;

    G729ChannelContext *channel_context;
} G729Context;
