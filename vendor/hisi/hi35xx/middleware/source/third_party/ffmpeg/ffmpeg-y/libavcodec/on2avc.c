#include "libavutil/channel_layout.h"
#include "libavutil/ffmath.h"
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "bytestream.h"
#include "fft.h"
#include "get_bits.h"
#include "internal.h"
#include "on2avcdata.h"
#define ON2AVC_SUBFRAME_SIZE   1024
typedef struct On2AVCContext {
    AVCodecContext *avctx;
    AVFloatDSPContext *fdsp;
    FFTContext mdct, mdct_half, mdct_small;
    FFTContext fft128, fft256, fft512, fft1024;
    void (*wtf)(struct On2AVCContext *ctx, float *out, float *in, int size);

    int is_av500;

    const On2AVCMode *modes;
    int window_type, prev_window_type;
    int num_windows, num_bands;
    int bits_per_section;
    const int *band_start;

    int grouping[8];
    int ms_present;
    int ms_info[ON2AVC_MAX_BANDS];

    int is_long;

    uint8_t band_type[ON2AVC_MAX_BANDS];
    uint8_t band_run_end[ON2AVC_MAX_BANDS];
    int     num_sections;

    float band_scales[ON2AVC_MAX_BANDS];

    VLC scale_diff;
    VLC cb_vlc[16];

    float scale_tab[128];

    DECLARE_ALIGNED(32, float, coeffs)[2][ON2AVC_SUBFRAME_SIZE];
    DECLARE_ALIGNED(32, float, delay) [2][ON2AVC_SUBFRAME_SIZE];

    DECLARE_ALIGNED(32, float, temp)     [ON2AVC_SUBFRAME_SIZE * 2];
    DECLARE_ALIGNED(32, float, mdct_buf) [ON2AVC_SUBFRAME_SIZE];
    DECLARE_ALIGNED(32, float, long_win) [ON2AVC_SUBFRAME_SIZE];
    DECLARE_ALIGNED(32, float, short_win)[ON2AVC_SUBFRAME_SIZE / 8];
} On2AVCContext;
#define CMUL1_R(s, t, is, it) \
#define CMUL1_I(s, t, is, it) \
#define CMUL2_R(s, t, is, it) \
#define CMUL2_I(s, t, is, it) \
#define CMUL0(dst, id, s0, s1, s2, s3, t0, t1, t2, t3, is, it)         \
#define CMUL1(dst, s0, s1, s2, s3, t0, t1, t2, t3, is, it)             \
#define CMUL2(dst, s0, s1, s2, s3, t0, t1, t2, t3, is, it)             \
