#include "channel_layout.h"
#include "avassert.h"
#include "buffer.h"
#include "common.h"
#include "dict.h"
#include "frame.h"
#include "imgutils.h"
#include "mem.h"
#include "samplefmt.h"
#if FF_API_FRAME_GET_SET
#endif
#define CHECK_CHANNELS_CONSISTENCY(frame) \
#if FF_API_FRAME_QP
#endif
#if FF_API_PKT_PTS
#endif
void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}
#if FF_API_PKT_PTS
#endif
#if FF_API_ERROR_FRAME
#endif
#if FF_API_FRAME_QP
#endif
#if FF_API_FRAME_QP
#endif
#if FF_API_FRAME_QP
#endif
