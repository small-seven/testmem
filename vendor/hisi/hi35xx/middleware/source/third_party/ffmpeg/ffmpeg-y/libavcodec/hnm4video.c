#include <string.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define HNM4_CHUNK_ID_PL 19536
#define HNM4_CHUNK_ID_IZ 23113
#define HNM4_CHUNK_ID_IU 21833
#define HNM4_CHUNK_ID_SD 17491
typedef struct Hnm4VideoContext {
    uint8_t version;
    int width;
    int height;
    uint8_t *current;
    uint8_t *previous;
    uint8_t *buffer1;
    uint8_t *buffer2;
    uint8_t *processed;
    uint32_t palette[256];
} Hnm4VideoContext;
