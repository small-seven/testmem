#include "config.h"
#ifndef AVFFT
#define AVFFT 0
#endif
#include <math.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libavutil/cpu.h"
#include "libavutil/lfg.h"
#include "libavutil/log.h"
#include "libavutil/mathematics.h"
#include "libavutil/time.h"
#if AVFFT
#include "libavcodec/avfft.h"
#else
#include "libavcodec/fft.h"
#endif
#if FFT_FLOAT
#include "libavcodec/dct.h"
#include "libavcodec/rdft.h"
#endif
#define MUL16(a, b) ((a) * (b))
#define CMAC(pre, pim, are, aim, bre, bim)          \
#if FFT_FLOAT || AVFFT
#define RANGE 1.0
#define REF_SCALE(x, bits)  (x)
#define FMT "%10.6f"
#elif FFT_FIXED_32
#define RANGE 8388608
#define REF_SCALE(x, bits) (x)
#define FMT "%6d"
#else
#define RANGE 16384
#define REF_SCALE(x, bits) ((x) / (1 << (bits)))
#define FMT "%6d"
#endif
#if CONFIG_MDCT
#endif /* CONFIG_MDCT */
#if FFT_FLOAT
#if CONFIG_DCT
#endif /* CONFIG_DCT */
#endif /* FFT_FLOAT */
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if FFT_FLOAT
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#if AVFFT
#else
#endif
#endif /* FFT_FLOAT */
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
#if FFT_FLOAT
#endif /* FFT_FLOAT */
#if !AVFFT
#endif
#if !AVFFT && FFT_FLOAT
#endif
#if CONFIG_MDCT
#endif /* CONFIG_MDCT */
#if FFT_FLOAT
#    if CONFIG_RDFT
#    endif /* CONFIG_RDFT */
#    if CONFIG_DCT
#    endif /* CONFIG_DCT */
#endif /* FFT_FLOAT */
#if CONFIG_MDCT
#endif /* CONFIG_MDCT */
#if FFT_FLOAT
#if CONFIG_RDFT
#endif /* CONFIG_RDFT */
#if CONFIG_DCT
#endif /* CONFIG_DCT */
#endif /* FFT_FLOAT */
#if FFT_FLOAT
#endif /* FFT_FLOAT */
#if CONFIG_MDCT
#endif /* CONFIG_MDCT */
#if FFT_FLOAT
#    if CONFIG_RDFT
#    endif /* CONFIG_RDFT */
#    if CONFIG_DCT
#    endif /* CONFIG_DCT */
#endif /* FFT_FLOAT */
#if !AVFFT
#endif
#if !AVFFT && FFT_FLOAT
#endif
