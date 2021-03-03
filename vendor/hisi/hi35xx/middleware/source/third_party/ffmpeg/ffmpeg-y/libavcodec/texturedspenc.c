#include <stddef.h>
#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "texturedsp.h"
#define mul8(a, b) (((a) * (b) + 128 + (((a) * (b) + 128) >> 8)) >> 8)
#define rgb2rgb565(r, g, b) \
#define lerp13(a, b) ((2 * (a) + (b)) / 3)
