#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "audio_frame_queue.h"
#include "internal.h"
#include "libavutil/avassert.h"
void ff_af_queue_remove(AudioFrameQueue *afq, int nb_samples, int64_t *pts,
                        int64_t *duration)
{
    int64_t out_pts = AV_NOPTS_VALUE;
    int removed_samples = 0;
    int i;

    if (afq->frame_count || afq->frame_alloc) {
        if (afq->frames->pts != AV_NOPTS_VALUE)
            out_pts = afq->frames->pts;
    }
    if(!afq->frame_count)
        av_log(afq->avctx, AV_LOG_WARNING, "Trying to remove %d samples, but the queue is empty\n", nb_samples);
    if (pts)
        *pts = ff_samples_to_time_base(afq->avctx, out_pts);

    for(i=0; nb_samples && i<afq->frame_count; i++){
        int n= FFMIN(afq->frames[i].duration, nb_samples);
        afq->frames[i].duration -= n;
        nb_samples              -= n;
        removed_samples         += n;
        if(afq->frames[i].pts != AV_NOPTS_VALUE)
            afq->frames[i].pts      += n;
    }
    afq->remaining_samples -= removed_samples;
    i -= i && afq->frames[i-1].duration;
    memmove(afq->frames, afq->frames + i, sizeof(*afq->frames) * (afq->frame_count - i));
    afq->frame_count -= i;

    if(nb_samples){
        av_assert0(!afq->frame_count);
        av_assert0(afq->remaining_samples == afq->remaining_delay);
        if(afq->frames && afq->frames[0].pts != AV_NOPTS_VALUE)
            afq->frames[0].pts += nb_samples;
        av_log(afq->avctx, AV_LOG_DEBUG, "Trying to remove %d more samples than there are in the queue\n", nb_samples);
    }
    if (duration)
        *duration = ff_samples_to_time_base(afq->avctx, removed_samples);
}
