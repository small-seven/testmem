#include "libavutil/avassert.h"
#include "libavutil/crc.h"
#include "libavutil/intmath.h"
#include "libavutil/md5.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "put_bits.h"
#include "golomb.h"
#include "internal.h"
#include "lpc.h"
#include "flac.h"
#include "flacdata.h"
#include "flacdsp.h"
#define FLAC_SUBFRAME_CONSTANT  0
#define FLAC_SUBFRAME_VERBATIM  1
#define FLAC_SUBFRAME_FIXED     8
#define FLAC_SUBFRAME_LPC      32
#define MAX_FIXED_ORDER     4
#define MAX_PARTITION_ORDER 8
#define MAX_PARTITIONS     (1 << MAX_PARTITION_ORDER)
#define MAX_LPC_PRECISION  15
#define MIN_LPC_SHIFT       0
#define MAX_LPC_SHIFT      15
typedef struct CompressionOptions {
    int compression_level;
    int block_time_ms;
    enum FFLPCType lpc_type;
    int lpc_passes;
    int lpc_coeff_precision;
    int min_prediction_order;
    int max_prediction_order;
    int prediction_order_method;
    int min_partition_order;
    int max_partition_order;
    int ch_mode;
    int exact_rice_parameters;
    int multi_dim_quant;
} CompressionOptions;
typedef struct RiceContext {
    enum CodingMode coding_mode;
    int porder;
    int params[MAX_PARTITIONS];
} RiceContext;
typedef struct FlacSubframe {
    int type;
    int type_code;
    int obits;
    int wasted;
    int order;
    int32_t coefs[MAX_LPC_ORDER];
    int shift;

    RiceContext rc;
    uint32_t rc_udata[FLAC_MAX_BLOCKSIZE];
    uint64_t rc_sums[32][MAX_PARTITIONS];

    int32_t samples[FLAC_MAX_BLOCKSIZE];
    int32_t residual[FLAC_MAX_BLOCKSIZE+11];
} FlacSubframe;
typedef struct FlacFrame {
    FlacSubframe subframes[FLAC_MAX_CHANNELS];
    int blocksize;
    int bs_code[2];
    uint8_t crc8;
    int ch_mode;
    int verbatim_only;
} FlacFrame;
typedef struct FlacEncodeContext {
    AVClass *class;
    PutBitContext pb;
    int channels;
    int samplerate;
    int sr_code[2];
    int bps_code;
    int max_blocksize;
    int min_framesize;
    int max_framesize;
    int max_encoded_framesize;
    uint32_t frame_count;
    uint64_t sample_count;
    uint8_t md5sum[16];
    FlacFrame frame;
    CompressionOptions options;
    AVCodecContext *avctx;
    LPCContext lpc_ctx;
    struct AVMD5 *md5ctx;
    uint8_t *md5_buffer;
    unsigned int md5_buffer_size;
    BswapDSPContext bdsp;
    FLACDSPContext flac_dsp;

    int flushed;
    int64_t next_pts;
} FlacEncodeContext;
#if FF_API_PRIVATE_OPT
#endif
#define COPY_SAMPLES(bits) do {                                     \
#define rice_encode_count(sum, n, k) (((n)*((k)+1))+((sum-(n>>1))>>(k)))
#if HAVE_BIGENDIAN
#endif
#if FF_API_SIDEDATA_ONLY_PKT
#else
#endif
#define FLAGS AV_OPT_FLAG_ENCODING_PARAM | AV_OPT_FLAG_AUDIO_PARAM
