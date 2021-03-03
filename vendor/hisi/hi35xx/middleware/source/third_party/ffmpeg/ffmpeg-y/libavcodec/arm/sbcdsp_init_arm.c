#include "libavutil/cpu.h"
#include "libavutil/arm/cpu.h"
#include "libavcodec/sbcdsp.h"
#if HAVE_BIGENDIAN
#define PERM(a, b, c, d) {        \
#else
#define PERM(a, b, c, d) {        \
#endif
