#include <stdint.h>
#include <string.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "celp_math.h"
#include "g723_1.h"
#include "internal.h"
#define BITSTREAM_WRITER_LE
#include "put_bits.h"
#define get_index(num, offset, size)                                          \
