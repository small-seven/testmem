#include <stdint.h>
#include "libavutil/common.h"
#include "mss34dsp.h"
#define DCT_TEMPLATE(blk, step, SOP, shift)                         \
#define SOP_ROW(a) (((a) * (1U << 16)) + 0x2000)
#define SOP_COL(a) (((a) + 32) * (1U << 16))
