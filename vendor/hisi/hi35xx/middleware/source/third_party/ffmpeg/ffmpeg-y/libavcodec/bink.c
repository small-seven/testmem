#include "libavutil/attributes.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "binkdata.h"
#include "binkdsp.h"
#include "blockdsp.h"
#include "get_bits.h"
#include "hpeldsp.h"
#include "internal.h"
#include "mathops.h"
#define BINK_FLAG_ALPHA 0x00100000
#define BINK_FLAG_GRAY  0x00020000
typedef struct Tree {
    int     vlc_num;  ///< tree number (in bink_trees[])
    uint8_t syms[16]; ///< leaf value to symbol mapping
} Tree;
#define GET_HUFF(gb, tree)  (tree).syms[get_vlc2(gb, bink_trees[(tree).vlc_num].table,\
typedef struct Bundle {
    int     len;       ///< length of number of entries to decode (in bits)
    Tree    tree;      ///< Huffman tree-related data
    uint8_t *data;     ///< buffer for decoded symbols
    uint8_t *data_end; ///< buffer end
    uint8_t *cur_dec;  ///< pointer to the not yet decoded part of the buffer
    uint8_t *cur_ptr;  ///< pointer to the data that is not read from buffer yet
} Bundle;
typedef struct BinkContext {
    AVCodecContext *avctx;
    BlockDSPContext bdsp;
    HpelDSPContext hdsp;
    BinkDSPContext binkdsp;
    AVFrame        *last;
    int            version;              ///< internal Bink file version
    int            has_alpha;
    int            swap_planes;
    unsigned       frame_num;

    Bundle         bundle[BINKB_NB_SRC]; ///< bundles for decoding all data types
    Tree           col_high[16];         ///< trees for decoding high nibble in "colours" data type
    int            col_lastval;          ///< value of last decoded high nibble in "colours" data type
} BinkContext;
#define CHECK_READ_VAL(gb, b, t) \
#define DC_START_BITS 11
#define C (1LL<<30)
