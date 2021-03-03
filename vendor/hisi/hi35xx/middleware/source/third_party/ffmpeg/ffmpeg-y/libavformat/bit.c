#include "avformat.h"
#include "internal.h"
#include "libavcodec/get_bits.h"
#include "libavcodec/put_bits.h"
#define MAX_FRAME_SIZE 10
#define SYNC_WORD  0x6b21
#define BIT_0      0x7f
#define BIT_1      0x81
#if CONFIG_BIT_DEMUXER
#endif
#if CONFIG_BIT_MUXER
#endif
