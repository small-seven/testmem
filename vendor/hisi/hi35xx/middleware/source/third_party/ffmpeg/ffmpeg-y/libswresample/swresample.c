#include "libavutil/opt.h"
#include "swresample_internal.h"
#include "audioconvert.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include <float.h>
#define ALIGN 32
#include "libavutil/ffversion.h"
#define LICENSE_PREFIX "libswresample license: "
#if CONFIG_LIBSOXR
#endif
#define RSC 1 //FIXME finetune
#if defined(ASSERT_LEVEL) && ASSERT_LEVEL >1
#endif
#define MAX_DROP_STEP 16384
#define MAX_SILENCE_STEP 16384
