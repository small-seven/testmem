#include <dav1d/dav1d.h>
#include "libavutil/avassert.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "decode.h"
#include "internal.h"
typedef struct Libdav1dContext {
    AVClass *class;
    Dav1dContext *c;
    AVBufferPool *pool;
    int pool_size;

    Dav1dData data;
    int tile_threads;
    int frame_threads;
    int apply_grain;
} Libdav1dContext;
static int libdav1d_picture_allocator(Dav1dPicture *p, void *cookie)
{
    Libdav1dContext *dav1d = cookie;
    enum AVPixelFormat format = pix_fmt[p->p.layout][p->seq_hdr->hbd];
    int ret, linesize[4], h = FFALIGN(p->p.h, 128);
    uint8_t *aligned_ptr, *data[4];
    AVBufferRef *buf;

    ret = av_image_fill_arrays(data, linesize, NULL, format, FFALIGN(p->p.w, 128),
                               h, DAV1D_PICTURE_ALIGNMENT);
    if (ret < 0)
        return ret;

    if (ret != dav1d->pool_size) {
        av_buffer_pool_uninit(&dav1d->pool);
        // Use twice the amount of required padding bytes for aligned_ptr below.
        dav1d->pool = av_buffer_pool_init(ret + DAV1D_PICTURE_ALIGNMENT * 2, NULL);
        if (!dav1d->pool) {
            dav1d->pool_size = 0;
            return AVERROR(ENOMEM);
        }
        dav1d->pool_size = ret;
    }
    buf = av_buffer_pool_get(dav1d->pool);
    if (!buf)
        return AVERROR(ENOMEM);

    // libdav1d requires DAV1D_PICTURE_ALIGNMENT aligned buffers, which av_malloc()
    // doesn't guarantee for example when AVX is disabled at configure time.
    // Use the extra DAV1D_PICTURE_ALIGNMENT padding bytes in the buffer to align it
    // if required.
    aligned_ptr = (uint8_t *)FFALIGN((uintptr_t)buf->data, DAV1D_PICTURE_ALIGNMENT);
    ret = av_image_fill_pointers(data, format, h, aligned_ptr, linesize);
    if (ret < 0) {
        av_buffer_unref(&buf);
        return ret;
    }

    p->data[0] = data[0];
    p->data[1] = data[1];
    p->data[2] = data[2];
    p->stride[0] = linesize[0];
    p->stride[1] = linesize[1];
    p->allocator_data = buf;

    return 0;
}
#if FF_API_PKT_PTS
#endif
#define OFFSET(x) offsetof(Libdav1dContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
