#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define PALETTE_COUNT 256
#define VQA_HEADER_SIZE 0x2A
#define MAX_CODEBOOK_VECTORS 0xFF00
#define SOLID_PIXEL_VECTORS 0x100
#define MAX_VECTORS (MAX_CODEBOOK_VECTORS + SOLID_PIXEL_VECTORS)
#define MAX_CODEBOOK_SIZE (MAX_VECTORS * 4 * 4)
#define CBF0_TAG MKBETAG('C', 'B', 'F', '0')
#define CBFZ_TAG MKBETAG('C', 'B', 'F', 'Z')
#define CBP0_TAG MKBETAG('C', 'B', 'P', '0')
#define CBPZ_TAG MKBETAG('C', 'B', 'P', 'Z')
#define CPL0_TAG MKBETAG('C', 'P', 'L', '0')
#define CPLZ_TAG MKBETAG('C', 'P', 'L', 'Z')
#define VPTZ_TAG MKBETAG('V', 'P', 'T', 'Z')
typedef struct VqaContext {

    AVCodecContext *avctx;
    GetByteContext gb;

    uint32_t palette[PALETTE_COUNT];

    int width;   /* width of a frame */
    int height;   /* height of a frame */
    int vector_width;  /* width of individual vector */
    int vector_height;  /* height of individual vector */
    int vqa_version;  /* this should be either 1, 2 or 3 */

    unsigned char *codebook;         /* the current codebook */
    int codebook_size;
    unsigned char *next_codebook_buffer;  /* accumulator for next codebook */
    int next_codebook_buffer_index;

    unsigned char *decode_buffer;
    int decode_buffer_size;

    /* number of frames to go before replacing codebook */
    int partial_countdown;
    int partial_count;

} VqaContext;
#define CHECK_COUNT() \
#define CHECK_COPY(idx) \
