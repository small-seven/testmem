#include "libavutil/avassert.h"
#include "parser.h"
#include "gsm.h"
typedef struct GSMParseContext {
    ParseContext pc;
    int block_size;
    int duration;
    int remaining;
} GSMParseContext;
