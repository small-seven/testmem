#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define TMV_TAG MKTAG('T', 'M', 'A', 'V')
typedef struct TMVContext {
    unsigned audio_chunk_size;
    unsigned video_chunk_size;
    unsigned padding;
    unsigned stream_index;
} TMVContext;
#define TMV_HEADER_SIZE       12
#define PROBE_MIN_SAMPLE_RATE 5000
#define PROBE_MAX_FPS         120
#define PROBE_MIN_AUDIO_SIZE  (PROBE_MIN_SAMPLE_RATE / PROBE_MAX_FPS)
