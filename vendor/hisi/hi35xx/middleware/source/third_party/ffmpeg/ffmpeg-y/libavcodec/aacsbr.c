#define USE_FIXED 0
#include "aac.h"
#include "sbr.h"
#include "aacsbr.h"
#include "aacsbrdata.h"
#include "aacsbr_tablegen.h"
#include "fft.h"
#include "internal.h"
#include "aacps.h"
#include "sbrdsp.h"
#include "libavutil/internal.h"
#include "libavutil/libm.h"
#include "libavutil/avassert.h"
#include <stdint.h>
#include <float.h>
#include <math.h>
#if ARCH_MIPS
#include "mips/aacsbr_mips.h"
#endif /* ARCH_MIPS */
#include "aacsbr_template.c"
