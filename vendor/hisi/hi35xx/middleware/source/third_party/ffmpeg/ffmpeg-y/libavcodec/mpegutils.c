#include <stdint.h>
#include "libavutil/common.h"
#include "libavutil/frame.h"
#include "libavutil/pixdesc.h"
#include "libavutil/motion_vector.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "mpegutils.h"
#if FF_API_DEBUG_MV
#define COLOR(theta, r) \
#endif
