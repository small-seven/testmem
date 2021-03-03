#include "avformat.h"
#include "rawdec.h"
#include "libavutil/intreadwrite.h"
#include "libavcodec/internal.h"
#define SEQ_START_CODE          0x000001b3
#define GOP_START_CODE          0x000001b8
#define PICTURE_START_CODE      0x00000100
#define SLICE_START_CODE        0x00000101
#define PACK_START_CODE         0x000001ba
#define VIDEO_ID                0x000001e0
#define AUDIO_ID                0x000001c0
