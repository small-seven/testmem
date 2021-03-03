#include "libavutil/attributes.h"
#include "libavutil/ffmath.h"
#include "avcodec.h"
#include "aactab.h"
#include "psymodel.h"
#define PSY_3GPP_THR_SPREAD_HI   1.5f // spreading factor for low-to-hi threshold spreading  (15 dB/Bark)
#define PSY_3GPP_THR_SPREAD_LOW  3.0f // spreading factor for hi-to-low threshold spreading  (30 dB/Bark)
#define PSY_3GPP_EN_SPREAD_HI_L1 2.0f
#define PSY_3GPP_EN_SPREAD_HI_L2 1.5f
#define PSY_3GPP_EN_SPREAD_HI_S  1.5f
#define PSY_3GPP_EN_SPREAD_LOW_L 3.0f
#define PSY_3GPP_EN_SPREAD_LOW_S 2.0f
#define PSY_3GPP_RPEMIN      0.01f
#define PSY_3GPP_RPELEV      2.0f
#define PSY_3GPP_C1          3.0f           /* log2(8) */
#define PSY_3GPP_C2          1.3219281f     /* log2(2.5) */
#define PSY_3GPP_C3          0.55935729f    /* 1 - C2 / C1 */
#define PSY_SNR_1DB          7.9432821e-1f  /* -1dB */
#define PSY_SNR_25DB         3.1622776e-3f  /* -25dB */
#define PSY_3GPP_SAVE_SLOPE_L  -0.46666667f
#define PSY_3GPP_SAVE_SLOPE_S  -0.36363637f
#define PSY_3GPP_SAVE_ADD_L    -0.84285712f
#define PSY_3GPP_SAVE_ADD_S    -0.75f
#define PSY_3GPP_SPEND_SLOPE_L  0.66666669f
#define PSY_3GPP_SPEND_SLOPE_S  0.81818181f
#define PSY_3GPP_SPEND_ADD_L   -0.35f
#define PSY_3GPP_SPEND_ADD_S   -0.26111111f
#define PSY_3GPP_CLIP_LO_L      0.2f
#define PSY_3GPP_CLIP_LO_S      0.2f
#define PSY_3GPP_CLIP_HI_L      0.95f
#define PSY_3GPP_CLIP_HI_S      0.75f
#define PSY_3GPP_AH_THR_LONG    0.5f
#define PSY_3GPP_AH_THR_SHORT   0.63f
#define PSY_PE_FORGET_SLOPE  511
#define PSY_3GPP_BITS_TO_PE(bits) ((bits) * 1.18f)
#define PSY_3GPP_PE_TO_BITS(bits) ((bits) / 1.18f)
#define PSY_LAME_FIR_LEN 21         ///< LAME psy model FIR order
#define AAC_BLOCK_SIZE_LONG 1024    ///< long block size
#define AAC_BLOCK_SIZE_SHORT 128    ///< short block size
#define AAC_NUM_BLOCKS_SHORT 8      ///< number of blocks in a short sequence
#define PSY_LAME_NUM_SUBBLOCKS 3    ///< Number of sub-blocks in each short block
typedef struct AacPsyBand{
    float energy;       ///< band energy
    float thr;          ///< energy threshold
    float thr_quiet;    ///< threshold in quiet
    float nz_lines;     ///< number of non-zero spectral lines
    float active_lines; ///< number of active spectral lines
    float pe;           ///< perceptual entropy
    float pe_const;     ///< constant part of the PE calculation
    float norm_fac;     ///< normalization factor for linearization
    int   avoid_holes;  ///< hole avoidance flag
}AacPsyBand;
typedef struct AacPsyChannel{
    AacPsyBand band[128];               ///< bands information
    AacPsyBand prev_band[128];          ///< bands information from the previous frame

    float       win_energy;              ///< sliding average of channel energy
    float       iir_state[2];            ///< hi-pass IIR filter state
    uint8_t     next_grouping;           ///< stored grouping scheme for the next frame (in case of 8 short window sequence)
    enum WindowSequence next_window_seq; ///< window sequence to be used in the next frame
    /* LAME psy model specific members */
    float attack_threshold;              ///< attack threshold for this channel
    float prev_energy_subshort[AAC_NUM_BLOCKS_SHORT * PSY_LAME_NUM_SUBBLOCKS];
    int   prev_attack;                   ///< attack value for the last short block in the previous sequence
}AacPsyChannel;
typedef struct AacPsyCoeffs{
    float ath;           ///< absolute threshold of hearing per bands
    float barks;         ///< Bark value for each spectral band in long frame
    float spread_low[2]; ///< spreading factor for low-to-high threshold spreading in long frame
    float spread_hi [2]; ///< spreading factor for high-to-low threshold spreading in long frame
    float min_snr;       ///< minimal SNR
}AacPsyCoeffs;
typedef struct AacPsyContext{
    int chan_bitrate;     ///< bitrate per channel
    int frame_bits;       ///< average bits per frame
    int fill_level;       ///< bit reservoir fill level
    struct {
        float min;        ///< minimum allowed PE for bit factor calculation
        float max;        ///< maximum allowed PE for bit factor calculation
        float previous;   ///< allowed PE of the previous frame
        float correction; ///< PE correction factor
    } pe;
typedef struct PsyLamePreset {
    int   quality;  ///< Quality to map the rest of the vaules to.
     /* This is overloaded to be both kbps per channel in ABR mode, and
      * requested quality in constant quality mode.
      */
    float st_lrm;   ///< short threshold for L, R, and M channels
} PsyLamePreset;
#if ARCH_MIPS
#   include "mips/aacpsy_mips.h"
#endif /* ARCH_MIPS */
#define ATH_ADD 4
#ifndef calc_thr_3gpp
#endif /* calc_thr_3gpp */
#ifndef psy_hp_filter
#endif /* psy_hp_filter */
