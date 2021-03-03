#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "avio_internal.h"
#include "rawenc.h"
#include "sox.h"
typedef struct SoXContext {
    int64_t header_size;
} SoXContext;
