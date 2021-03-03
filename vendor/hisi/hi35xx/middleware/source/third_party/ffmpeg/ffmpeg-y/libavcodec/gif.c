#define BITSTREAM_WRITER_LE
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "lzw.h"
#include "gif.h"
#include "put_bits.h"
#define DEFAULT_TRANSPARENCY_INDEX 0x1f
typedef struct GIFContext {
    const AVClass *class;
    LZWState *lzw;
    uint8_t *buf;
    int buf_size;
    AVFrame *last_frame;
    int flags;
    int image;
    uint32_t palette[AVPALETTE_COUNT];  ///< local reference palette for !pal8
    int palette_loaded;
    int transparent_index;
    uint8_t *tmpl;                      ///< temporary line buffer
} GIFContext;
#define OFFSET(x) offsetof(GIFContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
