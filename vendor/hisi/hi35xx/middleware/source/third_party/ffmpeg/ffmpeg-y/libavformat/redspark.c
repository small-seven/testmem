#include "libavcodec/bytestream.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "avio.h"
#include "internal.h"
#define HEADER_SIZE 4096
#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))
typedef struct RedSparkContext {
    int         samples_count;
} RedSparkContext;
