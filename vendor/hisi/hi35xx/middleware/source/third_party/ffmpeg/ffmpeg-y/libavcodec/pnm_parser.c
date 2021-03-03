#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "parser.h" //for ParseContext
#include "pnm.h"
typedef struct PNMParseContext {
    ParseContext pc;
    int remaining_bytes;
    int ascii_scan;
}PNMParseContext;
