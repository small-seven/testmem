#include <inttypes.h>
#include <limits.h>
#include "avcodec.h"
#include "g729.h"
#include "acelp_pitch_delay.h"
#include "g729postfilter.h"
#include "celp_math.h"
#include "acelp_filters.h"
#include "acelp_vectors.h"
#include "celp_filters.h"
#define FRAC_BITS 15
#include "mathops.h"
#ifdef G729_BITEXACT
#else
#endif
