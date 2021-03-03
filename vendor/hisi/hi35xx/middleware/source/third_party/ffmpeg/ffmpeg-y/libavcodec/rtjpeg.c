#include "libavutil/common.h"
#include "get_bits.h"
#include "rtjpeg.h"
#define PUT_COEFF(c) \
#define ALIGN(a) \
#define BLOCK(quant, dst, stride) do { \
