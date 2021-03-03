#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
typedef struct HEntry {
    int16_t l, r;
} HEntry;
typedef struct HCOMContext {
    AVCodecContext *avctx;

    uint8_t first_sample;
    uint8_t sample;
    int dict_entries;
    int dict_entry;
    int delta_compression;

    HEntry *dict;
} HCOMContext;
