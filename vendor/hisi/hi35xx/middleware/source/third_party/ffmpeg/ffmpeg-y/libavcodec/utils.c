#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/channel_layout.h"
#include "libavutil/crc.h"
#include "libavutil/frame.h"
#include "libavutil/hwcontext.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/mem_internal.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/dict.h"
#include "libavutil/thread.h"
#include "avcodec.h"
#include "decode.h"
#include "hwaccel.h"
#include "libavutil/opt.h"
#include "mpegvideo.h"
#include "thread.h"
#include "frame_thread_encoder.h"
#include "internal.h"
#include "raw.h"
#include "bytestream.h"
#include "version.h"
#include <stdlib.h>
#include <stdarg.h>
#include <stdatomic.h>
#include <limits.h>
#include <float.h>
#if CONFIG_ICONV
# include <iconv.h>
#endif
#include "libavutil/ffversion.h"
void av_fast_padded_malloc(void *ptr, unsigned int *size, size_t min_size)
{
    uint8_t **p = ptr;
    if (min_size > SIZE_MAX - AV_INPUT_BUFFER_PADDING_SIZE) {
        av_freep(p);
        *size = 0;
        return;
    }
    if (!ff_fast_malloc(p, size, min_size + AV_INPUT_BUFFER_PADDING_SIZE, 1))
        memset(*p + min_size, 0, AV_INPUT_BUFFER_PADDING_SIZE);
}
#if FF_API_CODEC_GET_SET
#endif
#if FF_API_CODED_FRAME
#endif
#if CONFIG_ICONV
#else
#endif
#if FF_API_AVCTX_TIMEBASE
#endif
#if FF_API_CODED_FRAME
#endif
void avsubtitle_free(AVSubtitle *sub)
{
    int i;

    for (i = 0; i < sub->num_rects; i++) {
        av_freep(&sub->rects[i]->data[0]);
        av_freep(&sub->rects[i]->data[1]);
        av_freep(&sub->rects[i]->data[2]);
        av_freep(&sub->rects[i]->data[3]);
        av_freep(&sub->rects[i]->text);
        av_freep(&sub->rects[i]->ass);
        av_freep(&sub->rects[i]);
    }

    av_freep(&sub->rects);

    memset(sub, 0, sizeof(*sub));
}
#if FF_API_CODED_FRAME
#endif
#define TAG_PRINT(x)                                              \
#define LICENSE_PREFIX "libavcodec license: "
#if !HAVE_THREADS
#endif
#if FF_API_USER_VISIBLE_AVHWACCEL
#endif
#if FF_API_LOCKMGR
#endif
#if !HAVE_THREADS
#endif
void avcodec_parameters_free(AVCodecParameters **ppar)
{
    AVCodecParameters *par = *ppar;

    if (!par)
        return;
    codec_parameters_reset(par);

    av_freep(ppar);
}
