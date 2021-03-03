#include "libavutil/avstring.h"
#include "libavutil/avassert.h"
#include "libavutil/bswap.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/tree.h"
#include "libavcodec/bytestream.h"
#include "avio_internal.h"
#include "isom.h"
#include "nut.h"
#include "riff.h"
#define NUT_MAX_STREAMS 256    /* arbitrary sanity check value */
#define GET_V(dst, check)                                                     \
