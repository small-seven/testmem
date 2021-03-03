#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "get_bits.h"
#include "hpeldsp.h"
#include "internal.h"
#include "mathops.h"
#include "thread.h"
#include "videodsp.h"
#include "vp3data.h"
#include "vp4data.h"
#include "vp3dsp.h"
#include "xiph.h"
#define FRAGMENT_PIXELS 8
typedef struct Vp3Fragment {
    int16_t dc;
    uint8_t coding_method;
    uint8_t qpi;
} Vp3Fragment;
#define SB_NOT_CODED        0
#define SB_PARTIALLY_CODED  1
#define SB_FULLY_CODED      2
#define MAXIMUM_LONG_BIT_RUN 4129
#define MODE_INTER_NO_MV      0
#define MODE_INTRA            1
#define MODE_INTER_PLUS_MV    2
#define MODE_INTER_LAST_MV    3
#define MODE_INTER_PRIOR_LAST 4
#define MODE_USING_GOLDEN     5
#define MODE_GOLDEN_MV        6
#define MODE_INTER_FOURMV     7
#define CODING_MODE_COUNT     8
#define MODE_COPY             8
typedef struct {
    int dc;
    int type;
} VP4Predictor;
#define MIN_DEQUANT_VAL 2
typedef struct Vp3DecodeContext {
    AVCodecContext *avctx;
    int theora, theora_tables, theora_header;
    int version;
    int width, height;
    int chroma_x_shift, chroma_y_shift;
    ThreadFrame golden_frame;
    ThreadFrame last_frame;
    ThreadFrame current_frame;
    int keyframe;
    uint8_t idct_permutation[64];
    uint8_t idct_scantable[64];
    HpelDSPContext hdsp;
    VideoDSPContext vdsp;
    VP3DSPContext vp3dsp;
    DECLARE_ALIGNED(16, int16_t, block)[64];
    int flipped_image;
    int last_slice_end;
    int skip_loop_filter;

    int qps[3];
    int nqps;
    int last_qps[3];

    int superblock_count;
    int y_superblock_width;
    int y_superblock_height;
    int y_superblock_count;
    int c_superblock_width;
    int c_superblock_height;
    int c_superblock_count;
    int u_superblock_start;
    int v_superblock_start;
    unsigned char *superblock_coding;

    int macroblock_count; /* y macroblock count */
    int macroblock_width;
    int macroblock_height;
    int c_macroblock_count;
    int c_macroblock_width;
    int c_macroblock_height;
    int yuv_macroblock_count; /* y+u+v macroblock count */

    int fragment_count;
    int fragment_width[2];
    int fragment_height[2];

    Vp3Fragment *all_fragments;
    int fragment_start[3];
    int data_offset[3];
    uint8_t offset_x;
    uint8_t offset_y;
    int offset_x_warned;

    int8_t (*motion_val[2])[2];

    /* tables */
    uint16_t coded_dc_scale_factor[2][64];
    uint32_t coded_ac_scale_factor[64];
    uint8_t base_matrix[384][64];
    uint8_t qr_count[2][3];
    uint8_t qr_size[2][3][64];
    uint16_t qr_base[2][3][64];

    /**
     * This is a list of all tokens in bitstream order. Reordering takes place
     * by pulling from each level during IDCT. As a consequence, IDCT must be
     * in Hilbert order, making the minimum slice height 64 for 4:2:0 and 32
     * otherwise. The 32 different tokens with up to 12 bits of extradata are
     * collapsed into 3 types, packed as follows:
     *   (from the low to high bits)
     *
     * 2 bits: type (0,1,2)
     *   0: EOB run, 14 bits for run length (12 needed)
     *   1: zero run, 7 bits for run length
     *                7 bits for the next coefficient (3 needed)
     *   2: coefficient, 14 bits (11 needed)
     *
     * Coefficients are signed, so are packed in the highest bits for automatic
     * sign extension.
     */
    int16_t *dct_tokens[3][64];
    int16_t *dct_tokens_base;
#define TOKEN_EOB(eob_run)              ((eob_run) << 2)
#define TOKEN_ZERO_RUN(coeff, zero_run) (((coeff) * 512) + ((zero_run) << 2) + 1)
#define TOKEN_COEFF(coeff)              (((coeff) * 4) + 2)

    /**
     * number of blocks that contain DCT coefficients at
     * the given level or higher
     */
    int num_coded_frags[3][64];
    int total_num_coded_frags;

    /* this is a list of indexes into the all_fragments array indicating
     * which of the fragments are coded */
    int *coded_fragment_list[3];

    int *kf_coded_fragment_list;
    int *nkf_coded_fragment_list;
    int num_kf_coded_fragment[3];

    VLC dc_vlc[16];
    VLC ac_vlc_1[16];
    VLC ac_vlc_2[16];
    VLC ac_vlc_3[16];
    VLC ac_vlc_4[16];

    VLC superblock_run_length_vlc; /* version < 2 */
    VLC fragment_run_length_vlc; /* version < 2 */
    VLC block_pattern_vlc[2]; /* version >= 2*/
    VLC mode_code_vlc;
    VLC motion_vector_vlc; /* version < 2 */
    VLC vp4_mv_vlc[2][7]; /* version >=2 */

    /* these arrays need to be on 16-byte boundaries since SSE2 operations
     * index into them */
    DECLARE_ALIGNED(16, int16_t, qmat)[3][2][3][64];     ///< qmat[qpi][is_inter][plane]

    /* This table contains superblock_count * 16 entries. Each set of 16
     * numbers corresponds to the fragment indexes 0..15 of the superblock.
     * An entry will be -1 to indicate that no entry corresponds to that
     * index. */
    int *superblock_fragments;

    /* This is an array that indicates how a particular macroblock
     * is coded. */
    unsigned char *macroblock_coding;

    uint8_t *edge_emu_buffer;

    /* Huffman decode */
    int hti;
    unsigned int hbits;
    int entries;
    int huff_code_size;
    uint32_t huffman_table[80][32][2];

    uint8_t filter_limit_values[64];
    DECLARE_ALIGNED(8, int, bounding_values_array)[256 + 2];

    VP4Predictor * dc_pred_row; /* dc_pred_row[y_superblock_width * 4] */
} Vp3DecodeContext;
#define BLOCK_X (2 * mb_x + (k & 1))
#define BLOCK_Y (2 * mb_y + (k >> 1))
#if CONFIG_VP4_DECODER
#define body(n) { \
#define thresh(n) (0x200 - (0x80 >> n))
#define else_if(n) else if (bits < thresh(n)) body(n)
#undef body
#undef thresh
#undef else_if
#endif
#define SET_CHROMA_MODES                                                      \
#if CONFIG_VP4_DECODER
#endif
#define COMPATIBLE_FRAME(x)                                                   \
#define DC_COEFF(u) s->all_fragments[u].dc
#define PUL 8
#define PU 4
#define PUR 2
#define PL 1
#if CONFIG_VP4_DECODER
#define loop_stride 12
#endif
#if CONFIG_VP4_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
#define TRANSPOSE(x) (((x) >> 3) | (((x) & 7) << 3))
#undef TRANSPOSE
#if CONFIG_VP4_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
#if HAVE_THREADS
#define copy_fields(to, from, start_field, end_field)                         \
#undef copy_fields
#endif
#if CONFIG_THEORA_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
#if HAVE_THREADS
#endif
#if CONFIG_THEORA_DECODER
#endif
#if CONFIG_VP4_DECODER
#endif
