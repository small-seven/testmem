#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "get_bits.h"
#include "fft.h"
#include "internal.h"
#include "sinewin.h"
#include "atrac.h"
#include "atrac1data.h"
#define AT1_MAX_BFU      52                 ///< max number of block floating units in a sound unit
#define AT1_SU_SIZE      212                ///< number of bytes in a sound unit
#define AT1_SU_SAMPLES   512                ///< number of samples in a sound unit
#define AT1_FRAME_SIZE   AT1_SU_SIZE * 2
#define AT1_SU_MAX_BITS  AT1_SU_SIZE * 8
#define AT1_MAX_CHANNELS 2
#define AT1_QMF_BANDS    3
#define IDX_LOW_BAND     0
#define IDX_MID_BAND     1
#define IDX_HIGH_BAND    2
typedef struct AT1SUCtx {
    int                 log2_block_count[AT1_QMF_BANDS];    ///< log2 number of blocks in a band
    int                 num_bfus;                           ///< number of Block Floating Units
    float*              spectrum[2];
    DECLARE_ALIGNED(32, float, spec1)[AT1_SU_SAMPLES];     ///< mdct buffer
    DECLARE_ALIGNED(32, float, spec2)[AT1_SU_SAMPLES];     ///< mdct buffer
    DECLARE_ALIGNED(32, float, fst_qmf_delay)[46];         ///< delay line for the 1st stacked QMF filter
    DECLARE_ALIGNED(32, float, snd_qmf_delay)[46];         ///< delay line for the 2nd stacked QMF filter
    DECLARE_ALIGNED(32, float, last_qmf_delay)[256+39];    ///< delay line for the last stacked QMF filter
} AT1SUCtx;
typedef struct AT1Ctx {
    AT1SUCtx            SUs[AT1_MAX_CHANNELS];              ///< channel sound unit
    DECLARE_ALIGNED(32, float, spec)[AT1_SU_SAMPLES];      ///< the mdct spectrum buffer

    DECLARE_ALIGNED(32, float,  low)[256];
    DECLARE_ALIGNED(32, float,  mid)[256];
    DECLARE_ALIGNED(32, float, high)[512];
    float*              bands[3];
    FFTContext          mdct_ctx[3];
    AVFloatDSPContext   *fdsp;
} AT1Ctx;
