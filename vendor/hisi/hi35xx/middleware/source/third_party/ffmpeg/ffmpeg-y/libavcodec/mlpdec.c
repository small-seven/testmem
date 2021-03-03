#include <stdint.h>
#include "avcodec.h"
#include "libavutil/internal.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/channel_layout.h"
#include "get_bits.h"
#include "internal.h"
#include "libavutil/crc.h"
#include "parser.h"
#include "mlp_parse.h"
#include "mlpdsp.h"
#include "mlp.h"
#include "config.h"
#if ARCH_ARM
#define VLC_BITS            5
#define VLC_STATIC_SIZE     64
#else
#define VLC_BITS            9
#define VLC_STATIC_SIZE     512
#endif
typedef struct SubStream {
    /// Set if a valid restart header has been read. Otherwise the substream cannot be decoded.
    uint8_t     restart_seen;

    //@{
    /** restart header data */
    /// The type of noise to be used in the rematrix stage.
    uint16_t    noise_type;

    /// The index of the first channel coded in this substream.
    uint8_t     min_channel;
    /// The index of the last channel coded in this substream.
    uint8_t     max_channel;
    /// The number of channels input into the rematrix stage.
    uint8_t     max_matrix_channel;
    /// For each channel output by the matrix, the output channel to map it to
    uint8_t     ch_assign[MAX_CHANNELS];
    /// The channel layout for this substream
    uint64_t    mask;
    /// The matrix encoding mode for this substream
    enum AVMatrixEncoding matrix_encoding;

    /// Channel coding parameters for channels in the substream
    ChannelParams channel_params[MAX_CHANNELS];

    /// The left shift applied to random noise in 0x31ea substreams.
    uint8_t     noise_shift;
    /// The current seed value for the pseudorandom noise generator(s).
    uint32_t    noisegen_seed;

    /// Set if the substream contains extra info to check the size of VLC blocks.
    uint8_t     data_check_present;

    /// Bitmask of which parameter sets are conveyed in a decoding parameter block.
    uint8_t     param_presence_flags;
#define PARAM_BLOCKSIZE     (1 << 7)
#define PARAM_MATRIX        (1 << 6)
#define PARAM_OUTSHIFT      (1 << 5)
#define PARAM_QUANTSTEP     (1 << 4)
#define PARAM_FIR           (1 << 3)
#define PARAM_IIR           (1 << 2)
#define PARAM_HUFFOFFSET    (1 << 1)
#define PARAM_PRESENCE      (1 << 0)
    //@}
typedef struct MLPDecodeContext {
    AVCodecContext *avctx;

    /// Current access unit being read has a major sync.
    int         is_major_sync_unit;

    /// Size of the major sync unit, in bytes
    int         major_sync_header_size;

    /// Set if a valid major sync block has been read. Otherwise no decoding is possible.
    uint8_t     params_valid;

    /// Number of substreams contained within this stream.
    uint8_t     num_substreams;

    /// Index of the last substream to decode - further substreams are skipped.
    uint8_t     max_decoded_substream;

    /// Stream needs channel reordering to comply with FFmpeg's channel order
    uint8_t     needs_reordering;

    /// number of PCM samples contained in each frame
    int         access_unit_size;
    /// next power of two above the number of samples in each frame
    int         access_unit_size_pow2;

    SubStream   substream[MAX_SUBSTREAMS];

    int         matrix_changed;
    int         filter_changed[MAX_CHANNELS][NUM_FILTERS];

    int8_t      noise_buffer[MAX_BLOCKSIZE_POW2];
    int8_t      bypassed_lsbs[MAX_BLOCKSIZE][MAX_CHANNELS];
    DECLARE_ALIGNED(32, int32_t, sample_buffer)[MAX_BLOCKSIZE][MAX_CHANNELS];

    MLPDSPContext dsp;
} MLPDecodeContext;
#define MSB_MASK(bits)  (-1u << (bits))
#if CONFIG_MLP_DECODER
#endif
#if CONFIG_TRUEHD_DECODER
#endif /* CONFIG_TRUEHD_DECODER */
