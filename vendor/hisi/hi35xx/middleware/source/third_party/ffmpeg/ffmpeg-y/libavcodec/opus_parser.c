#include "avcodec.h"
#include "bytestream.h"
#include "opus.h"
#include "parser.h"
typedef struct OpusParseContext {
    ParseContext pc;
    OpusContext ctx;
    OpusPacket pkt;
    int extradata_parsed;
    int ts_framing;
} OpusParseContext;
