#include "libavutil/intreadwrite.h"
#include "libavutil/mathematics.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "internal.h"
#include "pcm.h"
#include "aiff.h"
#include "isom.h"
#include "id3v2.h"
#include "mov_chan.h"
#define AIFF                    0
#define AIFF_C_VERSION1         0xA2805140
typedef struct AIFFInputContext {
    int64_t data_end;
    int block_duration;
} AIFFInputContext;
#define MAX_SIZE 4096
