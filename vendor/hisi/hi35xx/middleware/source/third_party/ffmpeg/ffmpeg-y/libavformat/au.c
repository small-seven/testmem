#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#include "pcm.h"
#include "libavutil/avassert.h"
#define AU_UNKNOWN_SIZE ((uint32_t)(~0))
#define AU_DEFAULT_HEADER_SIZE (24+8)
#if CONFIG_AU_DEMUXER
#define BLOCK_SIZE 1024
#endif /* CONFIG_AU_DEMUXER */
#if CONFIG_AU_MUXER
typedef struct AUContext {
    uint32_t header_size;
} AUContext;
#include "rawenc.h"
#endif /* CONFIG_AU_MUXER */
