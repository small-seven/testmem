#include "avutil.h"
#include "common.h"
#include "intreadwrite.h"
#include "mem.h"
#include "xtea.h"
#if !CONFIG_SMALL
#endif
#if CONFIG_SMALL
#else
#define DSTEP(SUM, K0, K1) \
#endif
#if CONFIG_SMALL
#else
#define ESTEP(SUM, K0, K1) \
#endif
