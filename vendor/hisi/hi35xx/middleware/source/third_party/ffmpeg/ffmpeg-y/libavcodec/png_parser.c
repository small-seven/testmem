#include "parser.h"
#include "png.h"
typedef struct PNGParseContext {
    ParseContext pc;
    uint32_t chunk_pos;           ///< position inside current chunk
    uint32_t chunk_length;        ///< length of the current chunk
    uint32_t remaining_size;      ///< remaining size of the current chunk
} PNGParseContext;
