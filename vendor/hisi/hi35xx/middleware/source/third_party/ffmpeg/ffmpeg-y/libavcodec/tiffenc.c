#include "config.h"
#if CONFIG_ZLIB
#include <zlib.h>
#endif
#include "libavutil/imgutils.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "lzw.h"
#include "put_bits.h"
#include "rle.h"
#include "tiff.h"
#define TIFF_MAX_ENTRY 32
typedef struct TiffEncoderContext {
    AVClass *class;                         ///< for private options
    AVCodecContext *avctx;

    int width;                              ///< picture width
    int height;                             ///< picture height
    unsigned int bpp;                       ///< bits per pixel
    int compr;                              ///< compression level
    int bpp_tab_size;                       ///< bpp_tab size
    enum TiffPhotometric photometric_interpretation;  ///< photometric interpretation
    int strips;                             ///< number of strips
    uint32_t *strip_sizes;
    unsigned int strip_sizes_size;
    uint32_t *strip_offsets;
    unsigned int strip_offsets_size;
    uint8_t *yuv_line;
    unsigned int yuv_line_size;
    int rps;                                ///< row per strip
    uint8_t entries[TIFF_MAX_ENTRY * 12];   ///< entries in header
    int num_entries;                        ///< number of entries
    uint8_t **buf;                          ///< actual position in buffer
    uint8_t *buf_start;                     ///< pointer to first byte in buffer
    int buf_size;                           ///< buffer size
    uint16_t subsampling[2];                ///< YUV subsampling factors
    struct LZWEncodeState *lzws;            ///< LZW encode state
    uint32_t dpi;                           ///< image resolution in DPI
} TiffEncoderContext;
#if HAVE_BIGENDIAN
#endif
#if CONFIG_ZLIB
#endif
#define ADD_ENTRY(s, tag, type, count, ptr_val)         \
#define ADD_ENTRY1(s, tag, type, val)           \
#if CONFIG_ZLIB
#endif
#if !CONFIG_ZLIB
#endif
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(TiffEncoderContext, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
