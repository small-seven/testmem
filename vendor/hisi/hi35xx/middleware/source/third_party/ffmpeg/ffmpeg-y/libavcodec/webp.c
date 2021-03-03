#include "libavutil/imgutils.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "exif.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "vp8.h"
#define VP8X_FLAG_ANIMATION             0x02
#define VP8X_FLAG_XMP_METADATA          0x04
#define VP8X_FLAG_EXIF_METADATA         0x08
#define VP8X_FLAG_ALPHA                 0x10
#define VP8X_FLAG_ICC                   0x20
#define MAX_PALETTE_SIZE                256
#define MAX_CACHE_BITS                  11
#define NUM_CODE_LENGTH_CODES           19
#define HUFFMAN_CODES_PER_META_CODE     5
#define NUM_LITERAL_CODES               256
#define NUM_LENGTH_CODES                24
#define NUM_DISTANCE_CODES              40
#define NUM_SHORT_DISTANCES             120
#define MAX_HUFFMAN_CODE_LENGTH         15
typedef struct HuffReader {
    VLC vlc;                            /* Huffman decoder context */
    int simple;                         /* whether to use simple mode */
    int nb_symbols;                     /* number of coded symbols */
    uint16_t simple_symbols[2];         /* symbols for simple mode */
} HuffReader;
typedef struct ImageContext {
    enum ImageRole role;                /* role of this image */
    AVFrame *frame;                     /* AVFrame for data */
    int color_cache_bits;               /* color cache size, log2 */
    uint32_t *color_cache;              /* color cache data */
    int nb_huffman_groups;              /* number of huffman groups */
    HuffReader *huffman_groups;         /* reader for each huffman group */
    int size_reduction;                 /* relative size compared to primary image, log2 */
    int is_alpha_primary;
} ImageContext;
typedef struct WebPContext {
    VP8Context v;                       /* VP8 Context used for lossy decoding */
    GetBitContext gb;                   /* bitstream reader for main image chunk */
    AVFrame *alpha_frame;               /* AVFrame for alpha data decompressed from VP8L */
    AVCodecContext *avctx;              /* parent AVCodecContext */
    int initialized;                    /* set once the VP8 context is initialized */
    int has_alpha;                      /* has a separate alpha chunk */
    enum AlphaCompression alpha_compression; /* compression type for alpha chunk */
    enum AlphaFilter alpha_filter;      /* filtering method for alpha chunk */
    uint8_t *alpha_data;                /* alpha chunk data */
    int alpha_data_size;                /* alpha chunk data size */
    int has_exif;                       /* set after an EXIF chunk has been processed */
    int has_iccp;                       /* set after an ICCP chunk has been processed */
    int width;                          /* image width */
    int height;                         /* image height */
    int lossless;                       /* indicates lossless or lossy */

    int nb_transforms;                  /* number of transforms */
    enum TransformType transforms[4];   /* transformations used in the image, in order */
    int reduced_width;                  /* reduced width for index image, if applicable */
    int nb_huffman_groups;              /* number of huffman groups in the primary image */
    ImageContext image[IMAGE_ROLE_NB];  /* image context for each role */
} WebPContext;
#define GET_PIXEL(frame, x, y) \
#define GET_PIXEL_COMP(frame, x, y, c) \
static void image_ctx_free(ImageContext *img)
{
    int i, j;

    av_free(img->color_cache);
    if (img->role != IMAGE_ROLE_ARGB && !img->is_alpha_primary)
        av_frame_free(&img->frame);
    if (img->huffman_groups) {
        for (i = 0; i < img->nb_huffman_groups; i++) {
            for (j = 0; j < HUFFMAN_CODES_PER_META_CODE; j++)
                ff_free_vlc(&img->huffman_groups[i * HUFFMAN_CODES_PER_META_CODE + j].vlc);
        }
        av_free(img->huffman_groups);
    }
    memset(img, 0, sizeof(*img));
}
#define PARSE_BLOCK_SIZE(w, h) do {                                         \
typedef void (*inv_predict_func)(uint8_t *p, const uint8_t *p_l,
                                 const uint8_t *p_tl, const uint8_t *p_t,
                                 const uint8_t *p_tr);

static const inv_predict_func inverse_predict[14] = {
    inv_predict_0,  inv_predict_1,  inv_predict_2,  inv_predict_3,
    inv_predict_4,  inv_predict_5,  inv_predict_6,  inv_predict_7,
    inv_predict_8,  inv_predict_9,  inv_predict_10, inv_predict_11,
    inv_predict_12, inv_predict_13,
};
