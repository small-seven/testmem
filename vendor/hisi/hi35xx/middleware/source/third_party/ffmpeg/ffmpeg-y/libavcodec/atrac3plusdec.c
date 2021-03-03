#include <stdint.h>
#include <string.h>
#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#include "atrac.h"
#include "atrac3plus.h"
typedef struct ATRAC3PContext {
    GetBitContext gb;
    AVFloatDSPContext *fdsp;

    DECLARE_ALIGNED(32, float, samples)[2][ATRAC3P_FRAME_SAMPLES];  ///< quantized MDCT spectrum
    DECLARE_ALIGNED(32, float, mdct_buf)[2][ATRAC3P_FRAME_SAMPLES]; ///< output of the IMDCT
    DECLARE_ALIGNED(32, float, time_buf)[2][ATRAC3P_FRAME_SAMPLES]; ///< output of the gain compensation
    DECLARE_ALIGNED(32, float, outp_buf)[2][ATRAC3P_FRAME_SAMPLES];

    AtracGCContext gainc_ctx;   ///< gain compensation context
    FFTContext mdct_ctx;
    FFTContext ipqf_dct_ctx;    ///< IDCT context used by IPQF

    Atrac3pChanUnitCtx *ch_units;   ///< global channel units

    int num_channel_blocks;     ///< number of channel blocks
    uint8_t channel_blocks[5];  ///< channel configuration descriptor
    uint64_t my_channel_layout; ///< current channel layout
} ATRAC3PContext;
