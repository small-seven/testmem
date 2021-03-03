#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "dirac.h"
#include "put_bits.h"
#include "internal.h"
#include "version.h"
#include "vc2enc_dwt.h"
#include "diractab.h"
#define SSIZE_ROUND(b) (FFALIGN((b), s->size_scaler) + 4 + s->prefix_bytes)
#define SLICE_REDIST_TOTAL 150
typedef struct VC2BaseVideoFormat {
    enum AVPixelFormat pix_fmt;
    AVRational time_base;
    int width, height, interlaced, level;
    const char *name;
} VC2BaseVideoFormat;
typedef struct SubBand {
    dwtcoef *buf;
    ptrdiff_t stride;
    int width;
    int height;
} SubBand;
typedef struct Plane {
    SubBand band[MAX_DWT_LEVELS][4];
    dwtcoef *coef_buf;
    int width;
    int height;
    int dwt_width;
    int dwt_height;
    ptrdiff_t coef_stride;
} Plane;
typedef struct SliceArgs {
    PutBitContext pb;
    int cache[DIRAC_MAX_QUANT_INDEX];
    void *ctx;
    int x;
    int y;
    int quant_idx;
    int bits_ceil;
    int bits_floor;
    int bytes;
} SliceArgs;
typedef struct TransformArgs {
    void *ctx;
    Plane *plane;
    void *idata;
    ptrdiff_t istride;
    int field;
    VC2TransformContext t;
} TransformArgs;
typedef struct VC2EncContext {
    AVClass *av_class;
    PutBitContext pb;
    Plane plane[3];
    AVCodecContext *avctx;
    DiracVersionInfo ver;

    SliceArgs *slice_args;
    TransformArgs transform_args[3];

    /* For conversion from unsigned pixel values to signed */
    int diff_offset;
    int bpp;
    int bpp_idx;

    /* Picture number */
    uint32_t picture_number;

    /* Base video format */
    int base_vf;
    int level;
    int profile;

    /* Quantization matrix */
    uint8_t quant[MAX_DWT_LEVELS][4];
    int custom_quant_matrix;

    /* Division LUT */
    uint32_t qmagic_lut[116][2];

    int num_x; /* #slices horizontally */
    int num_y; /* #slices vertically */
    int prefix_bytes;
    int size_scaler;
    int chroma_x_shift;
    int chroma_y_shift;

    /* Rate control stuff */
    int frame_max_bytes;
    int slice_max_bytes;
    int slice_min_bytes;
    int q_ceil;
    int q_avg;

    /* Options */
    double tolerance;
    int wavelet_idx;
    int wavelet_depth;
    int strict_compliance;
    int slice_height;
    int slice_width;
    int interlaced;
    enum VC2_QM quant_matrix;

    /* Parse code state */
    uint32_t next_parse_offset;
    enum DiracParseCodes last_parse_code;
} VC2EncContext;
#define QUANT(c, mul, add, shift) (((mul) * (c) + (add)) >> (shift))
#define VC2ENC_FLAGS (AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
