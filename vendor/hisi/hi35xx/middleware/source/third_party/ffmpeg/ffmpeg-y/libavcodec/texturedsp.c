#include <stddef.h>
#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/libm.h"
#include "texturedsp.h"
#define RGBA(r, g, b, a) (((uint8_t)(r) <<  0) | \
