#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "parser.h"
typedef struct BMPParseContext {
    ParseContext pc;
    uint32_t fsize;
    uint32_t remaining_size;
} BMPParseContext;
