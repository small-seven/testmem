#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "copy_block.h"
#include "bytestream.h"
#include "get_bits.h"
#include "hpeldsp.h"
#include "internal.h"
#include "indeo3data.h"
#define BS_8BIT_PEL     (1 << 1) ///< 8-bit pixel bitdepth indicator
#define BS_KEYFRAME     (1 << 2) ///< intra frame indicator
#define BS_MV_Y_HALF    (1 << 4) ///< vertical mv halfpel resolution indicator
#define BS_MV_X_HALF    (1 << 5) ///< horizontal mv halfpel resolution indicator
#define BS_NONREF       (1 << 8) ///< nonref (discardable) frame indicator
#define BS_BUFFER        9       ///< indicates which of two frame buffers should be used
typedef struct Plane {
    uint8_t         *buffers[2];
    uint8_t         *pixels[2]; ///< pointer to the actual pixel data of the buffers above
    uint32_t        width;
    uint32_t        height;
    ptrdiff_t       pitch;
} Plane;
#define CELL_STACK_MAX  20
typedef struct Cell {
    int16_t         xpos;       ///< cell coordinates in 4x4 blocks
    int16_t         ypos;
    int16_t         width;      ///< cell width  in 4x4 blocks
    int16_t         height;     ///< cell height in 4x4 blocks
    uint8_t         tree;       ///< tree id: 0- MC tree, 1 - VQ tree
    const int8_t    *mv_ptr;    ///< ptr to the motion vector if any
} Cell;
typedef struct Indeo3DecodeContext {
    AVCodecContext *avctx;
    HpelDSPContext  hdsp;

    GetBitContext   gb;
    int             need_resync;
    int             skip_bits;
    const uint8_t   *next_cell_data;
    const uint8_t   *last_byte;
    const int8_t    *mc_vectors;
    unsigned        num_vectors;    ///< number of motion vectors in mc_vectors

    int16_t         width, height;
    uint32_t        frame_num;      ///< current frame number (zero-based)
    int             data_size;      ///< size of the frame data in bytes
    uint16_t        frame_flags;    ///< frame properties
    uint8_t         cb_offset;      ///< needed for selecting VQ tables
    uint8_t         buf_sel;        ///< active frame buffer: 0 - primary, 1 -secondary
    const uint8_t   *y_data_ptr;
    const uint8_t   *v_data_ptr;
    const uint8_t   *u_data_ptr;
    int32_t         y_data_size;
    int32_t         v_data_size;
    int32_t         u_data_size;
    const uint8_t   *alt_quant;     ///< secondary VQ table set for the modes 1 and 4
    Plane           planes[3];
} Indeo3DecodeContext;
#define AVG_32(dst, src, ref) \
#define AVG_64(dst, src, ref) \
#if HAVE_BIGENDIAN
#else
#endif
#if HAVE_BIGENDIAN
#else
#endif
#define BUFFER_PRECHECK \
#define RLE_BLOCK_COPY \
#define RLE_BLOCK_COPY_8 \
#define RLE_LINES_COPY \
#define RLE_LINES_COPY_M10 \
#define APPLY_DELTA_4 \
#define APPLY_DELTA_8 \
#define APPLY_DELTA_1011_INTER \
#define SPLIT_CELL(size, new_size) (new_size) = ((size) > 2) ? ((((size) + 2) >> 2) << 1) : 1
#define UPDATE_BITPOS(n) \
#define RESYNC_BITSTREAM \
#define CHECK_CELL \
#define OS_HDR_ID   MKBETAG('F', 'R', 'M', 'H')
