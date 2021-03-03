#include "libavutil/avassert.h"
#include "libavutil/intreadwrite.h"
#include "internal.h"
#include "get_bits.h"
#include "avcodec.h"
#include "golomb.h"
#include "mathops.h"
#include "dsd.h"
#define DST_MAX_CHANNELS 6
#define DST_MAX_ELEMENTS (2 * DST_MAX_CHANNELS)
#define DSD_FS44(sample_rate) (sample_rate * 8LL / 44100)
#define DST_SAMPLES_PER_FRAME(sample_rate) (588 * DSD_FS44(sample_rate))
typedef struct ArithCoder {
    unsigned int a;
    unsigned int c;
} ArithCoder;
typedef struct Table {
    unsigned int elements;
    unsigned int length[DST_MAX_ELEMENTS];
    int coeff[DST_MAX_ELEMENTS][128];
} Table;
typedef struct DSTContext {
    AVClass *class;

    GetBitContext gb;
    ArithCoder ac;
    Table fsets, probs;
    DECLARE_ALIGNED(16, uint8_t, status)[DST_MAX_CHANNELS][16];
    DECLARE_ALIGNED(16, int16_t, filter)[DST_MAX_ELEMENTS][16][256];
    DSDContext dsdctx[DST_MAX_CHANNELS];
} DSTContext;
#define F(x) filter[(x)][status[(x)]]
#undef F
