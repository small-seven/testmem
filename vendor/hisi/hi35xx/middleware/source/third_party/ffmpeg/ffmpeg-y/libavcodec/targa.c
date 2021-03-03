#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "targa.h"
typedef struct TargaContext {
    GetByteContext gb;
} TargaContext;
