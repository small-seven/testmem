#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include "libavutil/pixdesc.h"
#include "libavutil/log.h"
#include "libavutil/mem.h"
#include "libavutil/opt.h"
#include "libavformat/avformat.h"
#include "fbdev_common.h"
#include "avdevice.h"
typedef struct {
    AVClass *class;                   ///< class for private options
    int xoffset;                      ///< x coordinate of top left corner
    int yoffset;                      ///< y coordinate of top left corner
    struct fb_var_screeninfo varinfo; ///< framebuffer variable info
    struct fb_fix_screeninfo fixinfo; ///< framebuffer fixed info
    int fd;                           ///< framebuffer device file descriptor
    uint8_t *data;                    ///< framebuffer data
} FBDevContext;
#define OFFSET(x) offsetof(FBDevContext, x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
