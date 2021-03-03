#include <inttypes.h>
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/opt.h"
#include "lossless_audiodsp.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "internal.h"
#include "get_bits.h"
#include "unary.h"
#define MAX_CHANNELS        2
#define MAX_BYTESPERSAMPLE  3
#define APE_FRAMECODE_MONO_SILENCE    1
#define APE_FRAMECODE_STEREO_SILENCE  3
#define APE_FRAMECODE_PSEUDO_STEREO   4
#define HISTORY_SIZE 512
#define PREDICTOR_ORDER 8
#define PREDICTOR_SIZE 50
#define YDELAYA (18 + PREDICTOR_ORDER*4)
#define YDELAYB (18 + PREDICTOR_ORDER*3)
#define XDELAYA (18 + PREDICTOR_ORDER*2)
#define XDELAYB (18 + PREDICTOR_ORDER)
#define YADAPTCOEFFSA 18
#define XADAPTCOEFFSA 14
#define YADAPTCOEFFSB 10
#define XADAPTCOEFFSB 5
#define APE_FILTER_LEVELS 3
typedef struct APEFilter {
    int16_t *coeffs;        ///< actual coefficients used in filtering
    int16_t *adaptcoeffs;   ///< adaptive filter coefficients used for correcting of actual filter coefficients
    int16_t *historybuffer; ///< filter memory
    int16_t *delay;         ///< filtered values

    int avg;
} APEFilter;
typedef struct APERice {
    uint32_t k;
    uint32_t ksum;
} APERice;
typedef struct APERangecoder {
    uint32_t low;           ///< low end of interval
    uint32_t range;         ///< length of interval
    uint32_t help;          ///< bytes_to_follow resp. intermediate value
    unsigned int buffer;    ///< buffer for input/output
} APERangecoder;
typedef struct APEPredictor {
    int32_t *buf;

    int32_t lastA[2];

    int32_t filterA[2];
    int32_t filterB[2];

    int32_t coeffsA[2][4];  ///< adaption coefficients
    int32_t coeffsB[2][5];  ///< adaption coefficients
    int32_t historybuffer[HISTORY_SIZE + PREDICTOR_SIZE];

    unsigned int sample_pos;
} APEPredictor;
typedef struct APEContext {
    AVClass *class;                          ///< class for AVOptions
    AVCodecContext *avctx;
    BswapDSPContext bdsp;
    LLAudDSPContext adsp;
    int channels;
    int samples;                             ///< samples left to decode in current frame
    int bps;

    int fileversion;                         ///< codec version, very important in decoding process
    int compression_level;                   ///< compression levels
    int fset;                                ///< which filter set to use (calculated from compression level)
    int flags;                               ///< global decoder flags

    uint32_t CRC;                            ///< frame CRC
    int frameflags;                          ///< frame flags
    APEPredictor predictor;                  ///< predictor used for final reconstruction

    int32_t *decoded_buffer;
    int decoded_size;
    int32_t *decoded[MAX_CHANNELS];          ///< decoded data for each channel
    int blocks_per_loop;                     ///< maximum number of samples to decode for each call

    int16_t* filterbuf[APE_FILTER_LEVELS];   ///< filter memory

    APERangecoder rc;                        ///< rangecoder used to decode actual values
    APERice riceX;                           ///< rice code parameters for the second channel
    APERice riceY;                           ///< rice code parameters for the first channel
    APEFilter filters[APE_FILTER_LEVELS][2]; ///< filters used for reconstruction
    GetBitContext gb;

    uint8_t *data;                           ///< current frame data
    uint8_t *data_end;                       ///< frame data end
    int data_size;                           ///< frame data allocated size
    const uint8_t *ptr;                      ///< current position in frame data

    int error;

    void (*entropy_decode_mono)(struct APEContext *ctx, int blockstodecode);
    void (*entropy_decode_stereo)(struct APEContext *ctx, int blockstodecode);
    void (*predictor_decode_mono)(struct APEContext *ctx, int count);
    void (*predictor_decode_stereo)(struct APEContext *ctx, int count);
} APEContext;
#define CODE_BITS    32
#define TOP_VALUE    ((unsigned int)1 << (CODE_BITS-1))
#define SHIFT_BITS   (CODE_BITS - 9)
#define EXTRA_BITS   ((CODE_BITS-2) % 8 + 1)
#define BOTTOM_VALUE (TOP_VALUE >> 8)
#define MODEL_ELEMENTS 64
#define OFFSET(x) offsetof(APEContext, x)
#define PAR (AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM)
