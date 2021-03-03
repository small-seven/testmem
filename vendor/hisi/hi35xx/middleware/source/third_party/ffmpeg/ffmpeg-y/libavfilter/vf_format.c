#include <string.h>
#include "libavutil/internal.h"
#include "libavutil/mem.h"
#include "libavutil/pixdesc.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
#include "video.h"
typedef struct FormatContext {
    const AVClass *class;
    char *pix_fmts;

    /**
     * pix_fmts parsed into AVPixelFormats and terminated with
     * AV_PIX_FMT_NONE
     */
    enum AVPixelFormat *formats;
} FormatContext;
#define OFFSET(x) offsetof(FormatContext, x)
#if CONFIG_FORMAT_FILTER
#define format_options options
#endif /* CONFIG_FORMAT_FILTER */
#if CONFIG_NOFORMAT_FILTER
#define noformat_options options
#endif /* CONFIG_NOFORMAT_FILTER */
