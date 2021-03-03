#include <stdarg.h>
#include "avcodec.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "libavutil/common.h"
#include "ass_split.h"
#include "ass.h"
#define STYLE_FLAG_BOLD         (1<<0)
#define STYLE_FLAG_ITALIC       (1<<1)
#define STYLE_FLAG_UNDERLINE    (1<<2)
#define STYLE_RECORD_SIZE       12
#define SIZE_ADD                10
#define STYL_BOX   (1<<0)
#define HLIT_BOX   (1<<1)
#define HCLR_BOX   (1<<2)
#define av_bprint_append_any(buf, data, size)   av_bprint_append_data(buf, ((const char*)data), size)
typedef struct {
    uint16_t style_start;
    uint16_t style_end;
    uint8_t style_flag;
} StyleBox;
typedef struct {
    uint16_t start;
    uint16_t end;
} HighlightBox;
typedef struct {
   uint32_t color;
} HilightcolorBox;
typedef struct {
    AVCodecContext *avctx;

    ASSSplitContext *ass_ctx;
    AVBPrint buffer;
    StyleBox **style_attributes;
    StyleBox *style_attributes_temp;
    HighlightBox hlit;
    HilightcolorBox hclr;
    int count;
    uint8_t box_flags;
    uint16_t style_entries;
    uint16_t style_fontID;
    uint8_t style_fontsize;
    uint32_t style_color;
    uint16_t text_pos;
    uint16_t byte_count;
} MovTextContext;
typedef struct {
    uint32_t type;
    void (*encode)(MovTextContext *s, uint32_t tsmb_type);
} Box;
#if FF_API_ASS_TIMING
#endif
#if FF_API_ASS_TIMING
#endif
