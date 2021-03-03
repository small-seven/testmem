#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "parser.h"
typedef struct DPXParseContext {
    ParseContext pc;
    uint32_t index;
    uint32_t fsize;
    uint32_t remaining_size;
    int is_be;
} DPXParseContext;
