#include "libavutil/channel_layout.h"
#include "avformat.h"
#include "internal.h"
#include "libavutil/avstring.h"
#define ISS_SIG "IMA_ADPCM_Sound"
#define ISS_SIG_LEN 15
#define MAX_TOKEN_SIZE 20
typedef struct IssDemuxContext {
    int packet_size;
    int sample_start_pos;
} IssDemuxContext;
