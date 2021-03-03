#include <string.h>
#include "checkasm.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/h264dsp.h"
#include "libavcodec/h264data.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#define SIZEOF_PIXEL ((bit_depth + 7) / 8)
#define SIZEOF_COEF  (2 * ((bit_depth + 7) / 8))
#define PIXEL_STRIDE 16
#define randomize_buffers()                                                  \
#define dct4x4_impl(size, dctcoef)                                           \
#define DCT8_1D(src, srcstride, dst, dststride) do {                         \
#define dct8x8_impl(size, dctcoef)                                           \
#define CHECK_LOOP_FILTER(name, align, idc)                             \
#undef CHECK_LOOP_FILTER
#define CHECK_LOOP_FILTER(name, align, idc)                             \
#undef CHECK_LOOP_FILTER
