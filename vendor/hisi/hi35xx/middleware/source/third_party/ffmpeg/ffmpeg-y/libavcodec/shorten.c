#include <limits.h>
#include "avcodec.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "get_bits.h"
#include "golomb.h"
#include "internal.h"
#define MAX_CHANNELS 8
#define MAX_BLOCKSIZE 65535
#define OUT_BUFFER_SIZE 16384
#define ULONGSIZE 2
#define WAVE_FORMAT_PCM 0x0001
#define DEFAULT_BLOCK_SIZE 256
#define TYPESIZE 4
#define CHANSIZE 0
#define LPCQSIZE 2
#define ENERGYSIZE 3
#define BITSHIFTSIZE 2
#define TYPE_S8    1
#define TYPE_U8    2
#define TYPE_S16HL 3
#define TYPE_U16HL 4
#define TYPE_S16LH 5
#define TYPE_U16LH 6
#define NWRAP 3
#define NSKIPSIZE 1
#define LPCQUANT 5
#define V2LPCQOFFSET (1 << LPCQUANT)
#define FNSIZE 2
#define FN_DIFF0        0
#define FN_DIFF1        1
#define FN_DIFF2        2
#define FN_DIFF3        3
#define FN_QUIT         4
#define FN_BLOCKSIZE    5
#define FN_BITSHIFT     6
#define FN_QLPC         7
#define FN_ZERO         8
#define FN_VERBATIM     9
#define VERBATIM_CKSIZE_SIZE 5
#define VERBATIM_BYTE_SIZE 8
#define CANONICAL_HEADER_SIZE 44
typedef struct ShortenContext {
    AVCodecContext *avctx;
    GetBitContext gb;

    int min_framesize, max_framesize;
    unsigned channels;

    int32_t *decoded[MAX_CHANNELS];
    int32_t *decoded_base[MAX_CHANNELS];
    int32_t *offset[MAX_CHANNELS];
    int *coeffs;
    uint8_t *bitstream;
    int bitstream_size;
    int bitstream_index;
    unsigned int allocated_bitstream_size;
    int header_size;
    uint8_t header[OUT_BUFFER_SIZE];
    int version;
    int cur_chan;
    int bitshift;
    int nmean;
    int internal_ftype;
    int nwrap;
    int blocksize;
    int bitindex;
    int32_t lpcqoffset;
    int got_header;
    int got_quit_command;
    int swap;
    BswapDSPContext bdsp;
} ShortenContext;
