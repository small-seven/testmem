#include "libavutil/mathematics.h"
#include "libavutil/tree.h"
#include "nut.h"
#include "riff.h"
#include "internal.h"
static int enu_free(void *opaque, void *elem)
{
    av_free(elem);
    return 0;
}
