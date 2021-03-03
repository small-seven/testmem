#include "libavutil/common.h"
#include "libavutil/ffmath.h"
#include "libavutil/float_dsp.h"
#include "libavutil/mathematics.h"
#include "avcodec.h"
#include "acelp_pitch_delay.h"
#include "celp_math.h"
#include "audiodsp.h"
#ifdef G729_BITEXACT
#else
#endif
