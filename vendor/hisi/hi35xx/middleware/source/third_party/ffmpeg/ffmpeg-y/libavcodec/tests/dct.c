#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <math.h>
#include "libavutil/cpu.h"
#include "libavutil/common.h"
#include "libavutil/internal.h"
#include "libavutil/lfg.h"
#include "libavutil/time.h"
#include "libavcodec/dct.h"
#include "libavcodec/idctdsp.h"
#include "libavcodec/simple_idct.h"
#include "libavcodec/xvididct.h"
#include "libavcodec/aandcttab.h"
#include "libavcodec/faandct.h"
#include "libavcodec/faanidct.h"
#include "libavcodec/dctref.h"
#if CONFIG_FAANDCT
#endif /* CONFIG_FAANDCT */
#if CONFIG_FAANIDCT
#endif /* CONFIG_FAANIDCT */
#if CONFIG_MPEG4_DECODER
#endif /* CONFIG_MPEG4_DECODER */
#if ARCH_AARCH64
#include "aarch64/dct.c"
#elif ARCH_ARM
#include "arm/dct.c"
#elif ARCH_PPC
#include "ppc/dct.c"
#elif ARCH_X86
#include "x86/dct.c"
#else
#endif
#define AANSCALE_BITS 12
#define NB_ITS 20000
#define NB_ITS_SPEED 50000
#if ARCH_X86
#endif
#if 0
#endif
#if !HAVE_GETOPT
#include "compat/getopt.c"
#endif
#if CONFIG_FDCTDSP
#endif /* CONFIG_FDCTDSP */
