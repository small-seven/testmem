#include "avcodec.h"
#include "libavcodec/ass.h"
#include "libavcodec/dvbtxt.h"
#include "libavutil/opt.h"
#include "libavutil/bprint.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/common.h"
#include <libzvbi.h>
#define TEXT_MAXSZ    (25 * (56 + 1) * 4 + 2)
#define VBI_NB_COLORS 40
#define VBI_TRANSPARENT_BLACK 8
#define RGBA(r,g,b,a) (((a) << 24) | ((r) << 16) | ((g) << 8) | (b))
#define VBI_R(rgba)   (((rgba) >> 0) & 0xFF)
#define VBI_G(rgba)   (((rgba) >> 8) & 0xFF)
#define VBI_B(rgba)   (((rgba) >> 16) & 0xFF)
#define VBI_A(rgba)   (((rgba) >> 24) & 0xFF)
#define MAX_BUFFERED_PAGES 25
#define BITMAP_CHAR_WIDTH  12
#define BITMAP_CHAR_HEIGHT 10
#define MAX_SLICES 64
typedef struct TeletextPage
{
    AVSubtitleRect *sub_rect;
    int pgno;
    int subno;
    int64_t pts;
} TeletextPage;
typedef struct TeletextContext
{
    AVClass        *class;
    char           *pgno;
    int             x_offset;
    int             y_offset;
    int             format_id; /* 0 = bitmap, 1 = text/ass, 2 = ass */
    int             chop_top;
    int             sub_duration; /* in msec */
    int             transparent_bg;
    int             opacity;
    int             chop_spaces;

    int             lines_processed;
    TeletextPage    *pages;
    int             nb_pages;
    int64_t         pts;
    int             handler_ret;

    vbi_decoder *   vbi;
    vbi_sliced      sliced[MAX_SLICES];

    int             readorder;
    uint8_t         subtitle_map[2048];
    int             last_pgno;
    int             last_p5;
    int             last_ass_alignment;
} TeletextContext;
static void subtitle_rect_free(AVSubtitleRect **sub_rect)
{
    av_freep(&(*sub_rect)->data[0]);
    av_freep(&(*sub_rect)->data[1]);
    av_freep(&(*sub_rect)->ass);
    av_freep(sub_rect);
}
#define IS_TXT_SPACE(ch) ((ch).unicode < 0x0020 || (ch).unicode >= 0xe000 || (ch).unicode == 0x00a0 ||\
#if FF_API_AVPICTURE
#endif
#define OFFSET(x) offsetof(TeletextContext, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_DECODING_PARAM
