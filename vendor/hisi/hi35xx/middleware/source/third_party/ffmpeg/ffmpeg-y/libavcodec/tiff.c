#include "config.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#if CONFIG_LZMA
#define LZMA_API_STATIC
#include <lzma.h>
#endif
#include "libavutil/attributes.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "faxcompr.h"
#include "internal.h"
#include "lzw.h"
#include "mathops.h"
#include "tiff.h"
#include "tiff_data.h"
#include "thread.h"
#include "get_bits.h"
typedef struct TiffContext {
    AVClass *class;
    AVCodecContext *avctx;
    GetByteContext gb;

    int get_subimage;
    uint16_t get_page;
    int get_thumbnail;

    enum TiffType tiff_type;
    int width, height;
    unsigned int bpp, bppcount;
    uint32_t palette[256];
    int palette_is_set;
    int le;
    enum TiffCompr compr;
    enum TiffPhotometric photometric;
    int planar;
    int subsampling[2];
    int fax_opts;
    int predictor;
    int fill_order;
    uint32_t res[4];
    int is_thumbnail;

    int is_bayer;
    uint8_t pattern[4];
    unsigned white_level;

    uint32_t sub_ifd;
    uint16_t cur_page;

    int strips, rps, sstype;
    int sot;
    int stripsizesoff, stripsize, stripoff, strippos;
    LZWState *lzw;

    uint8_t *deinvert_buf;
    int deinvert_buf_size;
    uint8_t *yuv_line;
    unsigned int yuv_line_size;
    uint8_t *fax_buffer;
    unsigned int fax_buffer_size;

    int geotag_count;
    TiffGeoTag *geotags;
} TiffContext;
#define RET_GEOKEY(TYPE, array, element)\
#define RET_GEOKEY_VAL(TYPE, array)\
#if CONFIG_ZLIB
#endif
#if CONFIG_LZMA
#endif
#if CONFIG_ZLIB
#else
#endif
#if CONFIG_LZMA
#else
#endif
#if CONFIG_ZLIB
#else
#endif
#if CONFIG_LZMA
#else
#endif
#define ADD_METADATA(count, name, sep)\
#define OFFSET(x) offsetof(TiffContext, x)
