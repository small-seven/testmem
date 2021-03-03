#include "config.h"
#include "libavutil/attributes.h"
#include "avcodec.h"
#include "idctdsp.h"
#include "xvididct.h"
#define ROW_SHIFT 11
#define COL_SHIFT  6
#define RND0 65536 // 1 << (COL_SHIFT + ROW_SHIFT - 1);
#define RND1 3597  // FIX (1.75683487303);
#define RND2 2260  // FIX (1.10355339059);
#define RND3 1203  // FIX (0.587788325588);
#define RND4 0
#define RND5 120   // FIX (0.058658283817);
#define RND6 512   // FIX (0.25);
#define RND7 512   // FIX (0.25);
#define TAN1  0x32EC
#define TAN2  0x6A0A
#define TAN3  0xAB0E
#define SQRT2 0x5A82
#define MULT(c, x, n)  (((c) * (x)) >> (n))
#define BUTTERFLY(a, b, tmp)     \
#define LOAD_BUTTERFLY(m1, m2, a, b, tmp, s)   \
