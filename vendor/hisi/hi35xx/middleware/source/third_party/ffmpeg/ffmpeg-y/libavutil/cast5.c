#include "cast5.h"
#include "common.h"
#include "intreadwrite.h"
#include "attributes.h"
#define IA(x) ((x) >> 24)
#define IB(x) (((x) >> 16) & 0xff)
#define IC(x) (((x) >> 8) & 0xff)
#define ID(x) ((x) & 0xff)
#define LR(x, c) (((x) << (c)) | ((x) >> (32 - (c))))
#define F3(l, r, i)                                                                                  \
#define F2(l, r, i)                                                                                  \
#define F1(l, r, i)                                                                                  \
#define COMPUTE_Z                                                                                    \
#define COMPUTE_X                                                                                    \
typedef struct AVCAST5 {
    uint32_t Km[17];
    uint32_t Kr[17];
    int rounds;
} AVCAST5;
