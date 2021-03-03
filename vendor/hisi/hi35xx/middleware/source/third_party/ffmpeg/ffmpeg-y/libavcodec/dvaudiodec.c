#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "internal.h"
#include "dvaudio.h"
typedef struct DVAudioContext {
    int block_size;
    int is_12bit;
    int is_pal;
    int16_t shuffle[2000];
} DVAudioContext;
