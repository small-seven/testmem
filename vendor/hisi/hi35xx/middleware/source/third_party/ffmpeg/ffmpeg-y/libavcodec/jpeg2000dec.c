#include <inttypes.h>
#include <math.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/thread.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "thread.h"
#include "jpeg2000.h"
#include "jpeg2000dsp.h"
#include "profiles.h"
#define JP2_SIG_TYPE    0x6A502020
#define JP2_SIG_VALUE   0x0D0A870A
#define JP2_CODESTREAM  0x6A703263
#define JP2_HEADER      0x6A703268
#define HAD_COC 0x01
#define HAD_QCC 0x02
#define MAX_POCS 32
typedef struct Jpeg2000POCEntry {
    uint16_t LYEpoc;
    uint16_t CSpoc;
    uint16_t CEpoc;
    uint8_t RSpoc;
    uint8_t REpoc;
    uint8_t Ppoc;
} Jpeg2000POCEntry;
typedef struct Jpeg2000POC {
    Jpeg2000POCEntry poc[MAX_POCS];
    int nb_poc;
    int is_default;
} Jpeg2000POC;
typedef struct Jpeg2000TilePart {
    uint8_t tile_index;                 // Tile index who refers the tile-part
    const uint8_t *tp_end;
    GetByteContext tpg;                 // bit stream in tile-part
} Jpeg2000TilePart;
typedef struct Jpeg2000Tile {
    Jpeg2000Component   *comp;
    uint8_t             properties[4];
    Jpeg2000CodingStyle codsty[4];
    Jpeg2000QuantStyle  qntsty[4];
    Jpeg2000POC         poc;
    Jpeg2000TilePart    tile_part[32];
    uint16_t tp_idx;                    // Tile-part index
    int coord[2][2];                    // border coordinates {{x0, x1}, {y0, y1}}
typedef struct Jpeg2000DecoderContext {
    AVClass         *class;
    AVCodecContext  *avctx;
    GetByteContext  g;

    int             width, height;
    int             image_offset_x, image_offset_y;
    int             tile_offset_x, tile_offset_y;
    uint8_t         cbps[4];    // bits per sample in particular components
    uint8_t         sgnd[4];    // if a component is signed
    uint8_t         properties[4];
    int             cdx[4], cdy[4];
    int             precision;
    int             ncomponents;
    int             colour_space;
    uint32_t        palette[256];
    int8_t          pal8;
    int             cdef[4];
    int             tile_width, tile_height;
    unsigned        numXtiles, numYtiles;
    int             maxtilelen;
    AVRational      sar;

    Jpeg2000CodingStyle codsty[4];
    Jpeg2000QuantStyle  qntsty[4];
    Jpeg2000POC         poc;

    int             bit_index;

    int             curtileno;

    Jpeg2000Tile    *tile;
    Jpeg2000DSPContext dsp;

    /*options parameters*/
    int             reduction_factor;
} Jpeg2000DecoderContext;
#define RGB_PIXEL_FORMATS   AV_PIX_FMT_PAL8,AV_PIX_FMT_RGB24,AV_PIX_FMT_RGBA,AV_PIX_FMT_RGB48,AV_PIX_FMT_RGBA64
#define GRAY_PIXEL_FORMATS  AV_PIX_FMT_GRAY8,AV_PIX_FMT_GRAY8A,AV_PIX_FMT_GRAY16,AV_PIX_FMT_YA16
#define YUV_PIXEL_FORMATS   AV_PIX_FMT_YUV410P,AV_PIX_FMT_YUV411P,AV_PIX_FMT_YUVA420P, \
#define XYZ_PIXEL_FORMATS   AV_PIX_FMT_XYZ12
#define WRITE_FRAME(D, PIXEL)                                                                     \
#undef WRITE_FRAME
#define OFFSET(x) offsetof(Jpeg2000DecoderContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
