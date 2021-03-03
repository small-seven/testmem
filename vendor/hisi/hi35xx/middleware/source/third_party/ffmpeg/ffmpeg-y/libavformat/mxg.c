#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavcodec/mjpeg.h"
#include "avformat.h"
#include "internal.h"
#include "avio.h"
#define DEFAULT_PACKET_SIZE 1024
#define OVERREAD_SIZE 3
typedef struct MXGContext {
    uint8_t *buffer;
    uint8_t *buffer_ptr;
    uint8_t *soi_ptr;
    unsigned int buffer_size;
    int64_t dts;
    unsigned int cache_size;
} MXGContext;
