#include "avformat.h"
#include "internal.h"
#include "mpeg.h"
#define PVA_MAX_PAYLOAD_LENGTH  0x17f8
#define PVA_VIDEO_PAYLOAD       0x01
#define PVA_AUDIO_PAYLOAD       0x02
#define PVA_MAGIC               (('A' << 8) + 'V')
typedef struct PVAContext {
    int continue_pes;
} PVAContext;
#define pva_log if (read_packet) av_log
