#include "config.h"
#include "libavutil/avassert.h"
#include "libavcodec/avcodec.h"
#include "libavcodec/bytestream.h"
#include "libavformat/avformat.h"
typedef struct IOContext {
    int64_t pos;
    int64_t filesize;
    uint8_t *fuzz;
    int fuzz_size;
} IOContext;
