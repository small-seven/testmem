#include <math.h>
#include <stddef.h>
#include <stdio.h>
#define BITSTREAM_READER_LE
#include "libavutil/channel_layout.h"
#include "libavutil/thread.h"
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "fft.h"
typedef struct QDMCTone {
    uint8_t mode;
    uint8_t phase;
    uint8_t offset;
    int16_t freq;
    int16_t amplitude;
} QDMCTone;
typedef struct QDMCContext {
    AVCodecContext *avctx;

    uint8_t frame_bits;
    int band_index;
    int frame_size;
    int subframe_size;
    int fft_offset;
    int buffer_offset;
    int nb_channels;
    int checksum_size;

    uint8_t noise[2][19][17];
    QDMCTone tones[5][8192];
    int nb_tones[5];
    int cur_tone[5];
    float alt_sin[5][31];
    float fft_buffer[4][8192 * 2];
    float noise2_buffer[4096 * 2];
    float noise_buffer[4096 * 2];
    float buffer[2 * 32768];
    float *buffer_ptr;
    int rndval;

    DECLARE_ALIGNED(32, FFTComplex, cmplx)[2][512];
    FFTContext fft_ctx;
} QDMCContext;
#define INIT_VLC_STATIC_LE(vlc, nb_bits, nb_codes,                 \
