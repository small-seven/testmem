#include <string.h>
#include <math.h>
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "libavutil/common.h"
#include "libavutil/avassert.h"
#include "celp_math.h"
#include "celp_filters.h"
#include "acelp_filters.h"
#include "acelp_vectors.h"
#include "acelp_pitch_delay.h"
#include "lsp.h"
#include "amr.h"
#include "internal.h"
#include "amrnbdata.h"
#define AMR_BLOCK_SIZE              160   ///< samples per frame
#define AMR_SAMPLE_BOUND        32768.0   ///< threshold for synthesis overflow
#define AMR_SAMPLE_SCALE  (2.0 / 32768.0)
#define PRED_FAC_MODE_12k2             0.65
#define LSF_R_FAC          (8000.0 / 32768.0) ///< LSF residual tables to Hertz
#define MIN_LSF_SPACING    (50.0488 / 8000.0) ///< Ensures stability of LPC filter
#define PITCH_LAG_MIN_MODE_12k2          18   ///< Lower bound on decoded lag search in 12.2kbit/s mode
#define MIN_ENERGY -14.0
#define SHARP_MAX 0.79449462890625
#define AMR_TILT_RESPONSE   22
#define AMR_TILT_GAMMA_T   0.8
#define AMR_AGC_ALPHA      0.9
typedef struct AMRContext {
    AMRNBFrame                        frame; ///< decoded AMR parameters (lsf coefficients, codebook indexes, etc)
    uint8_t             bad_frame_indicator; ///< bad frame ? 1 : 0
    enum Mode                cur_frame_mode;

    int16_t     prev_lsf_r[LP_FILTER_ORDER]; ///< residual LSF vector from previous subframe
    double          lsp[4][LP_FILTER_ORDER]; ///< lsp vectors from current frame
    double   prev_lsp_sub4[LP_FILTER_ORDER]; ///< lsp vector for the 4th subframe of the previous frame

    float         lsf_q[4][LP_FILTER_ORDER]; ///< Interpolated LSF vector for fixed gain smoothing
    float          lsf_avg[LP_FILTER_ORDER]; ///< vector of averaged lsf vector

    float           lpc[4][LP_FILTER_ORDER]; ///< lpc coefficient vectors for 4 subframes

    uint8_t                   pitch_lag_int; ///< integer part of pitch lag from current subframe

    float excitation_buf[PITCH_DELAY_MAX + LP_FILTER_ORDER + 1 + AMR_SUBFRAME_SIZE]; ///< current excitation and all necessary excitation history
    float                       *excitation; ///< pointer to the current excitation vector in excitation_buf

    float   pitch_vector[AMR_SUBFRAME_SIZE]; ///< adaptive code book (pitch) vector
    float   fixed_vector[AMR_SUBFRAME_SIZE]; ///< algebraic codebook (fixed) vector (must be kept zero between frames)

    float               prediction_error[4]; ///< quantified prediction errors {20log10(^gamma_gc)} for previous four subframes
