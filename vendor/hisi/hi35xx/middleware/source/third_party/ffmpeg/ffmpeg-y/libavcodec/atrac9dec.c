#include "internal.h"
#include "get_bits.h"
#include "fft.h"
#include "atrac9tab.h"
#include "libavutil/lfg.h"
#include "libavutil/float_dsp.h"
typedef struct ATRAC9ChannelData {
    int band_ext;
    int q_unit_cnt;
    int band_ext_data[4];
    int32_t scalefactors[31];
    int32_t scalefactors_prev[31];

    int precision_coarse[30];
    int precision_fine[30];
    int precision_mask[30];

    int codebookset[30];

    int32_t q_coeffs_coarse[256];
    int32_t q_coeffs_fine[256];

    DECLARE_ALIGNED(32, float, coeffs  )[256];
    DECLARE_ALIGNED(32, float, prev_win)[128];
} ATRAC9ChannelData;
typedef struct ATRAC9BlockData {
    ATRAC9ChannelData channel[2];

    /* Base */
    int band_count;
    int q_unit_cnt;
    int q_unit_cnt_prev;

    /* Stereo block only */
    int stereo_q_unit;

    /* Band extension only */
    int has_band_ext;
    int has_band_ext_data;
    int band_ext_q_unit;

    /* Gradient */
    int grad_mode;
    int grad_boundary;
    int gradient[31];

    /* Stereo */
    int cpe_base_channel;
    int is_signs[30];

    int reuseable;

} ATRAC9BlockData;
typedef struct ATRAC9Context {
    AVCodecContext *avctx;
    AVFloatDSPContext *fdsp;
    FFTContext imdct;
    ATRAC9BlockData block[5];
    AVLFG lfg;

    /* Set on init */
    int frame_log2;
    int avg_frame_size;
    int frame_count;
    int samplerate_idx;
    const ATRAC9BlockConfig *block_config;

    /* Generated on init */
    VLC sf_vlc[2][8];            /* Signed/unsigned, length */
    VLC coeff_vlc[2][8][4];      /* Cookbook, precision, cookbook index */
    uint8_t alloc_curve[48][48];
    DECLARE_ALIGNED(32, float, imdct_win)[256];

    DECLARE_ALIGNED(32, float, temp)[256];
} ATRAC9Context;
