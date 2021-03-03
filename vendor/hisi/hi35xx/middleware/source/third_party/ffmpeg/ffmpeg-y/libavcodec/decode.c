#include <stdint.h>
#include <string.h>
#include "config.h"
#if CONFIG_ICONV
# include <iconv.h>
#endif
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/common.h"
#include "libavutil/frame.h"
#include "libavutil/hwcontext.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intmath.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "bytestream.h"
#include "decode.h"
#include "hwaccel.h"
#include "internal.h"
#include "thread.h"
#if FF_API_PKT_PTS
#endif
#if FF_API_AVCTX_TIMEBASE
#endif
#define UTF8_MAX_BYTES 4 /* 5 and 6 bytes sequences should not be used */
#if CONFIG_ICONV
#endif
#if CONFIG_ICONV
#else
#endif
#if FF_API_ASS_TIMING
#endif
#if FF_API_ASS_TIMING
#endif
#if FF_API_PKT_PTS
#endif
static void decode_data_free(void *opaque, uint8_t *data)
{
    FrameDecodeData *fdd = (FrameDecodeData*)data;

    if (fdd->post_process_opaque_free)
        fdd->post_process_opaque_free(fdd->post_process_opaque);

    if (fdd->hwaccel_priv_free)
        fdd->hwaccel_priv_free(fdd->hwaccel_priv);

    av_freep(&fdd);
}
