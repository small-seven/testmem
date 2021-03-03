#include "simple_idct.h"
#include "bit_depth_template.c"
#undef W1
#undef W2
#undef W3
#undef W4
#undef W5
#undef W6
#undef W7
#undef ROW_SHIFT
#undef COL_SHIFT
#undef DC_SHIFT
#undef MUL
#undef MAC
#if BIT_DEPTH == 8
#define W1  22725  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W2  21407  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W3  19266  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W4  16383  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W5  12873  //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W6  8867   //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define W7  4520   //cos(i*M_PI/16)*sqrt(2)*(1<<14) + 0.5
#define ROW_SHIFT 11
#define COL_SHIFT 20
#define DC_SHIFT 3
#define MUL(a, b)    MUL16(a, b)
#define MAC(a, b, c) MAC16(a, b, c)
#elif BIT_DEPTH == 10 || BIT_DEPTH == 12
# if BIT_DEPTH == 10
#define W1 22725 // 90901
#define W2 21407 //  85627
#define W3 19265 //  77062
#define W4 16384 //  65535
#define W5 12873 //  51491
#define W6  8867 //  35468
#define W7  4520 //  18081
#   ifdef EXTRA_SHIFT
#define ROW_SHIFT 13
#define COL_SHIFT 18
#define DC_SHIFT  1
#   elif IN_IDCT_DEPTH == 32
#define ROW_SHIFT 13
#define COL_SHIFT 21
#define DC_SHIFT  2
#   else
#define ROW_SHIFT 12
#define COL_SHIFT 19
#define DC_SHIFT  2
#   endif
# else
#define W1 45451
#define W2 42813
#define W3 38531
#define W4 32767
#define W5 25746
#define W6 17734
#define W7 9041
#define ROW_SHIFT 16
#define COL_SHIFT 17
#define DC_SHIFT -1
# endif
#define MUL(a, b)    ((int)((SUINT)(a) * (b)))
#define MAC(a, b, c) ((a) += (SUINT)(b) * (c))
#else
#error "Unsupported bitdepth"
#endif
#ifdef EXTRA_SHIFT
#else
#endif
#if IN_IDCT_DEPTH == 16
#if HAVE_FAST_64BIT
#define ROW0_MASK (0xffffLL << 48 * HAVE_BIGENDIAN)
#else
#endif
#endif
#if IN_IDCT_DEPTH == 32
#else
#endif
#define IDCT_COLS do {                                  \
#ifdef EXTRA_SHIFT
#else
#endif
#ifndef EXTRA_SHIFT
#if IN_IDCT_DEPTH == 16
#endif
#endif
