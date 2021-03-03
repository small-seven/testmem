#include <float.h>
#include "libavutil/avassert.h"
#include "libavutil/common.h"
#include "libavutil/ffmath.h"
#include "libavutil/opt.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/parseutils.h"
#include "libavutil/xga_font_data.h"
#include "avfilter.h"
#include "drawutils.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct TestSourceContext {
    const AVClass *class;
    int w, h;
    unsigned int nb_frame;
    AVRational time_base, frame_rate;
    int64_t pts;
    int64_t duration;           ///< duration expressed in microseconds
    AVRational sar;             ///< sample aspect ratio
    int draw_once;              ///< draw only the first frame, always put out the same picture
    int draw_once_reset;        ///< draw only the first frame or in case of reset
    AVFrame *picref;            ///< cached reference containing the painted picture

    void (* fill_picture_fn)(AVFilterContext *ctx, AVFrame *frame);

    /* only used by testsrc */
    int nb_decimals;

    /* only used by testsrc2 */
    int alpha;

    /* only used by color */
    FFDrawContext draw;
    FFDrawColor color;
    uint8_t color_rgba[4];

    /* only used by rgbtest */
    uint8_t rgba_map[4];

    /* only used by haldclut */
    int level;
} TestSourceContext;
#define OFFSET(x) offsetof(TestSourceContext, x)
#define FLAGS AV_OPT_FLAG_VIDEO_PARAM|AV_OPT_FLAG_FILTERING_PARAM
#define SIZE_OPTIONS \
#define COMMON_OPTIONS_NOSIZE \
#define COMMON_OPTIONS SIZE_OPTIONS COMMON_OPTIONS_NOSIZE
#if CONFIG_COLOR_FILTER
#endif /* CONFIG_COLOR_FILTER */
#if CONFIG_HALDCLUTSRC_FILTER
#define LOAD_CLUT(nbits) do {                                                   \
#endif /* CONFIG_HALDCLUTSRC_FILTER */
#if CONFIG_NULLSRC_FILTER
#define nullsrc_options options
#endif /* CONFIG_NULLSRC_FILTER */
#if CONFIG_TESTSRC_FILTER
#define TOP_HBAR        1
#define MID_HBAR        2
#define BOT_HBAR        4
#define LEFT_TOP_VBAR   8
#define LEFT_BOT_VBAR  16
#define RIGHT_TOP_VBAR 32
#define RIGHT_BOT_VBAR 64
#define GRADIENT_SIZE (6 * 256)
#endif /* CONFIG_TESTSRC_FILTER */
#if CONFIG_TESTSRC2_FILTER
#endif /* CONFIG_TESTSRC2_FILTER */
#if CONFIG_RGBTESTSRC_FILTER
#define rgbtestsrc_options options
#define R 0
#define G 1
#define B 2
#define A 3
#endif /* CONFIG_RGBTESTSRC_FILTER */
#if CONFIG_YUVTESTSRC_FILTER
#define yuvtestsrc_options options
#endif /* CONFIG_YUVTESTSRC_FILTER */
#if CONFIG_PAL75BARS_FILTER || CONFIG_PAL100BARS_FILTER || CONFIG_SMPTEBARS_FILTER || CONFIG_SMPTEHDBARS_FILTER
#if CONFIG_PAL75BARS_FILTER
#define pal75bars_options options
#endif  /* CONFIG_PAL75BARS_FILTER */
#if CONFIG_PAL100BARS_FILTER
#define pal100bars_options options
#endif  /* CONFIG_PAL100BARS_FILTER */
#if CONFIG_SMPTEBARS_FILTER
#define smptebars_options options
#endif  /* CONFIG_SMPTEBARS_FILTER */
#if CONFIG_SMPTEHDBARS_FILTER
#define smptehdbars_options options
#endif  /* CONFIG_SMPTEHDBARS_FILTER */
#endif  /* CONFIG_SMPTEBARS_FILTER || CONFIG_SMPTEHDBARS_FILTER */
#if CONFIG_ALLYUV_FILTER
#endif /* CONFIG_ALLYUV_FILTER */
#if CONFIG_ALLRGB_FILTER
#endif /* CONFIG_ALLRGB_FILTER */
