#include "config.h"
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <fenv.h>
#if CONFIG_LIBFONTCONFIG
#include <fontconfig/fontconfig.h>
#endif
#include "libavutil/avstring.h"
#include "libavutil/bprint.h"
#include "libavutil/common.h"
#include "libavutil/file.h"
#include "libavutil/eval.h"
#include "libavutil/opt.h"
#include "libavutil/random_seed.h"
#include "libavutil/parseutils.h"
#include "libavutil/timecode.h"
#include "libavutil/time_internal.h"
#include "libavutil/tree.h"
#include "libavutil/lfg.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
#if CONFIG_LIBFRIBIDI
#include <fribidi.h>
#endif
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include FT_STROKER_H
typedef double (*eval_func2)(void *, double a, double b);

static const eval_func2 fun2[] = {
    drand,
    NULL
};
typedef struct DrawTextContext {
    const AVClass *class;
    int exp_mode;                   ///< expansion mode to use for the text
    int reinit;                     ///< tells if the filter is being reinited
#if CONFIG_LIBFONTCONFIG
    uint8_t *font;              ///< font to be used
#endif
    uint8_t *fontfile;              ///< font to be used
    uint8_t *text;                  ///< text to be drawn
    AVBPrint expanded_text;         ///< used to contain the expanded text
    uint8_t *fontcolor_expr;        ///< fontcolor expression to evaluate
    AVBPrint expanded_fontcolor;    ///< used to contain the expanded fontcolor spec
    int ft_load_flags;              ///< flags used for loading fonts, see FT_LOAD_*
    FT_Vector *positions;           ///< positions for each element in the text
    size_t nb_positions;            ///< number of elements of positions array
    char *textfile;                 ///< file with text to be drawn
    int x;                          ///< x position to start drawing text
    int y;                          ///< y position to start drawing text
    int max_glyph_w;                ///< max glyph width
    int max_glyph_h;                ///< max glyph height
    int shadowx, shadowy;
    int borderw;                    ///< border width
    char *fontsize_expr;            ///< expression for fontsize
    AVExpr *fontsize_pexpr;         ///< parsed expressions for fontsize
    unsigned int fontsize;          ///< font size to use
    unsigned int default_fontsize;  ///< default font size to use

    int line_spacing;               ///< lines spacing in pixels
    short int draw_box;             ///< draw box around text - true or false
    int boxborderw;                 ///< box border width
    int use_kerning;                ///< font kerning is used - true/false
    int tabsize;                    ///< tab size
    int fix_bounds;                 ///< do we let it go out of frame bounds - t/f

    FFDrawContext dc;
    FFDrawColor fontcolor;          ///< foreground color
    FFDrawColor shadowcolor;        ///< shadow color
    FFDrawColor bordercolor;        ///< border color
    FFDrawColor boxcolor;           ///< background color

    FT_Library library;             ///< freetype font library handle
    FT_Face face;                   ///< freetype font face handle
    FT_Stroker stroker;             ///< freetype stroker handle
    struct AVTreeNode *glyphs;      ///< rendered glyphs, stored using the UTF-32 char code
    char *x_expr;                   ///< expression for x position
    char *y_expr;                   ///< expression for y position
    AVExpr *x_pexpr, *y_pexpr;      ///< parsed expressions for x and y
    int64_t basetime;               ///< base pts time in the real world for display
    double var_values[VAR_VARS_NB];
    char   *a_expr;
    AVExpr *a_pexpr;
    int alpha;
    AVLFG  prng;                    ///< random
    char       *tc_opt_string;      ///< specified timecode option string
    AVRational  tc_rate;            ///< frame rate for timecode
    AVTimecode  tc;                 ///< timecode context
    int tc24hmax;                   ///< 1 if timecode is wrapped to 24 hours, 0 otherwise
    int reload;                     ///< reload text file for each frame
    int start_number;               ///< starting frame number for n/frame_num var
#if CONFIG_LIBFRIBIDI
    int text_shaping;               ///< 1 to shape the text before drawing it
#endif
    AVDictionary *metadata;
} DrawTextContext;
#define OFFSET(x) offsetof(DrawTextContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#if CONFIG_LIBFONTCONFIG
#endif
#if CONFIG_LIBFRIBIDI
#endif
#undef __FTERRORS_H__
#define FT_ERROR_START_LIST {
#define FT_ERRORDEF(e, v, s) { (e), (s) },
#define FT_ERROR_END_LIST { 0, NULL } };
#include FT_ERRORS_H
#define FT_ERRMSG(e) ft_errors[e].err_msg
typedef struct Glyph {
    FT_Glyph glyph;
    FT_Glyph border_glyph;
    uint32_t code;
    unsigned int fontsize;
    FT_Bitmap bitmap; ///< array holding bitmaps of font
    FT_Bitmap border_bitmap; ///< array holding bitmaps of font border
    FT_BBox bbox;
    int advance;
    int bitmap_left;
    int bitmap_top;
} Glyph;
#if !CONFIG_LIBFONTCONFIG
#endif
#if CONFIG_LIBFONTCONFIG
#endif
#if CONFIG_LIBFONTCONFIG
#endif
#if CONFIG_LIBFRIBIDI
#endif
#if CONFIG_LIBFRIBIDI
#endif
static int glyph_enu_free(void *opaque, void *elem)
{
    Glyph *glyph = elem;

    FT_Done_Glyph(glyph->glyph);
    FT_Done_Glyph(glyph->border_glyph);
    av_free(elem);
    return 0;
}
#if CONFIG_LIBFRIBIDI
#endif
