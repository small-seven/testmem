#include <stddef.h>
#include "tx.h"
#include "thread.h"
#include "mem.h"
#include "avassert.h"
typedef float FFTSample;
typedef AVComplexFloat FFTComplex;

struct AVTXContext {
    int n;              /* Nptwo part */
    int m;              /* Ptwo part */

    FFTComplex *exptab; /* MDCT exptab */
    FFTComplex *tmp;    /* Temporary buffer needed for all compound transforms */
    int        *pfatab; /* Input/Output mapping for compound transforms */
    int        *revtab; /* Input mapping for power of two transforms */
};
#define FFT_NAME(x) x
#define COSTABLE(size) \
typedef struct CosTabsInitOnce {
    void (*func)(void);
    AVOnce control;
} CosTabsInitOnce;
#define INIT_FF_COS_TABS_FUNC(index, size)                                     \
#define BF(x, y, a, b) do {                                                    \
#define CMUL(dre, dim, are, aim, bre, bim) do {                                \
#define CMUL3(c, a, b) CMUL((c).re, (c).im, (a).re, (a).im, (b).re, (b).im)
#define DECL_FFT5(NAME, D0, D1, D2, D3, D4)                                    \
#define BUTTERFLIES(a0,a1,a2,a3) {\
#define BUTTERFLIES_BIG(a0,a1,a2,a3) {\
#define TRANSFORM(a0,a1,a2,a3,wre,wim) {\
#define TRANSFORM_ZERO(a0,a1,a2,a3) {\
#define PASS(name)\
#undef BUTTERFLIES
#define BUTTERFLIES BUTTERFLIES_BIG
#define DECL_FFT(n,n2,n4)\
#define pass pass_big
#define DECL_COMP_FFT(N)                                                       \
#define DECL_COMP_IMDCT(N)                                                     \
#define DECL_COMP_MDCT(N)                                                      \
#define CHECK_FACTOR(DST, FACTOR, SRC)                                         \
#undef CHECK_NPTWO_FACTOR
