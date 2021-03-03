#include "libavutil/channel_layout.h"
#include "libavutil/float_dsp.h"
#include "libavutil/internal.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "celp_filters.h"
#include "get_bits.h"
#include "internal.h"
#include "lpc.h"
#include "ra288.h"
#define MAX_BACKWARD_FILTER_ORDER  36
#define MAX_BACKWARD_FILTER_LEN    40
#define MAX_BACKWARD_FILTER_NONREC 35
#define RA288_BLOCK_SIZE        5
#define RA288_BLOCKS_PER_FRAME 32
typedef struct RA288Context {
    AVFloatDSPContext *fdsp;
    DECLARE_ALIGNED(32, float,   sp_lpc)[FFALIGN(36, 16)];   ///< LPC coefficients for speech data (spec: A)
    DECLARE_ALIGNED(32, float, gain_lpc)[FFALIGN(10, 16)];   ///< LPC coefficients for gain        (spec: GB)

    /** speech data history                                      (spec: SB).
     *  Its first 70 coefficients are updated only at backward filtering.
     */
    float sp_hist[111];

    /// speech part of the gain autocorrelation                  (spec: REXP)
    float sp_rec[37];

    /** log-gain history                                         (spec: SBLG).
     *  Its first 28 coefficients are updated only at backward filtering.
     */
    float gain_hist[38];

    /// recursive part of the gain autocorrelation               (spec: REXPLG)
    float gain_rec[11];
} RA288Context;
