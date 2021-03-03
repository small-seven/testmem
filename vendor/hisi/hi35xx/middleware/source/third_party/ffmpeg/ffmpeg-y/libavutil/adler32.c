#include "config.h"
#include "adler32.h"
#include "common.h"
#include "intreadwrite.h"
#define BASE 65521L /* largest prime smaller than 65536 */
#define DO1(buf)  { s1 += *buf++; s2 += s1; }
#define DO4(buf)  DO1(buf); DO1(buf); DO1(buf); DO1(buf);
#define DO16(buf) DO4(buf); DO4(buf); DO4(buf); DO4(buf);
#if HAVE_FAST_64BIT && HAVE_FAST_UNALIGNED && !CONFIG_SMALL
#if HAVE_BIGENDIAN
#else
#endif
#else
#endif
