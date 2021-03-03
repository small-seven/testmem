#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define FLIC_FILE_MAGIC_1 0xAF11
#define FLIC_FILE_MAGIC_2 0xAF12
#define FLIC_FILE_MAGIC_3 0xAF44  /* Flic Type for Extended FLX Format which
#define FLIC_CHUNK_MAGIC_1 0xF1FA
#define FLIC_CHUNK_MAGIC_2 0xF5FA
#define FLIC_MC_SPEED 5  /* speed for Magic Carpet game FLIs */
#define FLIC_DEFAULT_SPEED 5  /* for FLIs that have 0 speed */
#define FLIC_TFTD_CHUNK_AUDIO 0xAAAA /* Audio chunk. Used in Terror from the Deep.
#define FLIC_TFTD_SAMPLE_RATE 22050
#define FLIC_HEADER_SIZE 128
#define FLIC_PREAMBLE_SIZE 6
typedef struct FlicDemuxContext {
    int video_stream_index;
    int audio_stream_index;
    int frame_number;
} FlicDemuxContext;
