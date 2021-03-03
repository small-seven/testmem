#include "libavutil/common.h"
#include "libavutil/frame.h"
#include "libavutil/lfg.h"
#include "libavutil/xga_font_data.h"
#include "avcodec.h"
#include "cga_data.h"
#include "internal.h"
#define ATTR_BOLD         0x01  /**< Bold/Bright-foreground (mode 1) */
#define ATTR_FAINT        0x02  /**< Faint (mode 2) */
#define ATTR_UNDERLINE    0x08  /**< Underline (mode 4) */
#define ATTR_BLINK        0x10  /**< Blink/Bright-background (mode 5) */
#define ATTR_REVERSE      0x40  /**< Reverse (mode 7) */
#define ATTR_CONCEALED    0x80  /**< Concealed (mode 8) */
#define DEFAULT_FG_COLOR     7  /**< CGA color index */
#define DEFAULT_BG_COLOR     0
#define DEFAULT_SCREEN_MODE  3  /**< 80x25 */
#define FONT_WIDTH           8  /**< Font width */
typedef struct AnsiContext {
    AVFrame *frame;
    int x;                /**< x cursor position (pixels) */
    int y;                /**< y cursor position (pixels) */
    int sx;               /**< saved x cursor position (pixels) */
    int sy;               /**< saved y cursor position (pixels) */
    const uint8_t* font;  /**< font */
    int font_height;      /**< font height */
    int attributes;       /**< attribute flags */
    int fg;               /**< foreground color */
    int bg;               /**< background color */
    int first_frame;

    /* ansi parser state machine */
    enum {
        STATE_NORMAL = 0,
        STATE_ESCAPE,
        STATE_CODE,
        STATE_MUSIC_PREAMBLE
    } state;
#define MAX_NB_ARGS 4
#define COLOR(x) ((x) * 40 + 55)
#define GRAY(x) ((x) * 10 + 8)
