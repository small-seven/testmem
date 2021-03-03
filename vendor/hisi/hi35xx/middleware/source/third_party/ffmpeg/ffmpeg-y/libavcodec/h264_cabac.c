#define CABAC(h) 1
#define UNCHECKED_BITSTREAM_READER 1
#define INT_BIT (CHAR_BIT * sizeof(int))
#include "libavutil/attributes.h"
#include "libavutil/avassert.h"
#include "libavutil/timer.h"
#include "config.h"
#include "cabac.h"
#include "cabac_functions.h"
#include "internal.h"
#include "avcodec.h"
#include "h264dec.h"
#include "h264data.h"
#include "h264_mvpred.h"
#include "mpegutils.h"
#if ARCH_X86
#include "x86/h264_cabac.c"
#endif
#define DECODE_CABAC_MB_MVD(sl, list,  n )\
#if !ARCH_X86
#define CABAC_ON_STACK
#endif
#ifdef CABAC_ON_STACK
#define CC &cc
#if !UNCHECKED_BITSTREAM_READER || ARCH_AARCH64
#endif
#else
#define CC &sl->cabac
#endif
#define DECODE_SIGNIFICANCE( coefs, sig_off, last_off ) \
#ifdef decode_significance
#else
#endif
#define STORE_BLOCK(type) \
#ifdef CABAC_ON_STACK
#endif
