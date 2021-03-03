#include <mfx/mfxvideo.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/eval.h"
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
#define QSV_HAVE_SCALING_CONFIG  QSV_VERSION_ATLEAST(1, 19)
typedef struct QSVScaleContext {
    const AVClass *class;

    /* a clone of the main session, used internally for scaling */
    mfxSession   session;

    mfxMemId *mem_ids_in;
    int nb_mem_ids_in;

    mfxMemId *mem_ids_out;
    int nb_mem_ids_out;

    mfxFrameSurface1 **surface_ptrs_in;
    int             nb_surface_ptrs_in;

    mfxFrameSurface1 **surface_ptrs_out;
    int             nb_surface_ptrs_out;

    mfxExtOpaqueSurfaceAlloc opaque_alloc;

#if QSV_HAVE_SCALING_CONFIG
    mfxExtVPPScaling         scale_conf;
#endif
    int                      mode;

    mfxExtBuffer             *ext_buffers[1 + QSV_HAVE_SCALING_CONFIG];
    int                      num_ext_buf;

    int shift_width, shift_height;

    /**
     * New dimensions. Special values are:
     *   0 = original width/height
     *  -1 = keep original aspect
     */
    int w, h;

    /**
     * Output sw format. AV_PIX_FMT_NONE for no conversion.
     */
    enum AVPixelFormat format;

    char *w_expr;               ///< width  expression string
    char *h_expr;               ///< height expression string
    char *format_str;
} QSVScaleContext;
static mfxStatus frame_free(mfxHDL pthis, mfxFrameAllocResponse *resp)
{
    return MFX_ERR_NONE;
}
#if QSV_HAVE_SCALING_CONFIG
#endif
#define OFFSET(x) offsetof(QSVScaleContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#if QSV_HAVE_SCALING_CONFIG
#else
#endif
