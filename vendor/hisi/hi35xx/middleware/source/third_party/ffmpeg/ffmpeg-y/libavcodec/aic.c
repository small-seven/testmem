#include <inttypes.h>
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "get_bits.h"
#include "golomb.h"
#include "idctdsp.h"
#include "thread.h"
#include "unary.h"
#define AIC_HDR_SIZE    24
#define AIC_BAND_COEFFS (64 + 32 + 192 + 96)
typedef struct AICContext {
    AVCodecContext *avctx;
    AVFrame        *frame;
    IDCTDSPContext idsp;
    ScanTable      scantable;

    int            num_x_slices;
    int            slice_width;
    int            mb_width, mb_height;
    int            quant;
    int            interlaced;

    int16_t        *slice_data;
    int16_t        *data_ptr[NUM_BANDS];

    DECLARE_ALIGNED(16, int16_t, block)[64];
    DECLARE_ALIGNED(16, uint8_t, quant_matrix)[64];
} AICContext;
#define GET_CODE(val, type, add_bits)                         \
