#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/float_dsp.h"
#include "libavutil/lfg.h"
#include "avcodec.h"
#include "lsp.h"
#include "celp_filters.h"
#include "celp_math.h"
#include "acelp_filters.h"
#include "acelp_vectors.h"
#include "acelp_pitch_delay.h"
#include "internal.h"
#define AMR_USE_16BIT_TABLES
#include "amr.h"
#include "amrwbdata.h"
#include "mips/amrwbdec_mips.h"
typedef struct AMRWBContext {
    AMRWBFrame                             frame; ///< AMRWB parameters decoded from bitstream
    enum Mode                        fr_cur_mode; ///< mode index of current frame
    uint8_t                           fr_quality; ///< frame quality index (FQI)
    float                      isf_cur[LP_ORDER]; ///< working ISF vector from current frame
    float                   isf_q_past[LP_ORDER]; ///< quantized ISF vector of the previous frame
    float               isf_past_final[LP_ORDER]; ///< final processed ISF vector of the previous frame
    double                      isp[4][LP_ORDER]; ///< ISP vectors from current frame
    double               isp_sub4_past[LP_ORDER]; ///< ISP vector for the 4th subframe of the previous frame

    float                   lp_coef[4][LP_ORDER]; ///< Linear Prediction Coefficients from ISP vector

    uint8_t                       base_pitch_lag; ///< integer part of pitch lag for the next relative subframe
    uint8_t                        pitch_lag_int; ///< integer part of pitch lag of the previous subframe

    float excitation_buf[AMRWB_P_DELAY_MAX + LP_ORDER + 2 + AMRWB_SFR_SIZE]; ///< current excitation and all necessary excitation history
    float                            *excitation; ///< points to current excitation in excitation_buf[]

    float           pitch_vector[AMRWB_SFR_SIZE]; ///< adaptive codebook (pitch) vector for current subframe
    float           fixed_vector[AMRWB_SFR_SIZE]; ///< algebraic codebook (fixed) vector for current subframe

    float                    prediction_error[4]; ///< quantified prediction errors {20log10(^gamma_gc)} for previous four subframes
#define BIT_STR(x,lsb,len) av_mod_uintp2((x) >> (lsb), (len))
#define BIT_POS(x, p) (((x) >> (p)) & 1)
#ifndef hb_fir_filter
#endif /* hb_fir_filter */
