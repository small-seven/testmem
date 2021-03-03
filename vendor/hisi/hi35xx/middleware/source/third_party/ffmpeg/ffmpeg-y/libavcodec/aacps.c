#include <stdint.h>
#include "libavutil/common.h"
#include "libavutil/mathematics.h"
#include "avcodec.h"
#include "get_bits.h"
#include "aacps.h"
#if USE_FIXED
#include "aacps_fixed_tablegen.h"
#else
#include "libavutil/internal.h"
#include "aacps_tablegen.h"
#endif /* USE_FIXED */
#include "aacpsdata.c"
#define PS_BASELINE 0  ///< Operate in Baseline PS mode
#define numQMFSlots 32 //numTimeSlots * RATE
#define READ_PAR_DATA(PAR, OFFSET, MASK, ERR_CONDITION) \
#if USE_FIXED
#endif /* USE_FIXED */
#define DECAY_SLOPE      Q30(0.05f)
#if USE_FIXED
#else
#endif /* USE_FIXED */
#if USE_FIXED
#else
#endif /* USE_FIXED */
#if !USE_FIXED
#endif /* USE_FIXED */
#if USE_FIXED
#else
#endif /* USE_FIXED */
#if USE_FIXED
#else
#endif /* USE_FIXED */
#if USE_FIXED
#endif
#define PS_INIT_VLC_STATIC(num, size) \
#define PS_VLC_ROW(name) \
