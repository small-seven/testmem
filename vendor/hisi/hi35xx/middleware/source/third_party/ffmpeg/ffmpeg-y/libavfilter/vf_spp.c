#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/opt.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#include "vf_spp.h"
#define OFFSET(x) offsetof(SPPContext, x)
#define FLAGS AV_OPT_FLAG_FILTERING_PARAM|AV_OPT_FLAG_VIDEO_PARAM
#define STORE(pos) do {                                                     \
#define STORE16(pos) do {                                                   \
