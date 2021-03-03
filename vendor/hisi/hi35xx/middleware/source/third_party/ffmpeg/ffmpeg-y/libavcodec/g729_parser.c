#include "libavutil/avassert.h"
#include "parser.h"
#include "g729.h"
typedef struct G729ParseContext {
    ParseContext pc;
    int block_size;
    int duration;
    int remaining;
} G729ParseContext;
