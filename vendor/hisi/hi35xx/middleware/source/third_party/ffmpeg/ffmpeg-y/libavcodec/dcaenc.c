#define FFT_FLOAT 0
#define FFT_FIXED_32 1
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "dca.h"
#include "dcaadpcm.h"
#include "dcamath.h"
#include "dca_core.h"
#include "dcadata.h"
#include "dcaenc.h"
#include "fft.h"
#include "internal.h"
#include "mathops.h"
#include "put_bits.h"
#define MAX_CHANNELS 6
#define DCA_MAX_FRAME_SIZE 16384
#define DCA_HEADER_SIZE 13
#define DCA_LFE_SAMPLES 8
#define DCAENC_SUBBANDS 32
#define SUBFRAMES 1
#define SUBSUBFRAMES 2
#define SUBBAND_SAMPLES (SUBFRAMES * SUBSUBFRAMES * 8)
#define AUBANDS 25
#define COS_T(x) (c->cos_table[(x) & 2047])
typedef struct CompressionOptions {
    int adpcm_mode;
} CompressionOptions;
typedef struct DCAEncContext {
    AVClass *class;
    PutBitContext pb;
    DCAADPCMEncContext adpcm_ctx;
    FFTContext mdct;
    CompressionOptions options;
    int frame_size;
    int frame_bits;
    int fullband_channels;
    int channels;
    int lfe_channel;
    int samplerate_index;
    int bitrate_index;
    int channel_config;
    const int32_t *band_interpolation;
    const int32_t *band_spectrum;
    int lfe_scale_factor;
    softfloat lfe_quant;
    int32_t lfe_peak_cb;
    const int8_t *channel_order_tab;  ///< channel reordering table, lfe and non lfe

    int32_t prediction_mode[MAX_CHANNELS][DCAENC_SUBBANDS];
    int32_t adpcm_history[MAX_CHANNELS][DCAENC_SUBBANDS][DCA_ADPCM_COEFFS * 2];
    int32_t history[MAX_CHANNELS][512]; /* This is a circular buffer */
    int32_t *subband[MAX_CHANNELS][DCAENC_SUBBANDS];
    int32_t quantized[MAX_CHANNELS][DCAENC_SUBBANDS][SUBBAND_SAMPLES];
    int32_t peak_cb[MAX_CHANNELS][DCAENC_SUBBANDS];
    int32_t diff_peak_cb[MAX_CHANNELS][DCAENC_SUBBANDS]; ///< expected peak of residual signal
    int32_t downsampled_lfe[DCA_LFE_SAMPLES];
    int32_t masking_curve_cb[SUBSUBFRAMES][256];
    int32_t bit_allocation_sel[MAX_CHANNELS];
    int abits[MAX_CHANNELS][DCAENC_SUBBANDS];
    int scale_factor[MAX_CHANNELS][DCAENC_SUBBANDS];
    softfloat quant[MAX_CHANNELS][DCAENC_SUBBANDS];
    int32_t quant_index_sel[MAX_CHANNELS][DCA_CODE_BOOKS];
    int32_t eff_masking_curve_cb[256];
    int32_t band_masking_cb[32];
    int32_t worst_quantization_noise;
    int32_t worst_noise_ever;
    int consumed_bits;
    int consumed_adpcm_bits; ///< Number of bits to transmit ADPCM related info

    int32_t cos_table[2048];
    int32_t band_interpolation_tab[2][512];
    int32_t band_spectrum_tab[2][8];
    int32_t auf[9][AUBANDS][256];
    int32_t cb_to_add[256];
    int32_t cb_to_level[2048];
    int32_t lfe_fir_64i[512];
} DCAEncContext;
static void subband_bufer_free(DCAEncContext *c)
{
    if (c->subband[0][0]) {
        int32_t *bufer = c->subband[0][0] - DCA_ADPCM_COEFFS;
        av_free(bufer);
        c->subband[0][0] = NULL;
    }
}
typedef void (*walk_band_t)(DCAEncContext *c, int band1, int band2, int f,
                            int32_t spectrum1, int32_t spectrum2, int channel,
                            int32_t * arg);

static void walk_band_low(DCAEncContext *c, int band, int channel,
                          walk_band_t walk, int32_t *arg)
{
    int f;

    if (band == 0) {
        for (f = 0; f < 4; f++)
            walk(c, 0, 0, f, 0, -2047, channel, arg);
    } else {
#define USED_1ABITS 1
#define USED_26ABITS 4
#define DCAENC_FLAGS AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM
