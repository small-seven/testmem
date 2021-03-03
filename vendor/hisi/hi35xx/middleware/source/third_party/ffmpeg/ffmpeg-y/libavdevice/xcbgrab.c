#include "config.h"
#include <stdlib.h>
#include <xcb/xcb.h>
#if CONFIG_LIBXCB_XFIXES
#include <xcb/xfixes.h>
#endif
#if CONFIG_LIBXCB_SHM
#include <sys/shm.h>
#include <xcb/shm.h>
#endif
#if CONFIG_LIBXCB_SHAPE
#include <xcb/shape.h>
#endif
#include "libavutil/internal.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/time.h"
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
typedef struct XCBGrabContext {
    const AVClass *class;

    uint8_t *buffer;

    xcb_connection_t *conn;
    xcb_screen_t *screen;
    xcb_window_t window;
#if CONFIG_LIBXCB_SHM
    xcb_shm_seg_t segment;
#endif
    int64_t time_frame;
    AVRational time_base;

    int x, y;
    int width, height;
    int frame_size;
    int bpp;

    int draw_mouse;
    int follow_mouse;
    int show_region;
    int region_border;
    int centered;

    const char *video_size;
    const char *framerate;

    int has_shm;
} XCBGrabContext;
#define FOLLOW_CENTER -1
#define OFFSET(x) offsetof(XCBGrabContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_LIBXCB_SHM
#endif /* CONFIG_LIBXCB_SHM */
#if CONFIG_LIBXCB_XFIXES
#define BLEND(target, source, alpha) \
#endif /* CONFIG_LIBXCB_XFIXES */
#if CONFIG_LIBXCB_SHM
#endif
#if CONFIG_LIBXCB_XFIXES
#endif
#if CONFIG_LIBXCB_SHM
#endif
#if CONFIG_LIBXCB_SHAPE
#endif
#if CONFIG_LIBXCB_SHM
#endif
#if CONFIG_LIBXCB_XFIXES
#endif
