#define ZLIB_INTERNAL
#include "zlib.h"
#define BASE 65521UL    /* largest prime smaller than 65536 */
#define NMAX 5552
#define DO1(buf,i)  {adler += (buf)[i]; sum2 += adler;}
#define DO2(buf,i)  DO1(buf,i); DO1(buf,i+1);
#define DO4(buf,i)  DO2(buf,i); DO2(buf,i+2);
#define DO8(buf,i)  DO4(buf,i); DO4(buf,i+4);
#define DO16(buf)   DO8(buf,0); DO8(buf,8);
#ifdef NO_DIVIDE
#  define MOD(a) \
#  define MOD4(a) \
#else
#  define MOD(a) a %= BASE
#  define MOD4(a) a %= BASE
#endif
