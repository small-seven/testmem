#include "sbc.h"
#include "parser.h"
typedef struct SBCParseContext {
    ParseContext pc;
    uint8_t header[3];
    int header_size;
    int buffered_size;
} SBCParseContext;
