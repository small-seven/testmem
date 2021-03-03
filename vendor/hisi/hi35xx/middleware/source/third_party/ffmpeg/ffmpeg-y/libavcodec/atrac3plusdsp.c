#include <math.h>
#include "libavutil/float_dsp.h"
#include "libavutil/libm.h"
#include "avcodec.h"
#include "sinewin.h"
#include "fft.h"
#include "atrac3plus.h"
#define ATRAC3P_MDCT_SIZE (ATRAC3P_SUBBAND_SAMPLES * 2)
#define TWOPI (2 * M_PI)
#define DEQUANT_PHASE(ph) (((ph) & 0x1F) << 6)
