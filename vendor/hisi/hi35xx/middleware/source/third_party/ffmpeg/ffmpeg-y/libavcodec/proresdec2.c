#define LONG_BITSTREAM_READER
#include "libavutil/internal.h"
#include "avcodec.h"
#include "get_bits.h"
#include "idctdsp.h"
#include "internal.h"
#include "profiles.h"
#include "simple_idct.h"
#include "proresdec.h"
#include "proresdata.h"
#include "thread.h"
#define ALPHA_SHIFT_16_TO_10(alpha_val) (alpha_val >> 6)
#define ALPHA_SHIFT_8_TO_10(alpha_val)  ((alpha_val << 2) | (alpha_val >> 6))
#define ALPHA_SHIFT_16_TO_12(alpha_val) (alpha_val >> 4)
#define ALPHA_SHIFT_8_TO_12(alpha_val)  ((alpha_val << 4) | (alpha_val >> 4))
#define DECODE_CODEWORD(val, codebook, SKIP)                            \
#define TOSIGNED(x) (((x) >> 1) ^ (-((x) & 1)))
#define FIRST_DC_CB 0xB8
#if HAVE_THREADS
#endif
