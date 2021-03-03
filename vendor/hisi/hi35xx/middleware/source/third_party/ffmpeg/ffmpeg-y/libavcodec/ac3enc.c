#include <stdint.h>
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/crc.h"
#include "libavutil/internal.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "me_cmp.h"
#include "put_bits.h"
#include "audiodsp.h"
#include "ac3dsp.h"
#include "ac3.h"
#include "fft.h"
#include "ac3enc.h"
#include "eac3enc.h"
typedef struct AC3Mant {
    int16_t *qmant1_ptr, *qmant2_ptr, *qmant4_ptr; ///< mantissa pointers for bap=1,2,4
    int mant1_cnt, mant2_cnt, mant4_cnt;    ///< mantissa counts for bap=1,2,4
} AC3Mant;
#define CMIXLEV_NUM_OPTIONS 3
#define SURMIXLEV_NUM_OPTIONS 3
#define EXTMIXLEV_NUM_OPTIONS 8
#define EXP_DIFF_THRESHOLD 500
#define CRC16_POLY ((1 << 0) | (1 << 2) | (1 << 15) | (1 << 16))
#ifdef DEBUG
#endif
#define FLT_OPTION_THRESHOLD 0.01
