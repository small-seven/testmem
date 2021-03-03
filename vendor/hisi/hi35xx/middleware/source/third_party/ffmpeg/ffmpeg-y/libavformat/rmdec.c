#include <inttypes.h>
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "avio_internal.h"
#include "internal.h"
#include "rmsipr.h"
#include "rm.h"
#define DEINT_ID_GENR MKTAG('g', 'e', 'n', 'r') ///< interleaving for Cooker/ATRAC
#define DEINT_ID_INT0 MKTAG('I', 'n', 't', '0') ///< no interleaving needed
#define DEINT_ID_INT4 MKTAG('I', 'n', 't', '4') ///< interleaving for 28.8
#define DEINT_ID_SIPR MKTAG('s', 'i', 'p', 'r') ///< interleaving for Sipro
#define DEINT_ID_VBRF MKTAG('v', 'b', 'r', 'f') ///< VBR case for AAC
#define DEINT_ID_VBRS MKTAG('v', 'b', 'r', 's') ///< VBR case for AAC
typedef struct RMDemuxContext {
    int nb_packets;
    int old_format;
    int current_stream;
    int remaining_len;
    int audio_stream_num; ///< Stream number for audio packets
    int audio_pkt_cnt; ///< Output packet counter
    int data_end;
} RMDemuxContext;
#if FF_API_R_FRAME_RATE
#endif
#define RAW_PACKET_SIZE 1000
