#include "config.h"
#include "libavformat/internal.h"
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include <windows.h>
#define WIN32_API_ERROR(str)                                            \
#define REGION_WND_BORDER 3
gdigrab_region_wnd_destroy(AVFormatContext *s1, struct gdigrab *gdigrab)
{
    if (gdigrab->region_hwnd)
        DestroyWindow(gdigrab->region_hwnd);
    gdigrab->region_hwnd = NULL;
}
#define CURSOR_ERROR(str)                 \
#define OFFSET(x) offsetof(struct gdigrab, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
