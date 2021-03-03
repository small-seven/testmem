#include "avcodec.h"
#include "ass.h"
#include "libavutil/bprint.h"
#include "libavutil/opt.h"
typedef struct {
    AVClass *class;
    const char *linebreaks;
    int keep_ass_markup;
    int readorder;
} TextContext;
#define OFFSET(x) offsetof(TextContext, x)
#define SD AV_OPT_FLAG_SUBTITLE_PARAM | AV_OPT_FLAG_DECODING_PARAM
#define DECLARE_CLASS(decname) static const AVClass decname ## _decoder_class = {   \
#if CONFIG_TEXT_DECODER
#define text_options options
#endif
#if CONFIG_VPLAYER_DECODER || CONFIG_PJS_DECODER || CONFIG_SUBVIEWER1_DECODER || CONFIG_STL_DECODER
#if CONFIG_VPLAYER_DECODER
#define vplayer_options options
#endif
#if CONFIG_STL_DECODER
#define stl_options options
#endif
#if CONFIG_PJS_DECODER
#define pjs_options options
#endif
#if CONFIG_SUBVIEWER1_DECODER
#define subviewer1_options options
#endif
#endif /* text subtitles with '|' line break */
