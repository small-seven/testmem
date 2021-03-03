#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "mathops.h"
#include "mss34dsp.h"
#define HEADER_SIZE 27
#define MODEL2_SCALE       13
#define MODEL_SCALE        15
#define MODEL256_SEC_SCALE  9
typedef struct Model2 {
    int      upd_val, till_rescale;
    unsigned zero_freq,  zero_weight;
    unsigned total_freq, total_weight;
} Model2;
typedef struct Model {
    int weights[16], freqs[16];
    int num_syms;
    int tot_weight;
    int upd_val, max_upd_val, till_rescale;
} Model;
typedef struct Model256 {
    int weights[256], freqs[256];
    int tot_weight;
    int secondary[68];
    int sec_size;
    int upd_val, max_upd_val, till_rescale;
} Model256;
#define RAC_BOTTOM 0x01000000
typedef struct RangeCoder {
    const uint8_t *src, *src_end;

    uint32_t range, low;
    int got_error;
} RangeCoder;
typedef struct BlockTypeContext {
    int      last_type;
    Model    bt_model[5];
} BlockTypeContext;
typedef struct FillBlockCoder {
    int      fill_val;
    Model    coef_model;
} FillBlockCoder;
typedef struct ImageBlockCoder {
    Model256 esc_model, vec_entry_model;
    Model    vec_size_model;
    Model    vq_model[125];
} ImageBlockCoder;
typedef struct DCTBlockCoder {
    int      *prev_dc;
    ptrdiff_t prev_dc_stride;
    int      prev_dc_height;
    int      quality;
    uint16_t qmat[64];
    Model    dc_model;
    Model2   sign_model;
    Model256 ac_model;
} DCTBlockCoder;
typedef struct HaarBlockCoder {
    int      quality, scale;
    Model256 coef_model;
    Model    coef_hi_model;
} HaarBlockCoder;
typedef struct MSS3Context {
    AVCodecContext   *avctx;
    AVFrame          *pic;

    int              got_error;
    RangeCoder       coder;
    BlockTypeContext btype[3];
    FillBlockCoder   fill_coder[3];
    ImageBlockCoder  image_coder[3];
    DCTBlockCoder    dct_coder[3];
    HaarBlockCoder   haar_coder[3];

    int              dctblock[64];
    int              hblock[16 * 16];
} MSS3Context;
