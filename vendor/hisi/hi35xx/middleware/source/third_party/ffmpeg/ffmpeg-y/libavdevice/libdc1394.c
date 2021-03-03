#include <dc1394/dc1394.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
typedef struct dc1394_data {
    AVClass *class;
    dc1394_t *d;
    dc1394camera_t *camera;
    dc1394video_frame_t *frame;
    int current_frame;
    int  frame_rate;        /**< frames per 1000 seconds (fps * 1000) */
    char *video_size;       /**< String describing video size, set by a private option. */
    char *pixel_format;     /**< Set by a private option. */
    char *framerate;        /**< Set by a private option. */

    int size;
    int stream_index;
} dc1394_data;
#define OFFSET(x) offsetof(dc1394_data, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
