#include "internal.h"
#include "avcodec.h"
#include "h264dec.h"
#include "h264_ps.h"
#include "mpegutils.h"
#include "rectangle.h"
#include "thread.h"
#include <assert.h>
#define MB_TYPE_16x16_OR_INTRA (MB_TYPE_16x16 | MB_TYPE_INTRA4x4 | \
