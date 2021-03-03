#include <caca.h>
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "avdevice.h"
typedef struct CACAContext {
    AVClass         *class;
    AVFormatContext *ctx;
    char            *window_title;
    int             window_width,  window_height;

    caca_canvas_t   *canvas;
    caca_display_t  *display;
    caca_dither_t   *dither;

    char            *algorithm, *antialias;
    char            *charset, *color;
    char            *driver;

    char            *list_dither;
    int             list_drivers;
} CACAContext;
#define DEFINE_LIST_DITHER(thing, thing_str)                                 \
#define CHECK_DITHER_OPT(opt) do {                                              \
#define OFFSET(x) offsetof(CACAContext,x)
#define ENC AV_OPT_FLAG_ENCODING_PARAM
