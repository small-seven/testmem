#define USE_FIXED 1
#include "aac.h"
#include "sbr.h"
#include "aacsbr.h"
#include "aacsbrdata.h"
#include "aacsbr_fixed_tablegen.h"
#include "fft.h"
#include "aacps.h"
#include "sbrdsp.h"
#include "libavutil/internal.h"
#include "libavutil/libm.h"
#include "libavutil/avassert.h"
#include <stdint.h>
#include <float.h>
#include <math.h>
#include "aacsbr_template.c"
