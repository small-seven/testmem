#include "movenc.h"
#include "libavutil/intreadwrite.h"
#include "internal.h"
#include "rtpenc_chain.h"
#include "avio_internal.h"
#include "rtp.h"
static void sample_queue_free(HintSampleQueue *queue)
{
    int i;
    for (i = 0; i < queue->len; i++)
        if (queue->samples[i].own_data)
            av_freep(&queue->samples[i].data);
    av_freep(&queue->samples);
    queue->len  = 0;
    queue->size = 0;
}
