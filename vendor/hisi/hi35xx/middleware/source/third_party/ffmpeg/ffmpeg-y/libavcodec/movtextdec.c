#include "avcodec.h"
#include "ass.h"
#include "libavutil/avstring.h"
#include "libavutil/common.h"
#include "libavutil/bprint.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#define STYLE_FLAG_BOLD         (1<<0)
#define STYLE_FLAG_ITALIC       (1<<1)
#define STYLE_FLAG_UNDERLINE    (1<<2)
#define BOX_SIZE_INITIAL    40
#define STYL_BOX   (1<<0)
#define HLIT_BOX   (1<<1)
#define HCLR_BOX   (1<<2)
#define TWRP_BOX   (1<<3)
#define BOTTOM_LEFT     1
#define BOTTOM_CENTER   2
#define BOTTOM_RIGHT    3
#define MIDDLE_LEFT     4
#define MIDDLE_CENTER   5
#define MIDDLE_RIGHT    6
#define TOP_LEFT        7
#define TOP_CENTER      8
#define TOP_RIGHT       9
typedef struct {
    char *font;
    int fontsize;
    int color;
    int back_color;
    int bold;
    int italic;
    int underline;
    int alignment;
} MovTextDefault;
typedef struct {
    uint16_t fontID;
    char *font;
} FontRecord;
typedef struct {
    uint16_t style_start;
    uint16_t style_end;
    uint8_t style_flag;
    uint8_t fontsize;
    uint16_t style_fontID;
} StyleBox;
typedef struct {
    uint16_t hlit_start;
    uint16_t hlit_end;
} HighlightBox;
typedef struct {
   uint8_t hlit_color[4];
} HilightcolorBox;
typedef struct {
    uint8_t wrap_flag;
} TextWrapBox;
typedef struct {
    StyleBox **s;
    StyleBox *s_temp;
    HighlightBox h;
    HilightcolorBox c;
    FontRecord **ftab;
    FontRecord *ftab_temp;
    TextWrapBox w;
    MovTextDefault d;
    uint8_t box_flags;
    uint16_t style_entries, ftab_entries;
    uint64_t tracksize;
    int size_var;
    int count_s, count_f;
    int readorder;
} MovTextContext;
typedef struct {
    uint32_t type;
    size_t base_size;
    int (*decode)(const uint8_t *tsmb, MovTextContext *m, AVPacket *avpkt);
} Box;
