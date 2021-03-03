#include "avcodec.h"
#include "get_bits.h"
#include "golomb.h"
#include "internal.h"
#include "rangecoder.h"
#define MAX_CHANNELS 2
#define MID_SIDE 0
#define LEFT_SIDE 1
#define RIGHT_SIDE 2
typedef struct SonicContext {
    int version;
    int minor_version;
    int lossless, decorrelation;

    int num_taps, downsampling;
    double quantization;

    int channels, samplerate, block_align, frame_size;

    int *tap_quant;
    int *int_samples;
    int *coded_samples[MAX_CHANNELS];

    // for encoding
    int *tail;
    int tail_size;
    int *window;
    int window_size;

    // for decoding
    int *predictor_k;
    int *predictor_state[MAX_CHANNELS];
} SonicContext;
#define LATTICE_SHIFT   10
#define SAMPLE_SHIFT    4
#define LATTICE_FACTOR  (1 << LATTICE_SHIFT)
#define SAMPLE_FACTOR   (1 << SAMPLE_SHIFT)
#define BASE_QUANT      0.6
#define RATE_VARIATION  3.0
#define put_rac(C,S,B) \
#undef put_rac
#if 1
#elif 1
#else
#define ADAPT_LEVEL 8
#endif
#if 1
#else
#endif
#if CONFIG_SONIC_ENCODER || CONFIG_SONIC_LS_ENCODER
#if 1
#else
#endif
#if 1
#else
#endif
#endif /* CONFIG_SONIC_ENCODER || CONFIG_SONIC_LS_ENCODER */
#if CONFIG_SONIC_DECODER
#endif /* CONFIG_SONIC_DECODER */
#if CONFIG_SONIC_ENCODER
#endif
#if CONFIG_SONIC_LS_ENCODER
#endif
