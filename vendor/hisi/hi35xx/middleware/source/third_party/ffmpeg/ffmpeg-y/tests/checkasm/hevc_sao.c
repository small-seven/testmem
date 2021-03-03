#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/hevcdsp.h"
#include "checkasm.h"
#define SIZEOF_PIXEL ((bit_depth + 7) / 8)
#define PIXEL_STRIDE (2*MAX_PB_SIZE + AV_INPUT_BUFFER_PADDING_SIZE) //same with sao_edge src_stride
#define BUF_SIZE (PIXEL_STRIDE * (64+2) * 2) //+2 for top and bottom row, *2 for high bit depth
#define OFFSET_THRESH (1 << (bit_depth - 5))
#define OFFSET_LENGTH 5
#define randomize_buffers(buf0, buf1, size)                 \
#define randomize_buffers2(buf, size)                       \
