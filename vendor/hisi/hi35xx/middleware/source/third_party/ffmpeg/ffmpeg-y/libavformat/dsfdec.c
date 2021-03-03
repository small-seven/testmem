#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "id3v2.h"
typedef struct {
    uint64_t data_end;
    uint64_t audio_size;
    uint64_t data_size;
} DSFContext;
