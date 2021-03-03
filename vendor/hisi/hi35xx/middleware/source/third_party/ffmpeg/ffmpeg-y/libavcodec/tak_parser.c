#define BITSTREAM_READER_LE
#include "parser.h"
#include "tak.h"
typedef struct TAKParseContext {
    ParseContext  pc;
    TAKStreamInfo ti;
    int           index;
} TAKParseContext;
