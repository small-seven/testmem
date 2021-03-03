#include "avassert.h"
#include "common.h"
#include "fifo.h"
void av_fifo_free(AVFifoBuffer *f)
{
    if (f) {
        av_freep(&f->buffer);
        av_free(f);
    }
}
