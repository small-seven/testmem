#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/lfg.h"
#include "libavutil/random_seed.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "fft.h"
#include "get_bits.h"
#include "internal.h"
#include "nellymoser.h"
#include "sinewin.h"
typedef struct NellyMoserDecodeContext {
    AVCodecContext* avctx;
    AVLFG           random_state;
    GetBitContext   gb;
    float           scale_bias;
    AVFloatDSPContext *fdsp;
    FFTContext      imdct_ctx;
    DECLARE_ALIGNED(32, float, imdct_buf)[2][NELLY_BUF_LEN];
    float          *imdct_out;
    float          *imdct_prev;
} NellyMoserDecodeContext;
