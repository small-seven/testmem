#include <float.h>
#include "avcodec.h"
#include "internal.h"
#include "bytestream.h"
#include "jpeg2000.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "libavutil/intreadwrite.h"
#define NMSEDEC_BITS 7
#define NMSEDEC_FRACBITS (NMSEDEC_BITS-1)
#define WMSEDEC_SHIFT 13 ///< must be >= 13
#define LAMBDA_SCALE (100000000LL << (WMSEDEC_SHIFT - 13))
#define CODEC_JP2 1
#define CODEC_J2K 0
typedef struct {
   Jpeg2000Component *comp;
} Jpeg2000Tile;
typedef struct {
    AVClass *class;
    AVCodecContext *avctx;
    const AVFrame *picture;

    int width, height; ///< image width and height
    uint8_t cbps[4]; ///< bits per sample in particular components
    int chroma_shift[2];
    uint8_t planar;
    int ncomponents;
    int tile_width, tile_height; ///< tile size
    int numXtiles, numYtiles;

    uint8_t *buf_start;
    uint8_t *buf;
    uint8_t *buf_end;
    int bit_index;

    int64_t lambda;

    Jpeg2000CodingStyle codsty;
    Jpeg2000QuantStyle  qntsty;

    Jpeg2000Tile *tile;

    int format;
    int pred;
} Jpeg2000EncoderContext;
#if 0
#undef ifprintf
#undef printf
#endif
#if FF_API_PRIVATE_OPT
#endif
static int j2kenc_destroy(AVCodecContext *avctx)
{
    Jpeg2000EncoderContext *s = avctx->priv_data;

    cleanup(s);
    return 0;
}
#define OFFSET(x) offsetof(Jpeg2000EncoderContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
