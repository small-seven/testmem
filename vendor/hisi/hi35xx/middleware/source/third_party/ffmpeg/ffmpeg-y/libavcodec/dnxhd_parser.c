#include "parser.h"
#include "dnxhddata.h"
typedef struct {
    ParseContext pc;
    int cur_byte;
    int remaining;
    int w, h;
} DNXHDParserContext;
