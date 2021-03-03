#include "libavutil/intreadwrite.h"
#include "libavutil/xga_font_data.h"
#include "avcodec.h"
#include "cga_data.h"
#include "bintext.h"
#include "internal.h"
#define FONT_WIDTH 8
typedef struct XbinContext {
    AVFrame *frame;
    int palette[16];
    int flags;
    int font_height;
    const uint8_t *font;
    int x, y;
} XbinContext;
#define DEFAULT_BG_COLOR 0
#if CONFIG_BINTEXT_DECODER
#endif
#if CONFIG_XBIN_DECODER
#endif
#if CONFIG_IDF_DECODER
#endif
