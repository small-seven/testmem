#define BITSTREAM_WRITER_LE
#include "libavutil/intreadwrite.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
#include "bytestream.h"
#include "wavpackenc.h"
#include "wavpack.h"
#define UPDATE_WEIGHT(weight, delta, source, result) \
#define APPLY_WEIGHT_F(weight, sample) ((((((sample) & 0xffff) * (weight)) >> 9) + \
#define APPLY_WEIGHT_I(weight, sample) (((weight) * (sample) + 512) >> 10)
#define APPLY_WEIGHT(weight, sample) ((sample) != (short) (sample) ? \
#define CLEAR(destin) memset(&destin, 0, sizeof(destin));
#define SHIFT_LSB       13
#define SHIFT_MASK      (0x1FU << SHIFT_LSB)
#define MAG_LSB         18
#define MAG_MASK        (0x1FU << MAG_LSB)
#define SRATE_LSB       23
#define SRATE_MASK      (0xFU << SRATE_LSB)
#define EXTRA_TRY_DELTAS     1
#define EXTRA_ADJUST_DELTAS  2
#define EXTRA_SORT_FIRST     4
#define EXTRA_BRANCHES       8
#define EXTRA_SORT_LAST     16
typedef struct WavPackExtraInfo {
    struct Decorr dps[MAX_TERMS];
    int nterms, log_limit, gt16bit;
    uint32_t best_bits;
} WavPackExtraInfo;
typedef struct WavPackWords {
    int pend_data, holding_one, zeros_acc;
    int holding_zero, pend_count;
    WvChannel c[2];
} WavPackWords;
typedef struct WavPackEncodeContext {
    AVClass *class;
    AVCodecContext *avctx;
    PutBitContext pb;
    int block_samples;
    int buffer_size;
    int sample_index;
    int stereo, stereo_in;
    int ch_offset;

    int32_t *samples[2];
    int samples_size[2];

    int32_t *sampleptrs[MAX_TERMS+2][2];
    int sampleptrs_size[MAX_TERMS+2][2];

    int32_t *temp_buffer[2][2];
    int temp_buffer_size[2][2];

    int32_t *best_buffer[2];
    int best_buffer_size[2];

    int32_t *js_left, *js_right;
    int js_left_size, js_right_size;

    int32_t *orig_l, *orig_r;
    int orig_l_size, orig_r_size;

    unsigned extra_flags;
    int optimize_mono;
    int decorr_filter;
    int joint;
    int num_branches;

    uint32_t flags;
    uint32_t crc_x;
    WavPackWords w;

    uint8_t int32_sent_bits, int32_zeros, int32_ones, int32_dups;
    uint8_t float_flags, float_shift, float_max_exp, max_exp;
    int32_t shifted_ones, shifted_zeros, shifted_both;
    int32_t false_zeros, neg_zeros, ordata;

    int num_terms, shift, joint_stereo, false_stereo;
    int num_decorrs, num_passes, best_decorr, mask_decorr;
    struct Decorr decorr_passes[MAX_TERMS];
    const WavPackDecorrSpec *decorr_specs;
    float delta_decay;
} WavPackEncodeContext;
#define FLOAT_SHIFT_ONES 1
#define FLOAT_SHIFT_SAME 2
#define FLOAT_SHIFT_SENT 4
#define FLOAT_ZEROS_SENT 8
#define FLOAT_NEG_ZEROS  0x10
#define FLOAT_EXCEPTIONS 0x20
#define get_mantissa(f)     ((f) & 0x7fffff)
#define get_exponent(f)     (((f) >> 23) & 0xff)
#define get_sign(f)         (((f) >> 31) & 0x1)
#define count_bits(av) ((av) ? 32 - ff_clz(av) : 0)
#define update_weight_d2(weight, delta, source, result) \
#define update_weight_clip_d2(weight, delta, source, result) \
#define WRITE_DECWEIGHT(type) do {            \
#define WRITE_DECSAMPLE(type) do {        \
#define WRITE_CHAN_ENTROPY(chan) do {               \
#define COPY_SAMPLES(type, offset, shift) do {            \
#define OFFSET(x) offsetof(WavPackEncodeContext, x)
#define FLAGS AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM
