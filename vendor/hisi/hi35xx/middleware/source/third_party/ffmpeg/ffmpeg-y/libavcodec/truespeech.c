#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avcodec.h"
#include "bswapdsp.h"
#include "get_bits.h"
#include "internal.h"
#include "truespeech_data.h"
typedef struct TSContext {
    BswapDSPContext bdsp;
    /* input data */
    DECLARE_ALIGNED(16, uint8_t, buffer)[32];
    int16_t vector[8];  ///< input vector: 5/5/4/4/4/3/3/3
    int offset1[2];     ///< 8-bit value, used in one copying offset
    int offset2[4];     ///< 7-bit value, encodes offsets for copying and for two-point filter
    int pulseoff[4];    ///< 4-bit offset of pulse values block
    int pulsepos[4];    ///< 27-bit variable, encodes 7 pulse positions
    int pulseval[4];    ///< 7x2-bit pulse values
    int flag;           ///< 1-bit flag, shows how to choose filters
    /* temporary data */
    int filtbuf[146];   // some big vector used for storing filters
    int prevfilt[8];    // filter from previous frame
    int16_t tmp1[8];    // coefficients for adding to out
    int16_t tmp2[8];    // coefficients for adding to out
    int16_t tmp3[8];    // coefficients for adding to out
    int16_t cvector[8]; // correlated input vector
    int filtval;        // gain value for one function
    int16_t newvec[60]; // tmp vector
    int16_t filters[32]; // filters for every subframe
} TSContext;
