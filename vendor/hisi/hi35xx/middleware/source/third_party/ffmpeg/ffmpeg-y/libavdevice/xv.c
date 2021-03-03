#include <X11/Xlib.h>
#include <X11/extensions/Xv.h>
#include <X11/extensions/XShm.h>
#include <X11/extensions/Xvlib.h>
#include <sys/shm.h>
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavformat/internal.h"
#include "avdevice.h"
typedef struct {
    AVClass *class;
    GC gc;

    Window window;
    int64_t window_id;
    char *window_title;
    int window_width, window_height;
    int window_x, window_y;
    int dest_x, dest_y;          /**< display area position */
    unsigned int dest_w, dest_h; /**< display area dimensions */

    Display* display;
    char *display_name;

    XvImage* yuv_image;
    enum AVPixelFormat image_format;
    int image_width, image_height;
    XShmSegmentInfo yuv_shminfo;
    int xv_port;
    Atom wm_delete_message;
} XVContext;
typedef struct XVTagFormatMap
{
    int tag;
    enum AVPixelFormat format;
} XVTagFormatMap;
#define OFFSET(x) offsetof(XVContext, x)
