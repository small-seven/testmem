#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
#include "mathops.h"
#include "clearvideodata.h"
typedef struct LevelCodes {
    uint16_t    mv_esc;
    uint16_t    bias_esc;
    VLC         flags_cb;
    VLC         mv_cb;
    VLC         bias_cb;
} LevelCodes;
typedef struct MV {
    int16_t x, y;
} MV;
typedef struct MVInfo {
    int mb_w;
    int mb_h;
    int mb_size;
    int mb_stride;
    int top;
    MV  *mv;
} MVInfo;
typedef struct TileInfo {
    uint16_t        flags;
    int16_t         bias;
    MV              mv;
    struct TileInfo *child[4];
} TileInfo;
typedef struct CLVContext {
    AVCodecContext *avctx;
    IDCTDSPContext idsp;
    AVFrame        *pic;
    AVFrame        *prev;
    GetBitContext  gb;
    int            mb_width, mb_height;
    int            pmb_width, pmb_height;
    MVInfo         mvi;
    int            tile_size;
    int            tile_shift;
    VLC            dc_vlc, ac_vlc;
    LevelCodes     ylev[4], ulev[3], vlev[3];
    int            luma_dc_quant, chroma_dc_quant, ac_quant;
    DECLARE_ALIGNED(16, int16_t, block)[64];
    int            top_dc[3], left_dc[4];
} CLVContext;
#define DCT_TEMPLATE(blk, step, bias, shift, dshift, OP)                \
#define ROP(x) x
#define COP(x) (((x) + 4) >> 3)
