#include <string.h>
#include <sys/types.h>
#include <mfx/mfxvideo.h>
#include "libavutil/common.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_qsv.h"
#include "libavutil/mem.h"
#include "libavutil/log.h"
#include "libavutil/pixdesc.h"
#include "libavutil/pixfmt.h"
#include "libavutil/time.h"
#include "avcodec.h"
#include "internal.h"
#include "qsv.h"
#include "qsv_internal.h"
#include "qsvdec.h"
#define CHECK_MATCH(x) \
#undef CHECK_MATCH
#if FF_API_PKT_PTS
#endif
