#include "libavutil/channel_layout.h"
#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
#define FRAC_BITS   15   /* fractional bits for sb_samples and dct */
#define WFRAC_BITS  14   /* fractional bits for window */
#include "mpegaudio.h"
#include "mpegaudiodsp.h"
#include "mpegaudiodata.h"
#include "mpegaudiotab.h"
#define MUL(a,b) (((int64_t)(a) * (int64_t)(b)) >> FRAC_BITS)
#define SAMPLES_BUF_SIZE 4096
typedef struct MpegAudioContext {
    PutBitContext pb;
    int nb_channels;
    int lsf;           /* 1 if mpeg2 low bitrate selected */
    int bitrate_index; /* bit rate */
    int freq_index;
    int frame_size; /* frame size, in bits, without padding */
    /* padding computation */
    int frame_frac, frame_frac_incr, do_padding;
    short samples_buf[MPA_MAX_CHANNELS][SAMPLES_BUF_SIZE]; /* buffer for filter */
    int samples_offset[MPA_MAX_CHANNELS];       /* offset in samples_buf */
    int sb_samples[MPA_MAX_CHANNELS][3][12][SBLIMIT];
    unsigned char scale_factors[MPA_MAX_CHANNELS][SBLIMIT][3]; /* scale factors */
    /* code to group 3 scale factors */
    unsigned char scale_code[MPA_MAX_CHANNELS][SBLIMIT];
    int sblimit; /* number of used subbands */
    const unsigned char *alloc_table;
    int16_t filter_bank[512];
    int scale_factor_table[64];
    unsigned char scale_diff_table[128];
#if USE_FLOATS
    float scale_factor_inv_table[64];
#else
    int8_t scale_factor_shift[64];
    unsigned short scale_factor_mult[64];
#endif
    unsigned short total_quant_bits[17]; /* total number of bits per allocation group */
} MpegAudioContext;
#if WFRAC_BITS != 16
#endif
#if USE_FLOATS
#else
#define P 15
#endif
#define WSHIFT (WFRAC_BITS + 15 - FRAC_BITS)
#define SB_NOTALLOCATED  0
#define SB_ALLOCATED     1
#define SB_NOMORE        2
#if USE_FLOATS
#else
#endif
