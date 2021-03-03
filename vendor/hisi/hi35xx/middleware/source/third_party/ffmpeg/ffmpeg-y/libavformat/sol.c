#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "pcm.h"
#define AU_UNKNOWN_SIZE ((uint32_t)(~0))
#define SOL_DPCM    1
#define SOL_16BIT   4
#define SOL_STEREO 16
#define MAX_SIZE 4096
