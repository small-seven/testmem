#include "libavutil/pixdesc.h"
#include "libavutil/thread.h"
#include "avcodec.h"
#include "get_bits.h"
#include "bytestream.h"
#include "internal.h"
#include "golomb.h"
#include "dirac_arith.h"
#include "dirac_vlc.h"
#include "mpeg12data.h"
#include "libavcodec/mpegvideo.h"
#include "mpegvideoencdsp.h"
#include "dirac_dwt.h"
#include "dirac.h"
#include "diractab.h"
#include "diracdsp.h"
#include "videodsp.h"
#define MAX_REFERENCE_FRAMES 8
#define MAX_DELAY 5         /* limit for main profile for frame coding (TODO: field coding) */
#define MAX_FRAMES (MAX_REFERENCE_FRAMES + MAX_DELAY + 1)
#define MAX_QUANT 255        /* max quant for VC-2 */
#define MAX_BLOCKSIZE 32    /* maximum xblen/yblen we support */
#define DIRAC_REF_MASK_REF1   1
#define DIRAC_REF_MASK_REF2   2
#define DIRAC_REF_MASK_GLOBAL 4
#define DELAYED_PIC_REF 4
#define CALC_PADDING(size, depth)                       \
#define DIVRNDUP(a, b) (((a) + (b) - 1) / (b))
typedef struct {
    AVFrame *avframe;
    int interpolated[3];    /* 1 if hpel[] is valid */
    uint8_t *hpel[3][4];
    uint8_t *hpel_base[3][4];
    int reference;
} DiracFrame;
typedef struct {
    union {
        int16_t mv[2][2];
        int16_t dc[3];
    } u; /* anonymous unions aren't in C99 :( */
typedef struct SubBand {
    int level;
    int orientation;
    int stride; /* in bytes */
    int width;
    int height;
    int pshift;
    int quant;
    uint8_t *ibuf;
    struct SubBand *parent;

    /* for low delay */
    unsigned length;
    const uint8_t *coeff_data;
} SubBand;
typedef struct Plane {
    DWTPlane idwt;

    int width;
    int height;
    ptrdiff_t stride;

    /* block length */
    uint8_t xblen;
    uint8_t yblen;
    /* block separation (block n+1 starts after this many pixels in block n) */
    uint8_t xbsep;
    uint8_t ybsep;
    /* amount of overspill on each edge (half of the overlap between blocks) */
    uint8_t xoffset;
    uint8_t yoffset;

    SubBand band[MAX_DWT_LEVELS][4];
} Plane;
typedef struct DiracSlice {
    GetBitContext gb;
    int slice_x;
    int slice_y;
    int bytes;
} DiracSlice;
typedef struct DiracContext {
    AVCodecContext *avctx;
    MpegvideoEncDSPContext mpvencdsp;
    VideoDSPContext vdsp;
    DiracDSPContext diracdsp;
    DiracGolombLUT *reader_ctx;
    DiracVersionInfo version;
    GetBitContext gb;
    AVDiracSeqHeader seq;
    int seen_sequence_header;
    int64_t frame_number;       /* number of the next frame to display       */
    Plane plane[3];
    int chroma_x_shift;
    int chroma_y_shift;

    int bit_depth;              /* bit depth                                 */
    int pshift;                 /* pixel shift = bit_depth > 8               */

    int zero_res;               /* zero residue flag                         */
    int is_arith;               /* whether coeffs use arith or golomb coding */
    int core_syntax;            /* use core syntax only                      */
    int low_delay;              /* use the low delay syntax                  */
    int hq_picture;             /* high quality picture, enables low_delay   */
    int ld_picture;             /* use low delay picture, turns on low_delay */
    int dc_prediction;          /* has dc prediction                         */
    int globalmc_flag;          /* use global motion compensation            */
    int num_refs;               /* number of reference pictures              */

    /* wavelet decoding */
    unsigned wavelet_depth;     /* depth of the IDWT                         */
    unsigned wavelet_idx;

    /**
     * schroedinger older than 1.0.8 doesn't store
     * quant delta if only one codebook exists in a band
     */
    unsigned old_delta_quant;
    unsigned codeblock_mode;

    unsigned num_x;              /* number of horizontal slices               */
    unsigned num_y;              /* number of vertical slices                 */

    uint8_t *thread_buf;         /* Per-thread buffer for coefficient storage */
    int threads_num_buf;         /* Current # of buffers allocated            */
    int thread_buf_size;         /* Each thread has a buffer this size        */

    DiracSlice *slice_params_buf;
    int slice_params_num_buf;

    struct {
        unsigned width;
        unsigned height;
    } codeblock[MAX_DWT_LEVELS+1];
#define SIGN_CTX(x) (CTX_SIGN_ZERO + ((x) > 0) - ((x) < 0))
#define UNPACK_ARITH(n, type) \
#define INTRA_DC_PRED(n, type) \
#define PARSE_VALUES(type, x, gb, ebits, buf1, buf2) \
typedef struct SliceCoeffs {
    int left;
    int top;
    int tot_h;
    int tot_v;
    int tot;
} SliceCoeffs;
#define CHECKEDREAD(dst, cond, errmsg) \
#define ROLLOFF(i) offset == 1 ? ((i) ? 5 : 3) :        \
#define DATA_UNIT_HEADER_SIZE 13
