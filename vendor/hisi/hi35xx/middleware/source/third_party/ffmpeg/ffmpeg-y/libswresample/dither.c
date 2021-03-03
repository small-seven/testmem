#include "libavutil/avassert.h"
#include "swresample_internal.h"
#include "noise_shaping_data.c"
#define TMP_EXTRA 2
#define TEMPLATE_DITHER_S16
#include "dither_template.c"
#undef TEMPLATE_DITHER_S16
#define TEMPLATE_DITHER_S32
#include "dither_template.c"
#undef TEMPLATE_DITHER_S32
#define TEMPLATE_DITHER_FLT
#include "dither_template.c"
#undef TEMPLATE_DITHER_FLT
#define TEMPLATE_DITHER_DBL
#include "dither_template.c"
#undef TEMPLATE_DITHER_DBL
