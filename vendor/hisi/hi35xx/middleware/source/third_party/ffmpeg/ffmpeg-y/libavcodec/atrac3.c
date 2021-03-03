#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "libavutil/attributes.h"
#include "libavutil/float_dsp.h"
#include "libavutil/libm.h"
#include "avcodec.h"
#include "bytestream.h"
#include "fft.h"
#include "get_bits.h"
#include "internal.h"
#include "atrac.h"
#include "atrac3data.h"
#define MIN_CHANNELS    1
#define MAX_CHANNELS    8
#define MAX_JS_PAIRS    8 / 2
#define JOINT_STEREO    0x12
#define SINGLE          0x2
#define SAMPLES_PER_FRAME 1024
#define MDCT_SIZE          512
typedef struct GainBlock {
    AtracGainInfo g_block[4];
} GainBlock;
typedef struct TonalComponent {
    int pos;
    int num_coefs;
    float coef[8];
} TonalComponent;
typedef struct ChannelUnit {
    int            bands_coded;
    int            num_components;
    float          prev_frame[SAMPLES_PER_FRAME];
    int            gc_blk_switch;
    TonalComponent components[64];
    GainBlock      gain_block[2];

    DECLARE_ALIGNED(32, float, spectrum)[SAMPLES_PER_FRAME];
    DECLARE_ALIGNED(32, float, imdct_buf)[SAMPLES_PER_FRAME];

    float          delay_buf1[46]; ///<qmf delay buffers
    float          delay_buf2[46];
    float          delay_buf3[46];
} ChannelUnit;
typedef struct ATRAC3Context {
    GetBitContext gb;
    //@{
    /** stream data */
    int coding_mode;

    ChannelUnit *units;
    //@}
#define INTERPOLATE(old, new, nsample) \
