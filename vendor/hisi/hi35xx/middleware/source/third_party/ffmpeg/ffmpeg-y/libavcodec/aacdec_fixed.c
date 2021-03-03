#define FFT_FLOAT 0
#define FFT_FIXED_32 1
#define USE_FIXED 1
#include "libavutil/fixed_dsp.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "fft.h"
#include "lpc.h"
#include "kbdwin.h"
#include "sinewin.h"
#include "aac.h"
#include "aactab.h"
#include "aacdectab.h"
#include "adts_header.h"
#include "cbrt_data.h"
#include "sbr.h"
#include "aacsbr.h"
#include "mpeg4audio.h"
#include "profiles.h"
#include "libavutil/intfloat.h"
#include <math.h>
#include <string.h>
#include "aacdec_template.c"
