#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "evrcdata.h"
#include "acelp_vectors.h"
#include "lsp.h"
#define MIN_LSP_SEP (0.05 / (2.0 * M_PI))
#define MIN_DELAY      20
#define MAX_DELAY     120
#define NB_SUBFRAMES    3
#define SUBFRAME_SIZE  54
#define FILTER_ORDER   10
#define ACB_SIZE      128
typedef enum {
    RATE_ERRS = -1,
    SILENCE,
    RATE_QUANT,
    RATE_QUARTER,
    RATE_HALF,
    RATE_FULL,
} evrc_packet_rate;
typedef struct EVRCAFrame {
    uint8_t  lpc_flag;        ///< spectral change indicator
    uint16_t lsp[4];          ///< index into LSP codebook
    uint8_t  pitch_delay;     ///< pitch delay for entire frame
    uint8_t  delay_diff;      ///< delay difference for entire frame
    uint8_t  acb_gain[3];     ///< adaptive codebook gain
    uint16_t fcb_shape[3][4]; ///< fixed codebook shape
    uint8_t  fcb_gain[3];     ///< fixed codebook gain index
    uint8_t  energy_gain;     ///< frame energy gain index
    uint8_t  tty;             ///< tty baud rate bit
} EVRCAFrame;
typedef struct EVRCContext {
    AVClass *class;

    int              postfilter;

    GetBitContext    gb;
    evrc_packet_rate bitrate;
    evrc_packet_rate last_valid_bitrate;
    EVRCAFrame       frame;

    float            lspf[FILTER_ORDER];
    float            prev_lspf[FILTER_ORDER];
    float            synthesis[FILTER_ORDER];
    float            postfilter_fir[FILTER_ORDER];
    float            postfilter_iir[FILTER_ORDER];
    float            postfilter_residual[ACB_SIZE + SUBFRAME_SIZE];
    float            pitch_delay;
    float            prev_pitch_delay;
    float            avg_acb_gain;  ///< average adaptive codebook gain
    float            avg_fcb_gain;  ///< average fixed codebook gain
    float            pitch[ACB_SIZE + FILTER_ORDER + SUBFRAME_SIZE];
    float            pitch_back[ACB_SIZE];
    float            interpolation_coeffs[136];
    float            energy_vector[NB_SUBFRAMES];
    float            fade_scale;
    float            last;

    uint8_t          prev_energy_gain;
    uint8_t          prev_error_flag;
    uint8_t          warned_buf_mismatch_bitrate;
} EVRCContext;
#define OFFSET(x) offsetof(EVRCContext, x)
#define AD AV_OPT_FLAG_AUDIO_PARAM | AV_OPT_FLAG_DECODING_PARAM
