#include "libavutil/common.h"
#include "libavutil/mem.h"
#include "timefilter.h"
void ff_timefilter_destroy(TimeFilter *self)
{
    av_freep(&self);
}
