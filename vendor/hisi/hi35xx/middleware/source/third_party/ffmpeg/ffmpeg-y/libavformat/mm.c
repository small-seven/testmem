#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define MM_PREAMBLE_SIZE    6
#define MM_TYPE_HEADER      0x0
#define MM_TYPE_INTER       0x5
#define MM_TYPE_INTRA       0x8
#define MM_TYPE_INTRA_HH    0xc
#define MM_TYPE_INTER_HH    0xd
#define MM_TYPE_INTRA_HHV   0xe
#define MM_TYPE_INTER_HHV   0xf
#define MM_TYPE_AUDIO       0x15
#define MM_TYPE_PALETTE     0x31
#define MM_HEADER_LEN_V     0x16    /* video only */
#define MM_HEADER_LEN_AV    0x18    /* video + audio */
#define MM_PALETTE_COUNT    128
#define MM_PALETTE_SIZE     (MM_PALETTE_COUNT*3)
typedef struct MmDemuxContext {
  unsigned int audio_pts, video_pts;
} MmDemuxContext;
