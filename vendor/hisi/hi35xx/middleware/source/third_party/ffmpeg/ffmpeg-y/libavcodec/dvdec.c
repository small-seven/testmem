#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/pixdesc.h"
#include "avcodec.h"
#include "dv.h"
#include "dv_profile_internal.h"
#include "dvdata.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
#include "put_bits.h"
#include "simple_idct.h"
#include "thread.h"
typedef struct BlockInfo {
    const uint32_t *factor_table;
    const uint8_t *scan_table;
    uint8_t pos; /* position in block */
    void (*idct_put)(uint8_t *dest, ptrdiff_t stride, int16_t *block);
    uint8_t partial_bit_count;
    uint32_t partial_bit_buffer;
    int shift_offset;
} BlockInfo;
