#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <time.h>
#include <linux/fb.h>
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixdesc.h"
#include "libavformat/internal.h"
#include "avdevice.h"
#include "fbdev_common.h"
typedef struct FBDevContext {
    AVClass *class;          ///< class for private options
    int frame_size;          ///< size in bytes of a grabbed frame
    AVRational framerate_q;  ///< framerate
    int64_t time_frame;      ///< time for the next frame to output (in 1/1000000 units)

    int fd;                  ///< framebuffer device file descriptor
    int width, height;       ///< assumed frame resolution
    int frame_linesize;      ///< linesize of the output frame, it is assumed to be constant
    int bytes_per_pixel;

    struct fb_var_screeninfo varinfo; ///< variable info;
    struct fb_fix_screeninfo fixinfo; ///< fixed    info;

    uint8_t *data;           ///< framebuffer data
} FBDevContext;
#define OFFSET(x) offsetof(FBDevContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
