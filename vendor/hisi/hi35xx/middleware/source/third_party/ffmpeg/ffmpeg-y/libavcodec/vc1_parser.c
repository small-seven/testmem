#include "libavutil/attributes.h"
#include "parser.h"
#include "vc1.h"
#include "get_bits.h"
#include "internal.h"
#define UNESCAPED_THRESHOLD 37
#define UNESCAPED_LIMIT 144
typedef enum {
    NO_MATCH,
    ONE_ZERO,
    TWO_ZEROS,
    ONE
} VC1ParseSearchState;
typedef struct VC1ParseContext {
    ParseContext pc;
    VC1Context v;
    uint8_t prev_start_code;
    size_t bytes_to_skip;
    uint8_t unesc_buffer[UNESCAPED_LIMIT];
    size_t unesc_index;
    VC1ParseSearchState search_state;
} VC1ParseContext;
