#include <stdint.h>
#include "parser.h"
#define LATM_HEADER     0x56e000        // 0x2b7 (11 bits)
#define LATM_MASK       0xFFE000        // top 11 bits
#define LATM_SIZE_MASK  0x001FFF        // bottom 13 bits
typedef struct LATMParseContext{
    ParseContext pc;
    int count;
} LATMParseContext;
