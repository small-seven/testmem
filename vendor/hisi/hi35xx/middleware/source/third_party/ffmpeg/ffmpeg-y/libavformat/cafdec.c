#include <inttypes.h>
#include "avformat.h"
#include "internal.h"
#include "isom.h"
#include "mov_chan.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/intfloat.h"
#include "libavutil/dict.h"
#include "caf.h"
typedef struct CafContext {
    int bytes_per_packet;           ///< bytes in a packet, or 0 if variable
    int frames_per_packet;          ///< frames in a packet, or 0 if variable
    int64_t num_bytes;              ///< total number of bytes in stream

    int64_t packet_cnt;             ///< packet counter
    int64_t frame_cnt;              ///< frame counter

    int64_t data_start;             ///< data start position, in bytes
    int64_t data_size;              ///< raw data size, in bytes
} CafContext;
#define ALAC_PREAMBLE 12
#define ALAC_HEADER   36
#define ALAC_NEW_KUKI 24
#define CAF_MAX_PKT_SIZE 4096
