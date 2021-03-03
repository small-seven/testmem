#include "libavutil/avassert.h"
#include "framequeue.h"
#if defined(ASSERT_LEVEL) && ASSERT_LEVEL >= 2
#endif
void ff_framequeue_free(FFFrameQueue *fq)
{
    while (fq->queued) {
        AVFrame *frame = ff_framequeue_take(fq);
        av_frame_free(&frame);
    }
    if (fq->queue != &fq->first_bucket)
        av_freep(&fq->queue);
}
