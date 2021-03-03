#include "avcodec.h"
#include "internal.h"
#include "put_bits.h"
#include "audio_frame_queue.h"
#include "libavutil/crc.h"
#include "libavutil/avstring.h"
#include "libavutil/samplefmt.h"
#include "mlp.h"
#include "lpc.h"
#define MAJOR_HEADER_INTERVAL 16
#define MLP_MIN_LPC_ORDER      1
#define MLP_MAX_LPC_ORDER      8
#define MLP_MIN_LPC_SHIFT      8
#define MLP_MAX_LPC_SHIFT     15
typedef struct {
    uint8_t         min_channel;         ///< The index of the first channel coded in this substream.
    uint8_t         max_channel;         ///< The index of the last channel coded in this substream.
    uint8_t         max_matrix_channel;  ///< The number of channels input into the rematrix stage.

    uint8_t         noise_shift;         ///< The left shift applied to random noise in 0x31ea substreams.
    uint32_t        noisegen_seed;       ///< The current seed value for the pseudorandom noise generator(s).

    int             data_check_present;  ///< Set if the substream contains extra info to check the size of VLC blocks.

    int32_t         lossless_check_data; ///< XOR of all output samples

    uint8_t         max_huff_lsbs;       ///< largest huff_lsbs
    uint8_t         max_output_bits;     ///< largest output bit-depth
} RestartHeader;
typedef struct {
    uint8_t         count;                  ///< number of matrices to apply

    uint8_t         outch[MAX_MATRICES];    ///< output channel for each matrix
    int32_t         forco[MAX_MATRICES][MAX_CHANNELS+2];    ///< forward coefficients
    int32_t         coeff[MAX_MATRICES][MAX_CHANNELS+2];    ///< decoding coefficients
    uint8_t         fbits[MAX_CHANNELS];    ///< fraction bits

    int8_t          shift[MAX_CHANNELS];    ///< Left shift to apply to decoded PCM values to get final 24-bit output.
} MatrixParams;
typedef struct {
    uint16_t        blocksize;                  ///< number of PCM samples in current audio block
    uint8_t         quant_step_size[MAX_CHANNELS];  ///< left shift to apply to Huffman-decoded residuals

    MatrixParams    matrix_params;

    uint8_t         param_presence_flags;       ///< Bitmask of which parameter sets are conveyed in a decoding parameter block.
} DecodingParams;
typedef struct BestOffset {
    int16_t offset;
    int bitcount;
    int lsb_bits;
    int16_t min;
    int16_t max;
} BestOffset;
#define HUFF_OFFSET_MIN    -16384
#define HUFF_OFFSET_MAX     16383
#define NUM_CODEBOOKS       4
typedef struct {
    AVCodecContext *avctx;

    int             num_substreams;         ///< Number of substreams contained within this stream.

    int             num_channels;   /**< Number of channels in major_scratch_buffer.
                                     *   Normal channels + noise channels. */

    int             coded_sample_fmt [2];   ///< sample format encoded for MLP
    int             coded_sample_rate[2];   ///< sample rate encoded for MLP
    int             coded_peak_bitrate;     ///< peak bitrate for this major sync header

    int             flags;                  ///< major sync info flags

    /* channel_meaning */
    int             substream_info;
    int             fs;
    int             wordlength;
    int             channel_occupancy;
    int             summary_info;

    int32_t        *inout_buffer;           ///< Pointer to data currently being read from lavc or written to bitstream.
    int32_t        *major_inout_buffer;     ///< Buffer with all in/out data for one entire major frame interval.
    int32_t        *write_buffer;           ///< Pointer to data currently being written to bitstream.
    int32_t        *sample_buffer;          ///< Pointer to current access unit samples.
    int32_t        *major_scratch_buffer;   ///< Scratch buffer big enough to fit all data for one entire major frame interval.
    int32_t        *last_frame;             ///< Pointer to last frame with data to encode.

    int32_t        *lpc_sample_buffer;

    unsigned int    major_number_of_frames;
    unsigned int    next_major_number_of_frames;

    unsigned int    major_frame_size;       ///< Number of samples in current major frame being encoded.
    unsigned int    next_major_frame_size;  ///< Counter of number of samples for next major frame.

    int32_t        *lossless_check_data;    ///< Array with lossless_check_data for each access unit.

    unsigned int   *max_output_bits;        ///< largest output bit-depth
    unsigned int   *frame_size;             ///< Array with number of samples/channel in each access unit.
    unsigned int    frame_index;            ///< Index of current frame being encoded.

    unsigned int    one_sample_buffer_size; ///< Number of samples*channel for one access unit.

    unsigned int    max_restart_interval;   ///< Max interval of access units in between two major frames.
    unsigned int    min_restart_interval;   ///< Min interval of access units in between two major frames.
    unsigned int    restart_intervals;      ///< Number of possible major frame sizes.

    uint16_t        timestamp;              ///< Timestamp of current access unit.
    uint16_t        dts;                    ///< Decoding timestamp of current access unit.

    uint8_t         channel_arrangement;    ///< channel arrangement for MLP streams

    uint8_t         ch_modifier_thd0;       ///< channel modifier for TrueHD stream 0
    uint8_t         ch_modifier_thd1;       ///< channel modifier for TrueHD stream 1
    uint8_t         ch_modifier_thd2;       ///< channel modifier for TrueHD stream 2

    unsigned int    seq_size  [MAJOR_HEADER_INTERVAL];
    unsigned int    seq_offset[MAJOR_HEADER_INTERVAL];
    unsigned int    sequence_size;

    ChannelParams  *channel_params;

    BestOffset      best_offset[MAJOR_HEADER_INTERVAL+1][MAX_CHANNELS][NUM_CODEBOOKS];

    DecodingParams *decoding_params;
    RestartHeader   restart_header [MAX_SUBSTREAMS];

    ChannelParams   major_channel_params[MAJOR_HEADER_INTERVAL+1][MAX_CHANNELS];       ///< ChannelParams to be written to bitstream.
    DecodingParams  major_decoding_params[MAJOR_HEADER_INTERVAL+1][MAX_SUBSTREAMS];    ///< DecodingParams to be written to bitstream.
    int             major_params_changed[MAJOR_HEADER_INTERVAL+1][MAX_SUBSTREAMS];     ///< params_changed to be written to bitstream.

    unsigned int    major_cur_subblock_index;
    unsigned int    major_filter_state_subblock;
    unsigned int    major_number_of_subblocks;

    BestOffset    (*cur_best_offset)[NUM_CODEBOOKS];
    ChannelParams  *cur_channel_params;
    DecodingParams *cur_decoding_params;
    RestartHeader  *cur_restart_header;

    AudioFrameQueue afq;

    /* Analysis stage. */
    unsigned int    starting_frame_index;
    unsigned int    number_of_frames;
    unsigned int    number_of_samples;
    unsigned int    number_of_subblocks;
    unsigned int    seq_index;              ///< Sequence index for high compression levels.

    ChannelParams  *prev_channel_params;
    DecodingParams *prev_decoding_params;

    ChannelParams  *seq_channel_params;
    DecodingParams *seq_decoding_params;

    unsigned int    max_codebook_search;

    LPCContext      lpc_ctx;
} MLPEncodeContext;
#define SYNC_MAJOR      0xf8726f
#define MAJOR_SYNC_INFO_SIGNATURE   0xB752
#define SYNC_MLP        0xbb
#define SYNC_TRUEHD     0xba
#define FLAGS_DVDA      0x4000
#define FLAGS_CONST     0x8000
#define SUBSTREAM_INFO_MAX_2_CHAN   0x01
#define SUBSTREAM_INFO_HIGH_RATE    0x02
#define SUBSTREAM_INFO_ALWAYS_SET   0x04
#define SUBSTREAM_INFO_2_SUBSTREAMS 0x08
#define SAMPLE_MAX(bitdepth) ((1 << (bitdepth - 1)) - 1)
#define SAMPLE_MIN(bitdepth) (~SAMPLE_MAX(bitdepth))
#define MSB_MASK(bits)  (-1u << bits)
typedef struct {
    char    path[MAJOR_HEADER_INTERVAL + 3];
    int     bitcount;
} PathCounter;
#define ZERO_PATH               '0'
#define CODEBOOK_CHANGE_BITS    21
#if CONFIG_MLP_ENCODER
#endif
#if CONFIG_TRUEHD_ENCODER
#endif
