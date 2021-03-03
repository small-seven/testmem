#define FFT_FLOAT 1
#define FFT_FIXED_32 0
#define USE_FIXED 0
#include "libavutil/float_dsp.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
#include "get_bits.h"
#include "fft.h"
#include "mdct15.h"
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
#include <errno.h>
#include <math.h>
#include <stdint.h>
#include <string.h>
#if ARCH_ARM
#   include "arm/aac.h"
#elif ARCH_MIPS
#   include "mips/aacdec_mips.h"
#endif
#ifndef VMUL2
#endif
#ifndef VMUL4
#endif
#ifndef VMUL2S
#endif
#ifndef VMUL4S
#endif
#include "aacdec_template.c"
#define LOAS_SYNC_WORD   0x2b7       ///< 11 bits LOAS sync word
