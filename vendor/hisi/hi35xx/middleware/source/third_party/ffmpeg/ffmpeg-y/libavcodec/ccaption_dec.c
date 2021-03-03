#include "avcodec.h"
#include "ass.h"
#include "libavutil/opt.h"
#define SCREEN_ROWS 15
#define SCREEN_COLUMNS 32
#define SET_FLAG(var, val)   ( (var) |=   ( 1 << (val)) )
#define UNSET_FLAG(var, val) ( (var) &=  ~( 1 << (val)) )
#define CHECK_FLAG(var, val) ( (var) &    ( 1 << (val)) )
typedef struct CCaptionSubContext {
    AVClass *class;
    int real_time;
    struct Screen screen[2];
    int active_screen;
    uint8_t cursor_row;
    uint8_t cursor_column;
    uint8_t cursor_color;
    uint8_t cursor_font;
    uint8_t cursor_charset;
    AVBPrint buffer;
    int buffer_changed;
    int rollup;
    enum cc_mode mode;
    int64_t start_time;
    /* visible screen time */
    int64_t startv_time;
    int64_t end_time;
    int screen_touched;
    int64_t last_real_time;
    char prev_cmd[2];
    /* buffer to store pkt data */
    uint8_t *pktbuf;
    int pktbuf_size;
    int readorder;
} CCaptionSubContext;
#define OFFSET(x) offsetof(CCaptionSubContext, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_DECODING_PARAM
