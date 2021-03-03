#include <mfx/mfxvideo.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_qsv.h"
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time.h"
#include "libavfilter/qsvvpp.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct QSVFrame {
    AVFrame *frame;
    mfxFrameSurface1 surface;
    int used;

    struct QSVFrame *next;
} QSVFrame;
typedef struct QSVDeintContext {
    const AVClass *class;

    AVBufferRef *hw_frames_ctx;
    /* a clone of the main session, used internally for deinterlacing */
    mfxSession   session;

    mfxMemId *mem_ids;
    int    nb_mem_ids;

    mfxFrameSurface1 **surface_ptrs;
    int             nb_surface_ptrs;

    mfxExtOpaqueSurfaceAlloc opaque_alloc;
    mfxExtVPPDeinterlacing   deint_conf;
    mfxExtBuffer            *ext_buffers[2];
    int                      num_ext_buffers;

    QSVFrame *work_frames;

    int64_t last_pts;

    int eof;

    /* option for Deinterlacing algorithm to be used */
    int mode;
} QSVDeintContext;
static mfxStatus frame_free(mfxHDL pthis, mfxFrameAllocResponse *resp)
{
    return MFX_ERR_NONE;
}
#define OFFSET(x) offsetof(QSVDeintContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
