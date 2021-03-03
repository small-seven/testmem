#include "libavutil/intreadwrite.h"
#include "parser.h"
#include "adx.h"
typedef struct ADXParseContext {
    ParseContext pc;
    int header_size;
    int block_size;
    int remaining;
} ADXParseContext;
