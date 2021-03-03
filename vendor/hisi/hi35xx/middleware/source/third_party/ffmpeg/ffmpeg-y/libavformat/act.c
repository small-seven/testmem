#include "avformat.h"
#include "riff.h"
#include "internal.h"
#include "libavcodec/get_bits.h"
#define CHUNK_SIZE 512
#define RIFF_TAG MKTAG('R','I','F','F')
#define WAVE_TAG MKTAG('W','A','V','E')
typedef struct{
    int bytes_left_in_chunk;
    uint8_t audio_buffer[22];///< temporary buffer for ACT frame
    char second_packet;      ///< 1 - if temporary buffer contains valid (second) G.729 packet
} ACTContext;
