#include "avcodec.h"
#include "internal.h"
#include "libavutil/common.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/colorspace.h"
#if FF_API_AVPICTURE
void avpicture_free(AVPicture *picture)
{
    av_freep(&picture->data[0]);
}
#endif /* FF_API_AVPICTURE */
