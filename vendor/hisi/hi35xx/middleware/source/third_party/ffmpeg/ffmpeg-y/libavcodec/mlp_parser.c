#include <stdint.h>
#include "libavutil/internal.h"
#include "get_bits.h"
#include "parser.h"
#include "mlp_parse.h"
#include "mlp.h"
typedef struct MLPParseContext
{
    ParseContext pc;

    int bytes_left;

    int in_sync;

    int num_substreams;
} MLPParseContext;
