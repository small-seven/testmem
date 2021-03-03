#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "parser.h"
#define DIRAC_PARSE_INFO_PREFIX 0x42424344
typedef struct DiracParseContext {
    int state;
    int is_synced;
    int sync_offset;
    int header_bytes_needed;
    int overread_index;
    int buffer_size;
    int index;
    uint8_t *buffer;
    int dirac_unit_size;
    uint8_t *dirac_unit;
} DiracParseContext;
typedef struct DiracParseUnit {
    int next_pu_offset;
    int prev_pu_offset;
    uint8_t pu_type;
} DiracParseUnit;
