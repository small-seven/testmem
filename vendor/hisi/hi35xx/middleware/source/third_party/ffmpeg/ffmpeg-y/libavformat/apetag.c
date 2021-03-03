#include <inttypes.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "avio_internal.h"
#include "apetag.h"
#include "internal.h"
#define APE_TAG_FLAG_CONTAINS_HEADER  (1U << 31)
#define APE_TAG_FLAG_LACKS_FOOTER     (1 << 30)
#define APE_TAG_FLAG_IS_HEADER        (1 << 29)
#define APE_TAG_FLAG_IS_BINARY        (1 << 1)
