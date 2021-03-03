#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "libavutil/display.h"
#include "libavutil/internal.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/md5.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/stereo3d.h"
#include "bswapdsp.h"
#include "bytestream.h"
#include "cabac_functions.h"
#include "golomb.h"
#include "hevc.h"
#include "hevc_data.h"
#include "hevc_parse.h"
#include "hevcdec.h"
#include "hwaccel.h"
#include "profiles.h"
static void pic_arrays_free(HEVCContext *s)
{
    av_freep(&s->sao);
    av_freep(&s->deblock);

    av_freep(&s->skip_flag);
    av_freep(&s->tab_ct_depth);

    av_freep(&s->tab_ipm);
    av_freep(&s->cbf_luma);
    av_freep(&s->is_pcm);

    av_freep(&s->qp_y_tab);
    av_freep(&s->tab_slice_address);
    av_freep(&s->filter_slice_edges);

    av_freep(&s->horizontal_bs);
    av_freep(&s->vertical_bs);

    av_freep(&s->sh.entry_point_offset);
    av_freep(&s->sh.size);
    av_freep(&s->sh.offset);

    av_buffer_pool_uninit(&s->tab_mvf_pool);
    av_buffer_pool_uninit(&s->rpl_tab_pool);
}
#define HWACCEL_MAX (CONFIG_HEVC_DXVA2_HWACCEL + \
#if CONFIG_HEVC_DXVA2_HWACCEL
#endif
#if CONFIG_HEVC_D3D11VA_HWACCEL
#endif
#if CONFIG_HEVC_VAAPI_HWACCEL
#endif
#if CONFIG_HEVC_VDPAU_HWACCEL
#endif
#if CONFIG_HEVC_NVDEC_HWACCEL
#endif
#if CONFIG_HEVC_VIDEOTOOLBOX_HWACCEL
#endif
#if CONFIG_HEVC_DXVA2_HWACCEL
#endif
#if CONFIG_HEVC_D3D11VA_HWACCEL
#endif
#if CONFIG_HEVC_VAAPI_HWACCEL
#endif
#if CONFIG_HEVC_VIDEOTOOLBOX_HWACCEL
#endif
#if CONFIG_HEVC_NVDEC_HWACCEL
#endif
#if CONFIG_HEVC_VDPAU_HWACCEL
#endif
#if CONFIG_HEVC_NVDEC_HWACCEL
#endif
#if CONFIG_HEVC_NVDEC_HWACCEL
#endif
#define CTB(tab, x, y) ((tab)[(y) * s->ps.sps->ctb_width + (x)])
#define SET_SAO(elem, value)                            \
#undef SET_SAO
#undef CTB
#define SUBDIVIDE(x, y, idx)                                                    \
#undef SUBDIVIDE
#define POS(c_idx, x, y)                                                              \
#if HAVE_BIGENDIAN
#endif
#if HAVE_BIGENDIAN
#endif
static av_cold int hevc_decode_free(AVCodecContext *avctx)
{
    HEVCContext       *s = avctx->priv_data;
    int i;

    pic_arrays_free(s);

    av_freep(&s->md5_ctx);

    av_freep(&s->cabac_state);

    for (i = 0; i < 3; i++) {
        av_freep(&s->sao_pixel_buffer_h[i]);
        av_freep(&s->sao_pixel_buffer_v[i]);
    }
    av_frame_free(&s->output_frame);

    for (i = 0; i < FF_ARRAY_ELEMS(s->DPB); i++) {
        ff_hevc_unref_frame(s, &s->DPB[i], ~0);
        av_frame_free(&s->DPB[i].frame);
    }

    ff_hevc_ps_uninit(&s->ps);

    av_freep(&s->sh.entry_point_offset);
    av_freep(&s->sh.offset);
    av_freep(&s->sh.size);

    for (i = 1; i < s->threads_number; i++) {
        HEVCLocalContext *lc = s->HEVClcList[i];
        if (lc) {
            av_freep(&s->HEVClcList[i]);
            av_freep(&s->sList[i]);
        }
    }
    if (s->HEVClc == s->HEVClcList[0])
        s->HEVClc = NULL;
    av_freep(&s->HEVClcList[0]);

    ff_h2645_packet_uninit(&s->pkt);

    ff_hevc_reset_sei(&s->sei);

    return 0;
}
#if HAVE_THREADS
#endif
#if HAVE_THREADS
#endif
#define OFFSET(x) offsetof(HEVCContext, x)
#define PAR (AV_OPT_FLAG_DECODING_PARAM | AV_OPT_FLAG_VIDEO_PARAM)
#if CONFIG_HEVC_DXVA2_HWACCEL
#endif
#if CONFIG_HEVC_D3D11VA_HWACCEL
#endif
#if CONFIG_HEVC_D3D11VA2_HWACCEL
#endif
#if CONFIG_HEVC_NVDEC_HWACCEL
#endif
#if CONFIG_HEVC_VAAPI_HWACCEL
#endif
#if CONFIG_HEVC_VDPAU_HWACCEL
#endif
#if CONFIG_HEVC_VIDEOTOOLBOX_HWACCEL
#endif
