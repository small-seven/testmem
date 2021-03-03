#include "libavutil/channel_layout.h"
#include "libavutil/lfg.h"
#include "audiodsp.h"
#include "avcodec.h"
#include "get_bits.h"
#include "bytestream.h"
#include "fft.h"
#include "internal.h"
#include "sinewin.h"
#include "unary.h"
#include "cookdata.h"
#define MONO            0x1000001
#define STEREO          0x1000002
#define JOINT_STEREO    0x1000003
#define MC_COOK         0x2000000   // multichannel Cook, not supported
#define SUBBAND_SIZE    20
#define MAX_SUBPACKETS   5
typedef struct cook_gains {
    int *now;
    int *previous;
} cook_gains;
typedef struct COOKSubpacket {
    int                 ch_idx;
    int                 size;
    int                 num_channels;
    int                 cookversion;
    int                 subbands;
    int                 js_subband_start;
    int                 js_vlc_bits;
    int                 samples_per_channel;
    int                 log2_numvector_size;
    unsigned int        channel_mask;
    VLC                 channel_coupling;
    int                 joint_stereo;
    int                 bits_per_subpacket;
    int                 bits_per_subpdiv;
    int                 total_subbands;
    int                 numvector_size;       // 1 << log2_numvector_size;

    float               mono_previous_buffer1[1024];
    float               mono_previous_buffer2[1024];

    cook_gains          gains1;
    cook_gains          gains2;
    int                 gain_1[9];
    int                 gain_2[9];
    int                 gain_3[9];
    int                 gain_4[9];
} COOKSubpacket;
typedef struct cook {
    /*
     * The following 5 functions provide the lowlevel arithmetic on
     * the internal audio buffers.
     */
    void (*scalar_dequant)(struct cook *q, int index, int quant_index,
                           int *subband_coef_index, int *subband_coef_sign,
                           float *mlt_p);

    void (*decouple)(struct cook *q,
                     COOKSubpacket *p,
                     int subband,
                     float f1, float f2,
                     float *decode_buffer,
                     float *mlt_buffer1, float *mlt_buffer2);

    void (*imlt_window)(struct cook *q, float *buffer1,
                        cook_gains *gains_ptr, float *previous_buffer);

    void (*interpolate)(struct cook *q, float *buffer,
                        int gain_index, int gain_index_next);

    void (*saturate_output)(struct cook *q, float *out);

    AVCodecContext*     avctx;
    AudioDSPContext     adsp;
    GetBitContext       gb;
    /* stream data */
    int                 num_vectors;
    int                 samples_per_channel;
    /* states */
    AVLFG               random_state;
    int                 discarded_packets;

    /* transform data */
    FFTContext          mdct_ctx;
    float*              mlt_window;

    /* VLC data */
    VLC                 envelope_quant_index[13];
    VLC                 sqvh[7];          // scalar quantization

    /* generate tables and related variables */
    int                 gain_size_factor;
    float               gain_table[31];

    /* data buffers */

    uint8_t*            decoded_bytes_buffer;
    DECLARE_ALIGNED(32, float, mono_mdct_output)[2048];
    float               decode_buffer_1[1024];
    float               decode_buffer_2[1024];
    float               decode_buffer_0[1060]; /* static allocation for joint decode */

    const float         *cplscales[5];
    int                 num_subpackets;
    COOKSubpacket       subpacket[MAX_SUBPACKETS];
} COOKContext;
#define DECODE_BYTES_PAD1(bytes) (3 - ((bytes) + 3) % 4)
#define DECODE_BYTES_PAD2(bytes) ((bytes) % 4 + DECODE_BYTES_PAD1(2 * (bytes)))
#define PRINT(a, b) ff_dlog(q->avctx, " %s = %d\n", a, b);
