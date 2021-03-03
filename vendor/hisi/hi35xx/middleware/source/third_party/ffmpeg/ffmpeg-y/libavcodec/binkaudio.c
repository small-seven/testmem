#include "libavutil/channel_layout.h"
#include "libavutil/intfloat.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "dct.h"
#include "decode.h"
#include "get_bits.h"
#include "internal.h"
#include "rdft.h"
#include "wma_freqs.h"
#define MAX_CHANNELS 2
#define BINK_BLOCK_MAX_SIZE (MAX_CHANNELS << 11)
typedef struct BinkAudioContext {
    GetBitContext gb;
    int version_b;          ///< Bink version 'b'
    int first;
    int channels;
    int frame_len;          ///< transform size (samples)
    int overlap_len;        ///< overlap size (samples)
    int block_size;
    int num_bands;
    unsigned int *bands;
    float root;
    DECLARE_ALIGNED(32, FFTSample, coeffs)[BINK_BLOCK_MAX_SIZE];
    float previous[MAX_CHANNELS][BINK_BLOCK_MAX_SIZE / 16];  ///< coeffs from previous audio block
    AVPacket *pkt;
    union {
        RDFTContext rdft;
        DCTContext dct;
    } trans;
