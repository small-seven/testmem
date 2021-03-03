#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define AUD_HEADER_SIZE 12
#define AUD_CHUNK_PREAMBLE_SIZE 8
#define AUD_CHUNK_SIGNATURE 0x0000DEAF
