#include "libavutil/imgutils.h"
#include "libavutil/timer.h"
#include "avcodec.h"
#include "blockdsp.h"
#define  UNCHECKED_BITSTREAM_READER 1
#include "get_bits.h"
#include "dnxhddata.h"
#include "idctdsp.h"
#include "internal.h"
#include "profiles.h"
#include "thread.h"
typedef struct RowContext {
    DECLARE_ALIGNED(32, int16_t, blocks)[12][64];
    int luma_scale[64];
    int chroma_scale[64];
    GetBitContext gb;
    int last_dc[3];
    int last_qscale;
    int errors;
    /** -1:not set yet  0:off=RGB  1:on=YUV  2:variable */
    int format;
} RowContext;
typedef struct DNXHDContext {
    AVCodecContext *avctx;
    RowContext *rows;
    BlockDSPContext bdsp;
    const uint8_t* buf;
    int buf_size;
    int64_t cid;                        ///< compression id
    unsigned int width, height;
    enum AVPixelFormat pix_fmt;
    unsigned int mb_width, mb_height;
    uint32_t mb_scan_index[512];
    int data_offset;                    // End of mb_scan_index, where macroblocks start
    int cur_field;                      ///< current interlaced field
    VLC ac_vlc, dc_vlc, run_vlc;
    IDCTDSPContext idsp;
    ScanTable scantable;
    const CIDEntry *cid_table;
    int bit_depth; // 8, 10, 12 or 0 if not initialized at all.
    int is_444;
    int alpha;
    int lla;
    int mbaff;
    int act;
    int (*decode_dct_block)(const struct DNXHDContext *ctx,
                            RowContext *row, int n);
} DNXHDContext;
#define DNXHD_VLC_BITS 9
#define DNXHD_DC_VLC_BITS 7
