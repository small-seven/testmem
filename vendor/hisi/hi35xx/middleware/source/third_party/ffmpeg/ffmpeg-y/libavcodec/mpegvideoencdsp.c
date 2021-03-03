#include <assert.h>
#include <stdint.h>
#include <string.h>
#include "config.h"
#include "libavutil/avassert.h"
#include "libavutil/attributes.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "me_cmp.h"
#include "mpegvideoencdsp.h"
#if HAVE_FAST_64BIT
#else
#endif
