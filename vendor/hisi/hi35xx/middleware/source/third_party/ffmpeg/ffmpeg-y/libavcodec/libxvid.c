#include <stdio.h>
#include <string.h>
#include <xvid.h>
#include "libavutil/avassert.h"
#include "libavutil/cpu.h"
#include "libavutil/file.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "libxvid.h"
#include "mpegutils.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_IO_H
#include <io.h>
#endif
#define BUFFER_SIZE         1024
#define BUFFER_REMAINING(x) (BUFFER_SIZE - strlen(x))
#define BUFFER_CAT(x)       (&((x)[strlen(x)]))
static int xvid_ff_2pass_destroy(struct xvid_context *ref,
                                 xvid_plg_destroy_t *param)
{
    /* Currently cannot think of anything to do on destruction */
    /* Still, the framework should be here for reference/use */
    if (ref->twopassbuffer)
        ref->twopassbuffer[0] = 0;
    return 0;
}
#if (XVID_VERSION <= 0x010303) && (XVID_VERSION >= 0x010300)
#endif
#if FF_API_PRIVATE_OPT
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#if FF_API_CODED_FRAME
#endif
#define OFFSET(x) offsetof(struct xvid_context, x)
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
