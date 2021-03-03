#include "libavutil/avassert.h"
#include "libavutil/bswap.h"
#include "libavutil/common.h"
#include "gif.h"
#include "parser.h"
typedef enum GIFParseStates {
    GIF_HEADER = 1,
    GIF_EXTENSION,
    GIF_EXTENSION_BLOCK,
    GIF_IMAGE,
    GIF_IMAGE_BLOCK,
} gif_states;
typedef struct GIFParseContext {
    ParseContext pc;
    unsigned found_sig;
    int found_start;
    int found_end;
    int index;
    int state;
    int gct_flag;
    int gct_size;
    int block_size;
    int etype;
    int delay;
} GIFParseContext;
