#include "libavutil/common.h"
#include "avcodec.h"
#include "internal.h"
#define RBG323_TO_BGR8(x) ((((x) << 3) & 0xC0) |                                \
#define INC_XY(n)                                                             \
