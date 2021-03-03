#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "hwaccel.h"
#include "internal.h"
#include "mathops.h"
#include "rectangle.h"
#include "thread.h"
#include "vp8.h"
#include "vp8data.h"
#if ARCH_ARM
#   include "arm/vp8.h"
#endif
#if CONFIG_VP7_DECODER && CONFIG_VP8_DECODER
#define VPX(vp7, f) (vp7 ? vp7_ ## f : vp8_ ## f)
#elif CONFIG_VP7_DECODER
#define VPX(vp7, f) vp7_ ## f
#else // CONFIG_VP8_DECODER
#define VPX(vp7, f) vp8_ ## f
#endif
#if HAVE_THREADS
#endif
#if CONFIG_VP8_DECODER
#endif /* CONFIG_VP8_DECODER */
#if CONFIG_VP8_VAAPI_HWACCEL
#endif
#if CONFIG_VP8_NVDEC_HWACCEL
#endif
#if HAVE_THREADS
#endif
#define VP7_MVC_SIZE 17
#define VP8_MVC_SIZE 19
#define MV_EDGE_CHECK(n)                                                      \
#ifndef vp8_decode_block_coeffs_internal
#endif
#define XCHG(a, b, xchg)                                                      \
#define H_LOOP_FILTER_16Y_INNER(cond)                                         \
#define MARGIN (16 << 2)
#if HAVE_THREADS
#define check_thread_pos(td, otd, mb_x_check, mb_y_check)                     \
#define update_pos(td, mb_y, mb_x)                                            \
#else
#define check_thread_pos(td, otd, mb_x_check, mb_y_check) while(0)
#define update_pos(td, mb_y, mb_x) while(0)
#endif
#if CONFIG_VP7_DECODER
#endif /* CONFIG_VP7_DECODER */
av_cold int ff_vp8_decode_free(AVCodecContext *avctx)
{
    VP8Context *s = avctx->priv_data;
    int i;

    if (!s)
        return 0;

    vp8_decode_flush_impl(avctx, 1);
    for (i = 0; i < FF_ARRAY_ELEMS(s->frames); i++)
        av_frame_free(&s->frames[i].tf.f);

    return 0;
}
#if CONFIG_VP7_DECODER
#endif /* CONFIG_VP7_DECODER */
#if CONFIG_VP8_DECODER
#if HAVE_THREADS
#define REBASE(pic) ((pic) ? (pic) - &s_src->frames[0] + &s->frames[0] : NULL)
#endif /* HAVE_THREADS */
#endif /* CONFIG_VP8_DECODER */
#if CONFIG_VP7_DECODER
#endif /* CONFIG_VP7_DECODER */
#if CONFIG_VP8_DECODER
#if CONFIG_VP8_VAAPI_HWACCEL
#endif
#if CONFIG_VP8_NVDEC_HWACCEL
#endif
#endif /* CONFIG_VP7_DECODER */
