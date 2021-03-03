#include <string.h>
#include "config.h"
#include "libavutil/intmath.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "bytestream.h"
#include "hevc.h"
#include "h264.h"
#include "h2645_parse.h"
#define STARTCODE_TEST                                                  \
#if HAVE_FAST_UNALIGNED
#define FIND_FIRST_ZERO                                                 \
#if HAVE_FAST_64BIT
#else
#endif /* HAVE_FAST_64BIT */
#else
#endif /* HAVE_FAST_UNALIGNED */
