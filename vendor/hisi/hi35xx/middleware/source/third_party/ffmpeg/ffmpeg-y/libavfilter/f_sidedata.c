#include "libavutil/avassert.h"
#include "libavutil/internal.h"
#include "libavutil/frame.h"
#include "libavutil/opt.h"
#include "avfilter.h"
#include "formats.h"
#include "internal.h"
typedef struct SideDataContext {
    const AVClass *class;

    int mode;
    enum AVFrameSideDataType type;
} SideDataContext;
#define OFFSET(x) offsetof(SideDataContext, x)
#if FF_API_FRAME_QP
#define DEFINE_OPTIONS(filt_name, FLAGS) \
#else
#define DEFINE_OPTIONS(filt_name, FLAGS) \
#endif
#if CONFIG_ASIDEDATA_FILTER
#endif /* CONFIG_ASIDEDATA_FILTER */
#if CONFIG_SIDEDATA_FILTER
#endif /* CONFIG_SIDEDATA_FILTER */
