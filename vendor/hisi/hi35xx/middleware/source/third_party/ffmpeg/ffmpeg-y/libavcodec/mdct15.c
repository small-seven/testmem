#include <float.h>
#include <math.h>
#include <stddef.h>
#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/common.h"
#include "mdct15.h"
#define FFT_FLOAT 1
#include "fft-internal.h"
#define CMUL3(c, a, b) CMUL((c).re, (c).im, (a).re, (a).im, (b).re, (b).im)
