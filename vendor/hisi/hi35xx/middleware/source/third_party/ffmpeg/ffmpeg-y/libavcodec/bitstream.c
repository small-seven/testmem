#include "libavutil/avassert.h"
#include "libavutil/qsort.h"
#include "avcodec.h"
#include "internal.h"
#include "mathops.h"
#include "put_bits.h"
#include "vlc.h"
#define GET_DATA(v, table, i, wrap, size)                   \
typedef struct VLCcode {
    uint8_t bits;
    uint16_t symbol;
    /** codeword, with the first bit-to-be-read in the msb
     * (even if intended for a little-endian bitstream reader) */
    uint32_t code;
} VLCcode;
#define COPY(condition)\
