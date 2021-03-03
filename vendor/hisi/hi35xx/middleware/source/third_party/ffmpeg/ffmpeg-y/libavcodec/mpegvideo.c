#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/motion_vector.h"
#include "libavutil/timer.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "h264chroma.h"
#include "idctdsp.h"
#include "internal.h"
#include "mathops.h"
#include "mpeg_er.h"
#include "mpegutils.h"
#include "mpegvideo.h"
#include "mpegvideodata.h"
#include "mjpegenc.h"
#include "msmpeg4.h"
#include "qpeldsp.h"
#include "thread.h"
#include "wmv2.h"
#include <limits.h>
#define COPY(a) bak->a = src->a
#undef COPY
#define UPDATE_PICTURE(pic)\
#define REBASE_PICTURE(pic, new_ctx, old_ctx)                                 \
#if 0 // BUFREF-FIXME
#endif
#if !CONFIG_SMALL
#endif
