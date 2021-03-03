#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "me_cmp.h"
#include "snow_dwt.h"
void ff_slice_buffer_destroy(slice_buffer *buf)
{
    int i;
    ff_slice_buffer_flush(buf);

    if (buf->data_stack)
        for (i = buf->data_count - 1; i >= 0; i--)
            av_freep(&buf->data_stack[i]);
    av_freep(&buf->data_stack);
    av_freep(&buf->line);
}
#define LIFT(src, ref, inv) ((src) + ((inv) ? -(ref) : +(ref)))
#define LIFTS(src, ref, inv)                                            \
