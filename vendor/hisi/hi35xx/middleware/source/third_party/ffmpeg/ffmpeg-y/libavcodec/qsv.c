#include <mfx/mfxvideo.h>
#include <mfx/mfxplugin.h>
#include <mfx/mfxjpeg.h>
#include <stdio.h>
#include <string.h>
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/error.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_qsv.h"
#include "libavutil/imgutils.h"
#include "libavutil/avassert.h"
#include "avcodec.h"
#include "qsv_internal.h"
#if QSV_VERSION_ATLEAST(1, 12)
#include "mfx/mfxvp8.h"
#endif
#if QSV_VERSION_ATLEAST(1, 8)
#endif
#if QSV_VERSION_ATLEAST(1, 12)
#endif
#define MAP(c, p, v) { AV_CODEC_ID_ ## c, FF_PROFILE_ ## p, MFX_PROFILE_ ## v }
#if QSV_VERSION_ATLEAST(1, 3)
#endif
#if QSV_VERSION_ATLEAST(1, 8)
#endif
#if QSV_VERSION_ATLEAST(1, 16)
#endif
#undef MAP
static void mids_buf_free(void *opaque, uint8_t *data)
{
    AVBufferRef *hw_frames_ref = opaque;
    av_buffer_unref(&hw_frames_ref);
    av_freep(&data);
}
static mfxStatus qsv_frame_free(mfxHDL pthis, mfxFrameAllocResponse *resp)
{
    av_buffer_unref((AVBufferRef**)&resp->mids[resp->NumFrameActual]);
    av_buffer_unref((AVBufferRef**)&resp->mids[resp->NumFrameActual + 1]);
    av_freep(&resp->mids);
    return MFX_ERR_NONE;
}
