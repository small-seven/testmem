#include "libavutil/common.h"
#include "libavutil/mathematics.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_qsv.h"
#include "libavutil/time.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#include "qsvvpp.h"
#include "video.h"
#define IS_VIDEO_MEMORY(mode)  (mode & (MFX_MEMTYPE_VIDEO_MEMORY_DECODER_TARGET | \
#define IS_OPAQUE_MEMORY(mode) (mode & MFX_MEMTYPE_OPAQUE_FRAME)
#define IS_SYSTEM_MEMORY(mode) (mode & MFX_MEMTYPE_SYSTEM_MEMORY)
typedef struct QSVFrame {
    AVFrame          *frame;
    mfxFrameSurface1 *surface;
    mfxFrameSurface1  surface_internal;  /* for system memory */
    struct QSVFrame  *next;
} QSVFrame;
static mfxStatus frame_free(mfxHDL pthis, mfxFrameAllocResponse *resp)
{
    av_freep(&resp->mids);
    return MFX_ERR_NONE;
}
int ff_qsvvpp_free(QSVVPPContext **vpp)
{
    QSVVPPContext *s = *vpp;

    if (!s)
        return 0;

    if (s->session) {
        MFXVideoVPP_Close(s->session);
        MFXClose(s->session);
    }

    /* release all the resources */
    clear_frame_list(&s->in_frame_list);
    clear_frame_list(&s->out_frame_list);
    av_freep(&s->surface_ptrs_in);
    av_freep(&s->surface_ptrs_out);
    av_freep(&s->ext_buffers);
    av_freep(&s->frame_infos);
    av_freep(vpp);

    return 0;
}
