#include <float.h>
#include <zlib.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intfloat.h"
#include "libavutil/opt.h"
#include "libavutil/color_utils.h"
#include "avcodec.h"
#include "bytestream.h"
#if HAVE_BIGENDIAN
#include "bswapdsp.h"
#endif
#include "exrdsp.h"
#include "get_bits.h"
#include "internal.h"
#include "mathops.h"
#include "thread.h"
typedef struct EXRChannel {
    int xsub, ysub;
    enum ExrPixelType pixel_type;
} EXRChannel;
typedef struct EXRTileAttribute {
    int32_t xSize;
    int32_t ySize;
    enum ExrTileLevelMode level_mode;
    enum ExrTileLevelRound level_round;
} EXRTileAttribute;
typedef struct EXRThreadData {
    uint8_t *uncompressed_data;
    int uncompressed_size;

    uint8_t *tmp;
    int tmp_size;

    uint8_t *bitmap;
    uint16_t *lut;

    int ysize, xsize;

    int channel_line_size;
} EXRThreadData;
typedef struct EXRContext {
    AVClass *class;
    AVFrame *picture;
    AVCodecContext *avctx;
    ExrDSPContext dsp;

#if HAVE_BIGENDIAN
    BswapDSPContext bbdsp;
#endif

    enum ExrCompr compression;
    enum ExrPixelType pixel_type;
    int channel_offsets[4]; // 0 = red, 1 = green, 2 = blue and 3 = alpha
    const AVPixFmtDescriptor *desc;

    int w, h;
    uint32_t xmax, xmin;
    uint32_t ymax, ymin;
    uint32_t xdelta, ydelta;

    int scan_lines_per_block;

    EXRTileAttribute tile_attr; /* header data attribute of tile */
    int is_tile; /* 0 if scanline, 1 if tile */

    int is_luma;/* 1 if there is an Y plane */

    GetByteContext gb;
    const uint8_t *buf;
    int buf_size;

    EXRChannel *channels;
    int nb_channels;
    int current_channel_offset;

    EXRThreadData *thread_data;

    const char *layer;

    enum AVColorTransferCharacteristic apply_trc_type;
    float gamma;
    uint16_t gamma_table[65536];
} EXRContext;
#define HALF_FLOAT_MIN_BIASED_EXP_AS_SINGLE_FP_EXP 0x38000000
#define HALF_FLOAT_MAX_BIASED_EXP_AS_SINGLE_FP_EXP 0x47800000
#define FLOAT_MAX_BIASED_EXP (0xFF << 23)
#define HALF_FLOAT_MAX_BIASED_EXP (0x1F << 10)
#define USHORT_RANGE (1 << 16)
#define BITMAP_SIZE  (1 << 13)
#define HUF_ENCBITS 16  // literal (value) bit length
#define HUF_DECBITS 14  // decoding bit size (>= 8)
#define HUF_ENCSIZE ((1 << HUF_ENCBITS) + 1)  // encoding table size
#define HUF_DECSIZE (1 << HUF_DECBITS)        // decoding table size
#define HUF_DECMASK (HUF_DECSIZE - 1)
typedef struct HufDec {
    int len;
    int lit;
    int *p;
} HufDec;
#define SHORT_ZEROCODE_RUN  59
#define LONG_ZEROCODE_RUN   63
#define SHORTEST_LONG_RUN   (2 + LONG_ZEROCODE_RUN - SHORT_ZEROCODE_RUN)
#define LONGEST_LONG_RUN    (255 + SHORTEST_LONG_RUN)
#define get_char(c, lc, gb)                                                   \
#define get_code(po, rlc, c, lc, gb, out, oe, outb)                           \
#define NBITS      16
#define A_OFFSET  (1 << (NBITS - 1))
#define MOD_MASK  ((1 << NBITS) - 1)
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#endif
#if HAVE_THREADS
#endif
#define OFFSET(x) offsetof(EXRContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
