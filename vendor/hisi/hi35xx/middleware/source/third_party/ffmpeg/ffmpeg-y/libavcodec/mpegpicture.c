#include <stdint.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "motion_est.h"
#include "mpegpicture.h"
#include "mpegutils.h"
#define MAKE_WRITABLE(table) \
#   define EMU_EDGE_HEIGHT (4 * 70)
#if FF_API_DEBUG_MV
#endif
#define UPDATE_TABLE(table)                                                   \
