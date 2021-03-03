#include "avcodec.h"
#include "internal.h"
#include "pthread_internal.h"
#include "thread.h"
void ff_thread_free(AVCodecContext *avctx)
{
    if (avctx->active_thread_type&FF_THREAD_FRAME)
        ff_frame_thread_free(avctx, avctx->thread_count);
    else
        ff_slice_thread_free(avctx);
}
