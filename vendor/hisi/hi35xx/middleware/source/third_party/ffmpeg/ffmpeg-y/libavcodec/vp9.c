#include "avcodec.h"
#include "get_bits.h"
#include "hwaccel.h"
#include "internal.h"
#include "profiles.h"
#include "thread.h"
#include "videodsp.h"
#include "vp56.h"
#include "vp9.h"
#include "vp9data.h"
#include "vp9dec.h"
#include "libavutil/avassert.h"
#include "libavutil/pixdesc.h"
#define VP9_SYNCCODE 0x498342
#if HAVE_THREADS
#else
#endif
#define HWACCEL_MAX (CONFIG_VP9_DXVA2_HWACCEL + \
#if CONFIG_VP9_DXVA2_HWACCEL
#endif
#if CONFIG_VP9_D3D11VA_HWACCEL
#endif
#if CONFIG_VP9_NVDEC_HWACCEL
#endif
#if CONFIG_VP9_VAAPI_HWACCEL
#endif
#if CONFIG_VP9_NVDEC_HWACCEL
#endif
#if CONFIG_VP9_VAAPI_HWACCEL
#endif
#define assign(var, type, n) var = (type) p; p += s->sb_cols * (n) * sizeof(*var)
#undef assign
static av_cold int vp9_decode_free(AVCodecContext *avctx)
{
    VP9Context *s = avctx->priv_data;
    int i;

    for (i = 0; i < 3; i++) {
        if (s->s.frames[i].tf.f->buf[0])
            vp9_frame_unref(avctx, &s->s.frames[i]);
        av_frame_free(&s->s.frames[i].tf.f);
    }
    for (i = 0; i < 8; i++) {
        if (s->s.refs[i].f->buf[0])
            ff_thread_release_buffer(avctx, &s->s.refs[i]);
        av_frame_free(&s->s.refs[i].f);
        if (s->next_refs[i].f->buf[0])
            ff_thread_release_buffer(avctx, &s->next_refs[i]);
        av_frame_free(&s->next_refs[i].f);
    }

    free_buffers(s);
    vp9_free_entries(avctx);
    av_freep(&s->td);
    return 0;
}
#if HAVE_THREADS
#endif
#if FF_API_PKT_PTS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#if CONFIG_VP9_DXVA2_HWACCEL
#endif
#if CONFIG_VP9_D3D11VA_HWACCEL
#endif
#if CONFIG_VP9_D3D11VA2_HWACCEL
#endif
#if CONFIG_VP9_NVDEC_HWACCEL
#endif
#if CONFIG_VP9_VAAPI_HWACCEL
#endif
