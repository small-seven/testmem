#include <inttypes.h>
#include <zlib.h>
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "bytestream.h"
#include "elsdec.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
#include "jpegtables.h"
#include "mjpeg.h"
#define EPIC_PIX_STACK_SIZE 1024
#define EPIC_PIX_STACK_MAX  (EPIC_PIX_STACK_SIZE - 1)
typedef struct ePICPixListElem {
    struct ePICPixListElem *next;
    uint32_t               pixel;
    uint8_t                rung;
} ePICPixListElem;
typedef struct ePICPixHashElem {
    uint32_t                pix_id;
    struct ePICPixListElem  *list;
} ePICPixHashElem;
#define EPIC_HASH_SIZE 256
typedef struct ePICPixHash {
    ePICPixHashElem *bucket[EPIC_HASH_SIZE];
    int              bucket_size[EPIC_HASH_SIZE];
    int              bucket_fill[EPIC_HASH_SIZE];
} ePICPixHash;
typedef struct ePICContext {
    ElsDecCtx        els_ctx;
    int              next_run_pos;
    ElsUnsignedRung  unsigned_rung;
    uint8_t          W_flag_rung;
    uint8_t          N_flag_rung;
    uint8_t          W_ctx_rung[256];
    uint8_t          N_ctx_rung[512];
    uint8_t          nw_pred_rung[256];
    uint8_t          ne_pred_rung[256];
    uint8_t          prev_row_rung[14];
    uint8_t          runlen_zeroes[14];
    uint8_t          runlen_one;
    int              stack_pos;
    uint32_t         stack[EPIC_PIX_STACK_SIZE];
    ePICPixHash      hash;
} ePICContext;
typedef struct JPGContext {
    BlockDSPContext bdsp;
    IDCTDSPContext idsp;
    ScanTable  scantable;

    VLC        dc_vlc[2], ac_vlc[2];
    int        prev_dc[3];
    DECLARE_ALIGNED(32, int16_t, block)[6][64];

    uint8_t    *buf;
} JPGContext;
typedef struct G2MContext {
    ePICContext ec;
    JPGContext jc;

    int        version;

    int        compression;
    int        width, height, bpp;
    int        orig_width, orig_height;
    int        tile_width, tile_height;
    int        tiles_x, tiles_y, tile_x, tile_y;

    int        got_header;

    uint8_t    *framebuf;
    int        framebuf_stride, old_width, old_height;

    uint8_t    *synth_tile, *jpeg_tile, *epic_buf, *epic_buf_base;
    int        tile_stride, epic_buf_stride, old_tile_w, old_tile_h;
    int        swapuv;

    uint8_t    *kempf_buf, *kempf_flags;

    uint8_t    *cursor;
    int        cursor_stride;
    int        cursor_fmt;
    int        cursor_w, cursor_h, cursor_x, cursor_y;
    int        cursor_hot_x, cursor_hot_y;
} G2MContext;
#define LOAD_NEIGHBOURS(x)      \
#define UPDATE_NEIGHBOURS(x)    \
#define R_shift 16
#define G_shift  8
#define B_shift  0
#define TOSIGNED(val) (((val) >> 1) ^ -((val) & 1))
#define APPLY_ALPHA(src, new, alpha) \
