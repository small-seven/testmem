#include "config.h"
#include "libavcodec/avfft.h"
#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "libavutil/xga_font_data.h"
#include "libavutil/eval.h"
#include "libavutil/pixdesc.h"
#include "libavutil/time.h"
#include "avfilter.h"
#include "internal.h"
#include "lavfutils.h"
#include "lswsutils.h"
#if CONFIG_LIBFREETYPE
#include <ft2build.h>
#include FT_FREETYPE_H
#endif
#if CONFIG_LIBFONTCONFIG
#include <fontconfig/fontconfig.h>
#endif
#include "avf_showcqt.h"
#define BASEFREQ        20.01523126408007475
#define ENDFREQ         20495.59681441799654
#define TLENGTH         "384*tc/(384+tc*f)"
#define TLENGTH_MIN     0.001
#define VOLUME_MAX      100.0
#define FONTCOLOR       "st(0, (midi(f)-59.5)/12);" \
#define CSCHEME         "1|0.5|0|0|0.5|1"
#define PTS_STEP 10
#define PTS_TOLERANCE 1
#define OFFSET(x) offsetof(ShowCQTContext, x)
#define FLAGS (AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM)
#if CONFIG_LIBFREETYPE
#else
#endif
#if CONFIG_LIBFONTCONFIG
#else
#endif
#define DRAW_BAR_WITH_CHROMA(x) \
#define DRAW_BAR_WITHOUT_CHROMA(x) \
#define BLEND_WITH_CHROMA(c) \
#define BLEND_WITHOUT_CHROMA(c, alpha_inc) \
#define BLEND_CHROMA2(c) \
#define BLEND_CHROMA2x2(c) \
#define UPDATE_TIME(t) \
