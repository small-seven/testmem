#include <stdint.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/tree.h"
#include "libavutil/dict.h"
#include "libavutil/avassert.h"
#include "libavutil/time.h"
#include "libavutil/opt.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/mpegaudiodata.h"
#include "nut.h"
#include "internal.h"
#include "avio_internal.h"
#include "riff.h"
#if 1
#endif
#define OFFSET(x) offsetof(NUTContext, x)
#define E AV_OPT_FLAG_ENCODING_PARAM
