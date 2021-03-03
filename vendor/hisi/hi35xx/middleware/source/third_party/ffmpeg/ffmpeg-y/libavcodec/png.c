#include "avcodec.h"
#include "png.h"
void *ff_png_zalloc(void *opaque, unsigned int items, unsigned int size)
{
    return av_mallocz_array(items, size);
}
void ff_png_zfree(void *opaque, void *ptr)
{
    av_free(ptr);
}
