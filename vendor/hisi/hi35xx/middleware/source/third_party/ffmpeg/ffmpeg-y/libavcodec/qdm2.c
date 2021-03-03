#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include "libavutil/channel_layout.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "get_bits.h"
#include "bytestream.h"
#include "internal.h"
#include "mpegaudio.h"
#include "mpegaudiodsp.h"
#include "rdft.h"
#include "qdm2_tablegen.h"
#define QDM2_LIST_ADD(list, size, packet) \
#define QDM2_SB_USED(sub_sampling) (((sub_sampling) >= 2) ? 30 : 8 << (sub_sampling))
#define FIX_NOISE_IDX(noise_idx) \
#define SB_DITHERING_NOISE(sb,noise_idx) (noise_table[(noise_idx)++] * sb_noise_attenuation[(sb)])
#define SAMPLES_NEEDED \
#define SAMPLES_NEEDED_2(why) \
#define QDM2_MAX_FRAME_SIZE 512
typedef int8_t sb_int8_array[2][30][64];

/**
 * Subpacket
 */
typedef struct QDM2SubPacket {
    int type;            ///< subpacket type
    unsigned int size;   ///< subpacket size
    const uint8_t *data; ///< pointer to subpacket data (points to input data buffer, it's not a private copy)
} QDM2SubPacket;
typedef struct QDM2SubPNode {
    QDM2SubPacket *packet;      ///< packet
    struct QDM2SubPNode *next; ///< pointer to next packet in the list, NULL if leaf node
} QDM2SubPNode;
typedef struct QDM2Complex {
    float re;
    float im;
} QDM2Complex;
typedef struct FFTTone {
    float level;
    QDM2Complex *complex;
    const float *table;
    int   phase;
    int   phase_shift;
    int   duration;
    short time_index;
    short cutoff;
} FFTTone;
typedef struct FFTCoefficient {
    int16_t sub_packet;
    uint8_t channel;
    int16_t offset;
    int16_t exp;
    uint8_t phase;
} FFTCoefficient;
typedef struct QDM2FFT {
    DECLARE_ALIGNED(32, QDM2Complex, complex)[MPA_MAX_CHANNELS][256];
} QDM2FFT;
typedef struct QDM2Context {
    /// Parameters from codec header, do not change during playback
    int nb_channels;         ///< number of channels
    int channels;            ///< number of channels
    int group_size;          ///< size of frame group (16 frames per group)
    int fft_size;            ///< size of FFT, in complex numbers
    int checksum_size;       ///< size of data block, used also for checksum

    /// Parameters built from header parameters, do not change during playback
    int group_order;         ///< order of frame group
    int fft_order;           ///< order of FFT (actually fftorder+1)
    int frame_size;          ///< size of data frame
    int frequency_range;
    int sub_sampling;        ///< subsampling: 0=25%, 1=50%, 2=100% */
    int coeff_per_sb_select; ///< selector for "num. of coeffs. per subband" tables. Can be 0, 1, 2
    int cm_table_select;     ///< selector for "coding method" tables. Can be 0, 1 (from init: 0-4)

    /// Packets and packet lists
    QDM2SubPacket sub_packets[16];      ///< the packets themselves
    QDM2SubPNode sub_packet_list_A[16]; ///< list of all packets
    QDM2SubPNode sub_packet_list_B[16]; ///< FFT packets B are on list
    int sub_packets_B;                  ///< number of packets on 'B' list
    QDM2SubPNode sub_packet_list_C[16]; ///< packets with errors?
    QDM2SubPNode sub_packet_list_D[16]; ///< DCT packets

    /// FFT and tones
    FFTTone fft_tones[1000];
    int fft_tone_start;
    int fft_tone_end;
    FFTCoefficient fft_coefs[1000];
    int fft_coefs_index;
    int fft_coefs_min_index[5];
    int fft_coefs_max_index[5];
    int fft_level_exp[6];
    RDFTContext rdft_ctx;
    QDM2FFT fft;

    /// I/O data
    const uint8_t *compressed_data;
    int compressed_size;
    float output_buffer[QDM2_MAX_FRAME_SIZE * MPA_MAX_CHANNELS * 2];

    /// Synthesis filter
    MPADSPContext mpadsp;
    DECLARE_ALIGNED(32, float, synth_buf)[MPA_MAX_CHANNELS][512*2];
    int synth_buf_offset[MPA_MAX_CHANNELS];
    DECLARE_ALIGNED(32, float, sb_samples)[MPA_MAX_CHANNELS][128][SBLIMIT];
    DECLARE_ALIGNED(32, float, samples)[MPA_MAX_CHANNELS * MPA_FRAME_SIZE];

    /// Mixed temporary data used in decoding
    float tone_level[MPA_MAX_CHANNELS][30][64];
    int8_t coding_method[MPA_MAX_CHANNELS][30][64];
    int8_t quantized_coeffs[MPA_MAX_CHANNELS][10][8];
    int8_t tone_level_idx_base[MPA_MAX_CHANNELS][30][8];
    int8_t tone_level_idx_hi1[MPA_MAX_CHANNELS][3][8][8];
    int8_t tone_level_idx_mid[MPA_MAX_CHANNELS][26][8];
    int8_t tone_level_idx_hi2[MPA_MAX_CHANNELS][26];
    int8_t tone_level_idx[MPA_MAX_CHANNELS][30][64];
    int8_t tone_level_idx_temp[MPA_MAX_CHANNELS][30][64];

    // Flags
    int has_errors;         ///< packet has errors
    int superblocktype_2_3; ///< select fft tables and some algorithm based on superblock type
    int do_synth_filter;    ///< used to perform or skip synthesis filter

    int sub_packet;
    int noise_idx; ///< index for dithering noise table
} QDM2Context;
